#pragma once
#include <iostream>
#include <string>
using namespace std;
class Yuk
{
	friend ostream& operator<<(ostream& out, const Yuk& y);
public:
	Yuk();
	~Yuk();
	Yuk(const Yuk& other);
	Yuk(char* Icerik, double Agirlik, double Hacim, 
		string Alici, string BinisNoktasi, string InisNoktasi);
	const Yuk& operator=(const Yuk& other);
	void setter_Icerik(char* Icerik);
	void setter_Agirlik(double Agirlik);
	void setter_Hacim(double Hacim);
	void setter_Alici(string Alici);
	void setter_BinisNoktasi(string BinisNoktasi);
	void setter_InisNoktasi(string InisNoktasi);
	char* getter_Icerik();
	double getter_Agirlik();
	double getter_Hacim();
	string getter_Alici();
	string getter_BinisNoktasi();
	string getter_InisNoktasi();
private:
	char* Icerik = nullptr;
	double Agirlik;
	double Hacim;
	string Alici;
	string BinisNoktasi;
	string InisNoktasi;
	unsigned strlen(char* str);
};


