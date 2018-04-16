#ifndef GERENCIADOR_SAVE_H
#define GERENCIADOR_SAVE_H

#include "Save.h"

static class GerenciadorSave
{
public:
	static void SalvaInfo(Save* save, const char* caminho);
	static Save* CarregaInfo(const char* caminho);

	static Save* GetSave();

private:
	static Save* save;
};

#endif