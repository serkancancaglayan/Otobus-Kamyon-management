//Serkan Can Caglayan 18120205021
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <locale>
#include "Arac.h"
#include "Otobus.h"
#include "Kamyon.h"
#include "rapidxml.hpp"
#include <string>
using namespace std;
using namespace rapidxml;
unsigned int dosyadanOku(const string& filename, list<Arac*> &araclar);

//bu fonksiyon char pointerini Ehliyet tipine cevirir ve dondurur
EhliyetSinifi cptoEhliyet(char* str);

int main()
{
	list <Arac*> t;
	int i = dosyadanOku("bil122_hw08.xml", t);
	int x = 0;
	for (const Arac* V : t)
	{
		cout << "#######################################################################"<<endl;
		cout << *V;
		cout << "#######################################################################"<<endl;
	}
	cout << "Toplam okunan arac sayisi = " << i<<endl;
	return 0;
}
unsigned int dosyadanOku(const string& filename, list<Arac*> &araclar)
{
	setlocale(LC_ALL, "tr_TR.utf8"); // Turkish locale settings

	xml_document<> doc;
	xml_node<>* root_node;

	// Read the xml file into a vector
	ifstream theFile(filename);

	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');

	// Parse the buffer using the xml file parsing library into doc 
	doc.parse<0>(&buffer[0]);

	// Set the root node
	root_node = doc.first_node("Araclar");

	// Iterate over the Vehicles
	cout << "Parsing Vehicles.xml..." << endl;

	//kac arac okundugunu tutacak degisken
	int i = 0;
	for (auto* vehicle_node = root_node->first_node("Arac"); vehicle_node; vehicle_node = vehicle_node->next_sibling())
	{
		++i;
		//iclerine veri okunacak liste ve vektorler
		list <Surucu> templist;
		vector <Yolcu> temp_passenger;
		vector <Yuk> temp_yuk;
	
		//liste ve vektorler bir sonraki aracin verilerini tutmak icin bosaltildi
		templist.clear();
		temp_passenger.clear();
		temp_yuk.clear();

		char* temp_plaka = vehicle_node->first_node("Plaka")->value();

		auto* drivers_root_node = vehicle_node->first_node("Suruculer");
		for (auto* driver_node = drivers_root_node->first_node("Surucu"); driver_node; driver_node = driver_node->next_sibling())
		{
			char* Ad = driver_node->first_node("Adi")->value();
			unsigned int Yas = atoi(driver_node->first_node("Yasi")->value());
			EhliyetSinifi Ehliyet = cptoEhliyet(driver_node->first_node("EhliyetSinifi")->value());
			Surucu temp(Ad, Yas, Ehliyet);
			templist.push_back(temp);
		}
		//Aracin turu otobus ise yolcular okundu
		if (!strcmp(vehicle_node->first_node("Turu")->value(), "Otobus"))
		{
			auto* passenger_root_node = vehicle_node->first_node("Yolcular");
			for (auto* passenger_node = passenger_root_node->first_node("Yolcu"); passenger_node; passenger_node = passenger_node->next_sibling())
			{
				char* Ad = passenger_node->first_node("Adi")->value();
				char* BinisNoktasi = passenger_node->first_node("BinisNoktasi")->value();
				string InisNoktasi = passenger_node->first_node("InisNoktasi")->value();
				Yolcu temp(Ad, BinisNoktasi, InisNoktasi);
				temp_passenger.push_back(temp);
			}
			Arac* temp_arac = new Otobus(temp_plaka, templist, temp_passenger);
			araclar.push_back(temp_arac);
		}
		//Aracin turu kamyon ise yuk okundu
		if (!strcmp(vehicle_node->first_node("Turu")->value(), "Kamyon"))
		{
			char* OzluSoz = vehicle_node->first_node("OzluSoz")->value();
			auto* yuk_root_node = vehicle_node->first_node("Yukler");
			for (auto* yuk_node = yuk_root_node->first_node("Yuk"); yuk_node; yuk_node = yuk_node->next_sibling())
			{
				char* Icerik = yuk_node->first_node("Icerik")->value();
				double Agirlik = atof(yuk_node->first_node("Agirlik")->value());
				double Hacim = atof(yuk_node->first_node("Hacim")->value());
				string Alici = yuk_node->first_node("Alici")->value();
				string BinisNoktasi = yuk_node->first_node("BinisNoktasi")->value();
				string InisNoktasi = yuk_node->first_node("InisNoktasi")->value();
				Yuk temp(Icerik, Agirlik, Hacim, Alici, BinisNoktasi, InisNoktasi);
				temp_yuk.push_back(temp);
			}
			Arac* temp_arac = new Kamyon(temp_plaka, templist, temp_yuk,OzluSoz);
			araclar.push_back(temp_arac);
		}
	}
	return i;
}
EhliyetSinifi cptoEhliyet(char* str)
{
	if (str[0] == 'B')
		return B;
	if (str[0] == 'C')
		return C;
	if (str[0] == 'D')
		return D;
	if (str[0] == 'E')
		return E;
}
