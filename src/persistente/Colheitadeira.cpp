#include "include\persistente\Colheitadeira.h"

Colheitadeira::Colheitadeira(vector<string> valores){
	this->setValores(valores);
}

Colheitadeira::Colheitadeira(){
}

Colheitadeira::Colheitadeira(int id){
	this->setID(id);
}

Colheitadeira::Colheitadeira(string nome, int hacolhidaHora, int horaColhidaDia, string descricao)
{
	this->setNome(nome);
	this->setHacolhidaHora(hacolhidaHora);
	this->setHoraColhidaDia(horaColhidaDia);
	this->setDescricao(descricao);
}


Colheitadeira::Colheitadeira(int id, string nome, int hacolhidaHora, int horaColhidaDia, string descricao)
{
	this->setID(id);
	this->setNome(nome);
	this->setHacolhidaHora(hacolhidaHora);
	this->setHoraColhidaDia(horaColhidaDia);
	this->setDescricao(descricao);	
}

Colheitadeira::~Colheitadeira(void)
{
}


TeAttributeList Colheitadeira::getAtributos(){
	TeAttributeList attList;        
    
	TeAttribute atr;

    atr.rep_.name_= "ID";						// Nome do Atributo (o mesmo que aparecerra na tabela)
    atr.rep_.type_ = TeINT;						// Tipo de atributo
    atr.rep_.isPrimaryKey_ = true;				// Se ele sera chave primaria
	atr.rep_.isAutoNumber_ = true;				// Se ele sera auto-incremento
	atr.rep_.null_ = false;						// Se ele pode ser nulo
    attList.push_back(atr);						// Adiciona o atributo a lista

	atr.rep_.name_= "NomeColheitadeira";
    atr.rep_.type_ = TeSTRING;
    atr.rep_.numChar_ = 50;						// Tamanho do atributo
    atr.rep_.isPrimaryKey_ = false;
	atr.rep_.isAutoNumber_ = false;
	atr.rep_.null_ = false;
    attList.push_back(atr);

	atr.rep_.name_= "HaColhidasPorHora";
    atr.rep_.type_ = TeINT;
    atr.rep_.isPrimaryKey_ = false;
	atr.rep_.isAutoNumber_ = false;
	atr.rep_.null_ = false;
    attList.push_back(atr);

	atr.rep_.name_= "HorasColhidasPorDia";
    atr.rep_.type_ = TeINT;
    atr.rep_.isPrimaryKey_ = false;
	atr.rep_.isAutoNumber_ = false;
	atr.rep_.null_ = false;
    attList.push_back(atr);

	atr.rep_.name_= "Descricao";
    atr.rep_.type_ = TeSTRING;
    atr.rep_.numChar_ = 250;
    atr.rep_.isPrimaryKey_ = false;
	atr.rep_.isAutoNumber_ = false;
	atr.rep_.null_ = false;
    attList.push_back(atr);

	return attList;
}

vector<string> Colheitadeira::getValores(){
	vector<string> valores;

	valores.push_back(Te2String(this->ID));
	valores.push_back(this->nome);
	valores.push_back(Te2String(this->hacolhidaHora));
	valores.push_back(Te2String(this->horaColhidaDia));
	valores.push_back(this->descricao);

	return valores;

}

void Colheitadeira::setValores(vector<string> valores){
	this->setID(atoi(valores[0].c_str()));
	this->setNome(valores[1]);
	this->setHacolhidaHora(atoi(valores[2].c_str()));
	this->setHoraColhidaDia(atoi(valores[3].c_str()));
	this->setDescricao(valores[4]);
}

Persistente* Colheitadeira::clone(vector<string> valores){
	return new Colheitadeira(valores);
}

void Colheitadeira::setNome(string nome){
	if(nome.c_str() != ""){
		this->nome = nome;
	}
}

void Colheitadeira::setHacolhidaHora(int hacolhidaHora){
	if(hacolhidaHora != 0){
		this->hacolhidaHora = hacolhidaHora;
	}
}

void Colheitadeira::setHoraColhidaDia(int horaColhidaDia){
	if(horaColhidaDia != 0){
		this->horaColhidaDia = horaColhidaDia;
	}
}

void Colheitadeira::setDescricao(string descricao){
	if(descricao.c_str() != ""){
		this->descricao = descricao;
	}

}

void Colheitadeira::setID(int id){
	if (id != 0)
		this->ID = id;
}

string Colheitadeira::getID(){
	return Te2String(this->ID);
}

string Colheitadeira::getNome(){
	return this->nome;
}

int Colheitadeira::getHacolhidaHora(){
	return this->hacolhidaHora;
}

int Colheitadeira::getHoraColhidaDia(){
	return this->horaColhidaDia;
}

int Colheitadeira::getHaColhidaDia(){
	return (this->hacolhidaHora * this->horaColhidaDia);
}

string Colheitadeira::getDescricao(){
	return this->descricao;
}