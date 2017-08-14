#include <iostream>
#include <sstream> //stringstream 
#include <limits> //numeric limits
#include <Windows.h>//system("cls")
#include <iomanip> //setw() och setprecision()
using namespace std;

//funktion för inmatning av tal
string matain(string tal){
	cout << "Mata in \x94nskat antal tal med enter eller mellanslag emellan: ";
	getline(cin, tal); 
	return tal;
}

//funktion för uträkning av summan
double utsum(int vektor[], int index){
	double sum;
	sum = 0;
	for (int j=0; j < index; j++){
		sum += vektor[j];
	}
	return sum;
}

//funktion för sortering av vektor
int sortering(int index, int vektor[]){
	int v; //index i vektorn som pekar ut två element 
	int h; //v för vänster h höger
	int temp; //temporär lagring av värden
	
	for (v = 0; v <= index; v++){
		for (h = v+1; h <= index-1; h++){
			if (vektor[h] < vektor[v]){ //om h är mindre än v, byt plats
				temp = vektor[v];
				vektor[v]=vektor[h];
				vektor[h] = temp;
			}
		}
	}
	return 0;
}

//funktion för att skriva ut sorterad vektor
int sorterad(int vektor[], int index){
	cout << endl << "Inmatade tal: ";
	for (int j = 0; j < index; j++){
		cout << vektor[j] << " ";
	}
	return 0;
}

//funktion för att ta bort värden ur vektorn innan omstart
int bytutvektor(int index, int vektor[]){
	for (int f = 0; f < sizeof(index); f++) { 
        	vektor[f] = '\0';
	}
	return 0;
}

//välkommen-banner
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
		tal = matain(tal); //mata in en sträng med tal
		stringstream stream(tal); //gör om strängen till en strängstream
		
		int tal, index = 0; 
		
		while(stream >> tal){ //fyll vektorn med värden från streamen
        	vektor[index] = tal; 
        	index++;
    	}
 		if ( index == 1 ) { //om användaren anger enter efter första talet
			while ( tal != 0 ) {
				cout << "Mata in tal " << j << " (avsluta med 0): "; 
				cin >> tal;
						
				while (!(cin)){ //felhantering vid felaktig input
					cin.clear(); 
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
					cout <<"Felaktig inmatning, mata in tal " << j <<" p\x86 nytt: ";
					cin >> tal; //mata in på nytt
				}
				if (tal != 0){ //för att den avslutande nollan inte ska läggas in i vektorn
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
		system("CLS"); //rensa skärmen
	}
	
	cout << "Programmet avslutas!" ;
	Sleep(600);
}


	
	
	
	
	
