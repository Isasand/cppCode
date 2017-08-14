#include <iostream>
#include <string>

using namespace std;
int main(){

	string str= "Cisbest";

	for (int i=0; i<6; i++){//antal rader i programmet
		for (int space1=6; space1>i; space1--){//första fältet av spaces, börjar på 6
			cout << "  ";
			}
			
		cout <<str.at(i);//en bokstav i slutet av första fältet av spaces
		for (int space2=0; space2<i;space2++){//mellanrummet i triangeln
			cout << "    ";
		}
		if (i==0)//för att Ct på första raden inte ska synas.. kan säkert göras i forloopen innan
			cout<< endl;
		else
			cout << str.at(i)<< endl;//här skriver jag ut efter mellanrummet på resten av raderna 
		
	}
	for (int r=6; r>0; r--){
		cout << " "<< str.at(r);//första delen av ordet baklänges
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
