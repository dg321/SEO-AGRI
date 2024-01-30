#pragma once
#include <Persistente.h>

class Distancia: public  Persistente
{
public:
	Distancia(void){};
	Distancia(vector<string> valores);
	Distancia(int id);
	Distancia(string area_1, string area_2, double distancia);
	Distancia(int id, string area_1, string area_2, double distancia);
	~Distancia(void){};
	string getID();
	vector<string> getValores();
	void setValores(vector<string> valores);
	TeAttributeList getAtributos();
	Persistente* clone(vector<string> valores);

	void setAreas(string area_1, string area_2);
	void setArea1(string area);
	string getArea1();
	void setArea2(string area);
	string getArea2();
	void setDistancia(double distancia);
	double getDistancia();

private:
	void setID(int id);
	int id;
	string area_1, area_2;
	double distancia;

};

