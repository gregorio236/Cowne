#ifndef GUERREIRO_H
#define GUERREIRO_H

#include "Personagem.h"

class Guerreiro : public Personagem
{
public:
	Guerreiro();
	~Guerreiro();

	virtual void rodar();

private:
	Sprite bola;
	bool rolando;
	float tempo;
	Vetor2D direcao;
	Som som;

	virtual void poder();
	virtual void inputs();
	virtual void animar();
	virtual void desenhar();

	void rolar();
};

#endif