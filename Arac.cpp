#include "Arac.h"
Arac::Arac()
{
	Plaka = nullptr;
}
Arac::~Arac()
{
	if (Plaka != nullptr)
		delete[] Plaka;
}
void Arac::setter_Plaka(char* Plaka)
{
	if (this->Plaka != nullptr)
		delete[] this->Plaka;
	try
	{
		this->Plaka = new char[strlen(Plaka)+1];
	}
	catch (bad_alloc & bad)
	{
		cerr << bad.what() << '\n';
		exit(EXIT_FAILURE);
	}
	for (unsigned i = 0; i < strlen(Plaka); i++)
		this->Plaka[i] = Plaka[i];
	this->Plaka[strlen(Plaka)] = '\0';
}
void Arac::setter_Suruculer(const list<Surucu> & Suruculer) { this->Suruculer = Suruculer; }
char* Arac::getter_Plaka() const { return Plaka; }
list<Surucu> Arac::getter_Suruculer() const { return Suruculer; }