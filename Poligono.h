#pragma once
#include <Persistente.h>

class Poligono : public Persistente
{
public:
	virtual void setCoordenadas(vector<vector<double>> coordenadas) = 0;

	virtual void addCoordenadas(double coord_X, double coord_Y) = 0;
	virtual vector<vector<double>> getCoordenadas() = 0;

	virtual void setTamanho(double tamanho) = 0;

};