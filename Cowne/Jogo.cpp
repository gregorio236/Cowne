#include "Jogo.h"

#include "GerenciadorObjetos.h"
#include "GerenciadorColisao.h"
#include "Particula.h"

Personagem* Jogo::jogador;

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

Personagem * Jogo::getJogador()
{
	return jogador;
}

void Jogo::inicializar()
{
	uniInicializar(800, 600, false);

	gJanela.setCorDeFundo(75, 75, 75);

	gRecursos.carregarSpriteSheet("curandeiro", "../assets/curandeiroSheet.png", 4, 4);
	gRecursos.carregarSpriteSheet("tiro", "../assets/tiroSheet.png", 1, 32);
	gRecursos.carregarSpriteSheet("guerreiro", "../assets/guerreiroSheet.png", 4, 4);
	gRecursos.carregarSpriteSheet("bola", "../assets/bolaSheet.png", 1, 4);
	gRecursos.carregarSpriteSheet("necromante", "../assets/necromanteSheet.png", 4, 4);
	gRecursos.carregarSpriteSheet("caixa", "../assets/caixaSheet.png", 1, 1);
	gRecursos.carregarSpriteSheet("particula", "../assets/particulaSheet.png", 1, 19);

	gRecursos.carregarAudio("tiro", "../assets/tiro.wav");
	gRecursos.carregarAudio("bola", "../assets/bola.wav");
	gRecursos.carregarAudio("levitar", "../assets/levitar.mp3");
	gRecursos.carregarAudio("fundo", "../assets/fundo.mp3");

	curandeiro = new Curandeiro();
	guerreiro = new Guerreiro();
	necromante = new Necromante();

	jogador = curandeiro;
	jogador->setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	GerenciadorObjetos::criaCaixa(100.0f, 100.0f);
	GerenciadorObjetos::criaCaixa(200.0f, 200.0f);
	GerenciadorObjetos::criaCaixa(250.0f, 200.0f);
	GerenciadorObjetos::criaCaixa(300.0f, 200.0f);
	GerenciadorObjetos::criaCaixa(400.0f, 200.0f);
	GerenciadorObjetos::criaCaixa(500.0f, 200.0f);

	musica.setAudio("fundo");
	musica.setVolume(50.0f);
	musica.tocar();

	gAudios.setVolumeGlobal(17.0f);
}

void Jogo::finalizar()
{
	gRecursos.descarregarTudo();
	uniFinalizar();
}

void Jogo::executar()
{
	while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

		if (jogador->podeTrocar())
		{
			if (gTeclado.pressionou[TECLA_1])
			{
				curandeiro->setAnimacao(jogador->getAnimacao());
				jogador = curandeiro;
			}
			else if (gTeclado.pressionou[TECLA_2])
			{
				guerreiro->setAnimacao(jogador->getAnimacao());
				jogador = guerreiro;
			}
			else if (gTeclado.pressionou[TECLA_3])
			{
				necromante->setAnimacao(jogador->getAnimacao());
				jogador = necromante;
			}
		}

		Particula::rodar();

		GerenciadorObjetos::rodar();

		jogador->rodar();

		if (musica.terminouDeTocar())
			musica.tocar();

		uniTerminarFrame();
	}
}

