#include "Save.h"

Save::Save()
{

}

Save::Save(Vetor2D caixa1, Vetor2D caixa2, Vetor2D caixa3)
{
	this->caixas[0] = caixa1;
	this->caixas[1] = caixa2;
	this->caixas[2] = caixa3;
}

Save::~Save()
{

}

Vetor2D Save::GetCaixa(int i)
{
	return this->caixas[i];
}
