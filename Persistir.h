#pragma once
#include <Persistente.h>
#include <Poligono.h>
#include <TeDatabase.h>

static class Persistir
{
public:
	static bool salvar(Poligono* objeto, TeDatabase* dataBase, string tabela, string layer);
	static void carregar(Persistente* objeto, TeDatabase* dataBase, string tabela, string layer);
	static bool salvar(Persistente* objeto, TeDatabase* dataBase, string tabela, string layer);
	static bool deletar(Persistente* objeto, TeDatabase* dataBase, string tabela, string layer);
	static vector<Persistente*> buscar(Persistente* objeto,  TeDatabase* dataBase, string tabela, string restricao);
	static TeProjection* pLatLong();
	static bool deletar(Poligono* objeto, TeDatabase* dataBase, string tabela, string layer);
private:
	static TeLayer* carregaLayer(TeDatabase* dataBase, string layer);
	static TeTable carregaTabela(TeDatabase* dataBase, TeAttributeList atributos, string layer, string tabela);
};

