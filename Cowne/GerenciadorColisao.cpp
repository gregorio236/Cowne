#include "GerenciadorColisao.h"

#include <vector>
using namespace std;

#include "libUnicornio.h"

#include "Jogo.h"
#include "GerenciadorObjetos.h"

GerenciadorColisao::GerenciadorColisao()
{

}

GerenciadorColisao::~GerenciadorColisao()
{

}

bool GerenciadorColisao::testarCComJ(Caixa* caixa, float dx, float dy)
{
	Personagem* j = Jogo::getJogador();
	if (uniTestarColisaoSpriteComSprite(caixa->getSprite(), dx, dy, 0.0f,
		j->getSprite(), j->getX(), j->getY(), 0.0f))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GerenciadorColisao::testarJComC(float dx, float dy)
{
	Personagem* j = Jogo::getJogador();

	vector<Caixa*> caixas = GerenciadorObjetos::getCaixas();

	for (int i = 0; i < caixas.size(); i++)
	{
		Caixa* c = caixas[i];
		if (uniTestarColisaoSpriteComSprite(j->getSprite(), dx, dy, 0.0f,
			c->getSprite(), c->getX(), c->getY(), 0.0f))
		{
			return true;
		}
	}

	return false;
}

bool GerenciadorColisao::testarCComC(Caixa * caixa, float dx, float dy)
{
	vector<Caixa*> caixas = GerenciadorObjetos::getCaixas();

	for (int i = 0; i < caixas.size(); i++)
	{
		Caixa* c = caixas[i];
		if (c != caixa)
		{
			if (uniTestarColisaoSpriteComSprite(caixa->getSprite(), dx, dy, 0.0f,
				c->getSprite(), c->getX(), c->getY(), 0.0f))
			{
				return true;
			}
		}
	}

	return false;
}
