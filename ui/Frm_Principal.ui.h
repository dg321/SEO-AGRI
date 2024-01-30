
/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you wish to add, delete or rename functions or slots use
** Qt Designer which will update this file, preserving your code. Create an
** init() function in place of a constructor, and a destroy() function in
** place of a destructor.
*****************************************************************************/

#include <include\persistente\Colheitadeira.h>
#include <include\persistente\Perda.h>
#include <include\persistente\Umidade.h>
#include <Distancia.h>
#include <Area.h>
#include <Persistir.h>
#include <qmessagebox.h>


static string tabelaPerdas = "perdas";
static string tabelaColheitadeiras = "colheitadeiras";
static string tabelaUmidade = "umidades";
static string tabelaArea = "areas";
static string tabelaDistancias = "distancias";
static string layer = "area";
TerraViewBase* tview_;
PluginParameters* params_;
TeDatabase* dataBase_;


void Frm_Principal::iniciar(TerraViewBase* tview, PluginParameters* params )
{
	tview_ = tview;
	params_ = params;
	dataBase_ = tview->currentDatabase();
	atualizaTodasTabelas();
	carregaTodosCombo();
	this->show();
}


void Frm_Principal::atualizaTodasTabelas()
{
	atualizarTabela(tb_PerdaLista, new Perda(), dataBase_, tabelaPerdas, "");
	atualizarTabela(tb_ColheitadeiraLista, new Colheitadeira(), dataBase_, tabelaColheitadeiras, "");
	atualizarTabela(tb_AreaLista, new Area(), dataBase_, tabelaArea, "");
	atualizarTabela(tb_UmidadeLista, new Umidade(), dataBase_, tabelaUmidade, "");
	atualizaTabelaOrdem();
	carregaMatrizDistancia();
}


void Frm_Principal::bt_PerdaDeletar_clicked()
{
	if ( tb_PerdaLista->numSelections() == 0){
		QMessageBox::message( "SEO-AGRI","Selecione um registro!" );
		return ;
	}

	if ( QMessageBox::question( this, "SEO-AGRI","Deseja mesmo excluir esse registro?", "Yes", "No" ) == 0 )
	{
		
		Perda* perda = new Perda(atoi(tb_PerdaLista->text(tb_PerdaLista->currentRow(), 0)));

		Persistir::carregar(perda, dataBase_, tabelaPerdas, layer);
		
		if (!Persistir::deletar(perda, dataBase_, tabelaPerdas, layer))
			QMessageBox::message( "SEO-AGRI",std::string("Erro ao deletar o registro! \n" + dataBase_->errorMessage()).c_str() );
		atualizarTabela(tb_PerdaLista, new Perda(), dataBase_, tabelaPerdas, "");
	}
}


void Frm_Principal::bt_PerdaSalvar_clicked()
{
	Perda* perda = new Perda(edt_PerdaUmidade->text().toInt(), edt_PerdaPerda->text().toInt());
	if (!Persistir::salvar(perda, dataBase_, tabelaPerdas, layer))
		QMessageBox::message("SEO-AGRI",std::string("Erro ao salvar o registro! \n" + dataBase_->errorMessage()).c_str());
	else
		QMessageBox::information(this, "SEO-AGRI","Registro salvo com sucesso!");

	edt_PerdaUmidade->setText("");
	edt_PerdaPerda->setText("");

	atualizarTabela(tb_PerdaLista, new Perda(), dataBase_, tabelaPerdas, "");
}


void Frm_Principal::bt_ColheitadeiraSalvar_clicked()
{
	Colheitadeira* colheitadeira = new Colheitadeira(std::string(edt_ColheitadeiraNome->text()), atoi(edt_ColheitadeiraHaHora->text()), atoi(edt_ColheitadeiraHoraColhida->text()), std::string(edt_ColheitadeiraDescricao->text()));	

	if (!Persistir::salvar(colheitadeira, dataBase_, tabelaColheitadeiras, layer))
		QMessageBox::message("SEO-AGRI",std::string("Erro ao salvar o registro! \n" + dataBase_->errorMessage()).c_str());
	else
		QMessageBox::information(this, "SEO-AGRI","Registro salvo com sucesso!");

	edt_ColheitadeiraNome->setText("");
	edt_ColheitadeiraHaHora->setText("");
	edt_ColheitadeiraHoraColhida->setText("");
	edt_ColheitadeiraDescricao->setText("");

	atualizarTabela(tb_ColheitadeiraLista, new Colheitadeira(), dataBase_, tabelaColheitadeiras, "");
}


