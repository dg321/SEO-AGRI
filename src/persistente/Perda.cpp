#include "include\persistente\Perda.h"

Perda::Perda(vector<string> valores){
	setValores(valores);
}

Perda::Perda(){
}

Perda::Perda(int id){
	this->setID(id);
}

Perda::Perda(int umidade, int perda){
	this->setUmidade(umidade);
	this->setPerda(perda);
}

Perda::Perda(string id, int umidade, int perda){
	this->setID(atoi(id.c_str()));
	this->setUmidade(umidade);
	this->setPerda(perda);
}

Perda::~Perda(void){
}
	
std::string Perda::getID(){
	return this->id;
}

void Perda::setUmidade(int umidade){
	if (umidade > 0)
		this->umidade = umidade;
}

int Perda::getUmidade(){
	return this->umidade;
}

void Perda::setPerda(int perda){
	if (perda > 0)
		this->perda = perda;
}

int Perda::getPerda(){
	return perda;
}

TeAttributeList Perda::getAtributos(){
	
	TeAttributeList attList;
	TeAttribute at;

	at.rep_.name_= "ID";        
	at.rep_.type_ = TeINT;  
	at.rep_.null_ = false;
	at.rep_.isPrimaryKey_ = true;
	at.rep_.isAutoNumber_ = true;
	attList.push_back(at);

	at.rep_.name_= "Umidade";        
	at.rep_.type_ = TeINT;  
	at.rep_.null_ = false;
	at.rep_.isPrimaryKey_ = false;
	at.rep_.isAutoNumber_ = false;
	attList.push_back(at);

	at.rep_.name_= "Perdas";        
	at.rep_.type_ = TeINT;  
	at.rep_.null_ = false;
	at.rep_.isPrimaryKey_ = false;
	at.rep_.isAutoNumber_ = false;
	attList.push_back(at);

	return attList;
}

vector<string> Perda::getValores(){
	
	vector<string> valores;

	valores.push_back(this->getID());
	valores.push_back(Te2String(this->getUmidade()));
	valores.push_back(Te2String(this->getPerda()));
	return valores;
}

void Perda::setValores(vector<string> valores){
	this->id = valores[0];
	this->setUmidade(atoi(valores[1].c_str()));
	this->setPerda(atoi(valores[2].c_str()));
}

Persistente* Perda::clone(vector<string> valores){
	return new Perda(valores);
}

void Perda::setID(int ID){
	this->id = Te2String(ID);
}