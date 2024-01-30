#pragma once
#include <Persistente.h>

class Perda : public Persistente
{
public:
	Perda(vector<string> valores);
	Perda();
	Perda(int id);
	Perda(int umidade, int perda);
	Perda(string id, int umidade, int perda);
	
	~Perda(void);
	
	std::string getID();

	void setUmidade(int umidade);
	int getUmidade();

	void setPerda(int perda);
	int getPerda();

	TeAttributeList getAtributos();
	vector<string> getValores();
	void setValores(vector<string> valores);

	Persistente* clone(vector<string> valores);

private:
	string id;
	int umidade;
	int perda;
	void setID(int ID);
};