void Frm_Principal::bt_ColheitadeiraDeletar_clicked()
{
	if ( tb_ColheitadeiraLista->numSelections() == 0){
		QMessageBox::message( "SEO-AGRI","Selecione um registro!" );
		return ;
	}

    if ( QMessageBox::question( this, "SEO-AGRI","Deseja mesmo excluir esse registro?", "Yes", "No" ) == 0 )
	{
		
		Colheitadeira* colheitadeira = new Colheitadeira(atoi(tb_ColheitadeiraLista->text(tb_ColheitadeiraLista->currentRow(), 0)));
		Persistir::carregar(colheitadeira, dataBase_, tabelaColheitadeiras, layer);
		if (!Persistir::deletar(colheitadeira, dataBase_, tabelaColheitadeiras, layer))
			QMessageBox::message( "SEO-AGRI",std::string("Erro ao deletar o registro! \n" + dataBase_->errorMessage()).c_str() );
		atualizarTabela(tb_ColheitadeiraLista, new Colheitadeira(), dataBase_, tabelaColheitadeiras, "");
	}
}


void Frm_Principal::atualizarTabela( QTable * qtTabela, Persistente * objeto, TeDatabase * database, string nomeTabela, string filtro )
{
	vector<Persistente*> objetos = Persistir::buscar(objeto, database, nomeTabela, filtro);

	qtTabela->setShown(false);

	qtTabela->setNumRows(objetos.size());

	// laço para inserir dados na tabela
	for (int i = 0;i < objetos.size(); i++) 
	{
		vector<string> valores = objetos[i]->getValores();
		for (int j = 0;j < valores.size(); j++) {
			qtTabela->setText(i,j, valores[j].c_str());
		}
	}

	// Reinicia a atualização do QTable
	qtTabela->setShown(true);
}


void Frm_Principal::bt_AreaSalvar_clicked()
{
	
	vector<vector<double>> coordenadas;

	//Abre um laço que ira pegar os valores da tabela coordenada e
	//criar as linhas. O laço termina quando for encontrado uma coordenada vazia
	for (int i = 0; true; i++){
		if (!(tb_AreaCoordenada->text(i,0) && tb_AreaCoordenada->text(i,1)))
			break;
		
		vector<double> coordenada;
		coordenada.push_back(atof(tb_AreaCoordenada->text(i,0)));
		coordenada.push_back(atof(tb_AreaCoordenada->text(i,1)));
		coordenadas.push_back(coordenada);
	}


	if ((edt_AreaNome->text() == "") | (coordenadas.size() < 3))
		return ;

	Area* area = new Area(std::string(edt_AreaNome->text()), coordenadas);

	if (!Persistir::salvar(area, dataBase_, tabelaArea, layer))
		QMessageBox::message("SEO-AGRI",std::string("Erro ao salvar o registro! \n" + dataBase_->errorMessage()).c_str());
	else
		QMessageBox::information(this, "SEO-AGRI","Registro salvo com sucesso!");

	edt_AreaNome->setText("");
	for (int i = 0; i < tb_AreaCoordenada->numRows(); i++){
		tb_AreaCoordenada->clearCell(i,0);
		tb_AreaCoordenada->clearCell(i,1);
	}
	tb_AreaCoordenada->setNumRows(8);
	
	delete area;

	atualizarTabela(tb_AreaLista, new Area(), dataBase_, tabelaArea, "");
	carregaMatrizDistancia();
	carregaCombo(cb_UmidadeArea, new Area(), dataBase_, tabelaArea, "ID", "", false);
	atualizaTabelaOrdem();
}


void Frm_Principal::bt_AreaMaisCoordenadas_clicked()
{
	tb_AreaCoordenada->setNumRows(tb_AreaCoordenada->numRows() + 1);
}


