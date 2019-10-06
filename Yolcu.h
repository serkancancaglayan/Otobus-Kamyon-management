#pragma once
#include <iostream>
#include <string>
using namespace std;
class Yolcu
{
	friend ostream& operator<<(ostream& out, const Yolcu& y);
public:
	Yolcu();
	~Yolcu();
	Yolcu(const Yolcu& other);
	Yolcu(char* Ad, char* BinisNoktasi, string InisNoktasi);
	const Yolcu& operator=(const Yolcu& other);
	void setter_Ad(char* Ad);
	void setter_BinisNoktasi(char* BinisNoktasi);
	void setter_InisNoktasi(string InisNoktasi);
	char* getter_Ad();
	char* getter_BinisNoktasi();
	string getter_InisNoktasi();
private:
	char* Ad = nullptr;
	char* BinisNoktasi = nullptr;
	string InisNoktasi;
	unsigned strlen(char * str);
};

