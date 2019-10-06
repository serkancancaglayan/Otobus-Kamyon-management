#include "Yolcu.h"

Yolcu::Yolcu()
{
	Ad = nullptr;
	BinisNoktasi = nullptr;
}


Yolcu::~Yolcu()
{
	if (Ad != nullptr)
		delete[] Ad;
	if (BinisNoktasi != nullptr)
		delete[] BinisNoktasi;
}

Yolcu::Yolcu(const Yolcu& other)
{
	setter_Ad(other.Ad);
	setter_BinisNoktasi(other.BinisNoktasi);
	setter_InisNoktasi(other.InisNoktasi);
}

Yolcu::Yolcu(char* Ad, char* BinisNoktasi, string InisNoktasi)
{
	setter_Ad(Ad);
	setter_BinisNoktasi(BinisNoktasi);
	setter_InisNoktasi(InisNoktasi);
}

const Yolcu& Yolcu::operator=(const Yolcu& other)
{
	setter_Ad(other.Ad);
	setter_BinisNoktasi(other.BinisNoktasi);
	setter_InisNoktasi(other.InisNoktasi);
	return *this;
}

void Yolcu::setter_Ad(char* Ad)
{
	if (this->Ad != nullptr)
		delete[] this->Ad;
	try
	{
		this->Ad = new char[strlen(Ad) + 1];
	}
	catch (bad_alloc & bad)
	{
		cerr << bad.what();
		exit(EXIT_FAILURE);
	}
	for (unsigned i = 0; i < strlen(Ad); i++)
	{
		this->Ad[i] = Ad[i];
	}
	this->Ad[strlen(Ad)] = '\0';
}

void Yolcu::setter_BinisNoktasi(char* BinisNoktasi)
{
	if (this->BinisNoktasi != nullptr)
		delete[] this->BinisNoktasi;
	try
	{
		this->BinisNoktasi = new char[strlen(BinisNoktasi) + 1];
	}
	catch (bad_alloc & bad)
	{
		cerr << bad.what();
		exit(EXIT_FAILURE);
	}
	for (unsigned i = 0; i < strlen(BinisNoktasi); i++)
	{
		this->BinisNoktasi[i] = BinisNoktasi[i];
	}
	this->BinisNoktasi[strlen(BinisNoktasi)] = '\0';
}

void Yolcu::setter_InisNoktasi(string InisNoktasi)
{
	this->InisNoktasi = InisNoktasi;
}

char* Yolcu::getter_Ad()
{
	return Ad;
}

char* Yolcu::getter_BinisNoktasi()
{
	return BinisNoktasi;
}

string Yolcu::getter_InisNoktasi()
{
	return InisNoktasi;
}

unsigned Yolcu::strlen(char* str)
{
	unsigned len = 0;
	while (str[++len] != '\0');
	return len;
}

ostream& operator<<(ostream& out, const Yolcu& y)
{
	if (y.Ad != nullptr)
		cout << "Yolcu Adi: " << y.Ad<<endl;
	if (y.BinisNoktasi != nullptr)
		cout << "Binis Noktasi: " << y.BinisNoktasi<<endl;
	cout << "Inis Noktasi: " << y.InisNoktasi<<endl;
	return out;
}