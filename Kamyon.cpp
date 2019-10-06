#include "Kamyon.h"
ostream& Kamyon::doprint(ostream& out) const
{
	out << "Kamyon Plakasi: " << getter_Plaka() << endl;
	out << endl
		<< "Suruculer: " << endl;
	for (Surucu const& v : getter_Suruculer())
	{
		out << v << endl;
	}
	out << "Ozlu Soz: " << OzluSoz << endl;
	out << endl << "Yukler: " << endl;
	for (unsigned i = 0; i < Yukler.size(); i++)
	{
		out << Yukler[i] << endl;
	}
	return out;
}
Kamyon::~Kamyon()
{
	this->Arac::~Arac();
	if (OzluSoz != nullptr)
		delete[] OzluSoz;
}
Kamyon::Kamyon()
{
	OzluSoz = nullptr;
}
Kamyon::Kamyon(const Kamyon & other)
{
	setter_OzluSoz(other.OzluSoz);
	Yukler = other.Yukler;
	setter_Plaka(other.getter_Plaka());
	setter_Suruculer(other.getter_Suruculer());
}
Kamyon::Kamyon(char* Plaka, const list<Surucu> & Suruculer, const vector<Yuk> & Yukler, char* OzluSoz)
{
	setter_Plaka(Plaka);
	setter_Suruculer(Suruculer);
	setter_OzluSoz(OzluSoz);
	setter_Yukler(Yukler);
}
void Kamyon::setter_OzluSoz(char* OzluSoz)
{
	try
	{
		this->OzluSoz = new char[strlen(OzluSoz)+1];
	}
	catch (bad_alloc & bad)
	{
		cerr << bad.what() << '\n';
		exit(EXIT_FAILURE);
	}
	for (unsigned i = 0; i < strlen(OzluSoz); i++)
		this->OzluSoz[i] = OzluSoz[i];
	this->OzluSoz[strlen(OzluSoz)] = '\0';
}
void Kamyon::setter_Yukler(const vector<Yuk> & Yukler)
{
	this->Yukler = Yukler;
}
vector<Yuk> Kamyon::getter_Yukler() const
{
	return Yukler;
}
char* Kamyon::getter_OzluSoz() const
{
	return OzluSoz;
}
