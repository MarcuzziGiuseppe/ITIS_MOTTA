/* Marcuzzi Giuseppe
	Sessione di D&D
   09/06/2020

   29/01/2020 ho finalmente ricevuto la base della prima storia (i 2 portoni)
   24/02/2020 ho finalmente ricevuto il sistema di combattimenti
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
#define premiUnTasto "premiUnTasto"
#define ringraziamenti "ringraziamenti"

// paragrafi riguardanti il puro combattimetno
#define attaccaSchiva "attaccaSchiva"
#define combattimento1 "combattimento1"
#define combattimento2 "combattimento2"
#define combattimento3 "combattimento3"
#define combattimento4 "combattimento4"
#define combattimento5 "combattimento5"
#define combattimento6 "combattimento6"
#define combattimento7 "combattimento7"
#define combattimento8 "combattimento8"
#define combattimento9 "combattimento9"
#define combattimento10 "combattimento10"
#define combattimento11 "combattimento11"
#define combattimento12 "combattimento12"
#define combattimento13 "combattimento13"
#define combattimento14 "combattimento14"
#define combattimento15 "combattimento15"
#define combattimento16 "combattimento16"

// paragrafi inerenti soltanto la creazione del PG
#define creazionePg1 "creazionePg1"
#define creazionePg2 "creazionePg2"
#define creazionePg3 "creazionePg3"
#define creazionePg4 "creazionePg4"
#define creazionePg5 "creazionePg5"
#define creazionePg6 "creazionePg6"
#define creazionePg7 "creazionePg7"
#define creazionePg8 "creazionePg8"
#define creazionePg9 "creazionePg9"
#define creazionePg10 "creazionePg10"
#define creazionePg11 "creazionePg11"
#define creazionePg12 "creazionePg12"

// paragrafi inerenti le regole
#define regoleGioco1 "regoleGioco1"
#define regolePg1 "regolePg1"
#define regolePg2 "regolePg2"
#define regolePg3 "regolePg3"
#define regolePg4 "regolePg4"
#define regolePg5 "regolePg5"

// paragrafi inerenti alla storia dei 2 portoni
#define inizioStoria1 "inizioStoria1"
#define inizioStoria2 "inizioStoria2"
#define inizioStoria3 "inizioStoria3"
#define storiaPortoni1 "storiaPortoni1"
#define storiaPortoni2 "storiaPortoni2"
#define storiaPortoni3 "storiaPortoni3"
#define storiaPortoni4 "storiaPortoni4"
#define storiaPortoni5 "storiaPortoni5"
#define storiaPortoni6 "storiaPortoni6"
#define storiaPortoni7 "storiaPortoni7"
#define storiaPortoni8 "storiaPortoni8"
#define storiaPortoni9 "storiaPortoni9"
#define storiaPortoni10 "storiaPortoni10"
#define storiaPortoni11 "storiaPortoni11"
#define storiaPortoni12 "storiaPortoni12"
#define storiaPortoni13 "storiaPortoni13"
#define storiaPortoni14 "storiaPortoni14"
#define storiaPortoni15 "storiaPortoni15"
#define storiaPortoni16 "storiaPortoni16"
#define storiaPortoni17 "storiaPortoni17"
#define storiaPortoni18 "storiaPortoni18"
#define storiaPortoni19 "storiaPortoni19"
#define storiaPortoni20 "storiaPortoni20"
#define storiaPortoni21 "storiaPortoni21"
#define storiaPortoni22 "storiaPortoni22"
#define storiaPortoni23 "storiaPortoni23"
#define storiaPortoni24 "storiaPortoni24"
#define storiaPortoni25 "storiaPortoni25"
#define storiaPortoni26 "storiaPortoni26"
#define storiaPortoni27 "storiaPortoni27"
#define storiaPortoni28 "storiaPortoni28"
#define storiaPortoni29 "storiaPortoni29"
#define storiaPortoni30 "storiaPortoni30"
#define storiaPortoni31 "storiaPortoni31"
#define storiaPortoni32 "storiaPortoni32"
#define storiaPortoni33 "storiaPortoni33"
#define storiaPortoni34 "storiaPortoni34"
#define storiaPortoni35 "storiaPortoni35"
#define storiaPortoni36 "storiaPortoni36"
#define storiaPortoni37 "storiaPortoni37"

// paragrafi inerenti il combattimento
#define regoleCombattimento1 "regoleCombattimento1"

// variabili globali
bool godMod = false; // per attivare la godMod vado in regoleDelCombattimento e premo g (in minuscolo)
bool stampareLeClassiOLeRegole = false; // se e' false stampa la classe se e' true stampa la razza

// danno + vita del personaggio
int dannoPG = 0; // danno totale che il PG fa
int vitaPG = 0; // vita totale che il PG ha

// storia portoni
bool haAnalizzatoLAtlare = false;
float contatoreDelleAzioni = 0; // MOLTO IMPORTANTE PER UN FINALE SE AZIONI>30 LA DONNA MUORE E QUINDI TE PERDI
bool vuoleTornareAi2PortoniNelSaloneGrande = false;
// porta di destra e sinistra
bool chiaveDelCuoco = false;
bool chiaveArruginita = false;
// finali
bool personaggioMorto = false;
bool morteDellaDonnaCheUrla = false;
bool morteDellaDonnaCheUrlaDopoAverRiflettutoSullaVita = false;
bool fineDellaStoriaDelGrandeSalone = false;

// gestione dei file
void stampaAVideoIlTesto(string paragrafo);
string controlloDelleCartelle();
void creazioneDelleCartelle();

// statistiche e lancio dei dadi
int statistichePG[6] = { 0, 0, 0, 0, 0, 0 };
int lanciaDado(int);

// funzioni regole + creazione PG
void regoleDelPG();
void regoleDelCombattimento();
void regoleDelGioco();
char staisticheDaAumentare();
string creazionePG();

// storia portoni
int riduzioneDeiMostri(int, int);
void aperturaDiUnaDellePorteDellaPortaDiSinistraDelSalonePrincipale(int &finale);
void aperturaPorteDellaPortaDiSinistraNelSalonePrincipale(int &finale);
void portaDiSinistraNelSalonePrincipale(int &finale);
bool labirintoDelleTreStanzeNelPortoneDiDestra(bool);
bool portaDiDestraNelSalonePrincipale(bool, int &finale);
int inizioStoria();


int main(int argc, char* argv[]) {
	srand(time(NULL));
	char fermaCout;
	
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

	// controllo se la cartella che conterrà i finali esiste altrimenti la creo
	string attributi;
	string cartellaBase;
	cartellaBase=controlloDelleCartelle();

	int finale;
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
			stampaAVideoIlTesto(ringraziamenti);
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
			dataEOra = dataEOra + "-";
			// anno
			dataEOra = dataEOra + to_string((tPtr->tm_year)+1900);
			dataEOra = dataEOra + "_";
			// ora
			dataEOra = dataEOra + to_string((tPtr->tm_hour));
			dataEOra = dataEOra + ".";
			//minuti
			dataEOra = dataEOra + to_string((tPtr->tm_min));
			dataEOra = dataEOra + ".txt";

			string nomeFile = nomePg + "_" + dataEOra;
			cartellaBase="C:\\" + cartellaBase + "\\Finali\\" + nomeFile;
			const char *percorsoFinali = cartellaBase.data();

			// creazione e scrittura nel file
			ofstream fout;
			fout.open(percorsoFinali);
			fout << "Nel giorno: " <<(tPtr->tm_mday)<<"/"<< (tPtr->tm_mon)+1 <<"/"<< (tPtr->tm_year)+1900 // giorno
				<< " alle " << (tPtr->tm_hour)<<":"<< (tPtr->tm_min)<<":"<< (tPtr->tm_sec) << endl // ora
				<< "Con questo nome: " << nomePg << endl << endl 
				<< "finale " << finale << " di 8" << endl;
			fout.close();
			attributi = "attrib +r " + cartellaBase;
			const char *attributiFile = attributi.data();
			system(attributiFile);

		}
	} while (doveLUtenteVuoleAndarePartendoDalPrimoMenu != '0');

	return 0;
}

void stampaAVideoIlTesto(string paragrafo){
	
	// paragrafo variabile che verrà utilizzata per identificare il paragrafo da stampare

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
		    // cartella già esiste
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
    fout.open("C:\\zReadTheFileInsiede\\READ_ME_BEFORE_CANCEL.txt");
    string informazioni="Please do not cancel this directory and the next file \nThis directory and the next file are necessary for the correct function of the game";
    fout << informazioni;
    fout.close();
    attributi = "attrib +r C:\\zReadTheFileInsiede\\READ_ME_BEFORE_CANCEL.txt";
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
	cout << endl << "Cartella contenente i finali e' stata creata al seguente percorso: " << percorsoCartellaBase << endl 
				 << "Premi un tasto per continuare" << endl;
	fermaCout =_getch();

    // creazione della caartella che conterrà i finali ottenuti a fine partita con nome PG, data e ora dele completamento della storia e le statistiche
    string finePartita = percorsoCartellaBase + "\\Finali";
    path = finePartita.data();
    CreateDirectory(path, NULL);

    string percorsoCartella = percorsoCartellaBase + "\\Lingue";
    path = percorsoCartella.data();
    CreateDirectory(path, NULL);
    // creazione e scrittura in un file
    string percorsoFile = percorsoCartella + "\\READ ME.txt";
    path = percorsoFile.data();

    fout.open(path); // apre la cartella di dove stà il file

    string nome = "Sono ancora da fare devo trovare qualcuno che mi traduca i testi \n";
    fout << nome ; // scrive sul file
    nome = "Ma cosa ancora piu importante devo trovare un modo per selezionare quali testi far stampare \n";
    fout << nome;
    nome = "Ma cosa ancora più importante devo trovare un modo per togliere il fatto che mi vada a capo quando ci sono degli spazzi";
    fout << nome;
    fout.close(); // chiude il file

    // creazione di alcune cartelle create a caso
    string cartelleCreateACaso = percorsoCartellaBase + "\\Scripts";
    path = cartelleCreateACaso.data();
    CreateDirectory(path, NULL);
    // assegna gli attributi
    attributi = "attrib +h +r " + cartelleCreateACaso; // posso passare assegnare più parametri contemporaneamente
    const char *attributiCartelle= attributi.data();
    system(attributiCartelle);

    // creazione e scrittura in un file
    percorsoFile = cartelleCreateACaso + "\\Confing.txt";
    path= percorsoFile.data();
    nome="Non c'è nulla ma credo tu ci sperassi";
    fout.open(path); // apre la cartella di dove stà il file
    fout << nome << endl; // scrive sul file
    fout.close(); // chiude il file

    cartelleCreateACaso = cartelleCreateACaso + "\\Statistiche";
    path = cartelleCreateACaso.data();
    CreateDirectory(path, NULL);
    // creazione e scrittura in un file
    percorsoFile = cartelleCreateACaso + "\\Cheats.txt";
    path= percorsoFile.data();
    nome="Eh... Voleeeevi!\n\n\n\n\n\nIn realta' un modo per cheattare esiste ma non ti dico quale";
    fout.open(path); // apre la cartella di dove stà il file
    fout << nome << endl; // scrive sul file
    fout.close(); // chiude il file
    
}

int lanciaDado(int facce) {

	return rand() % facce + 1;
}

void regoleDelPG() {

	char fermaCout;
	char sceltaDiCosaVuoleVedere = 0;
	int cosaVuoleVedereNelleRegoleDelPG = 1;
	while (cosaVuoleVedereNelleRegoleDelPG != 0) {
		system("CLS");
		stampaAVideoIlTesto(regolePg1);
		fermaCout = _getch();
		cout << endl;

		switch (fermaCout) {

		case '1':
			// Classe
			system("CLS");
			stampaAVideoIlTesto(regolePg2);
			fermaCout = _getch();
			cout << endl;
			break;

		case '2':
			// Razze
			system("CLS");
			stampaAVideoIlTesto(regolePg3);
			fermaCout = _getch();
			cout << endl;
			break;

		case '3':
			// Statistiche
			system("CLS");
			stampaAVideoIlTesto(regolePg4);
			fermaCout = _getch();
			cout << endl;

			// Lancio dadi per le statistiche
			system("CLS");
			stampaAVideoIlTesto(regolePg5);
			fermaCout = _getch();
			cout << endl;
			break;

		case '0':
			cosaVuoleVedereNelleRegoleDelPG = 0;
			cout << endl;
			break;

		default:
			system("CLS");
			stampaAVideoIlTesto(sceltaSbaglaita);
			break;
		}
	}
}

void regoleDelCombattimento() {

	char fermaCout;
	system("CLS");
	stampaAVideoIlTesto(regoleCombattimento1);
	fermaCout = _getch();
	if (fermaCout == 'g') {
		godMod = true;
	}
}

void regoleDelGioco() {

	char fermaCout;
	int esciDalleRegoleDelGioco = 1;
	char sceltaSeRegolePgORegoleComabttimento;
	while (esciDalleRegoleDelGioco != 0) {
		system("CLS");
		stampaAVideoIlTesto(regoleGioco1);
		sceltaSeRegolePgORegoleComabttimento = _getch();
		cout << endl;

		switch (sceltaSeRegolePgORegoleComabttimento) {
		case '1':
			regoleDelPG();
			break;

		case '2':
			regoleDelCombattimento();
			break;

		case '0':
			esciDalleRegoleDelGioco = 0;
			break;

		default:
			system("CLS");
			stampaAVideoIlTesto(sceltaSbaglaita);
			break;
		}
	}
}

char staisticheDaAumentare() {

	string statistiche[6] = {
		"Forza",
		"Destrezza",
		"Costituzione",
		"Intelligenza",
		"Saggezza",
		"Carisma" };

	char carattereLettoDaTastiera;

	for (int i = 0; i < 6; i++) {
		cout << i + 1 << ")--> " << statistiche[i] << endl;
	}

	cout << endl << "ora scelgi cosa aumentare." << endl
		<< "Per secegliere basta che premi il numro della statistica corrispondente" << endl;
	carattereLettoDaTastiera = _getch(); // scelta
	cout << endl;
	return carattereLettoDaTastiera;
}

string creazionePG() {

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

	/* Con if in cascata potrei far scrivere all' utente direttamente la classe
	   perche' switch-case prende solo valori interi
	   (if in cascata con controlli dei char)
	   ma probabilmente appesentirebbe molto il programma */
	do {
		stampareLeClassiOLeRegole = false;
		do {
			haiSceltoUnaClasseORazzaNonValida = false;
			stampaAVideoIlTesto(creazionePg4);
			classeCheSceglie = _getch(); // scelta 
			if (classeCheSceglie == 'r') {
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
			fermaCout = _getch();
		}

		if (haiSceltoUnaClasseORazzaNonValida == false) {
			stampaAVideoIlTesto(creazionePg5);
			cout << classeScelta << endl;
			stampaAVideoIlTesto(seiSicuro);
			sicurezzaSceltaClasse = _getch();
			cout << endl;
		}
	} while (sicurezzaSceltaClasse != '1');
	stampareLeClassiOLeRegole = true;


	// scelta della razza
	string razze[7] = {
		"Nano",
		"Elfo",
		"Gnomo",
		"Mezzelfo",
		"Mezzorco",
		"Halfling",
		"Umano" };
	string razza = "razza";
	string razzaScelta;
	char razzaCheSceglie;
	char sicurezzaSceltaRazza = 0;

	/* Con if in cascata potrei far scrivere all' utente direttamente la razza
	   perche' switch-case prende solo valori interi
	   (if in cascata con controlli dei char)
	   ma probabilmente appesentirebbe molto il programma */
	do {
		do {
			haiSceltoUnaClasseORazzaNonValida = false;
			stampaAVideoIlTesto(creazionePg6);
			razzaCheSceglie = _getch(); // scelta
			if (razzaCheSceglie=='r'){
				regoleDelPG();
			}
		} while (razzaCheSceglie == 'r');

		if (razzaCheSceglie >= '1' && razzaCheSceglie <= '7') {
			razzaScelta = razze[razzaCheSceglie - 49];
		}
		else {
			haiSceltoUnaClasseORazzaNonValida=true;
			system("CLS");
			stampaAVideoIlTesto(sceltaSbaglaita);
			fermaCout= _getch();
		}

		if (haiSceltoUnaClasseORazzaNonValida == false) {
			stampaAVideoIlTesto(creazionePg5);
			cout << razzaScelta << endl;
			stampaAVideoIlTesto(seiSicuro);
			sicurezzaSceltaRazza = _getch();
			cout << endl;
		}
	} while ( sicurezzaSceltaRazza != '1');


	// calcolo statistiche
	string forza = "Forza";
	string destrezza = "Destrezza";
	string costituzione = "Costituzione";
	string intelligenza = "Intelligenza";
	string saggezza = "Saggezza";
	string carisma = "Carisma";
	bool haiSceltoUnaStatisticaNonValida = false;
	int calcoloStatistiche[4] = { 0 };
	int sommaPerIlCalcoloDelleStatistiche = 0;
	char aumentoStatistiche;
	string statisticaCheSceglieDiAumentare;
	char condizioneDelCicloPerLAumentoStatistiche;
	char vuoleVedereComeVengonoGenereateLeStatisticheNelleRegole;
	do {
		system("CLS");
		stampaAVideoIlTesto(creazionePg7);
		vuoleVedereComeVengonoGenereateLeStatisticheNelleRegole = _getch();
		if (vuoleVedereComeVengonoGenereateLeStatisticheNelleRegole=='r'){
			regoleDelPG();
		}
	} while (vuoleVedereComeVengonoGenereateLeStatisticheNelleRegole=='r');
	
	

	for (int i = 0; i < 6; i++) {
		do {

			for (int i2 = 0; i2 < 4; i2++) {
				calcoloStatistiche[i2] = lanciaDado(6);
			}

			sommaPerIlCalcoloDelleStatistiche = calcoloStatistiche[0] + calcoloStatistiche[1] + calcoloStatistiche[2] + calcoloStatistiche[3];
			statistichePG[i] = sommaPerIlCalcoloDelleStatistiche;
			if (i == 2 && statistichePG[i] > 20) {
				statistichePG[i] = 20;
			}
		} while (statistichePG[i] < 10);
	}

	switch (razzaCheSceglie) {
	case '1':
		statistichePG[0] + 2;
		statistichePG[4] + 2;
		statistichePG[5] - 2;
		stampaAVideoIlTesto(creazionePg8);
		break;

	case '2':
		statistichePG[1] + 2;
		statistichePG[0] - 2;
		statistichePG[3] + 2;
		stampaAVideoIlTesto(creazionePg8);
		break;

	case '3':
		statistichePG[0] - 2;
		statistichePG[1] + 2;
		statistichePG[5] + 2;
		stampaAVideoIlTesto(creazionePg8);
		break;

	case '4':
		do {
			haiSceltoUnaStatisticaNonValida = false;
			stampaAVideoIlTesto(creazionePg9);
			cout << razzaScelta;
			stampaAVideoIlTesto(creazionePg10);
			aumentoStatistiche = staisticheDaAumentare();

			switch (aumentoStatistiche) {
			case '1':
				statistichePG[0] = statistichePG[0] + 2;
				statisticaCheSceglieDiAumentare = forza;
				break;

			case '2':
				statistichePG[1] = statistichePG[1] + 2;
				statisticaCheSceglieDiAumentare = destrezza;
				break;

			case '3':
				if (statistichePG[2] == 20) {
					haiSceltoUnaStatisticaNonValida = true;
					stampaAVideoIlTesto(creazionePg11);
					fermaCout = _getch();
				}
				else {
					statisticaCheSceglieDiAumentare = costituzione;
					if (statistichePG[2] == 19) {
						statistichePG[2]++;
					}
					else {
						statistichePG[2] = statistichePG[2] + 2;
					}
				}
				break;

			case '4':
				statistichePG[3] = statistichePG[3] + 2;
				statisticaCheSceglieDiAumentare = intelligenza;
				break;

			case '5':
				statistichePG[4] = statistichePG[4] + 2;
				statisticaCheSceglieDiAumentare = saggezza;
				break;

			case '6':
				statistichePG[5] = statistichePG[5] + 2;
				statisticaCheSceglieDiAumentare = carisma;
				break;

			default:
				haiSceltoUnaStatisticaNonValida = true;
				system("CLS");
				stampaAVideoIlTesto(sceltaSbaglaita);
				break;
			}

			if (haiSceltoUnaStatisticaNonValida == false) {

				stampaAVideoIlTesto(creazionePg12);
				cout << statisticaCheSceglieDiAumentare << endl;
				stampaAVideoIlTesto(seiSicuro);
				condizioneDelCicloPerLAumentoStatistiche = _getch();
			}
		} while (condizioneDelCicloPerLAumentoStatistiche != '1');
		stampaAVideoIlTesto(creazionePg8);
		break;

	case '5':
		do {
			haiSceltoUnaStatisticaNonValida = false;
			stampaAVideoIlTesto(creazionePg9);
			cout << razzaScelta;
			stampaAVideoIlTesto(creazionePg10);
			aumentoStatistiche = staisticheDaAumentare();

			switch (aumentoStatistiche) {
			case '1':
				statistichePG[0] = statistichePG[0] + 2;
				statisticaCheSceglieDiAumentare = forza;
				break;

			case '2':
				statistichePG[1] = statistichePG[1] + 2;
				statisticaCheSceglieDiAumentare = destrezza;
				break;

			case '3':
				if (statistichePG[2] == 20) {
					haiSceltoUnaStatisticaNonValida = true;
					stampaAVideoIlTesto(creazionePg11);
					fermaCout = _getch();
				}
				else {
					statisticaCheSceglieDiAumentare = costituzione;
					if (statistichePG[2] == 19) {
						statistichePG[2]++;
					}
					else {
						statistichePG[2] = statistichePG[2] + 2;
					}
				}
				break;

			case '4':
				statistichePG[3] = statistichePG[3] + 2;
				statisticaCheSceglieDiAumentare = intelligenza;
				break;

			case '5':
				statistichePG[4] = statistichePG[4] + 2;
				statisticaCheSceglieDiAumentare = saggezza;
				break;

			case '6':
				statistichePG[5] = statistichePG[5] + 2;
				statisticaCheSceglieDiAumentare = carisma;
				break;

			default:
				haiSceltoUnaStatisticaNonValida = true;
				system("CLS");
				stampaAVideoIlTesto(sceltaSbaglaita);
				break;
			}

			if (haiSceltoUnaStatisticaNonValida == false) {

				stampaAVideoIlTesto(creazionePg12);
				cout << statisticaCheSceglieDiAumentare << endl;
				stampaAVideoIlTesto(seiSicuro);
				condizioneDelCicloPerLAumentoStatistiche = _getch();
			}
		} while (condizioneDelCicloPerLAumentoStatistiche != '1');

		statistichePG[5] - 2;
		stampaAVideoIlTesto(creazionePg8);
		break;

	case '6':
		statistichePG[0] - 2;
		statistichePG[1] + 2;
		statistichePG[5] + 2;
		stampaAVideoIlTesto(creazionePg8);
		break;

	case '7':
		do {
			haiSceltoUnaStatisticaNonValida = false;
			stampaAVideoIlTesto(creazionePg9);
			cout << razzaScelta;
			stampaAVideoIlTesto(creazionePg10);
			aumentoStatistiche = staisticheDaAumentare();

			switch (aumentoStatistiche) {
			case '1':
				statistichePG[0] = statistichePG[0] + 2;
				statisticaCheSceglieDiAumentare = forza;
				break;

			case '2':
				statistichePG[1] = statistichePG[1] + 2;
				statisticaCheSceglieDiAumentare = destrezza;
				break;

			case '3':
				if (statistichePG[2] == 20) {
					haiSceltoUnaStatisticaNonValida = true;
					stampaAVideoIlTesto(creazionePg11);
					fermaCout = _getch();
				}
				else {
					statisticaCheSceglieDiAumentare = costituzione;
					if (statistichePG[2] == 19) {
						statistichePG[2]++;
					}
					else {
						statistichePG[2] = statistichePG[2] + 2;
					}
				}
				break;

			case '4':
				statistichePG[3] = statistichePG[3] + 2;
				statisticaCheSceglieDiAumentare = intelligenza;
				break;

			case '5':
				statistichePG[4] = statistichePG[4] + 2;
				statisticaCheSceglieDiAumentare = saggezza;
				break;

			case '6':
				statistichePG[5] = statistichePG[5] + 2;
				statisticaCheSceglieDiAumentare = carisma;
				break;

			default:
				haiSceltoUnaStatisticaNonValida = true;
				system("CLS");
				stampaAVideoIlTesto(sceltaSbaglaita);
				break;
			}

			if (haiSceltoUnaStatisticaNonValida == false) {

				stampaAVideoIlTesto(creazionePg12);
				cout << statisticaCheSceglieDiAumentare << endl;
				stampaAVideoIlTesto(seiSicuro);
				condizioneDelCicloPerLAumentoStatistiche = _getch();
			}
		} while (condizioneDelCicloPerLAumentoStatistiche != '1');
		stampaAVideoIlTesto(creazionePg8);
		break;

	defoult:
	system("CLS");
		stampaAVideoIlTesto(sceltaSbaglaita);
		break;
	}

	if (godMod == true) {
		for (int i = 0; i < 6; i++) {
			statistichePG[i] = 1000;
		}
	}

	cout << forza << ": " << statistichePG[0] << endl
		<< destrezza << ": " << statistichePG[1] << endl
		<< costituzione << ": " << statistichePG[2] << endl
		<< intelligenza << ": " << statistichePG[3] << endl
		<< saggezza << ": " << statistichePG[4] << endl
		<< carisma << ": " << statistichePG[5] << endl << endl << endl;


	// assegnazione delle armi + assegnazione della vita
	int dannoArmiBase[8] = { 20, 18, 15, 18, 15, 15, 12, 13 };
	int vitaBase[8] = { 30, 32, 35, 32, 35, 35, 38, 37 };
	switch (classeCheSceglie) {
	case '1':
		dannoPG = dannoArmiBase[0] + statistichePG[0];
		vitaPG = vitaBase[0] + statistichePG[2];
		break;

	case '2':
		dannoPG = dannoArmiBase[1] + statistichePG[0];
		vitaPG = vitaBase[1] + statistichePG[2];
		break;

	case '3':
		dannoPG = dannoArmiBase[2] + statistichePG[0];
		vitaPG = vitaBase[2] + statistichePG[2];
		break;

	case '4':
		dannoPG = dannoArmiBase[3] + statistichePG[0];
		vitaPG = vitaBase[3] + statistichePG[2];
		break;

	case '5':
		dannoPG = dannoArmiBase[4] + statistichePG[1];
		vitaPG = vitaBase[4] + statistichePG[2];
		break;

	case '6':
		dannoPG = dannoArmiBase[5] + statistichePG[1];
		vitaPG = vitaBase[5] + statistichePG[2];
		break;

	case '7':
		dannoPG = dannoArmiBase[6] + statistichePG[3];
		vitaPG = vitaBase[6] + statistichePG[2];
		break;

	case '8':
		dannoPG = dannoArmiBase[7] + statistichePG[3];
		vitaPG = vitaBase[7] + statistichePG[2];
		break;

	default:
		break;
	}
	/*  Barbaro: Ascia 20 danni + for / 30 + cos
		Guerriero: Spada lunga 18 + for / 32 + cos
		Monaco: Pugni 15 + for / 35 + cos
		Paladino: Martello 18 + for / 32 + cos
		Ranger: Spada corta 15 + dex / 35 + cos
		Ladro: Pugnali 15 + dex / 35 + cos
		Stregone: Bastone magico 12 + int / 38 + cos
		Mago: Grimorio 13 + int / 37 + cos
	*/

	return nomePG;
}

