#ifndef SAVE_H
#define SAVE_H

#include "libUnicornio.h"

class Save
{
public:
	Save();
	Save(Vetor2D caixa1, Vetor2D caixa2, Vetor2D caixa3);
	~Save();

	Vetor2D GetCaixa(int i);


private:
	Vetor2D caixas[3];
};

#endif