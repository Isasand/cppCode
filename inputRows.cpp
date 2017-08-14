#include <iostream> 
#include <stdlib.h>
#include <iomanip> //setfill(), setw()
#include <Windows.h> //Sleep()

using namespace std;

int main()  {
	
	//deklarationer
	int antal = 1;
	char ban[] = {'V','\x8E','L','K','O','M','M','E','N'};
	
	//välkommen-banner
	for (int a = 0; a < sizeof(ban);a = a + 1){
		cout << ban[a];
		Sleep(120);
	}
	
	Sleep(1000);
	system("cls");
	
	while (antal !=0){
		//ut- och inmatning
		cout << "Ange antal rader eller tryck p\x86 0 f\x94r att avsluta: ";
		cin >> antal;
	
		//felhantering
		if ((antal <0) || (!cin)){
			cin.clear();
			cin.ignore(1000, '\n');
			antal = 1;
			cout << "Felaktig inmatning" << endl;
			Sleep (1000);
		}
		/*en for-loop skriver ut antal rader och tecken baserat på input
		ett antal blanksteg allokeras med setw() (antal baseras på värdet hos 
		variabeln rader) och fylls med angivet tecken med hjälp av setfill 
		fram till output av tecken*/
		else {
			for (int rader = 1; rader<=antal; rader++){
			cout << setfill ('*') << setw(rader) << endl;
			cout << "*";
			}
		}
		cout << endl << endl;
	}
//programmet avslutas
cout << endl << "Programmet avslutas!";
Sleep(1100);
return 0;
}
