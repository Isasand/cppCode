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
	
	ifstream read("elevinfo.txt");//skapa stream fr�n fil
	ifstreamfail(read);//om streamen failar
	
	string tempstring; //tempor�r string 
	while(getline(read,vektor[index])){ //l�gg in fil i vektorerna
		getline(read,tempstring);
		ageVektor[index]=atoi(tempstring.c_str()); //g�r om stringen till int
		index++;
	}
	
	read.close();//st�ng streamen
	
	sum=sumcalculation(ageVektor,sum,index);//r�kna ut summan
	medelvarde=meancalc(sum,index);//r�kna ut medel
	
	while(ask=='y' || ask =='Y'){
		choice = meny(); //f�rhandsvisning/l�gg till nya namn/s�k
		choice = ifinputfail();//felhantering
	
		switch(choice){
			case 1:{
				system("CLS");//rensa sk�rm
				fileinfo(index,medelvarde);//filinfo
				preview(vektor, ageVektor,index);//f�rhandsvisning av fil
		  		break;
			}
			case 2:{
				int j = index++; //ser till att vektorn inte skrivs �ver
				int n = 0;
				ofstream write("elevinfo.txt",ios::app); //�ppna stream till filen (ios:app g�r att filen inte skrivs �ver)
				system("CLS"); // rensa sk�rm
				inputnew(write,vektor,ageVektor,n,j);//l�gg in nya namn och �ldrar
				sum=sumcalculation(ageVektor,sum,index);//r�kna om summa
				medelvarde=meancalc(sum,index);//r�kna om medel
				output(n,index,medelvarde);//skriv ut uppdaterad filinfo
				write.close();//st�ng streamen
				break;
			}
			
			case 3:{
				int c; //antal hittade namn 
				string searchname[50];
				int searchage[50];
				
				system("CLS");//rensa sk�rm
				search(vektor, ageVektor,searchname,searchage,c, index);//s�k efter namn
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

//utr�kning medelv�rde
double meancalc(double sum, int index){ 
	double medelvarde =0;
	medelvarde = sum/index;
	return medelvarde;
}

//filinformation, medelv�rde av �lder och antal personer i fil	
void fileinfo(int index, double medelvarde){ 
	cout <<"Det finns " << index << " personer i filen." << endl;
	cout <<"Medelv\x84rde av \x86lder: "<<medelvarde << " \x86r." << endl << endl;
	return;
}

//f�rhandsvisning av filen som �r inl�st i listan
void preview(string vektor[], int ageVektor[], int index){ 
	for(int i=0;i<index;i++){ 
      	cout<<vektor[i] << endl;
      	cout<<ageVektor[i]<<endl;
	}
	return;   
}

//l�gg till nya personer och tillh�rande �lder
void inputnew(ofstream &write, string vektor[], int ageVektor[], int &n, int &j){
	char ask2='y';
	n =0;
	while (ask2=='y' || ask2=='Y'){
		cout << "Ange namn (F\x94rnamn Efternamn): ";
		cin.ignore();//rensa cin
		cin.clear();
		n++;
		getline(cin,vektor[j]); //l�gg in namn i vektorn
		write << vektor[j] << endl;//l�gg in namn och endl i filen
		cout << "Ange \x86lder: ";
		cin >> ageVektor[j],50; //l�gg in �lder in i vektorn
		while (!(cin)){ //felhantering om det inte �r en int
			cin.clear();
			cin.ignore(1000,'\n');
			cout << "Felinmatning, v\x84nligen f\x94rs\x94k igen: ";
			cin >> ageVektor[j],50;
		}	
		write << ageVektor[j] << endl;//l�gg in �ldern i filen
		cout << "L\x84gg till fler namn? (Y/n): ";
		cin >> ask2;
	}
	return;
}

//utr�kning av summan
double sumcalculation(int ageVektor[], double sum, int index){
	sum= 0;
	for (int i=0; i<index; i++){
		sum+=ageVektor[i];
	}
	return sum;
}

//utskrift antal namn tillagda, total antal namn, nytt medelv�rde
void output(int n, int index, double medelvarde){
	cout << "Antal namn tillagda till fil: " << n << endl;
	cout << "Totalt antal namn i fil: " << index << endl;
	cout << "Ny medel\x86lder: " << medelvarde;
	return;
}

//s�k f�r- eller/och efternamn
void search(string vektor[], int ageVektor[], string searchname[], int searchage[],int &c, int index){		
	c=0; //antal hittade namn nollst�lls
	string searchword; 
	cin.ignore(1000,'\n');
	cout << "S\x94k f\x94r- och/eller efternamn (stor begynnelsebokstav): ";
	getline(cin,searchword); //h�mta s�kord	
	for (int a =0; a <index; a++){ //s�k genom listan 
	if(vektor[a].find(searchword, 0)!=string::npos){
		searchname[c]=vektor[a]; //l�gg in matchande namn i namn[c]
		searchage[c]=ageVektor[a]; //l�gg in matchande namns �lder i alder[c]
		c++;
		}
	}
	return;
}

//utskrift s�kresultat
void searchresults(int c, string searchname[], int searchage[]){
cout << "Det hittades " << c << " matchningar" << endl;
	for (int i=0; i<c; i++){ 
	cout << searchname[i] << ", " << searchage[i] << "."<< endl;
	}
	return;
}









