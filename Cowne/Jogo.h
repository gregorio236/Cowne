#ifndef JOGO_H
#define JOGO_H

#include <vector>
using namespace std;

#include "libUnicornio.h"

#include "Personagem.h"
#include "Curandeiro.h"
#include "Guerreiro.h"
#include "Necromante.h"

class Jogo
{
public:
	Jogo();
	~Jogo();

	static Personagem* getJogador();

	void inicializar();
	void finalizar();

	void executar();

private:
	static Personagem * jogador;
	Curandeiro* curandeiro;
	Guerreiro* guerreiro;
	Necromante* necromante;

	Som musica;
};

#endif