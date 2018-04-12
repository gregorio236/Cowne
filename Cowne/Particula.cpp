#include "Particula.h"

vector<Particula*> Particula::particulas;

Particula::Particula(float x, float y, float tempo)
{
	this->x = x;
	this->y = y;
	this->tempo = tempo;
	this->duracao = tempo;

	sprite.setSpriteSheet("particula");
	sprite.setEscala(1.0f, 1.0f);
	sprite.setVelocidadeAnimacao(10.0f);
}

Particula::~Particula()
{

}

void Particula::cria(int qtd, float x, float y, float raio, float tempo)
{
	for (int i = 0; i < qtd; i++)
	{
		Vetor2D v;
		v.x = 1.0f;
		v.y = 0.0f;
		v.rotacionar(uniRandEntre(0.0f, 360.0f));
		particulas.push_back(new Particula(x + raio * v.x, y + raio * v.y, tempo));
	}
}

void Particula::rodar()
{
	deletarParticulas();

	for (int i = 0; i < particulas.size(); i++)
	{
		Particula* p = particulas[i];
		if (p->tempo > 0.0f)
		{
			p->sprite.avancarAnimacao();
			p->sprite.desenhar(p->x, p->y);
			p->tempo -= gTempo.getDeltaTempo();
			float escala = p->tempo / p->duracao;
			p->sprite.setEscala(escala, escala);
		}
	}
}

void Particula::deletarParticulas()
{
	for (int i = 0; i < particulas.size(); i++)
	{
		Particula* p = particulas[i];
		if (p->tempo <= 0.0f)
		{
			particulas.erase(particulas.begin() + i);
			delete p;
			i = 0;
		}
	}
}
