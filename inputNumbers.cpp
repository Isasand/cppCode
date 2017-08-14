#include <iostream>
#include <sstream> //stringstream 
#include <limits> //numeric limits
#include <Windows.h>//system("cls")
#include <iomanip> //setw() och setprecision()
using namespace std;

//funktion f�r inmatning av tal
string matain(string tal){
	cout << "Mata in \x94nskat antal tal med enter eller mellanslag emellan: ";
	getline(cin, tal); 
	return tal;
}

//funktion f�r utr�kning av summan
double utsum(int vektor[], int index){
	double sum;
	sum = 0;
	for (int j=0; j < index; j++){
		sum += vektor[j];
	}
	return sum;
}

//funktion f�r sortering av vektor
int sortering(int index, int vektor[]){
	int v; //index i vektorn som pekar ut tv� element 
	int h; //v f�r v�nster h h�ger
	int temp; //tempor�r lagring av v�rden
	
	for (v = 0; v <= index; v++){
		for (h = v+1; h <= index-1; h++){
			if (vektor[h] < vektor[v]){ //om h �r mindre �n v, byt plats
				temp = vektor[v];
				vektor[v]=vektor[h];
				vektor[h] = temp;
			}
		}
	}
	return 0;
}

//funktion f�r att skriva ut sorterad vektor
int sorterad(int vektor[], int index){
	cout << endl << "Inmatade tal: ";
	for (int j = 0; j < index; j++){
		cout << vektor[j] << " ";
	}
	return 0;
}

//funktion f�r att ta bort v�rden ur vektorn innan omstart
int bytutvektor(int index, int vektor[]){
	for (int f = 0; f < sizeof(index); f++) { 
        	vektor[f] = '\0';
	}
	return 0;
}

//v�lkommen-banner
void valkommen(){
	cout <<"=========="<< endl << "V\x8ELKOMMEN"<< endl <<"==========" << endl;
}

int main(){
	string tal;
	char startaOm = 'y';
	double summa;
	int j = 2;
	int index;
	int vektor[99];
	
	valkommen();
	
	while (startaOm == 'y' || startaOm == 'Y'){
		tal = matain(tal); //mata in en str�ng med tal
		stringstream stream(tal); //g�r om str�ngen till en str�ngstream
		
		int tal, index = 0; 
		
		while(stream >> tal){ //fyll vektorn med v�rden fr�n streamen
        	vektor[index] = tal; 
        	index++;
    	}
 		if ( index == 1 ) { //om anv�ndaren anger enter efter f�rsta talet
			while ( tal != 0 ) {
				cout << "Mata in tal " << j << " (avsluta med 0): "; 
				cin >> tal;
						
				while (!(cin)){ //felhantering vid felaktig input
					cin.clear(); 
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
					cout <<"Felaktig inmatning, mata in tal " << j <<" p\x86 nytt: ";
					cin >> tal; //mata in p� nytt
				}
				if (tal != 0){ //f�r att den avslutande nollan inte ska l�ggas in i vektorn
					vektor[index] = tal;
					index++;
					j++;
				}
			}
		}
			
		sortering(index,vektor); //sortera vektor
		sorterad(vektor, index); //skriv ut sorterad  vektor
		summa = utsum(vektor, index);
		
		cout << endl << endl << "Summa: " << setiosflags(ios::fixed) << setprecision(0) << setw(25) << summa;
		cout << endl << "Medelv\x84rde: " << setiosflags(ios::fixed) << setprecision(2)<< setw(20) << summa/index; //skriver ut summa och medel
		cout << endl << "St\x94rsta talet: " << setiosflags(ios::fixed) << setprecision(0) << setw(17) << vektor[index-1];
		cout << endl << "N\x84st st\x94rsta talet: " << setiosflags(ios::fixed) << setprecision(0) << setw(12) << vektor[index-2];
		cout << endl << "Minsta talet: " << setiosflags(ios::fixed) << setprecision(0) << setw(18) << vektor[0];	
		cout << endl << endl << "Vill du starta om? (Y/n) ";
		cin >> startaOm;
		cin.ignore(); //rensa cin
		cin.clear();
		
		bytutvektor(index,vektor); //rensa vektorn
		system("CLS"); //rensa sk�rmen
	}
	
	cout << "Programmet avslutas!" ;
	Sleep(600);
}


	
	
	
	
	
