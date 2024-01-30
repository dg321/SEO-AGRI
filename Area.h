#pragma once
#include <Persistente.h>
#include <Poligono.h>


class Area : public Poligono
{
public: 
	Area(vector<string> valores);
	Area();
	Area(string id);
	Area(string id, vector<vector<double>> coordenadas);

	~Area(){};

	string getID();

	void setTamanho(double tamanho);
	double getTamanho();

	vector<string> getValores();
	void setValores(vector<string> valores);
	TeAttributeList getAtributos();
	Persistente* clone(vector<string> valores);

	void setCoordenadas(vector<vector<double>> coordenadas);

	void addCoordenadas(double coord_X, double coord_Y);
	vector<vector<double>> getCoordenadas();

private:
	double tamanho;
	string id;

	vector<vector<double>> coordenadas;

	void setID(string id);
};