int riduzioneDeiMostri(int vitaDeiMostri, int quantitaDeiMostri) {

	// da vedere se fare
	// bisogna studiarsela bene
	if (vitaDeiMostri < 250) {
		quantitaDeiMostri = 5;
		if (vitaDeiMostri < 201) {
			quantitaDeiMostri = 4;
			if (vitaDeiMostri < 151) {
				quantitaDeiMostri = 3;
				if (vitaDeiMostri < 101) {
					quantitaDeiMostri = 2;
					if (vitaDeiMostri < 51) {
						quantitaDeiMostri = 1;
						if (vitaDeiMostri <= 0) {
							quantitaDeiMostri = 0;
						}
					}
				}
			}
		}
	}

	return quantitaDeiMostri;
}

void aperturaDiUnaDellePorteDellaPortaDiSinistraDelSalonePrincipale(int &finale) {

	char fermaCout;

	// variabili genrali
	bool finisceDiEsplorareLePorte;
	char chePortaDecideDiScegliere = 0;

	// variabili della 1^ porta a sinistra (il cuoco)
	char mangiareONonMangiareDalCuoco = 0;
	bool primaVoltaCheentraDalCuoco = true;
	int vitaDelMiniBoss = 100;

	// variabili 3^ porta a destra (goblin + donna da salvare)
	int quantitaGoblin = 5;
	int vitaDeiGoblin = quantitaGoblin * 50;
	int valoreBaseDellaVitaDeiMostri = 250;

	// variabili di combattimento
	char sceltaNelcombattimento = 0;
	int risultatoDalLancioDelDado = 0;
	int vitaTemporaneaDelPG = vitaPG;


	do {
		vuoleTornareAi2PortoniNelSaloneGrande = false;
		finisceDiEsplorareLePorte = false;
		system("CLS");
		stampaAVideoIlTesto(storiaPortoni15);
		chePortaDecideDiScegliere = _getch();
		switch (chePortaDecideDiScegliere) {
		case '1':
			if (primaVoltaCheentraDalCuoco == true) {
				primaVoltaCheentraDalCuoco = false;
				do {
					stampaAVideoIlTesto(storiaPortoni16);
					mangiareONonMangiareDalCuoco = _getch();
					switch (mangiareONonMangiareDalCuoco) {
					case '1':
						// finale 2
						finisceDiEsplorareLePorte = true;
						morteDellaDonnaCheUrla = true;
						fineDellaStoriaDelGrandeSalone = true;
						system("CLS");
						finale = 2;
						stampaAVideoIlTesto(storiaPortoni17);
						fermaCout = _getch();
						break;

					case '2':
						system("CLS");
						stampaAVideoIlTesto(storiaPortoni18);
						do {
							stampaAVideoIlTesto(attaccaSchiva);
							sceltaNelcombattimento = _getch();
							switch (sceltaNelcombattimento) {
							case '1':
								// attacco del PG
								contatoreDelleAzioni = contatoreDelleAzioni + 0.5;
								stampaAVideoIlTesto(combattimento1);
								risultatoDalLancioDelDado = lanciaDado(20);
								if (risultatoDalLancioDelDado >= 13) {
									vitaDelMiniBoss = vitaDelMiniBoss - dannoPG;
									stampaAVideoIlTesto(combattimento2);
									cout << vitaDelMiniBoss << " hp" << endl;
									stampaAVideoIlTesto(premiUnTasto);
									fermaCout = _getch();
									cout << endl;
								}
								else {
									stampaAVideoIlTesto(combattimento3);
									fermaCout = _getch();
									cout << endl;
								}

								// attacco del minBoss
								if (vitaDelMiniBoss > 0) {
									contatoreDelleAzioni = contatoreDelleAzioni + 0.5;
									risultatoDalLancioDelDado = lanciaDado(20);
									if (risultatoDalLancioDelDado >= statistichePG[2]) {
										vitaTemporaneaDelPG = vitaTemporaneaDelPG - 10;
										stampaAVideoIlTesto(combattimento4);
										cout << vitaTemporaneaDelPG << "hp" << endl;
										stampaAVideoIlTesto(premiUnTasto);
										fermaCout = _getch();
										cout << endl;
									}
									else {
										stampaAVideoIlTesto(combattimento5);
										fermaCout = _getch();
										cout << endl;
									}
								}
								break;

							case '2':
								// attacco del minBoss
								contatoreDelleAzioni = contatoreDelleAzioni + 0.5;
								risultatoDalLancioDelDado = lanciaDado(17);
								if (risultatoDalLancioDelDado >= statistichePG[2]) {
									vitaTemporaneaDelPG = vitaTemporaneaDelPG - 10;
									stampaAVideoIlTesto(combattimento4);
									cout << vitaTemporaneaDelPG << "hp" << endl;
									stampaAVideoIlTesto(premiUnTasto);
									fermaCout = _getch();
									cout << endl;
								}
								else {
									stampaAVideoIlTesto(combattimento5);
									fermaCout = _getch();
									cout << endl;
								}

								// attacco del PG
								if (vitaTemporaneaDelPG > 0) {
									contatoreDelleAzioni = contatoreDelleAzioni + 0.5;
									stampaAVideoIlTesto(combattimento1);
									risultatoDalLancioDelDado = lanciaDado(20);
									if (risultatoDalLancioDelDado >= 10) {
										vitaDelMiniBoss = vitaDelMiniBoss - (dannoPG + 5);
										stampaAVideoIlTesto(combattimento2);
										cout << vitaDelMiniBoss << " hp" << endl;
										stampaAVideoIlTesto(premiUnTasto);
										fermaCout = _getch();
										cout << endl;
									}
									else {
										stampaAVideoIlTesto(combattimento3);
										fermaCout = _getch();
										cout << endl;

										// 2° attacco del minBoss
										if (vitaDelMiniBoss > 0) {
											contatoreDelleAzioni = contatoreDelleAzioni + 0.5;
											risultatoDalLancioDelDado = lanciaDado(25);
											if (risultatoDalLancioDelDado >= statistichePG[2]) {
												vitaTemporaneaDelPG = vitaTemporaneaDelPG - 10;
												stampaAVideoIlTesto(combattimento4);
												cout << vitaTemporaneaDelPG << " hp" << endl;
												stampaAVideoIlTesto(premiUnTasto);
												fermaCout = _getch();
												cout << endl;
											}
											else {
												stampaAVideoIlTesto(combattimento5);
												fermaCout = _getch();
												cout << endl;
											}
										}
									}
								}
								break;

							default:
								system("CLS");
								stampaAVideoIlTesto(sceltaSbaglaita);
								fermaCout = _getch();
								break;
							}
						} while (vitaDelMiniBoss >= 0 && vitaTemporaneaDelPG >= 0);
						system("CLS");
						if (vitaTemporaneaDelPG <= 0) {
							finisceDiEsplorareLePorte = true;
							morteDellaDonnaCheUrla = true;
							fineDellaStoriaDelGrandeSalone = true;
							system("CLS");
							finale=3;
							stampaAVideoIlTesto(storiaPortoni19);
							fermaCout = _getch();
						}
						else {
							chiaveDelCuoco = true;
							stampaAVideoIlTesto(storiaPortoni20);
							fermaCout = _getch();
						}
						break;

					default:
						system("CLS");
						stampaAVideoIlTesto(sceltaSbaglaita);
						fermaCout = _getch();
						break;
					}
				} while (mangiareONonMangiareDalCuoco != '1' && mangiareONonMangiareDalCuoco != '2');
			} else {
				system("CLS");
				stampaAVideoIlTesto(storiaPortoni21);
				fermaCout = _getch();
			}
			break;

		case '2':
			contatoreDelleAzioni++;
			system("CLS");
			stampaAVideoIlTesto(storiaPortoni22);
			fermaCout = _getch();
			break;

		case '3':
			contatoreDelleAzioni++;
			system("CLS");
			stampaAVideoIlTesto(storiaPortoni22);
			fermaCout = _getch();
			break;

		case '4':
			contatoreDelleAzioni++;
			system("CLS");
			stampaAVideoIlTesto(storiaPortoni22);
			fermaCout = _getch();
			break;

		case '5':
			contatoreDelleAzioni++;
			system("CLS");
			stampaAVideoIlTesto(storiaPortoni22);
			fermaCout = _getch();
			break;

		case '6':
			if (chiaveArruginita == true || godMod == true) {
				if (contatoreDelleAzioni >= 30) {
					finisceDiEsplorareLePorte = true;
					morteDellaDonnaCheUrla = true;
					fineDellaStoriaDelGrandeSalone = true;
					system("CLS");
					finale=5;
					stampaAVideoIlTesto(storiaPortoni23);
					fermaCout = _getch();
				}
				else {
					if (morteDellaDonnaCheUrlaDopoAverRiflettutoSullaVita == true) {
						finisceDiEsplorareLePorte = true;
						morteDellaDonnaCheUrla = true;
						fineDellaStoriaDelGrandeSalone = true;
						system("CLS");
						finale=1;
						stampaAVideoIlTesto(storiaPortoni24);
						fermaCout = _getch();
					}
					else {
						// combattimento
						vitaTemporaneaDelPG = vitaPG;
						system("CLS");
						stampaAVideoIlTesto(storiaPortoni25);
						do {
							stampaAVideoIlTesto(attaccaSchiva);
							sceltaNelcombattimento = _getch();
							switch (sceltaNelcombattimento) {
							case '1':
								// attacco del PG
								contatoreDelleAzioni = contatoreDelleAzioni + 0.5;
								stampaAVideoIlTesto(combattimento1);
								risultatoDalLancioDelDado = lanciaDado(20);
								if (risultatoDalLancioDelDado >= 13) {
									vitaDeiGoblin = vitaDeiGoblin - dannoPG;
									quantitaGoblin = riduzioneDeiMostri(vitaDeiGoblin, quantitaGoblin);
									stampaAVideoIlTesto(combattimento6);
									cout << vitaDeiGoblin << " hp" << endl;
									stampaAVideoIlTesto(premiUnTasto);
									fermaCout = _getch();
									cout << endl;
								}
								else {
									stampaAVideoIlTesto(combattimento7);
									fermaCout = _getch();
									cout << endl;
								}

								// attacco dei goblin
								if (vitaDeiGoblin > 0) {
									contatoreDelleAzioni = contatoreDelleAzioni + 0.5;
									for (int i = quantitaGoblin; i != 0; i--) {
										risultatoDalLancioDelDado = lanciaDado(20);
										if (risultatoDalLancioDelDado >= statistichePG[2]) {
											vitaTemporaneaDelPG = vitaTemporaneaDelPG - 7;
											stampaAVideoIlTesto(combattimento8);
											cout << vitaTemporaneaDelPG << " hp";
											stampaAVideoIlTesto(premiUnTasto);
											fermaCout = _getch();
											cout << endl;
										}
										else {
											stampaAVideoIlTesto(combattimento5);
											fermaCout = _getch();
											cout << endl;
										}
										if (vitaTemporaneaDelPG <= 0) {
											i = 1;
											finisceDiEsplorareLePorte = true;
											morteDellaDonnaCheUrla = true;
											fineDellaStoriaDelGrandeSalone = true;
											system("CLS");
											finale=6;
											stampaAVideoIlTesto(combattimento9);
											fermaCout = _getch();
										}
									}
								}
								break;

							case '2':
								// attacco dei goblin
								contatoreDelleAzioni = contatoreDelleAzioni + 0.5;
								for (int i = quantitaGoblin; i != 0; i--) {
									risultatoDalLancioDelDado = lanciaDado(20);
									if (risultatoDalLancioDelDado >= statistichePG[2]) {
										vitaTemporaneaDelPG = vitaTemporaneaDelPG - 7;
										stampaAVideoIlTesto(combattimento8);
										cout << vitaTemporaneaDelPG << " hp";
										stampaAVideoIlTesto(premiUnTasto);
										fermaCout = _getch();
										cout << endl;
									}
									else {
										stampaAVideoIlTesto(combattimento5);
										fermaCout = _getch();
										cout << endl;
									}
									if (vitaTemporaneaDelPG <= 0) {
										i = 1;
										finisceDiEsplorareLePorte = true;
										morteDellaDonnaCheUrla = true;
										fineDellaStoriaDelGrandeSalone = true;
										system("CLS");
										finale=6;
										stampaAVideoIlTesto(combattimento9);
										fermaCout = _getch();
									}
								}

								// attacco del PG
								if (vitaTemporaneaDelPG > 0) {
									contatoreDelleAzioni = contatoreDelleAzioni + 0.5;
									stampaAVideoIlTesto(combattimento1);
									risultatoDalLancioDelDado = lanciaDado(20);
									if (risultatoDalLancioDelDado >= 13) {
										vitaDeiGoblin = vitaDeiGoblin - (dannoPG + 5);
										quantitaGoblin = riduzioneDeiMostri(vitaDeiGoblin, quantitaGoblin);
										stampaAVideoIlTesto(combattimento6);
										cout << vitaDeiGoblin << " hp" << endl;
										stampaAVideoIlTesto(premiUnTasto);
										fermaCout = _getch();
										cout << endl;
									}
									else {
										stampaAVideoIlTesto(combattimento7);
										fermaCout = _getch();
										cout << endl;
									}

									// 2° attacco dei goblin
									if (vitaDeiGoblin > 0) {
										contatoreDelleAzioni = contatoreDelleAzioni + 0.5;
										for (int i = quantitaGoblin; i != 0; i--) {
											risultatoDalLancioDelDado = lanciaDado(20);
											if (risultatoDalLancioDelDado >= statistichePG[2]) {
												vitaTemporaneaDelPG = vitaTemporaneaDelPG - 7;
												stampaAVideoIlTesto(combattimento8);
												cout << vitaTemporaneaDelPG << " hp";
												stampaAVideoIlTesto(premiUnTasto);
												fermaCout = _getch();
												cout << endl;
											}
											else {
												stampaAVideoIlTesto(combattimento5);
												fermaCout = _getch();
												cout << endl;
											}
											if (vitaTemporaneaDelPG <= 0) {
												i = 1;
												finisceDiEsplorareLePorte = true;
												morteDellaDonnaCheUrla = true;
												fineDellaStoriaDelGrandeSalone = true;
												system("CLS");
												finale=6;
												stampaAVideoIlTesto(combattimento9);
												fermaCout = _getch();
											}
										}
									}
								}
								break;

							default:
								system("CLS");
								stampaAVideoIlTesto(sceltaSbaglaita);
								fermaCout = _getch();
								break;
							}
						} while (vitaDeiGoblin > 0 && vitaTemporaneaDelPG > 0);
						if (vitaDeiGoblin <= 0 && vitaTemporaneaDelPG > 0) {
							finisceDiEsplorareLePorte = true;
							morteDellaDonnaCheUrla = true;
							fineDellaStoriaDelGrandeSalone = true;
							system("CLS");
							stampaAVideoIlTesto(combattimento10);
							do {
								stampaAVideoIlTesto(combattimento11);
								fermaCout = _getch(); // uso fermaCout per non creare un' ulteriore variabile
							} while (fermaCout != '1' && fermaCout != '2');
							switch (fermaCout) {
							case '1':
								system("CLS");
								finale=7;
								stampaAVideoIlTesto(combattimento12);
								fermaCout = _getch();
								break;

							case '2':
								system("CLS");
								finale=8;
								stampaAVideoIlTesto(combattimento13);
								fermaCout = _getch();
								break;

							default:
								system("CLS");
								stampaAVideoIlTesto(sceltaSbaglaita);
								fermaCout = _getch();
								break;
							}
						}
					}
				}
			}
			else {
				contatoreDelleAzioni++;
				system("CLS");
				stampaAVideoIlTesto(storiaPortoni22);
				fermaCout = _getch();
			}
			break;

		case '7':
			finisceDiEsplorareLePorte = true;
			break;

		default:
			system("CLS");
			stampaAVideoIlTesto(sceltaSbaglaita);
			fermaCout = _getch();
			break;
		}
	} while (finisceDiEsplorareLePorte != true);
}

