#include <iostream>
#include<fstream> 
#include <stdlib.h> //atoi, system("CLS")

using namespace std;

void ifstreamfail(ifstream &read);
int meny();
int ifinputfail();
double meancalc(double sum,int index);
void fileinfo(int index, double medelvarde);
void preview(string vektor[], int ageVektor[], int index);
void inputnew(ofstream &write,string vektor[], int ageVektor[], int &j, int &n);
double sumcalculation(int ageVektor[], double sum, int index);
void output(int n, int index, double medelvarde);
void search(string vektor[], int ageVektor[], string searchname[], int searchage[], int &c, int index);
void searchresults(int c, string searchname[], int searchage[]);

int main() {
	string vektor[50];
	int ageVektor[50];
	char ask = 'y';
	int choice;
	int index = 0;
	double medelvarde;
	double sum;
	
	ifstream read("elevinfo.txt");//skapa stream från fil
	ifstreamfail(read);//om streamen failar
	
	string tempstring; //temporär string 
	while(getline(read,vektor[index])){ //lägg in fil i vektorerna
		getline(read,tempstring);
		ageVektor[index]=atoi(tempstring.c_str()); //gör om stringen till int
		index++;
	}
	
	read.close();//stäng streamen
	
	sum=sumcalculation(ageVektor,sum,index);//räkna ut summan
	medelvarde=meancalc(sum,index);//räkna ut medel
	
	while(ask=='y' || ask =='Y'){
		choice = meny(); //förhandsvisning/lägg till nya namn/sök
		choice = ifinputfail();//felhantering
	
		switch(choice){
			case 1:{
				system("CLS");//rensa skärm
				fileinfo(index,medelvarde);//filinfo
				preview(vektor, ageVektor,index);//förhandsvisning av fil
		  		break;
			}
			case 2:{
				int j = index++; //ser till att vektorn inte skrivs över
				int n = 0;
				ofstream write("elevinfo.txt",ios::app); //öppna stream till filen (ios:app gör att filen inte skrivs över)
				system("CLS"); // rensa skärm
				inputnew(write,vektor,ageVektor,n,j);//lägg in nya namn och åldrar
				sum=sumcalculation(ageVektor,sum,index);//räkna om summa
				medelvarde=meancalc(sum,index);//räkna om medel
				output(n,index,medelvarde);//skriv ut uppdaterad filinfo
				write.close();//stäng streamen
				break;
			}
			
			case 3:{
				int c; //antal hittade namn 
				string searchname[50];
				int searchage[50];
				
				system("CLS");//rensa skärm
				search(vektor, ageVektor,searchname,searchage,c, index);//sök efter namn
				searchresults(c, searchname, searchage);//presentera resultat
				break;		
			}
			default:{
			system("CLS");
			cout << "Fel val, v\x84lj mellan 1-3";
			
			break;
			}
		}
		cout << endl << "Vill du g\x86 tillbaka till menyn? (Y/n): ";
		cin >> ask;
		system("CLS");
	}	
	cout << "programmet avslutas!";
	
}

/*_____________________________*/
/*funktioner				   */

//felhantering om filen inte finns
void ifstreamfail(ifstream &read){
	if (!read){
		cout << "FIL KUNDE INTE HITTAS! F\x94r att skapa en ny fil vid namn elevinfo.txt, v\x84lj alternativ 2." << endl
		<< endl;
	}
	return;
}

int meny(){ 
	int choice;
	cout << "==========="
	<< endl<< "   MENY    "
	<< endl<< "==========="
	<< endl << "1. F\x94rhandsvisa filen" 
	<< endl << "2. L\x84gg till nya personer i filen" 
	<< endl << "3. S\x94k"<< endl;
	cin >> choice; 
	return choice;
}

//Felhantering felaktig input
int ifinputfail(){  
	int val;
	while (!(cin)){
		cin.clear();
		cin.ignore(1000,'\n');
		cout << "Felinmatning, v\x84nligen f\x94rs\x94k igen: ";
		cin >> val; 
		return val;
	}
}		

//uträkning medelvärde
double meancalc(double sum, int index){ 
	double medelvarde =0;
	medelvarde = sum/index;
	return medelvarde;
}

//filinformation, medelvärde av ålder och antal personer i fil	
void fileinfo(int index, double medelvarde){ 
	cout <<"Det finns " << index << " personer i filen." << endl;
	cout <<"Medelv\x84rde av \x86lder: "<<medelvarde << " \x86r." << endl << endl;
	return;
}

//förhandsvisning av filen som är inläst i listan
void preview(string vektor[], int ageVektor[], int index){ 
	for(int i=0;i<index;i++){ 
      	cout<<vektor[i] << endl;
      	cout<<ageVektor[i]<<endl;
	}
	return;   
}

//lägg till nya personer och tillhörande ålder
void inputnew(ofstream &write, string vektor[], int ageVektor[], int &n, int &j){
	char ask2='y';
	n =0;
	while (ask2=='y' || ask2=='Y'){
		cout << "Ange namn (F\x94rnamn Efternamn): ";
		cin.ignore();//rensa cin
		cin.clear();
		n++;
		getline(cin,vektor[j]); //lägg in namn i vektorn
		write << vektor[j] << endl;//lägg in namn och endl i filen
		cout << "Ange \x86lder: ";
		cin >> ageVektor[j],50; //lägg in ålder in i vektorn
		while (!(cin)){ //felhantering om det inte är en int
			cin.clear();
			cin.ignore(1000,'\n');
			cout << "Felinmatning, v\x84nligen f\x94rs\x94k igen: ";
			cin >> ageVektor[j],50;
		}	
		write << ageVektor[j] << endl;//lägg in åldern i filen
		cout << "L\x84gg till fler namn? (Y/n): ";
		cin >> ask2;
	}
	return;
}

//uträkning av summan
double sumcalculation(int ageVektor[], double sum, int index){
	sum= 0;
	for (int i=0; i<index; i++){
		sum+=ageVektor[i];
	}
	return sum;
}

//utskrift antal namn tillagda, total antal namn, nytt medelvärde
void output(int n, int index, double medelvarde){
	cout << "Antal namn tillagda till fil: " << n << endl;
	cout << "Totalt antal namn i fil: " << index << endl;
	cout << "Ny medel\x86lder: " << medelvarde;
	return;
}

//sök för- eller/och efternamn
void search(string vektor[], int ageVektor[], string searchname[], int searchage[],int &c, int index){		
	c=0; //antal hittade namn nollställs
	string searchword; 
	cin.ignore(1000,'\n');
	cout << "S\x94k f\x94r- och/eller efternamn (stor begynnelsebokstav): ";
	getline(cin,searchword); //hämta sökord	
	for (int a =0; a <index; a++){ //sök genom listan 
	if(vektor[a].find(searchword, 0)!=string::npos){
		searchname[c]=vektor[a]; //lägg in matchande namn i namn[c]
		searchage[c]=ageVektor[a]; //lägg in matchande namns ålder i alder[c]
		c++;
		}
	}
	return;
}

//utskrift sökresultat
void searchresults(int c, string searchname[], int searchage[]){
cout << "Det hittades " << c << " matchningar" << endl;
	for (int i=0; i<c; i++){ 
	cout << searchname[i] << ", " << searchage[i] << "."<< endl;
	}
	return;
}









