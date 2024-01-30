#include "Persistir.h"
#include <qmessagebox.h>

void Persistir::carregar(Persistente* objeto, TeDatabase* dataBase, string tabela, string layer)
{
	TeTable table = carregaTabela(dataBase, objeto->getAtributos(), layer, tabela);

	for (int i = 0; i < table.size(); i++){
		if (table[i][0].c_str() == objeto->getID())
			objeto->setValores(table[i]);
	}
}

bool Persistir::deletar(Persistente* objeto, TeDatabase* dataBase, string tabela, string layer){
	string sql = "DELETE FROM " + tabela + " WHERE ID = '" + objeto->getID() + "'";

	return dataBase->execute(sql);

}

bool Persistir::salvar(Persistente* objeto, TeDatabase* dataBase, string tabela, string layer)
{
	carregaTabela(dataBase, objeto->getAtributos(), layer, tabela);

	string filtro = "ID = '" + objeto->getID() + "'";

	vector<Persistente*> objetos = Persistir::buscar(objeto, dataBase, tabela, filtro);

	if (objetos.size() == 0){
		TeTable table(tabela, objeto->getAtributos(), "");

		TeTableRow row;

		for (int i = 0; i < objeto->getValores().size(); i ++){
			row.push_back(objeto->getValores()[i]);
		}

		table.add(row);
		return dataBase->insertTable(table);
	} else {
		string sql = "UPDATE " + tabela + " SET ";
		for (int i = 1; i < objeto->getValores().size(); i++){
			sql += objeto->getAtributos()[i].rep_.name_ + " = '" + objeto->getValores()[i] + "'";
			if (i+1 < objeto->getValores().size())
				sql += " , ";
		}
		sql += " where ID = '" + objeto->getID() + "'";

		return dataBase->execute(sql);
	}
	
}

TeLayer* Persistir::carregaLayer(TeDatabase* dataBase,  string layer){

	// varifica se a camada já foi criada, se não foi ele cria
	if (!dataBase->layerExist(layer)) {
		
		TeLayer* layer_;
		
		layer_ = new TeLayer(layer,dataBase, pLatLong()); 

		return layer_;	
	}

	// carrega a camada
	TeLayer* layer_ = new TeLayer(layer);
	dataBase->loadLayer(layer_);
	return layer_;
}

TeTable Persistir::carregaTabela(TeDatabase* dataBase, TeAttributeList atributos, string layer,  string tabela){

	TeLayer* layer_ = carregaLayer(dataBase, layer);

	TeTable table(tabela, atributos, "");

	// verifica se a tabela já existe, casso não  existir cria
	if (!dataBase->tableExist(tabela)){ 
		if (!layer_->createAttributeTable(table))
			QMessageBox::message("SEO-AGRI", dataBase->errorMessage().c_str());
	}

	dataBase->loadTable(tabela, table);

	return table;
}


TeProjection* Persistir::pLatLong(){
	return new TeLatLong(TeDatumFactory::make("SAD69"));
}

vector<Persistente*> Persistir::buscar(Persistente* objeto,  TeDatabase* dataBase, string tabela, string restricao){
	vector<Persistente*> retorno;
	TeDatabasePortal* portal = dataBase->getPortal();

	string sql = "SELECT * FROM " + tabela;
	if (restricao != "")
		sql += " where " + restricao;
	
	sql += " ;";

	if (portal->query(sql))
	{
		while (portal->fetchRow()){
			vector<string> valores;

			for (int i = 0; i <portal->numFields(); i++){
				valores.push_back(portal->getData(i));
			}
			Persistente* temp = objeto->clone(valores);
			retorno.push_back(temp);
		}
	}

	delete portal;

	return retorno;
}

bool Persistir::salvar(Poligono* objeto, TeDatabase* dataBase, string tabela, string layer){

	

	//	Cria uma variavel para armasenar as coordenadas e formar as linhas
	TeLine2D line;	

	//Abre um laço que ira pegar os valores da tabela coordenada e
	//criar as linhas. O laço termina quando for encontrado uma coordenada vazia
	for (int i = 0; i < objeto->getCoordenadas().size(); i++){
		line.add(TeCoord2D(objeto->getCoordenadas()[i][0], objeto->getCoordenadas()[i][1]));
	}

	//Verifica se a coordenada inicial é final sejá a mesma,
	//casso não ser inserir a coordenada inicial no final para fexar o poligono.
	if (line[0] != line[line.size()-1])
		line.add(TeCoord2D(line[0].x_,line[0].y_));

	TeLinearRing r1(line);

	// cria o poligono adiciona as linhas no poligono e um identificador para o polignono
	TePolygon poly;
    poly.add(r1);
	poly.objectId(objeto->getID());


    TePolygonSet ps;
    ps.add(poly);

	// Carrega a camanda pelo nome 
	TeLayer* layer_ = carregaLayer(dataBase, layer);

	
    // Adiciona o conjunto de polígonos para a camada
    // Como addGeometry não foi chamado antes, a tabela de polígonos terá um nome padrão

    if (!layer_->addPolygons(ps))
    {
		return false;
    }

	string polyTable = "Poligons11";  // tabela de polígonos 
	// Consulta 1: calcular a área do município de São Paulo 
	// Chama uma função unária sobre a tabela de polígonos 
	vector<string> spId;   // identificadores dos objetos 

	spId.push_back(objeto->getID()); 

	double area; 
	dataBase->calculateArea(polyTable, TePOLYGONS, spId, area); 

	objeto->setTamanho(0);

	Persistente* persistente = objeto;

	return salvar(persistente, dataBase, tabela, layer);
}

bool Persistir::deletar(Poligono* objeto, TeDatabase* dataBase, string tabela, string layer){
	string sql = "DELETE FROM polygons1 WHERE object_id = '" + objeto->getID() + "' ;";
	
	Persistente* persistente = objeto;
	dataBase->beginTransaction();

	if ((deletar(persistente, dataBase, tabela, layer)) & (dataBase->execute(sql))){
		dataBase->commitTransaction();
		return true;
	}else{
		dataBase->rollbackTransaction();
		return false;
	}
}