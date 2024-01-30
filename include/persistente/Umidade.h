#pragma once
#include <string>
#include <Persistente.h>


class Umidade : public Persistente
{
public:

	Umidade(vector<string> valores);
	Umidade();
	Umidade(int id);
	Umidade(int id, string area, string data , int umidade);
	Umidade(string area, string data , int umidade);
	
	~Umidade(){};

	string getID();
	
	void setArea(string area);
	string getArea();

	string getData();
	void setData(string data);

	int getUmidade();
	void setUmidade(int umidade);

	TeAttributeList getAtributos();
	vector<string> getValores();
	void setValores(vector<string> valores);

	Persistente* clone(vector<string> valores);

private:
	void setID(int id);

	int umidade, ID;
	string data, area;
};

