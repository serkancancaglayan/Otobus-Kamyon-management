#pragma once
#include <iostream>
#include <list>
#include "Surucu.h"
#include "Yolcu.h"
#include "Yuk.h"
using namespace std;

class Arac
{
public:
	Arac();
	friend ostream& operator<<(ostream& out, const Arac& other)
	{
		return other.doprint(out);
	}
	virtual ostream& doprint(ostream& out) const = 0;
	virtual ~Arac() = 0;

	void setter_Plaka(char* Plaka);
	void setter_Suruculer(const list<Surucu>& Suruculer);

	char* getter_Plaka() const;
	list<Surucu> getter_Suruculer() const;

private:
	char* Plaka;
	list<Surucu> Suruculer;
};