void Frm_Principal::carregaTodosCombo()
{
	carregaCombo(cb_UmidadeArea, new Area(), dataBase_, tabelaArea, "ID", "", false);
	carregaCombo(cb_UmidadeFiltroArea, new Umidade(), dataBase_, tabelaUmidade, "Area", "", true);
	carregaCombo(cb_UmidadeFiltroData, new Umidade(), dataBase_, tabelaUmidade, "Data_Medicao", "", true);
}


void Frm_Principal::bt_UmidadeSalvar_clicked()
{
	if (edt_UmidadeUmidade->text() ==  "" || de_UmidadeData->date().isNull()){
		QMessageBox::message("SEO-AGRI","Preencha todos os campos!");
		return ;
	}


	Umidade* umidade = new Umidade(std::string(cb_UmidadeArea->currentText()), std::string(de_UmidadeData->date().toString("dd/MM/yyyy")), 
		atoi(edt_UmidadeUmidade->text()));

	if (!Persistir::salvar(umidade, dataBase_, tabelaUmidade, layer))
		QMessageBox::message("SEO-AGRI",std::string("Erro ao salvar o registro! \n" + dataBase_->errorMessage()).c_str());
	else
		QMessageBox::information(this, "SEO-AGRI","Registro salvo com sucesso!");

	edt_UmidadeUmidade->clear();
	de_UmidadeData->setDate(QDate());
	cb_UmidadeArea->setCurrentItem(0);

	carregaCombo(cb_UmidadeFiltroArea, new Umidade(), dataBase_, tabelaUmidade, "Area", "", true);
	carregaCombo(cb_UmidadeFiltroData, new Umidade(), dataBase_, tabelaUmidade, "Data_Medicao", "", true);

	atualizarTabela(tb_UmidadeLista, new Umidade(), dataBase_, tabelaUmidade, "");
}


void Frm_Principal::bt_UmidadeDelete_clicked()
{
	if ( tb_UmidadeLista->numSelections() == 0){
		QMessageBox::message( "SEO-AGRI","Selecione um registro!" );
		return ;
	}

	if ( QMessageBox::question( this, "SEO-AGRI","Deseja mesmo excluir esse registro?", "Yes", "No" ) == 0 )
	{
		
		Umidade* umidade = new Umidade(atoi(tb_UmidadeLista->text(tb_UmidadeLista->currentRow(), 0)));
		Persistir::carregar(umidade, dataBase_, tabelaUmidade, layer);
		if (!Persistir::deletar(umidade, dataBase_, tabelaUmidade, layer))
			QMessageBox::message( "SEO-AGRI", std::string("Erro ao deletar o registro! \n" + dataBase_->errorMessage()).c_str() );

	carregaCombo(cb_UmidadeFiltroArea, new Umidade(), dataBase_, tabelaUmidade, "Area", "", true);
	carregaCombo(cb_UmidadeFiltroData, new Umidade(), dataBase_, tabelaUmidade, "Data_Medicao", "", true);

	atualizarTabela(tb_UmidadeLista, new Umidade(), dataBase_, tabelaUmidade, "");
	}	
}


void Frm_Principal::bt_UmidadeFiltrar_clicked()
{
	string query;
	if (cb_UmidadeFiltroArea->currentText() != "Todos")
		query = "Area = '"+ cb_UmidadeFiltroArea->currentText() +"'";
	if (cb_UmidadeFiltroData->currentText() != "Todos"){
		if (query != "")
			query += " and ";
		string data = cb_UmidadeFiltroData->currentText();
		string novaData = data.substr(6,4) + "-" + data.substr(3,2) + "-" + data.substr(0,2);
		query += " Data_Medicao like '" + novaData + "%'";
	}

	atualizarTabela(tb_UmidadeLista, new Umidade(), dataBase_, tabelaUmidade, query);
}


