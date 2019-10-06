#pragma once
#include "Arac.h"
#include <vector>
using namespace std;
class Otobus : public Arac
{
public:
	ostream& doprint(ostream&) const;
	~Otobus();
	Otobus();
	Otobus(const Otobus& other);
	Otobus(char* Plaka, const list<Surucu>& Suruculer, const vector<Yolcu>& Yolcular);
	const Otobus& operator=(const Otobus& other);
	void setter_Yolcular(vector<Yolcu> Yolcular);
	vector<Yolcu> getter_Yolcular() const;

private:
	vector<Yolcu> Yolcular;
};