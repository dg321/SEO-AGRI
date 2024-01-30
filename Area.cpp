#include "Area.h"
#include <qmessagebox.h>

Area::Area(vector<string> valores){
	this->setValores(valores);
}

Area::Area(string id){
	this->setID(id);
}

Area::Area(string id, vector<vector<double>> coordenadas){
	this->setID(id);
	this->setCoordenadas(coordenadas);
}

Area::Area(void)
{
}

string Area::getID(){
	return this->id;
}

void Area::setID(string id){
	if (id != "")
		this->id = id;
}

void Area::setTamanho(double tamanho){
	if (tamanho >= 0)
		this->tamanho = tamanho;
}

double Area::getTamanho(){
	return this->tamanho;
}

vector<string> Area::getValores(){
	vector<string> retorno;
	retorno.push_back(this->getID());
	retorno.push_back(Te2String(this->getTamanho(),3).c_str());
	return retorno;
}

void Area::setValores(vector<string> valores){
	this->setID(valores[0]);
	this->setTamanho(atof(valores[1].c_str()));
}

TeAttributeList Area::getAtributos(){
	
	// Define uma lista de atributos

    TeAttributeList attList;
    TeAttribute at;

    at.rep_.type_ = TeSTRING;
    at.rep_.numChar_ = 80;
    at.rep_.name_ = "ID";
	at.rep_.isPrimaryKey_ = true;
    attList.push_back(at); 

    at.rep_.type_ = TeREAL;
    at.rep_.numChar_ = 5;
    at.rep_.decimals_ = 3;
    at.rep_.name_ = "Tamanho";
    at.rep_.isPrimaryKey_ = false;
	at.rep_.isAutoNumber_ = false;
	at.rep_.null_ = true;
    attList.push_back(at);  

	return attList;
}

Persistente* Area::clone(vector<string> valores){
	return new Area(valores);
}


void Area::setCoordenadas(vector<vector<double>> coordenadas){
	if (coordenadas.size() > 0)
		this->coordenadas = coordenadas;
}

void Area::addCoordenadas(double coord_X, double coord_Y){
	vector<double> coordenada;
	coordenada.push_back(coord_X);
	coordenada.push_back(coord_Y);

	coordenadas.push_back(coordenada);
}

vector<vector<double>> Area::getCoordenadas(){
	return this->coordenadas;
}