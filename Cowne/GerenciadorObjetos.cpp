#include "GerenciadorObjetos.h"

vector<Tiro*> GerenciadorObjetos::tiros;
vector<Caixa*> GerenciadorObjetos::caixas;

GerenciadorObjetos::GerenciadorObjetos()
{
}

GerenciadorObjetos::~GerenciadorObjetos()
{
}

vector<Caixa*> GerenciadorObjetos::getCaixas()
{
	return caixas;
}

void GerenciadorObjetos::rodar()
{
	for (int i = 0; i < tiros.size(); i++)
	{
		tiros[i]->animar();
		tiros[i]->andar();
		testarTiro(tiros[i]);
	}
	for (int i = 0; i < tiros.size(); i++)
	{
		tiros[i]->desenhar();
	}

	for (int i = 0; i < caixas.size(); i++)
	{
		caixas[i]->animar();
		caixas[i]->desenhar();
	}
}

void GerenciadorObjetos::criarTiro(float x, float y, Vetor2D direcao)
{
	tiros.push_back(new Tiro(x, y, direcao));
}

void GerenciadorObjetos::deletarTiro(Tiro * tiro)
{
	for (int i = 0; i < tiros.size(); i++)
	{
		if (tiros[i] == tiro)
		{
			tiros.erase(tiros.begin() + i);
			delete tiro;
			break;
		}
	}
}

void GerenciadorObjetos::criaCaixa(float x, float y)
{
	caixas.push_back(new Caixa(x, y));
}

Caixa * GerenciadorObjetos::pegaCaixa(float x, float y)
{
	Caixa* caixa = nullptr;

	for (int i = 0; i < caixas.size(); i++)
	{
		Caixa* c = caixas[i];
		if (uniTestarColisaoPontoComSprite(x, y, c->getSprite(), c->getX(), c->getY(), 0.0f))
		{
			caixa = c;
			break;
		}
	}

	return caixa;
}

void GerenciadorObjetos::testarTiro(Tiro * tiro)
{
	float tamX = tiro->getSprite().getLargura() / 2;
	float tamY = tiro->getSprite().getAltura() / 2;
	if ((tiro->getX() < tamX || tiro->getX() > (gJanela.getLargura() - tamX)) ||
		(tiro->getY() < tamY || tiro->getY() > (gJanela.getAltura() - tamY)))
	{
		deletarTiro(tiro);
	}
}