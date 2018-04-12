#include "Tiro.h"

Tiro::Tiro(float x, float y, Vetor2D direcao)
{
	this->x = x;
	this->y = y;
	vel = 4.0f;
	this->direcao = direcao.getNormal();

	sprite.setSpriteSheet("tiro");
	sprite.setEscala(1.5f, 1.5f);
	sprite.setVelocidadeAnimacao(20.0f);
}

Tiro::~Tiro()
{

}

Sprite Tiro::getSprite()
{
	return sprite;
}

float Tiro::getX()
{
	return x;
}

float Tiro::getY()
{
	return y;
}

void Tiro::animar()
{
	sprite.avancarAnimacao();
}

void Tiro::andar()
{
	x += vel * direcao.x;
	y += vel * direcao.y;
}

void Tiro::desenhar()
{
	sprite.desenhar(x, y, direcao.getAngulo());
}