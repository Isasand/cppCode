#include <iostream>
#include <string>

using namespace std;
int main(){

	string str= "Cisbest";

	for (int i=0; i<6; i++){//antal rader i programmet
		for (int space1=6; space1>i; space1--){//f�rsta f�ltet av spaces, b�rjar p� 6
			cout << "  ";
			}
			
		cout <<str.at(i);//en bokstav i slutet av f�rsta f�ltet av spaces
		for (int space2=0; space2<i;space2++){//mellanrummet i triangeln
			cout << "    ";
		}
		if (i==0)//f�r att Ct p� f�rsta raden inte ska synas.. kan s�kert g�ras i forloopen innan
			cout<< endl;
		else
			cout << str.at(i)<< endl;//h�r skriver jag ut efter mellanrummet p� resten av raderna 
		
	}
	for (int r=6; r>0; r--){
		cout << " "<< str.at(r);//f�rsta delen av ordet bakl�nges
	}
	for (int t=0; t<7;t++){
		cout << " "<< str.at(t);//ordet 
	}
}




/*		   C
         i   I
    	s       s
      b           b
    e               e
  s                   s
t s e b s i C i s b e s t*/
