#include "Distancia.h"


Distancia::Distancia(vector<string> valores){
	this->setValores(valores);
}

Distancia::Distancia(int id){
	this->setID(id);
}

Distancia::Distancia(string area_1, string area_2, double distancia){
	this->setArea1(area_1);
	this->setArea2(area_2);
	this->setDistancia(distancia);
}

Distancia::Distancia(int id, string area_1, string area_2, double distancia){
	this->setID(id);
	this->setArea1(area_1);
	this->setArea2(area_2);
	this->setDistancia(distancia);
}

string Distancia::getID(){
	return Te2String(id);
}

void Distancia::setID(int id){
	if (id != 0)
		this->id = id;
}

vector<string> Distancia::getValores(){
	vector<string> retorno;
	retorno.push_back(this->getID());
	retorno.push_back(this->getArea1());
	retorno.push_back(this->getArea2());
	retorno.push_back(Te2String(this->getDistancia(),3));

	return retorno;
}

void Distancia::setValores(vector<string> valores){
	if (valores.size() <= 0)
		return ;

	this->setID(atoi(valores[0].c_str()));
	this->setArea1(valores[1]);
	this->setArea2(valores[2]);
	this->setDistancia(atoi(valores[3].c_str()));
}
	
TeAttributeList Distancia::getAtributos(){

	TeAttributeList attList;
	TeAttribute at;

    at.rep_.name_= "ID";						// Nome do Atributo (o mesmo que aparecerra na tabela)
    at.rep_.type_ = TeINT;						// Tipo de atributo
    at.rep_.isPrimaryKey_ = true;				// Se ele sera chave primaria
	at.rep_.isAutoNumber_ = true;				// Se ele sera auto-incremento
	at.rep_.null_ = false;						// Se ele pode ser nulo
    attList.push_back(at);						// Adiciona o atributo a lista

	at.rep_.name_ = "Area1";
	at.rep_.type_ = TeSTRING;
	at.rep_.numChar_ = 50;
	at.rep_.isPrimaryKey_ = false;
	at.rep_.isAutoNumber_ = false;
	at.rep_.null_ = false;	
	attList.push_back(at); 

	at.rep_.name_ = "Area2";
	at.rep_.type_ = TeSTRING;
	at.rep_.numChar_ = 50;
	at.rep_.isPrimaryKey_ = false;
	at.rep_.isAutoNumber_ = false;
	at.rep_.null_ = false;	
	attList.push_back(at); 

	at.rep_.name_ = "Distancia";
    at.rep_.type_ = TeREAL;
    at.rep_.numChar_ = 5;
    at.rep_.decimals_ = 3;
    at.rep_.isPrimaryKey_ = false;
	at.rep_.isAutoNumber_ = false;
	at.rep_.null_ = true;
    attList.push_back(at);  

	return attList;
}

Persistente* Distancia::clone(vector<string> valores){
	return new Distancia(valores);
}

void Distancia::setAreas(string area_1, string area_2){
	this->setArea1(area_1);
	this->setArea2(area_2);
}

void Distancia::setArea1(string area){
	if (area != "")
		this->area_1 = area;
}

string Distancia::getArea1(){
	return this->area_1;
}

void Distancia::setArea2(string area){
	if (area != "")
		this->area_2 = area;
}

string Distancia::getArea2(){
	return this->area_2;
}

void Distancia::setDistancia(double distancia){
	if (distancia >= 0)
		this->distancia = distancia;
}

double Distancia::getDistancia(){
	return this->distancia;
}