#pragma once
#include <TeAttribute.h>
#include <TeUtils.h>
#include <xstring>
#include <ctime>

class Persistente
{
public:
	virtual ~Persistente(){};
	virtual string getID() = 0;
	virtual vector<string> getValores() = 0;
	virtual void setValores(vector<string> valores) = 0;
	virtual TeAttributeList getAtributos() = 0;
	virtual Persistente* clone(vector<string> valores) = 0;
};