void portaDiSinistraDelSalonePrincipale(int &finale) {

	char fermaCout;

	bool aperturaPortone1Volta = false;
	bool esceDallaPortaDiSinistraDelSalonePrincipale = false;
	bool ascoltaNellaPrimaScelta = false;
	bool esaminazioneDellePorte = false;
	bool morteDellaDonnaDopoAverSentitoLeUrla = false;
	char sceltaDellaPortaDiSinistraDelSalonePrincipale = '0';
	char decidereSeIndagareSeulleUrlaDellaDonna;
	bool indagareSulleUrlaDellaDonna = false;

	do {
		vuoleTornareAi2PortoniNelSaloneGrande = false;
		if (ascoltaNellaPrimaScelta == false && aperturaPortone1Volta == false) {
			system("CLS");
			aperturaPortone1Volta = true;
			stampaAVideoIlTesto(storiaPortoni6);
			sceltaDellaPortaDiSinistraDelSalonePrincipale = _getch();
			switch (sceltaDellaPortaDiSinistraDelSalonePrincipale) {
			case '1':
				contatoreDelleAzioni++;
				ascoltaNellaPrimaScelta = true;
				while (indagareSulleUrlaDellaDonna != true) {
					stampaAVideoIlTesto(storiaPortoni7);
					decidereSeIndagareSeulleUrlaDellaDonna = _getch();
					switch (decidereSeIndagareSeulleUrlaDellaDonna) {
					case '1':
						contatoreDelleAzioni++;
						aperturaDiUnaDellePorteDellaPortaDiSinistraDelSalonePrincipale(finale);
						indagareSulleUrlaDellaDonna = true;
						break;
					case '0':
						indagareSulleUrlaDellaDonna = false;
						cout << endl;
						break;

					default:
						system("CLS");
						stampaAVideoIlTesto(sceltaSbaglaita);
						fermaCout = _getch();
						break;
					}
				}
				break;

			case '2':
				contatoreDelleAzioni++;
				stampaAVideoIlTesto(storiaPortoni8);
				aperturaDiUnaDellePorteDellaPortaDiSinistraDelSalonePrincipale(finale);
				break;

			case '3':
				contatoreDelleAzioni++;
				cout << endl << endl;
				aperturaDiUnaDellePorteDellaPortaDiSinistraDelSalonePrincipale(finale);
				break;

			case '4':
				// finale 1
				morteDellaDonnaCheUrlaDopoAverRiflettutoSullaVita = true;
				stampaAVideoIlTesto(storiaPortoni9);
				if (ascoltaNellaPrimaScelta == true) {
					morteDellaDonnaDopoAverSentitoLeUrla = true;
					stampaAVideoIlTesto(storiaPortoni10);
				}
				stampaAVideoIlTesto(premiUnTasto);
				fermaCout = _getch();
				break;

			case '5':
				contatoreDelleAzioni++;
				vuoleTornareAi2PortoniNelSaloneGrande = true;
				break;
			default:
				system("CLS");
				stampaAVideoIlTesto(sceltaSbaglaita);
				fermaCout = _getch();
				break;
			}
		}
		else {
			system("CLS");
			if (ascoltaNellaPrimaScelta == false && morteDellaDonnaCheUrlaDopoAverRiflettutoSullaVita == false) {
				stampaAVideoIlTesto(storiaPortoni11);
				sceltaDellaPortaDiSinistraDelSalonePrincipale = _getch();
				switch (sceltaDellaPortaDiSinistraDelSalonePrincipale) {
				case '1':
					contatoreDelleAzioni++;
					ascoltaNellaPrimaScelta = true;
					while (indagareSulleUrlaDellaDonna != true) {
						stampaAVideoIlTesto(storiaPortoni7);
						decidereSeIndagareSeulleUrlaDellaDonna = _getch();
						switch (decidereSeIndagareSeulleUrlaDellaDonna) {
						case '0':
							contatoreDelleAzioni++;
							aperturaDiUnaDellePorteDellaPortaDiSinistraDelSalonePrincipale(finale);
							indagareSulleUrlaDellaDonna = true;
							break;
						case '1':
							indagareSulleUrlaDellaDonna = true;
							cout << endl;
							break;

						default:
							system("CLS");
							stampaAVideoIlTesto(sceltaSbaglaita);
							fermaCout = _getch();
							break;
						}
					}
					break;

				case '2':
					contatoreDelleAzioni++;
					stampaAVideoIlTesto(storiaPortoni8);
					aperturaDiUnaDellePorteDellaPortaDiSinistraDelSalonePrincipale(finale);
					break;

				case '3':
					contatoreDelleAzioni++;
					cout << endl << endl;
					aperturaDiUnaDellePorteDellaPortaDiSinistraDelSalonePrincipale(finale);
					break;

				case '4':
					// finale 1
					morteDellaDonnaCheUrlaDopoAverRiflettutoSullaVita = true;
					stampaAVideoIlTesto(storiaPortoni9);
					if (ascoltaNellaPrimaScelta == true) {
						morteDellaDonnaDopoAverSentitoLeUrla = true;
						stampaAVideoIlTesto(storiaPortoni10);
					}
					stampaAVideoIlTesto(premiUnTasto);
					fermaCout = _getch();
					break;

				case '5':
					contatoreDelleAzioni++;
					vuoleTornareAi2PortoniNelSaloneGrande = true;
					break;
				default:
					system("CLS");
					stampaAVideoIlTesto(sceltaSbaglaita);
					fermaCout = _getch();
					break;
				}
			}
			else {
				system("CLS");
				if (morteDellaDonnaCheUrlaDopoAverRiflettutoSullaVita == false) {
					stampaAVideoIlTesto(storiaPortoni12);
				}
				else {
					stampaAVideoIlTesto(storiaPortoni13);
				}
			}

			sceltaDellaPortaDiSinistraDelSalonePrincipale = _getch();
			switch (sceltaDellaPortaDiSinistraDelSalonePrincipale) {
			case '1':
				contatoreDelleAzioni++;
				stampaAVideoIlTesto(storiaPortoni8);
				aperturaDiUnaDellePorteDellaPortaDiSinistraDelSalonePrincipale(finale);
				break;

			case '2':
				contatoreDelleAzioni++;
				aperturaDiUnaDellePorteDellaPortaDiSinistraDelSalonePrincipale(finale);
				break;

			case '3':
				// finale 1
				morteDellaDonnaCheUrlaDopoAverRiflettutoSullaVita = true;
				stampaAVideoIlTesto(storiaPortoni9);
				if (ascoltaNellaPrimaScelta == true) {
					morteDellaDonnaDopoAverSentitoLeUrla = true;
					stampaAVideoIlTesto(storiaPortoni14);
				}
				stampaAVideoIlTesto(premiUnTasto);
				fermaCout = _getch();
				break;

			case '4':
				contatoreDelleAzioni++;
				vuoleTornareAi2PortoniNelSaloneGrande = true;
				break;

			default:
				system("CLS");
				stampaAVideoIlTesto(sceltaSbaglaita);
				fermaCout = _getch();
				break;
			}
		}
	} while (morteDellaDonnaCheUrla != true && vuoleTornareAi2PortoniNelSaloneGrande != true);
}

