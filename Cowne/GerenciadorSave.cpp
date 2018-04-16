#include "GerenciadorSave.h"

#include <fstream>
using namespace std;

Save* GerenciadorSave::save;

void GerenciadorSave::SalvaInfo(Save * save, const char * caminho)
{
	fstream arq;
	arq.open(caminho, ios::binary | ios::out);

	arq.write((char*)save, sizeof(Save));

	arq.close();
}

Save * GerenciadorSave::CarregaInfo(const char * caminho)
{
	fstream arq;
	arq.open(caminho, ios::binary | ios::in);

	Save* save = new Save();

	arq.read((char*)save, sizeof(Save));

	arq.close();

	GerenciadorSave::save = save;

	return save;
}

Save * GerenciadorSave::GetSave()
{
	return GerenciadorSave::save;
}
