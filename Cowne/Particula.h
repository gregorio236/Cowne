#ifndef PARTICULA_H
#define PARTICULA_H

#include <vector>
using namespace std;

#include "libUnicornio.h"

class Particula
{
public:
	Particula(float x, float y, float tempo);
	~Particula();

	static void cria(int qtd, float x, float y, float raio, float tempo);

	static void rodar();

private:
	static vector<Particula*> particulas;

	Sprite sprite;
	float x, y;
	float tempo;
	float duracao;

	static void deletarParticulas();
};

#endif