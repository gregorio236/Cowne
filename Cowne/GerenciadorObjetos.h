#ifndef GERENCIADOROBJETOS_H
#define GERENCIADOROBJETOS_H

#include "libUnicornio.h"

#include <vector>
using namespace std;

#include "Caixa.h"
#include "Tiro.h"

static class GerenciadorObjetos
{
public:
	static vector<Caixa*> getCaixas();

	static void Inicializar();

	static void rodar();

	static void criarTiro(float x, float y, Vetor2D direcao);

	static void criaCaixa(float x, float y);
	static Caixa* pegaCaixa(float x, float y);

	static void SalvarObjetos(const char* caminho);

private:
	static vector<Tiro*> tiros;
	static vector<Caixa*> caixas;

	static void testarTiro(Tiro * tiro);
	static void deletarTiro(Tiro* tiro);
};

#endif