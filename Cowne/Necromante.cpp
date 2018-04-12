#include "Necromante.h"

#include "GerenciadorObjetos.h"
#include "Particula.h"

Necromante::Necromante()
{
	sprite.setSpriteSheet("necromante");
	sprite.setEscala(3.0f, 3.0f);

	som.setAudio("levitar");
}

Necromante::~Necromante()
{

}

void Necromante::poder()
{
	pegar();
}

void Necromante::inputs()
{
	if (gMouse.pressionou[BOTAO_MOUSE_ESQ])
	{
		poder();
	}
	else if (gMouse.segurando[BOTAO_MOUSE_ESQ])
	{
		levitar();
	}
	else if (gMouse.soltou[BOTAO_MOUSE_ESQ])
	{
		soltar();
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

void Necromante::pegar()
{
	caixa = GerenciadorObjetos::pegaCaixa(gMouse.x, gMouse.y);
	if (caixa != nullptr)
	{
		trocar = false;
		som.tocar();
	}
}

void Necromante::levitar()
{
	if (caixa != nullptr)
	{
		caixa->setPosicao(gMouse.x, gMouse.y);

		Particula::cria(5, caixa->getX(), caixa->getY(), 60.0f, uniRandEntre(0.5f, 1.5f));

		if (som.terminouDeTocar())
			som.tocar();
	}
}

void Necromante::soltar()
{
	if (caixa != nullptr)
	{
		caixa = nullptr;
		trocar = true;
		som.parar();
	}
}
