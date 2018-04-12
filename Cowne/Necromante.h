#ifndef NECROMANTE_H
#define NECROMANTE_H

#include "Personagem.h"
#include "Caixa.h"

class Necromante : public Personagem
{
public:
	Necromante();
	~Necromante();

protected:
	virtual void poder();
	virtual void inputs();

private:
	Caixa * caixa;
	Som som;

	void pegar();
	void levitar();
	void soltar();
};
#endif