bool labirintoDelleTreStanzeNelPortoneDiDestra(bool primaVoltaCheEntraNelLabirinto) {

	char fermaCout;

	/*
	Ti titrovi in una stanza quadrata con tre porte una a destra una davanti e una a sinistra [Piccolo labirinto, dopo aver aperto la porta (una qualsiasi ci si ritrova in una stanza uguale per 3 volte alla terza se non si ? fatta la combinazione corretta (che ? dx -> dx -> avanti)) si ritorner? al salone principale]
	Ti ritrovi in una stanza circolare con un altare, sembrerebbe una chiesa ma al centro c'? un mostro enorme (boss)
	1? combinazione	((dx -> dx -> avanti)).
	2? combinazione	((avanti -> avanti -> sx)) */

	// quando esce dal ciclo deve ritornare che ? entrato nella stanza del boss
	char qualePortaSceglie = 0;
	int contatoreDiQuanteStanzeSceglieDuranteIlLavirinto = 0;
	int combinazione1 = 0;
	int combinazione2 = 0;
	bool entraNellaStanzaDelBoss = true;

	if (primaVoltaCheEntraNelLabirinto == true) {

		system("CLS");
		do {
			if (contatoreDiQuanteStanzeSceglieDuranteIlLavirinto != 3) {
				if (contatoreDiQuanteStanzeSceglieDuranteIlLavirinto != 2) {
					stampaAVideoIlTesto(storiaPortoni36);
					qualePortaSceglie = _getch();
					switch (qualePortaSceglie) {
					case '1':
						contatoreDiQuanteStanzeSceglieDuranteIlLavirinto++;
						contatoreDelleAzioni++;
						break;

					case '2':
						contatoreDiQuanteStanzeSceglieDuranteIlLavirinto++;
						contatoreDelleAzioni++;
						combinazione2++;
						break;

					case '3':
						contatoreDiQuanteStanzeSceglieDuranteIlLavirinto++;
						contatoreDelleAzioni++;
						combinazione1++;
						break;

					default:
						system("CLS");
						stampaAVideoIlTesto(sceltaSbaglaita);
						fermaCout = _getch();
						break;
					}
				}
				else {
					// terza scelta della porta
					stampaAVideoIlTesto(storiaPortoni37);
					qualePortaSceglie = _getch();
					switch (qualePortaSceglie) {
					case '1':
						contatoreDiQuanteStanzeSceglieDuranteIlLavirinto++;
						contatoreDelleAzioni++;
						combinazione2++;
						break;

					case '2':
						contatoreDiQuanteStanzeSceglieDuranteIlLavirinto++;
						contatoreDelleAzioni++;
						combinazione1++;
						break;

					case '3':
						contatoreDiQuanteStanzeSceglieDuranteIlLavirinto++;
						contatoreDelleAzioni++;
						break;

					default:
						system("CLS");
						stampaAVideoIlTesto(sceltaSbaglaita);
						fermaCout = _getch();
						break;
					}
				}
			}
			else {
				contatoreDiQuanteStanzeSceglieDuranteIlLavirinto = 0;
				combinazione1 = 0;
				combinazione2 = 0;
			}
		} while (combinazione1 != 3 && combinazione2 != 3);
	}

	return entraNellaStanzaDelBoss;
}

