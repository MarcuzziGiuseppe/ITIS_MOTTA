/* Marcuzzi Giuseppe
	Base
  15/05/2020
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

using namespace std;

// paragrafi inerenti solo all'inizio e per i vari switch-case
#define inizio "inizio"
#define menu "menu"
#define sceltaSbaglaita "sceltaSbaglaita"
#define seiSicuro "seiSicuro"

// paragrafi inerenti soltanto la creazione del PG
#define creazionePg1 "creazionePg1"
#define creazionePg2 "creazionePg2"
#define creazionePg3 "creazionePg3"
#define creazionePg4 "creazionePg4"
#define creazionePg5 "creazionePg5"
#define creazionePg6 "creazionePg6"
#define creazionePg7 "creazionePg7"

// paragrafi inerenti le regole
#define regoleGioco1 "regoleGioco1"
#define regolePg1 "regolePg1"
#define regolePg2 "regolePg2"
#define regolePg3 "regolePg3"
#define regolePg4 "regolePg4"
#define regolePg5 "regolePg5"

// paragrafi inerenti il combattimento
#define regoleCombattimento1 "regoleCombattimento1"

// gestione dei file
void stampaAVideoIlTesto(string paragrafo);
string controlloDelleCartelle();
void creazioneDelleCartelle();
int lanciaDado(int);


class personaggio {
private:
    string nome;
    string classe;
    string razza;
    int statistiche[6];

public:
    void assegnaNome();
    void assegnaClasse();
 
};

personaggio::assegnaNome() {

    char fermaCout;
	// creazione nome
	string nomePG;
	char sicurezzaNellaDecisioneDelNomeDelPG = 1;
	do {
		stampaAVideoIlTesto(creazionePg1);
		cin >> nomePG;
		stampaAVideoIlTesto(creazionePg2);
		cout << nomePG;
		stampaAVideoIlTesto(creazionePg3);
		sicurezzaNellaDecisioneDelNomeDelPG = _getch();
		cout << endl;
	} while (sicurezzaNellaDecisioneDelNomeDelPG != '1');

    return ;
}

personaggio::assegnaClasse() {
    // scelta della classe
	bool haiSceltoUnaClasseORazzaNonValida;
	string classi[8] = {
		"Barbaro",
		"Guerriero",
		"Monaco",
		"Paladino",
		"Ranger",
		"Ladro",
		"Stregone",
		"Mago" };
	string classe = "classe";
	string classeScelta;
	char classeCheSceglie;
	char sicurezzaSceltaClasse = 0;
	
	
	do {
		do {
			haiSceltoUnaClasseORazzaNonValida = false;
			stampaAVideoIlTesto(creazionePg4);
			classeCheSceglie = _getch(); // scelta 
			if (classeCheSceglie == 'r') {
				cout << endl;
				regoleDelPG(); // funzione che stampa e basta
			}
			cout << endl;
		} while (classeCheSceglie == 'r');

		if (classeCheSceglie >= '1' && classeCheSceglie <= '8') {
			classeScelta = classi[classeCheSceglie - 49];
		}
		else {
			system("CLS");
			haiSceltoUnaClasseORazzaNonValida = true;
			stampaAVideoIlTesto(sceltaSbaglaita);
		}

		if (haiSceltoUnaClasseORazzaNonValida == false) {
			stampaAVideoIlTesto(creazionePg5);
			cout << classeScelta << endl;
			stampaAVideoIlTesto(seiSicuro);
			sicurezzaSceltaClasse = _getch();
			cout << endl;
		}
	} while (sicurezzaSceltaClasse != '1');

    return ;
}
















int main (int arcg, char *argv[]){

    srand(time(NULL));
    char fermaCout;
	
	time_t t = time(NULL);
	tm* tPtr = localtime(&t);

// controllo se la cartella che conterrÃ  i finali esiste altrimenti la creo
	string attributi;
	string cartellaBase;
	cartellaBase=controlloDelleCartelle();


	int esciDalProgramma = 1;
	char doveLUtenteVuoleAndarePartendoDalPrimoMenu = '1';
	godMod = false;

	do {
		system("CLS");
		stampaAVideoIlTesto(inizio);
		fermaCout = _getch();
		cout << endl;
		stampaAVideoIlTesto(menu);
		doveLUtenteVuoleAndarePartendoDalPrimoMenu = _getch();
		std::cout << endl;
		
		string nomePg;
		

		switch (doveLUtenteVuoleAndarePartendoDalPrimoMenu) {
		case '1':
			nomePg = creazionePG();
			finale=inizioStoria();
			godMod=false;
			break;

		case '2':
			regoleDelGioco();
			break;

		case '3':
			{
				int quanteVolteLanciareIlDado = 1;
				do {
					cout << "How many times do you wanto to roll the dice?" << endl;
					std::cin >> quanteVolteLanciareIlDado;
				} while (quanteVolteLanciareIlDado <= 0);
				int facce;
				do {
					cout << "how many faces must the die have?" << endl;
					std::cin >> facce;
					cout << endl;
				} while (facce <= 0);
				for (int i = 0; i < quanteVolteLanciareIlDado; i++) {
					std::cout << lanciaDado(facce) << " ";
				}
				cout << endl << "Press any key to continue" << endl;
				fermaCout = _getch();
			}
		break;

		case '4':
			system("CLS");
			cout << "Ancora da fare" << endl
				 << "Alttulmente disponibile solo in Italiano" << endl
				 << "Premi un tasto per continuare" << endl;
			fermaCout= _getch();
			break;

		case '5':
			system("CLS");
			cout << "Un grandissimo ringraziamento a:" << endl << endl
				<< "Arbjo Guza: Tutto quello che riguarda i combattimenti" << endl << endl
				<< "Paola Trevisiol: Controllo e correzione del testo" << endl
				<< "     (eventuali errori testuali/lessicali sono colpa di Marcuzzi Giuseppe)." << endl << endl
				<< "Nico/Okin: Storia base dei 2 portoni" << endl << endl
				<< "Per avermi supportato ma sopratutto sopportato per tutto il tempo in cui mi hanno aiutato." << endl
				<< "Premi un tasto per continuare" << endl;
			fermaCout = _getch();
			break;

		case '0':
			// esce dal programma
			break;

		default:
			system("CLS");
			stampaAVideoIlTesto(sceltaSbaglaita);
			fermaCout= _getch();
			break;
		}


		if (doveLUtenteVuoleAndarePartendoDalPrimoMenu=='1'){
			// creazione dei finali nella cartella finali

			// nome del file
			// giorno
			string dataEOra = to_string((tPtr->tm_mday));
			dataEOra = dataEOra + "-";
			// mese
			dataEOra = dataEOra + to_string((tPtr->tm_mon)+1);
			dataEOra = dataEOra + " ";
			// ora
			dataEOra = dataEOra + to_string((tPtr->tm_hour));
			dataEOra = dataEOra + ".";
			//minuti
			dataEOra = dataEOra + to_string((tPtr->tm_min));
			dataEOra = dataEOra + ".txt";

			string nomeFile = nomePg + " " + dataEOra;
			cartellaBase="C:\\" + cartellaBase + "\\Finali\\" + nomeFile;
			const char *percorsoFinali = cartellaBase.data();

			// creazione e scrittura nel file
			ofstream fout;
			fout.open(percorsoFinali);
			fout << "Nel giorno: " <<(tPtr->tm_mday)<<"/"<< (tPtr->tm_mon)+1 <<"/"<< (tPtr->tm_year)+1900 // giorno
				<< "alle " << (tPtr->tm_hour)<<":"<< (tPtr->tm_min)<<":"<< (tPtr->tm_sec) << endl // ora
				<< "Con questo nome " << nomePg << endl << endl 
				<< "finale" << finale << " di 8" << endl;
			fout.close();
			attributi = "attrib +r " + cartellaBase;
			const char *attributiFile = attributi.data();
			system(attributiFile);
		}
	} while (doveLUtenteVuoleAndarePartendoDalPrimoMenu != '0');

	return 0;
}

void stampaAVideoIlTesto(string paragrafo){
	
	// paragrafo variabile che verrÃ  utilizzata per identificare il paragrafo da stampare

	ifstream fin;
    fin.open("italiano.txt");
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

string controlloDelleCartelle(){

	char fermaCout;

    string attributi;
    string nomeCartellaBase;

    CreateDirectory("C:\\zReadTheFileInsiede", NULL);
    string fileControlloDiBase="C:\\zReadTheFileInsiede";
    attributi = "attrib +h +r "+ fileControlloDiBase;
    const char *attributiFile= attributi.data();
    system(attributiFile);

    ifstream fin;
    fin.open("C:\\zReadTheFileInsiede\\fileEsiste.txt");

    if (fin.fail()){
        // il file non esiste

        fin.close();

        // crea le cartelle mancanti
        creazioneDelleCartelle();

    } else {
        // il file esiste
        fin >> nomeCartellaBase;
        fin.close();

        string cartellaBase="C:\\" + nomeCartellaBase;
        const char *path = cartellaBase.c_str();
        if (CreateDirectory(path, NULL)) {
            
            // crea le cartelle che sono state cancellate
            creazioneDelleCartelle();
        
        } else if (ERROR_ALREADY_EXISTS == GetLastError()) {
		    // cartella giÃ  esiste
        } else {
            cout << "E' possibile che tu non abbia piu' spazio per poter contenere la cartella contenete i file necessari al funzionamento del gioco" << endl
                 << "Oppure e' un'altro problema" <<endl
                 << "Premi un tasto per continuare" << endl;
            fermaCout= _getch();
        }
    }

	return nomeCartellaBase;

}

void creazioneDelleCartelle (){

	char fermaCout;

    string attributi;
    string nomeCartellaBase;

    ofstream fout;
    fout.open("C:\\zReadTheFileInsiede\\READ ME BEFORE CANCEL.txt");
    string informazioni="Please do not cancel this directory and the next file \nThis directory and the next file are necessary for the correct function of the game";
    fout << informazioni;
    fout.close();
    attributi = "attrib +r C:\\zReadTheFileInsiede\\READ ME BEFORE CANCEL.txt";
    const char *attributiFile= attributi.data();
    system(attributiFile);

        

    // faccio scegliere il nome che l'utente vuole dare alla cartella
    char nomeCorretto=1;
    do {   
        cout << "Inserisci il nome della cartella dove verranno salvati i finali" << endl
             << "Il nome non puo' contenere spazi" << endl;
        cin >> nomeCartellaBase;
        cout << endl << "Il nome dato alla cartella e': " << nomeCartellaBase << endl
             << "Sei sicuro di questo nome?" << endl
             << "Si=1 NO=0" << endl;
        nomeCorretto = _getch();
        cout << endl;
    } while (nomeCorretto != '1');
        
    // salvo dentro il file il nome della cartella
    fout.open("C:\\zReadTheFileInsiede\\fileEsiste.txt");
        fout << nomeCartellaBase;
    fout.close();
    attributi = "attrib +r C:\\zReadTheFileInsiede\\fileEsiste.txt";
    attributiFile= attributi.data();
    system(attributiFile);

    // creazione della cartella
    string percorsoCartellaBase = "C:\\" + nomeCartellaBase;
    const char *path = percorsoCartellaBase.c_str();
    CreateDirectory(path, NULL);
	cout << endl << "Cartella contenente i finali e' stata creata al seguente percorso: " << percorsoCartellaBase << endl << endl;


    // creazione della caartella che conterrÃ  i finali ottenuti a fine partita con nome PG, data e ora dele completamento della storia e le statistiche
    string finePartita = percorsoCartellaBase + "\\Finali";
    path = finePartita.data();
    CreateDirectory(path, NULL);

    string percorsoCartella = percorsoCartellaBase + "\\Lingue";
    path = percorsoCartella.data();
    CreateDirectory(path, NULL);
    // creazione e scrittura in un file
    string percorsoFile = percorsoCartella + "\\READ ME.txt";
    path = percorsoFile.data();

    fout.open(path); // apre la cartella di dove stÃ  il file

    string nome = "Sono ancora da fare devo trovare qualcuno che mi traduca i testi \n";
    fout << nome ; // scrive sul file
    nome = "Ma cosa ancora piu importante devo trovare un modo per selezionare quali testi far stampare \n";
    fout << nome;
    nome = "Ma cosa ancora piÃ¹ importante devo trovare un modo per togliere il fatto che mi vada a capo quando ci sono degli spazzi";
    fout << nome;
    fout.close(); // chiude il file

    // creazione di alcune cartelle create a caso
    string cartelleCreateACaso = percorsoCartellaBase + "\\Scripts";
    path = cartelleCreateACaso.data();
    CreateDirectory(path, NULL);
    // assegna gli attributi
    attributi = "attrib +h +r " + cartelleCreateACaso; // posso passare assegnare piÃ¹ parametri contemporaneamente
    const char *attributiCartelle= attributi.data();
    system(attributiCartelle);

    // creazione e scrittura in un file
    percorsoFile = cartelleCreateACaso + "\\Confing.txt";
    path= percorsoFile.data();
    nome="Non c'Ã¨ nulla ma credo tu ci sperassi";
    fout.open(path); // apre la cartella di dove stÃ  il file
    fout << nome << endl; // scrive sul file
    fout.close(); // chiude il file

    cartelleCreateACaso = cartelleCreateACaso + "\\Statistiche";
    path = cartelleCreateACaso.data();
    CreateDirectory(path, NULL);
    // creazione e scrittura in un file
    percorsoFile = cartelleCreateACaso + "\\Cheats.txt";
    path= percorsoFile.data();
    nome="Eh... Voleeeevi!\n\n\n\n\n\nIn realta' un modo per cheattare esiste ma non ti dico quale";
    fout.open(path); // apre la cartella di dove stÃ  il file
    fout << nome << endl; // scrive sul file
    fout.close(); // chiude il file
    
}

int lanciaDado(int facce) {

	return rand() % facce + 1;
}
