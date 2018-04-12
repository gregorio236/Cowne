#include "Curandeiro.h"

#include "GerenciadorObjetos.h"

Curandeiro::Curandeiro()
{
	sprite.setSpriteSheet("curandeiro");
	sprite.setEscala(3.0f, 3.0f);

	som.setAudio("tiro");
	som.setVolume(45.0f);
}

Curandeiro::~Curandeiro()
{

}

void Curandeiro::poder()
{
	Vetor2D direcao;
	direcao.x = gMouse.x - x;
	direcao.y = gMouse.y - y;
	GerenciadorObjetos::criarTiro(x, y, direcao);

	som.tocar();
}
