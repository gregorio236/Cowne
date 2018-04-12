#include "Caixa.h"

#include "GerenciadorColisao.h"

Caixa::Caixa(float x, float y)
{
	this->x = x;
	this->y = y;

	sprite.setSpriteSheet("caixa");
	sprite.setEscala(3.0f, 3.0f);
}

Caixa::~Caixa()
{
}

Sprite Caixa::getSprite()
{
	return sprite;
}

float Caixa::getX()
{
	return x;
}

float Caixa::getY()
{
	return y;
}

void Caixa::setPosicao(float x, float y)
{
	deslocamentoX(this->x, x - this->x);
	deslocamentoY(this->y, y - this->y);
}

void Caixa::animar()
{
	sprite.avancarAnimacao();
}

void Caixa::desenhar()
{
	sprite.desenhar(x, y);
}

void Caixa::deslocamentoX(float & x, float vel)
{
	if (!(GerenciadorColisao::testarCComJ(this, x + vel, y)) &&
		!(GerenciadorColisao::testarCComC(this, x + vel, y)))
	{
		x += vel;
		float tam = sprite.getLarguraOriginal() * 3 / 2;
		if (vel < 0)
		{
			if (x < tam)
			{
				x = tam;
			}
		}
		else
		{
			if (x > gJanela.getLargura() - tam)
			{
				x = gJanela.getLargura() - tam;
			}
		}
	}
	else
	{
		vel /= 100;
		for (int i = 0; i < 100; i++)
		{
			if (!(GerenciadorColisao::testarCComJ(this, x + vel, y)) &&
				!(GerenciadorColisao::testarCComC(this, x + vel, y)))
			{
				x += vel;
			}
			else
			{
				break;
			}
		}
	}
}

void Caixa::deslocamentoY(float & y, float vel)
{
	if (!(GerenciadorColisao::testarCComJ(this, x, y + vel)) &&
		!(GerenciadorColisao::testarCComC(this, x, y + vel)))
	{
		y += vel;
		float tam = sprite.getAlturaOriginal() * 3 / 2;
		if (vel < 0)
		{
			if (y < tam)
			{
				y = tam;
			}
		}
		else
		{
			if (y > gJanela.getAltura() - tam)
			{
				y = gJanela.getAltura() - tam;
			}
		}
	}
	else
	{
		vel /= 100;
		for (int i = 0; i < 100; i++)
		{
			if (!(GerenciadorColisao::testarCComJ(this, x, y + vel)) &&
				!(GerenciadorColisao::testarCComC(this, x, y + vel)))
			{
				y += vel;
			}
			else
			{
				break;
			}
		}
	}
}