#include "GerenciadorObjetos.h"

#include "GerenciadorSave.h"
#include "Save.h"

vector<Tiro*> GerenciadorObjetos::tiros;
vector<Caixa*> GerenciadorObjetos::caixas;

vector<Caixa*> GerenciadorObjetos::getCaixas()
{
	return caixas;
}

void GerenciadorObjetos::Inicializar()
{
	Save* save = GerenciadorSave::GetSave();

	GerenciadorObjetos::criaCaixa(save->GetCaixa(0).x, save->GetCaixa(0).y);
	GerenciadorObjetos::criaCaixa(save->GetCaixa(1).x, save->GetCaixa(1).y);
	GerenciadorObjetos::criaCaixa(save->GetCaixa(2).x, save->GetCaixa(2).y);
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

void GerenciadorObjetos::SalvarObjetos(const char * caminho)
{
	Vetor2D pos1(caixas[0]->getX(), caixas[0]->getY());
	Vetor2D pos2(caixas[1]->getX(), caixas[1]->getY());
	Vetor2D pos3(caixas[2]->getX(), caixas[2]->getY());

	Save* save = new Save(pos1, pos2, pos3);

	GerenciadorSave::SalvaInfo(save, caminho);
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