void Frm_Principal::carregaCombo( QComboBox * cbCombo, Persistente * objeto, TeDatabase * database, string nomeTabela, string item, string filtro, bool itemTodos)
{
	vector<Persistente*> objetos = Persistir::buscar(objeto, database, nomeTabela, filtro);
	
	cbCombo->clear();

	if (itemTodos)
		cbCombo->insertItem("Todos");

	if (objetos.size() <= 0)
		return ;

	cbCombo->setShown(false);

	int index;

	for (int i = 0;i < objeto[0].getAtributos().size(); i++)
		if (objeto[0].getAtributos()[i].rep_.name_ == item){
			index = i;
			break;
		}

	// laço para inserir dados na tabela
	for (int i = 0;i < objetos.size(); i++) 
	{
		Persistente* objeto = objetos[i];
		cbCombo->insertItem(objeto->getValores()[index].c_str());
	}
	// Reinicia a atualização do QTable
	cbCombo->setShown(true);
}


void Frm_Principal::bt_AreaDeletar_clicked()
{
	if ( tb_AreaLista->numSelections() == 0){
		QMessageBox::message( "SEO-AGRI","Selecione um registro!" );
		return ;
	}

	if ( QMessageBox::question( this, "SEO-AGRI","Deseja mesmo excluir esse registro?", "Yes", "No" ) == 0 )
	{
		
		Area* area = new Area(std::string(tb_AreaLista->text(tb_AreaLista->currentRow(), 0)));

		Persistir::carregar(area, dataBase_, tabelaArea, layer);

		string restricao = "AREA1 LIKE '"+ area->getID() +"' or AREA2 LIKE '"+ area->getID() +"'";

		vector<Persistente*> distancias = Persistir::buscar(new Area(), dataBase_, tabelaDistancias, restricao);

		vector<Persistente*> umidade = Persistir::buscar(new Umidade(), dataBase_, tabelaUmidade, " Area = '" + area->getID() +"'");

		dataBase_->beginTransaction();

		bool erro = false;

		for (int i = 0; (i < distancias.size()) && (!erro); i++)
			erro = !Persistir::deletar(distancias[i], dataBase_, tabelaDistancias, layer);	

		for (int i = 0; (i < umidade.size()) && (!erro); i++)
			erro = !Persistir::deletar(umidade[i], dataBase_, tabelaUmidade, layer);	

		if ((!erro) && !Persistir::deletar(area, dataBase_, tabelaArea, layer)){
			dataBase_->rollbackTransaction();
			QMessageBox::message( "SEO-AGRI", std::string("Erro ao deletar o registro! \n" + dataBase_->errorMessage()).c_str() );
		}

		dataBase_->commitTransaction();


		atualizaTodasTabelas();
		carregaTodosCombo();
	}	
}


void Frm_Principal::carregaMatrizDistancia()
{
	vector<Persistente*> areas = Persistir::buscar(new Area(), dataBase_, tabelaArea, "ID like '%%' order by ID");

	tb_DistanciaMatriz->setNumCols(areas.size());
	tb_DistanciaMatriz->setNumRows(areas.size());

	for (int i = 0; i < areas.size(); i++){
		tb_DistanciaMatriz->horizontalHeader()->setLabel(i, areas[i]->getID().c_str());
		tb_DistanciaMatriz->verticalHeader()->setLabel(i, areas[i]->getID().c_str());
		tb_DistanciaMatriz->setText(i,i,"0");
	}

	vector<Persistente*> distancias = Persistir::buscar(new Distancia(), dataBase_, tabelaDistancias, "");

	for (int i = 0; i < distancias.size(); i++){
		int x, y;
		for (int j = 0; j < tb_DistanciaMatriz->numCols(); j++){
			if (tb_DistanciaMatriz->horizontalHeader()->label(j) == distancias[i]->getValores()[1].c_str())
				x = j;
			if (tb_DistanciaMatriz->verticalHeader()->label(j) == distancias[i]->getValores()[2].c_str())
				y = j;
		}
		tb_DistanciaMatriz->setText(x,y, distancias[i]->getValores()[3].c_str());
	}

}


