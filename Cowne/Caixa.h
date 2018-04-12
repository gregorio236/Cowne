#ifndef CAIXA_H
#define CAIXA_H

#include "libUnicornio.h"

class Caixa
{
public:
	Caixa(float x, float y);
	~Caixa();

	Sprite getSprite();
	float getX();
	float getY();

	void setPosicao(float x, float y);

	void animar();
	void desenhar();

private:
	Sprite sprite;
	float x, y;
	float vel;

	void deslocamentoX(float &x, float vel);
	void deslocamentoY(float &y, float vel);
};

#endif