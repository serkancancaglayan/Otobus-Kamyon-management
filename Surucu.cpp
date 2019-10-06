#include "Surucu.h"
Surucu::Surucu()
{
	Ad = nullptr;
}
Surucu::~Surucu()
{
	if (Ad != nullptr)
		delete[] Ad;
}

Surucu::Surucu(const Surucu& other)
{
	setter_Ad(other.Ad);
	setter_Yas(other.Yas);
	setter_Ehliyet(other.EhliyetType);
}

Surucu::Surucu(char* Ad, unsigned Yas, EhliyetSinifi EhliyetType)
{
	setter_Ad(Ad);
	setter_Yas(Yas);
	setter_Ehliyet(EhliyetType);
}

const Surucu& Surucu::operator=(const Surucu& other)
{
	setter_Ad(other.Ad);
	setter_Yas(other.Yas);
	setter_Ehliyet(other.EhliyetType);
	return *this;
}
void Surucu::setter_Ad(char* Ad)
{
	if (this->Ad != nullptr)
		delete[] this->Ad;
	try
	{
		this->Ad = new char[strlen(Ad)+1];
	}
	catch(bad_alloc &bad)
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

void Surucu::setter_Yas(unsigned Yas)
{
	this->Yas = Yas-30;
}

void Surucu::setter_Ehliyet(EhliyetSinifi EhliyetType)
{
	this->EhliyetType = EhliyetType;
}

char* Surucu::getter_Ad()
{
	return Ad;
}

unsigned Surucu::getter_Yas()
{
	return Yas;
}

EhliyetSinifi Surucu::getter_Ehliyet()
{
	return EhliyetType;
}

unsigned Surucu::strlen(char* str)
{
	unsigned len = 0;
	while (str[++len] != '\0');
	return len;
}

ostream& operator<<(ostream& out, const Surucu& s)
{
	if(s.Ad != nullptr)
		out << "Surucunun Adi :" << s.Ad<< endl;
	out << "Yas:" << s.Yas+30 << endl;
	out << "Ehliyet Tipi: ";
	if (s.EhliyetType == 0)
		cout << "B" << endl;
	else if (s.EhliyetType == 1)
		cout << "C" << endl;
	else if (s.EhliyetType == 2)
		cout << "D" << endl;
	else if (s.EhliyetType == 3)
		cout << "E" << endl;
	return out;
}

