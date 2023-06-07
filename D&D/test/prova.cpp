/* Marcuzzi Giuseppe
	Sessione di D&D
   24/03/2020

*/

#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include<cmath>
#include <ctime>

#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")

using namespace std;


#define inizio "inizio"
#define menu "menu"
#define sceltaSbaglaita "sceltaSbaglaita"
#define seiSicuro "seiSicuro"
#define premiUnTasto "premiUnTasto"
#define ringraziamenti "ringraziamenti"


#define zona






void stampaAVideoIlTesto(string, int, string sezione);

// variabili globali
bool godMod = false; // per attivare la godMod vado in regoleDelCombattimento e premo g (in minuscolo)
char fermaCout;

// IN FASE DI TEST
// ABILITARE LA VISIONE DI FILE E VARTELLA NASCOSTE




int main(int argc, char* argv[]) {
	srand(time(NULL));
	
	time_t t = time(NULL);
	tm* tPtr = localtime(&t);
	
	/*
	cout << "\n\n Display the Current Date and Time :\n";
	cout << "----------------------------------------\n";
	cout << " seconds = " << (tPtr->tm_sec) << endl;
	cout << " minutes = " << (tPtr->tm_min) << endl;
	cout << " hours = " << (tPtr->tm_hour) << endl;
	cout << " day of month = " << (tPtr->tm_mday) << endl;
	cout << " month of year = " << (tPtr->tm_mon)+1 << endl;
	cout << " year = " << (tPtr->tm_year)+1900 << endl;
	cout << " weekday = " << (tPtr->tm_wday )<< endl;
	cout << " day of year = " << (tPtr->tm_yday )<< endl;
	cout << " daylight savings = " <<(tPtr->tm_isdst )<< endl;
    cout << endl;
    cout << endl;

    cout << " Current Date: " <<(tPtr->tm_mday)<<"/"<< (tPtr->tm_mon)+1 <<"/"<< (tPtr->tm_year)+1900<< endl; // giorno
    cout << " Current Time: " << (tPtr->tm_hour)<<":"<< (tPtr->tm_min)<<":"<< (tPtr->tm_sec) << endl; // ora
	*/

    
    string dwnld_URL = "https://pastebin.com/raw/vnuAVgMk";
    string savepath = "C:\\zzzz\\Lingue\\Italiano\\combattimento.txt";
    (URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL) == S_OK);
    

    //stampaAVideoIlTesto(menu, 1, "Inizio_E_FrasiRipetute");



	return 0;
}


void stampaAVideoIlTesto(string paragrafo, int lingua, string sezione){
	
	// paragrafo variabile che verrà utilizzata per identificare il paragrafo da stampare

    string percorsoLingua = "C:\\zzzz\\Lingue";

    switch (lingua) {
    case 1:
        // italiano
        percorsoLingua = percorsoLingua + "\\Italiano";
        break;
    
    case 2:
        // english
        percorsoLingua = percorsoLingua + "\\English";
        break;

    default:
        break;
    }

    percorsoLingua = percorsoLingua + "\\" + sezione + ".txt";

	ifstream fin;
    fin.open(percorsoLingua);
    string nome="bho"; 
    do {
        getline(fin, nome, '\n');
        if (nome==("<" + paragrafo + ">")) {
            do {
                getline(fin, nome, '\n');
                if (nome!=("<" + paragrafo + ">") && nome!=("</" + paragrafo + ">")){
                    cout << nome << endl;
                }
            } while (nome!=("</" + paragrafo + ">"));
        }
    } while (nome!=("</" + paragrafo + ">"));
    fin.close();

	return ;
}