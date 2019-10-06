#pragma once
#include "Arac.h"
#include <vector>
using namespace std;
class Kamyon : public Arac
{
public:
	ostream& doprint(ostream&) const;
	~Kamyon();
	Kamyon();
	Kamyon(const Kamyon& other);
	Kamyon(char* Plaka, const list<Surucu>& Suruculer, const vector<Yuk>& Yukler, char* OzluSoz);
	const Kamyon& operator=(const Kamyon& other);
	void setter_OzluSoz(char* OzluSoz);
	void setter_Yukler(const vector<Yuk>& Yukler);
	vector<Yuk> getter_Yukler() const;
	char* getter_OzluSoz() const;

private:
	char* OzluSoz = nullptr;
	vector<Yuk> Yukler;
};