void Frm_Principal::bt_DistanciaSalvar_released()
{
	bool erro = false;
	dataBase_->beginTransaction();
	for (int x = 0; ((x < tb_DistanciaMatriz->numCols()) && (!erro)) ; x++){
		for(int y = 0; ((y < tb_DistanciaMatriz->numRows()) && (!erro)); y++){
			string restricao = " Area1 = '" + 
				std::string(tb_DistanciaMatriz->horizontalHeader()->label(x)) + "' and Area2 = '" +
				std::string(tb_DistanciaMatriz->verticalHeader()->label(y)) + "'";

			vector<Persistente*> objetos = Persistir::buscar(new Distancia(), dataBase_, tabelaDistancias, restricao);

			Distancia* distancia;

			if (objetos.size() > 0){
				distancia = new Distancia(objetos[0]->getValores());
				distancia->setDistancia(atof(tb_DistanciaMatriz->text(y, x)));
			}
			else{
				distancia = new Distancia(std::string(tb_DistanciaMatriz->horizontalHeader()->label(x)), 
					std::string(tb_DistanciaMatriz->verticalHeader()->label(y)), atof(tb_DistanciaMatriz->text(y, x)));
			}
			erro = !Persistir::salvar(distancia, dataBase_, tabelaDistancias, layer);
		}
	}

	if (erro){
		dataBase_->rollbackTransaction();
		QMessageBox::message("SEO-AGRI", std::string("Erro ao salvar o registro! \n" + dataBase_->errorMessage()).c_str());
	}else{
		dataBase_->commitTransaction();
		carregaMatrizDistancia();
		QMessageBox::information(this, "SEO-AGRI","Registro salvo com sucesso!");
	}

}


void Frm_Principal::bt_OrdenarAdicionar_clicked()
{
	if (tb_OrdenarLista->numSelections() > 0)
	{
		for (int i = 0; i < tb_OrdenarLista->numRows(); i++)
		{
			if (tb_OrdenarLista->isRowSelected(i))
			{
				tb_OrdenarHaOrdenar->setNumRows(tb_OrdenarHaOrdenar->numRows() + 1);
				tb_OrdenarHaOrdenar->setText(tb_OrdenarHaOrdenar->numRows() - 1, 0, tb_OrdenarLista->text(i, 0));
			}
		}
	}
	atualizaTabelaOrdem();
}


void Frm_Principal::bt_OrdenarAdicionarTodas_clicked()
{
	for (int i = 0; i < tb_OrdenarLista->numRows(); i++)
	{
		tb_OrdenarHaOrdenar->setNumRows(tb_OrdenarHaOrdenar->numRows() + 1);
		tb_OrdenarHaOrdenar->setText(tb_OrdenarHaOrdenar->numRows() - 1, 0, tb_OrdenarLista->text(i, 0));
	}

	atualizaTabelaOrdem();
}


void Frm_Principal::bt_OrdenarRemoverTodos_clicked()
{
	tb_OrdenarHaOrdenar->setNumRows(0);

	atualizaTabelaOrdem();
}


void Frm_Principal::bt_OrdenarRemover_clicked()
{
	if (tb_OrdenarHaOrdenar->numSelections() > 0)
	{
		for (int i = 0; i < tb_OrdenarHaOrdenar->numRows(); i++)
		{
			if (tb_OrdenarHaOrdenar->isRowSelected(i))
			{
				tb_OrdenarHaOrdenar->removeRow(i);
			}
		}
	}
	atualizaTabelaOrdem();
}


void Frm_Principal::bt_OrdenarOrdenar_clicked()
{

}




void Frm_Principal::atualizaTabelaOrdem()
{
	vector<Persistente*> objetos = Persistir::buscar(new Area(), dataBase_, tabelaArea, "ID like '%%' order by ID");

	tb_OrdenarLista->setNumRows(0);
	

	for (int i = 0; i < objetos.size(); i++){
		boolean existe = false;

		for (int x = 0; x < tb_OrdenarHaOrdenar->numRows(); x++)
			if (objetos[i]->getID() == std::string(tb_OrdenarHaOrdenar->text(x,0))){
				existe = true;
				break;
			}
		if (!existe){
			tb_OrdenarLista->setNumRows(tb_OrdenarLista->numRows() + 1);
			tb_OrdenarLista->setText(tb_OrdenarLista->numRows() - 1, 0, objetos[i]->getID().c_str());
		}
	}

	tb_OrdenarHaOrdenar->clearSelection();
	tb_OrdenarLista->clearSelection();
	
}
