#include "include\persistente\Umidade.h"
#include <qmessagebox.h>

Umidade::Umidade(vector<string> valores){
	setValores(valores);
}
	
Umidade::Umidade(){
}

Umidade::Umidade(int id){
	setID(id);
}

Umidade::Umidade(int id, string area, string data , int umidade){
	setID(id);
	this->setData(data);
	this->setUmidade(umidade);
	this->setArea(area);
}

Umidade::Umidade(string area, string data , int umidade){
	this->setData(data);
	this->setUmidade(umidade);
	this->setArea(area);
}

string Umidade::getID(){
	return  Te2String(this->ID);
}

void Umidade::setID(int id){
	if (id > 0)
		this->ID = id;
}

void Umidade::setArea(string area){
	if (area != "")
		this->area = area;
}

string Umidade::getArea(){
	return this->area;
}

void Umidade::setData(string data){
	int pos = data.find("-");

	if (pos != string::npos){
		this->data = data.substr(8,2) + "/" + data.substr(5,2) + "/" + data.substr(0,4); 
	} else {
		this->data = data.substr(0,10);
	}
}

string Umidade::getData(){
	return this->data;
}
	
void Umidade::setUmidade(int umidade){
	if (umidade > 0)
		this->umidade = umidade;
}

int Umidade::getUmidade(){
	return this->umidade;
}
	

TeAttributeList Umidade::getAtributos(){
	// Define uma lista de atributos

	TeAttributeList attList;
	TeAttribute at;

	at.rep_.name_= "ID";						// Nome do Atributo (o mesmo que aparecerra na tabela)
    at.rep_.type_ = TeINT;						// Tipo de atributo
    at.rep_.isPrimaryKey_ = true;				// Se ele sera chave primaria
	at.rep_.isAutoNumber_ = true;				// Se ele sera auto-incremento
	at.rep_.null_ = false;						// Se ele pode ser nulo
    attList.push_back(at);						// Adiciona o atributo a lista

	at.rep_.type_ = TeSTRING;
    at.rep_.numChar_ = 80;
    at.rep_.name_ = "Area";
	at.rep_.isPrimaryKey_ = false;
	at.rep_.isAutoNumber_ = false;
    attList.push_back(at); 

    at.rep_.name_= "Data_Medicao";
    at.rep_.type_ = TeDATETIME;
    at.dateTimeFormat_ = "DDsMMsYYYY";
    at.dateChronon_ = TeSECOND;
    attList.push_back(at);

	at.rep_.name_= "Umidade";        
	at.rep_.type_ = TeREAL;  
	at.rep_.numChar_ = 2;
    at.rep_.decimals_ = 2;
	at.rep_.null_ = false;
	at.rep_.isPrimaryKey_ = false;
	attList.push_back(at);

	return attList;
}

vector<string> Umidade::getValores(){
	vector<string> retorno;

	retorno.push_back(this->getID());
	retorno.push_back(this->area);
	retorno.push_back(this->data);
	retorno.push_back(Te2String(this->getUmidade()));

	return retorno;
}
void Umidade::setValores(vector<string> valores){
	this->setID(atoi(valores[0].c_str()));
	this->setArea(valores[1].c_str());
	this->setData(valores[2].c_str());
	this->setUmidade(atoi(valores[3].c_str()));
}

Persistente* Umidade::clone(vector<string> valores){
	return new Umidade(valores);
}



