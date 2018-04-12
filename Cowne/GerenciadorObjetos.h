#ifndef GERENCIADOROBJETOS_H
#define GERENCIADOROBJETOS_H

#include "Caixa.h"
#include "Tiro.h"

static class GerenciadorObjetos
{
public:
	GerenciadorObjetos();
	~GerenciadorObjetos();

	static vector<Caixa*> getCaixas();

	static void rodar();

	static void criarTiro(float x, float y, Vetor2D direcao);

	static void criaCaixa(float x, float y);
	static Caixa* pegaCaixa(float x, float y);

private:
	static vector<Tiro*> tiros;
	static vector<Caixa*> caixas;

	static void testarTiro(Tiro * tiro);
	static void deletarTiro(Tiro* tiro);
};

#endif