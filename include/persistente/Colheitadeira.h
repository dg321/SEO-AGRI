#pragma once
#include <Persistente.h>


class Colheitadeira : public Persistente
{
public:

	Colheitadeira(vector<string> valores);
	Colheitadeira();
	Colheitadeira(int id);
	Colheitadeira(string nome, int hacolhidaHora, int horaColhidaDia, string descricao);
	Colheitadeira(int id, string nome, int hacolhidaHora, int horaColhidaDia, string descricao);
	~Colheitadeira();

	TeAttributeList getAtributos();
	vector<string> getValores();
	void setValores(vector<string> valores);

	Persistente* clone(vector<string> valores);

	string getID();

	void setNome(string nome);
	string getNome();

	void setHacolhidaHora(int hacolhidaHora);
	int getHacolhidaHora();

	void setHoraColhidaDia(int horaColhidaDia);
	int getHoraColhidaDia();

	int getHaColhidaDia();

	void setDescricao(string descricao);
	string getDescricao();
private:
	int ID, hacolhidaHora, horaColhidaDia;
	string nome, descricao;
	void setID(int id);

};

