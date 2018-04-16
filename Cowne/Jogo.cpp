#include "Jogo.h"

#include "GerenciadorObjetos.h"
#include "GerenciadorColisao.h"
#include "GerenciadorSave.h"
#include "Particula.h"
#include "Save.h"

Personagem* Jogo::jogador;

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
	delete curandeiro;
	delete guerreiro;
	delete necromante;
}

Personagem * Jogo::getJogador()
{
	return jogador;
}

void Jogo::inicializar()
{
	uniInicializar(800, 600, false);

	gJanela.setCorDeFundo(75, 75, 75);

	gRecursos.carregarSpriteSheet("curandeiro", "../Assets/curandeiroSheet.png", 4, 4);
	gRecursos.carregarSpriteSheet("tiro", "../Assets/tiroSheet.png", 1, 32);
	gRecursos.carregarSpriteSheet("guerreiro", "../Assets/guerreiroSheet.png", 4, 4);
	gRecursos.carregarSpriteSheet("bola", "../Assets/bolaSheet.png", 1, 4);
	gRecursos.carregarSpriteSheet("necromante", "../Assets/necromanteSheet.png", 4, 4);
	gRecursos.carregarSpriteSheet("caixa", "../Assets/caixaSheet.png", 1, 1);
	gRecursos.carregarSpriteSheet("particula", "../Assets/particulaSheet.png", 1, 19);

	gRecursos.carregarAudio("tiro", "../Assets/tiro.wav");
	gRecursos.carregarAudio("bola", "../Assets/bola.wav");
	gRecursos.carregarAudio("levitar", "../Assets/levitar.mp3");
	gRecursos.carregarAudio("fundo", "../Assets/fundo.mp3");

	GerenciadorSave::CarregaInfo("../Saves/save.dat");

	curandeiro = new Curandeiro();
	guerreiro = new Guerreiro();
	necromante = new Necromante();

	jogador = curandeiro;
	jogador->setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	GerenciadorObjetos::Inicializar();

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
	GerenciadorObjetos::SalvarObjetos("../Saves/save.dat");
}

