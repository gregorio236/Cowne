#ifndef GERENCIADORCOLISAO_H
#define GERENCIADORCOLISAO_H

#include "Caixa.h"

static class GerenciadorColisao
{
public:
	GerenciadorColisao();
	~GerenciadorColisao();

	static bool testarCComJ(Caixa* caixa, float dx, float dy);
	static bool testarJComC(float dx, float dy);
	static bool testarCComC(Caixa* caixa, float dx, float dy);
};

#endif