bool portaDiDestraDelSalonePrincipale(bool primaVoltaCheEntraDalBoss, int &finale) {

	char fermaCout;

	// variabili generali
	char vuoleAnalizzareLAltare = 0;
	bool stanzaDelBoss = false;
	bool personaggioMorto = false;

	// variabili di combattimento
	char sceltaNelcombattimento = 0;
	int risultatoDalLancioDelDado = 0;
	int vitaDelBoss = 200;
	int vitaTemporaneaDelPG = vitaPG;

	if (chiaveDelCuoco == true || godMod == true) {
		if (primaVoltaCheEntraDalBoss == true) {
			stanzaDelBoss = labirintoDelleTreStanzeNelPortoneDiDestra(primaVoltaCheEntraDalBoss);
			primaVoltaCheEntraDalBoss = false;
			// combattimento
			system("CLS");
			stampaAVideoIlTesto(storiaPortoni26);
			do {
				stampaAVideoIlTesto(attaccaSchiva);
				sceltaNelcombattimento = _getch();
				switch (sceltaNelcombattimento) {
				case '1':
					// attacco del PG
					contatoreDelleAzioni = contatoreDelleAzioni + 0.5;
					stampaAVideoIlTesto(combattimento1);
					risultatoDalLancioDelDado = lanciaDado(20);
					if (risultatoDalLancioDelDado >= 13) {
						vitaDelBoss = vitaDelBoss - dannoPG;
						stampaAVideoIlTesto(combattimento14);
						cout << vitaDelBoss << " hp" << endl;
						stampaAVideoIlTesto(premiUnTasto);
						fermaCout = _getch();
						cout << endl;
					}
					else {
						stampaAVideoIlTesto(combattimento3);
						fermaCout = _getch();
						cout << endl;
					}

					// attacco del Boss
					if (vitaDelBoss > 0) {
						contatoreDelleAzioni = contatoreDelleAzioni + 0.5;
						risultatoDalLancioDelDado = lanciaDado(20);
						if (risultatoDalLancioDelDado >= statistichePG[2]) {
							if (vitaDelBoss > 50) {
								vitaTemporaneaDelPG = vitaTemporaneaDelPG - 15;
								stampaAVideoIlTesto(combattimento4);
								cout << vitaTemporaneaDelPG << " hp" << endl;
								stampaAVideoIlTesto(premiUnTasto);
								fermaCout = _getch();
							}
							else {
								stampaAVideoIlTesto(combattimento4);
								cout << vitaTemporaneaDelPG << "hp" << endl;
								stampaAVideoIlTesto(premiUnTasto);
								fermaCout = _getch();
								cout << endl;
							}
							cout << endl;
						}
						else {
							stampaAVideoIlTesto(combattimento5);
							fermaCout = _getch();
							cout << endl;
						}
					}
					break;

				case '2':
					// attacco del Boss
					contatoreDelleAzioni = contatoreDelleAzioni + 0.5;
					risultatoDalLancioDelDado = lanciaDado(17);
					if (risultatoDalLancioDelDado >= statistichePG[2]) {
						vitaTemporaneaDelPG = vitaTemporaneaDelPG - 15;
						stampaAVideoIlTesto(combattimento4);
						cout << vitaTemporaneaDelPG << " hp" << endl;
						stampaAVideoIlTesto(premiUnTasto);
						fermaCout = _getch();
						cout << endl;
					}
					else {
						stampaAVideoIlTesto(combattimento5);
						fermaCout = _getch();
						cout << endl;
					}

					// attacco PG dopo la schivata
					if (vitaTemporaneaDelPG > 0) {
						contatoreDelleAzioni = contatoreDelleAzioni + 0.5;
						stampaAVideoIlTesto(combattimento1);
						risultatoDalLancioDelDado = lanciaDado(20);
						if (risultatoDalLancioDelDado >= 13) {
						vitaDelBoss = vitaDelBoss - dannoPG;
						stampaAVideoIlTesto(combattimento14);
						cout << vitaDelBoss << " hp" << endl;
						stampaAVideoIlTesto(premiUnTasto);
						fermaCout = _getch();
						cout << endl;
						} else {
							stampaAVideoIlTesto(combattimento5);
							fermaCout = _getch();
							cout << endl;

							// 2° attacco del Boss
							if (vitaDelBoss > 0) {
								contatoreDelleAzioni = contatoreDelleAzioni + 0.5;
								risultatoDalLancioDelDado = lanciaDado(25);
								if (risultatoDalLancioDelDado >= statistichePG[2]) {
									if (vitaDelBoss > 50) {
										vitaTemporaneaDelPG = vitaTemporaneaDelPG - 15;
										stampaAVideoIlTesto(combattimento4);
										cout << vitaTemporaneaDelPG << " hp" << endl;
										stampaAVideoIlTesto(premiUnTasto);
										fermaCout = _getch();
										cout << endl;
									}
									else {
										vitaTemporaneaDelPG = vitaTemporaneaDelPG - 23;
										stampaAVideoIlTesto(combattimento15);
										cout << vitaTemporaneaDelPG << " hp" << endl;
										stampaAVideoIlTesto(premiUnTasto);
										fermaCout = _getch();
									}
									cout << endl;
								}
								else {
									stampaAVideoIlTesto(combattimento5);
									fermaCout = _getch();
									cout << endl;
								}
							}
						}
					}
					break;

				default:
					system("CLS");
					stampaAVideoIlTesto(sceltaSbaglaita);
					fermaCout = _getch();
					break;
				}
			} while (vitaTemporaneaDelPG >= 0 && vitaDelBoss > 0);
			system("CLS");
			if (vitaTemporaneaDelPG <= 0) {
				morteDellaDonnaCheUrla = true;
				fineDellaStoriaDelGrandeSalone = true;
				system("CLS");
				finale = 4;
				stampaAVideoIlTesto(storiaPortoni27);
				fermaCout = _getch();
			}
			else {
				system("CLS");
				do {
					stampaAVideoIlTesto(storiaPortoni28);
					vuoleAnalizzareLAltare = _getch();
				} while (vuoleAnalizzareLAltare != '1' && vuoleAnalizzareLAltare != '0');

				if (vuoleAnalizzareLAltare == '1') {
					haAnalizzatoLAtlare = true;
					chiaveArruginita = true;
					system("CLS");
					stampaAVideoIlTesto(storiaPortoni29);
					fermaCout = _getch();
				}
				else {
					system("CLS");
					stampaAVideoIlTesto(storiaPortoni30);
					fermaCout = _getch();
				}
			}
		}
		else {
			if (haAnalizzatoLAtlare == true) {
				system("CLS");
				stampaAVideoIlTesto(storiaPortoni31);
				fermaCout = _getch();
			}
			else {
				system("CLS");
				do {
					stampaAVideoIlTesto(storiaPortoni32);
					vuoleAnalizzareLAltare = _getch();
				} while (vuoleAnalizzareLAltare != '1' && vuoleAnalizzareLAltare != '0');

				if (vuoleAnalizzareLAltare == '1') {
					haAnalizzatoLAtlare = true;
					chiaveArruginita = true;
					system("CLS");
					stampaAVideoIlTesto(storiaPortoni33);
					fermaCout = _getch();
				}
				else {
					system("CLS");
					stampaAVideoIlTesto(storiaPortoni34);
					fermaCout = _getch();
				}
			}
		}
	}
	else {
		stampaAVideoIlTesto(storiaPortoni35);
		fermaCout = _getch();
	}
	vuoleTornareAi2PortoniNelSaloneGrande = true;
	return primaVoltaCheEntraDalBoss;
}

