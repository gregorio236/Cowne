#include "Guerreiro.h"

Guerreiro::Guerreiro()
{
	sprite.setSpriteSheet("guerreiro");
	sprite.setEscala(3.0f, 3.0f);

	bola.setSpriteSheet("bola");
	bola.setEscala(3.0f, 3.0f);

	som.setAudio("bola");

	rolando = false;
	tempo = 0.0f;
}

Guerreiro::~Guerreiro()
{

}

void Guerreiro::poder()
{
	rolando = true;
	parado = false;
	trocar = false;
	bola.setFrame(0);
	direcao.x = gMouse.x - x;
	direcao.y = gMouse.y - y;
	direcao = direcao.getNormal();
	bola.setInverterX(direcao.x < 0);
	som.tocar();
}

void Guerreiro::rodar()
{
	Personagem::rodar();
	if (rolando)
	{
		rolar();
		if (tempo < 2.0f)
		{
			tempo += gTempo.getDeltaTempo();

			if (som.terminouDeTocar())
				som.tocar();
		}
		else
		{
			tempo = 0.0f;
			rolando = false;
			parado = true;
			trocar = true;

			som.parar();
		}
	}
}

void Guerreiro::inputs()
{
	if (!rolando)
	{
		if (gMouse.pressionou[BOTAO_MOUSE_ESQ])
		{
			poder();
			return;
		}

		if (gTeclado.segurando[TECLA_D])
		{
			deslocamentoX(vel);
			sprite.setAnimacao(DIREITA);
		}
		else if (gTeclado.segurando[TECLA_A])
		{
			deslocamentoX(-vel);
			sprite.setAnimacao(ESQUERDA);
		}
		else if (gTeclado.segurando[TECLA_W])
		{
			deslocamentoY(-vel);
			sprite.setAnimacao(CIMA);
		}
		else if (gTeclado.segurando[TECLA_S])
		{
			deslocamentoY(vel);
			sprite.setAnimacao(BAIXO);
		}
		else
		{
			parado = true;
			sprite.setFrame(0);
			return;
		}

		parado = false;
	}
}

void Guerreiro::animar()
{
	if (!rolando)
	{
		sprite.avancarAnimacao();
	}
	else
	{
		bola.avancarAnimacao();
	}
}

void Guerreiro::desenhar()
{
	if (!rolando)
	{
		sprite.desenhar(x, y);
	}
	else
	{
		bola.desenhar(x, y);
	}
}

void Guerreiro::rolar()
{
	deslocamentoX(1.7 * vel*direcao.x);
	deslocamentoY(1.7 * vel*direcao.y);
}
