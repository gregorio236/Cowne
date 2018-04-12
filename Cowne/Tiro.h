#ifndef TIRO_H
#define TIRO_H

#include "libUnicornio.h"

class Tiro
{
public:
	Tiro(float x, float y, Vetor2D direcao);
	~Tiro();

	Sprite getSprite();
	float getX();
	float getY();

	void animar();
	void andar();
	void desenhar();

private:
	Sprite sprite;
	float x, y;
	float vel;
	Vetor2D direcao;
};

#endif