int inizioStoria() {

	int finale;

	char fermaCout;

	bool inizioAvventura = false; //effettivamente non serve a nulla e' solo per cercare di rendere le cose un po' piu' divertenti ed interessanti
	char sceltaDellInizioAvventura; // anche questa variebile e' totalmete inutile ma creata per lo stecco discorso della precedente
	while (inizioAvventura != true) {
		stampaAVideoIlTesto(inizioStoria1);
		sceltaDellInizioAvventura = _getch();
		switch (sceltaDellInizioAvventura) {
		case '1':
			inizioAvventura = true;
			stampaAVideoIlTesto(inizioStoria2);
			fermaCout = _getch();
			break;

		case '0':
			inizioAvventura = true;
			stampaAVideoIlTesto(inizioStoria3);
			fermaCout = _getch();
			break;

		default:
			system("CLS");
			stampaAVideoIlTesto(sceltaSbaglaita);
			break;
		}
	}
	system("CLS");

	// inizio della storia
	bool esaminazioneDellePorte = false;
	bool primaVoltaCheEntraNelPortoneDiDestra = true;
	char sceltaDellaPortaPrincipale = '0';
	do {
		if (esaminazioneDellePorte == false && vuoleTornareAi2PortoniNelSaloneGrande == false) {
			stampaAVideoIlTesto(storiaPortoni1);
			sceltaDellaPortaPrincipale = _getch();
			switch (sceltaDellaPortaPrincipale) {
			case '1':
				contatoreDelleAzioni++;
				stampaAVideoIlTesto(storiaPortoni2);
				fermaCout = _getch();
				esaminazioneDellePorte = true;
				break;

			case '2':
				contatoreDelleAzioni++;
				portaDiSinistraDelSalonePrincipale(finale);
				break;

			case '3':
				contatoreDelleAzioni++;
				primaVoltaCheEntraNelPortoneDiDestra = portaDiDestraDelSalonePrincipale(primaVoltaCheEntraNelPortoneDiDestra, finale);
				break;

			default:
				system("CLS");
				stampaAVideoIlTesto(sceltaSbaglaita);
				break;
			}
		}
		else {
			if (esaminazioneDellePorte == false) {
				system("CLS");
				stampaAVideoIlTesto(storiaPortoni3);
				sceltaDellaPortaPrincipale = _getch();
				switch (sceltaDellaPortaPrincipale) {
				case '1':
					contatoreDelleAzioni++;
					stampaAVideoIlTesto(storiaPortoni4);
					fermaCout = _getch();
					esaminazioneDellePorte = true;
					break;

				case '2':
					contatoreDelleAzioni++;
					portaDiSinistraDelSalonePrincipale(finale);
					break;

				case '3':
					contatoreDelleAzioni++;
					primaVoltaCheEntraNelPortoneDiDestra = portaDiDestraDelSalonePrincipale(primaVoltaCheEntraNelPortoneDiDestra, finale);
					break;

				default:
					system("CLS");
					stampaAVideoIlTesto(sceltaSbaglaita);
					break;
				}
			}
			else {
				system("CLS");
				stampaAVideoIlTesto(storiaPortoni5);
				sceltaDellaPortaPrincipale = _getch();
				switch (sceltaDellaPortaPrincipale) {
				case '1':
					contatoreDelleAzioni++;
					portaDiSinistraDelSalonePrincipale(finale);
					break;

				case '2':
					contatoreDelleAzioni++;
					primaVoltaCheEntraNelPortoneDiDestra = portaDiDestraDelSalonePrincipale(primaVoltaCheEntraNelPortoneDiDestra, finale);
					break;

				default:
					system("CLS");
					stampaAVideoIlTesto(sceltaSbaglaita);
					break;
				}
			}
		}
	} while (fineDellaStoriaDelGrandeSalone != true);

	return finale;
}
