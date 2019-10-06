#pragma once
#include <iostream>
using namespace std;
typedef enum
{
	B,
	C,
	D,
	E
} EhliyetSinifi;
class Surucu
{
	friend ostream& operator<<(ostream& out, const Surucu& l);
public:
	Surucu();
	~Surucu();
	Surucu(const Surucu& other);
	Surucu(char* Ad,unsigned Yas,EhliyetSinifi EhliyetType);
	const Surucu& operator=(const Surucu& other);
	void setter_Ad(char* Ad);
	void setter_Yas(unsigned Yas);
	void setter_Ehliyet(EhliyetSinifi Ehliyet);
	char* getter_Ad();
	unsigned getter_Yas();
	EhliyetSinifi getter_Ehliyet();
private:
	char* Ad = nullptr;
	EhliyetSinifi EhliyetType;
	unsigned int Yas : 5;
	unsigned strlen(char *str);
};

