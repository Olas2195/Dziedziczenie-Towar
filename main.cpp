#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream plik1;
ofstream plik2;

class towar{	
	public:
		string cena, id;
		towar();
		~towar();
		
		void wprowadz();
};

towar::towar() {
	plik1.open("we.txt");
	plik2.open("wy.txt");	
}

void towar::wprowadz() {
	plik1>>id;
	plik1>>cena;
}

towar::~towar() {
	plik1.close();
	plik2.close();
}

class buty:public towar {
	public:
		string rozmiar;
		string kolor;
		string model;
		
		buty(string id, string cena, string rozmiar, string kolor, string model);		
		void wprowadz();
};

void buty::wprowadz() {
	towar::wprowadz();
	plik1>>model;
	plik1>>kolor;
	plik1>>rozmiar;
}

class pasty:public towar {
	public:
		string kolor;
		
		void wprowadz();
		pasty(string id, string cena, string kolor);
};

void pasty::wprowadz() {
	towar::wprowadz();
	plik1>>kolor;
}

class sklep{
	string produkt;
	
	towar t1;
	buty b1;
	pasty p1;
	
	public:
		vector <buty> kolekcjaButow;
		vector <pasty> kolekcjaPast;
		
		void obslugaPliku();
};

void sklep::obslugaPliku() {
	if(plik1.good()) {
		while(!plik1.eof()) {
			plik1>>produkt;
			if(produkt=="buty") {
				b1.wprowadz();
				kolekcjaButow.push_back(buty(b1.id, b1.cena, b1.rozmiar, b1.kolor, b1.model));
			}
			else {
				p1.wprowadz();
				kolekcjaPast.push_back(pasty(p1.id, p1.cena, p1.kolor));
			}
		}
	}
}


int main() {
	sklep s1;
	s1.obslugaPliku();	
	
	return 0;
}

