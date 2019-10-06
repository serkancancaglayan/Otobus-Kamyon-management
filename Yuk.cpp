#include "Yuk.h"
Yuk::Yuk()
{
	Icerik = nullptr;
	Agirlik = 0;
	Hacim = 0;
	InisNoktasi = "";
	BinisNoktasi = "";
	Alici = "";
}
Yuk::~Yuk()
{
	if (Icerik != nullptr)
		delete[] Icerik;
}

Yuk::Yuk(const Yuk& other)
{
	setter_Icerik(other.Icerik);
	setter_Agirlik(other.Agirlik);
	setter_Hacim(other.Hacim);
	setter_Alici(other.Alici);
	setter_BinisNoktasi(other.BinisNoktasi);
	setter_InisNoktasi(other.InisNoktasi);
}

Yuk::Yuk(char* Icerik, double Agirlik, double Hacim, string Alici, string BinisNoktasi, string InisNoktasi)
{
	setter_Icerik(Icerik);
	setter_Agirlik(Agirlik);
	setter_Hacim(Hacim);
	setter_Alici(Alici);
	setter_BinisNoktasi(BinisNoktasi);
	setter_InisNoktasi(InisNoktasi);
}

const Yuk& Yuk::operator=(const Yuk& other)
{
	setter_Icerik(other.Icerik);
	setter_Agirlik(other.Agirlik);
	setter_Hacim(other.Hacim);
	setter_Alici(other.Alici);
	setter_BinisNoktasi(other.BinisNoktasi);
	setter_InisNoktasi(other.InisNoktasi);
	return *this;
}

void Yuk::setter_Icerik(char* Icerik)
{
	if (this->Icerik != nullptr)
		delete[] this->Icerik;
	try
	{
		this->Icerik = new char[strlen(Icerik) + 1];
	}
	catch (bad_alloc & bad)
	{
		cerr << bad.what();
		exit(EXIT_FAILURE);
	}
	for (unsigned i = 0; i < strlen(Icerik); i++)
	{
		this->Icerik[i] = Icerik[i];
	}
	this->Icerik[strlen(Icerik)] = '\0';
}

void Yuk::setter_Agirlik(double Agirlik)
{
	this->Agirlik = Agirlik;
}
void Yuk::setter_Hacim(double Hacim)
{
	this->Hacim = Hacim;
}

void Yuk::setter_Alici(string Alici)
{
	this->Alici = Alici;
}

void Yuk::setter_BinisNoktasi(string BinisNoktasi)
{
	this->BinisNoktasi = BinisNoktasi;
}

void Yuk::setter_InisNoktasi(string InisNoktasi)
{
	this->InisNoktasi = InisNoktasi;
}

char* Yuk::getter_Icerik()
{
	return Icerik;
}

double Yuk::getter_Agirlik()
{
	return Agirlik;
}

double Yuk::getter_Hacim()
{
	return Hacim;
}

string Yuk::getter_Alici()
{
	return Alici;
}

string Yuk::getter_BinisNoktasi()
{
	return BinisNoktasi;
}

string Yuk::getter_InisNoktasi()
{
	return InisNoktasi;
}

unsigned Yuk::strlen(char* str)
{	
	unsigned len = 0;
	while (str[++len] != '\0');
	return len;
}

ostream& operator<<(ostream& out, const Yuk& y)
{
	if (y.Icerik != nullptr)
		out << "Icerik: " << y.Icerik << endl;
	out << "Agirlik: " << y.Agirlik << endl;
	out << "Hacim: " << y.Hacim << endl;
	out << "Alici: " << y.Alici << endl;
	out << "BinisNoktasi: " << y.BinisNoktasi << endl;
	out << "InisNoktasi: " << y.InisNoktasi << endl;
	return out;
}