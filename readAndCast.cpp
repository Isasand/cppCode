#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

char ReadChar();
int ReadInt();
float ReadFloat();
void CastChar(int, float, char);
void CastInt(char, float, int);
void CastFloat(int, char, float);

int main(){
	char c,tempchar;
	int a, tempint;
	float b, tempfloat, floatsqrt;
	c=ReadChar();
	a=ReadInt();
	b=ReadFloat();
	
	CastChar(tempint, tempfloat, c);
	CastInt(tempchar, tempfloat, a);
	CastFloat(tempint,tempchar,b);

}


char ReadChar(){
	char c;
	cout << "Input a single character: ";
	cin >> c;
	return c;
}

int ReadInt(){
	int a;
	cout << "Input an integer: ";
	cin >> a;
	return a;
}

float ReadFloat(){
	float b;
	cout << "Input a float: ";
	cin >> b;
	return b;
}

void CastChar(int tempint, float tempfloat, char c){
	tempint=c;
	tempfloat=c;
	cout << endl << "the character "<< c << " casted to an int gives the value: " << tempint;
	cout << endl << "the character "<< c << " casted to a float gives the value: "<< setprecision(2)<< setiosflags(ios::fixed)<< tempfloat;
}

void CastInt(char tempchar, float tempfloat, int a){
	tempchar=a;
	tempfloat=a;
	cout << endl << "the integer " << a << " casted to a char gives the value: " << tempchar;
	cout << endl << "the integer " << a << " casted to a float gives the value: "<< tempfloat;
	
}

void CastFloat(int tempint, char tempchar, float b){
	tempint=b;
	tempchar=b;
	cout << endl << "the float "<< b << " casted to an integer gives the value: "<< tempint;
	cout << endl << "the float "<< b << " casted to a char gives the value: "<< tempchar;
}
