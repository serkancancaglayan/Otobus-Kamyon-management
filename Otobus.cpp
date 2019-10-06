#include "Otobus.h"
ostream& Otobus::doprint(ostream& out) const
{
	out << "Otobusun Plakasi: " << getter_Plaka() << endl;
	out << endl
		<< "Suruculer: " << endl;
	for (Surucu const& v : getter_Suruculer())
	{
		out << v << endl;
	}
	out << endl
		<< "Yolcular: " << endl;
	for (unsigned i = 0; i < Yolcular.size(); i++)
	{
		out << Yolcular[i] << endl;
	}
	return out;
}
Otobus::Otobus(char* Plaka, const list<Surucu>& Suruculer, const vector<Yolcu>& Yolcular)
{
	setter_Plaka(Plaka);
	setter_Suruculer(Suruculer);
	this->Yolcular = Yolcular;
}
Otobus::Otobus() {}
Otobus::Otobus(const Otobus& other)
{
	setter_Plaka(other.getter_Plaka());
	setter_Suruculer(other.getter_Suruculer());
	this->Yolcular = other.Yolcular;
}
Otobus::~Otobus()
{
	this->Arac::~Arac();
}
const Otobus& Otobus::operator=(const Otobus& other)
{
	setter_Plaka(other.getter_Plaka());
	setter_Suruculer(other.getter_Suruculer());
	Yolcular = other.Yolcular;
	return *this;
}
void Otobus::setter_Yolcular(vector<Yolcu> Yolcular)
{
	this->Yolcular = Yolcular;
}
vector<Yolcu> Otobus::getter_Yolcular() const
{
	return Yolcular;
}

