#include <iostream>
#include <stdlib.h>//srand
#include <time.h>//time
#include <iomanip>//setwith, setprecision, setiosflags

using namespace std;

class pyramid{
public:
    pyramid (float X, float Y) { m_bredd = X; m_hojd = Y; };
    pyramid (){m_bredd=1; m_hojd= 1;};
    
    
    float x() const {return m_bredd;};
    float y() const {return m_hojd;};
    void setx (float x) {m_bredd=x;}; //tilldelar de privata medlemmarna v�rden
    void sety (float y) {m_hojd=y;};
    float area (){return m_bredd*m_bredd;} //utr�kning av arean
    float Volym(){return (m_bredd*m_bredd*m_hojd)/3;}//utr�kning av volym
    void change(float x, float y){ //byter plats p� bredd och h�jd
        float temp;
        temp=m_bredd;
        m_bredd=m_hojd;
        m_hojd=temp;
    }
        
    
private:
    float m_bredd;
    float m_hojd;
};

void setnumber(int &randomnumber); //funktion som skapar ett random nummer

int main(){
    srand(time(0));
    pyramid hej[29]; //objekt fr�n klassen pyramid instansieras 
    int rand_number;
    int rand_number2;
    float rand_float;
    float rand_hojd;
    float rand_bredd;;
    int antal = 0;
    int j=1;//counter f�r vilken pyramid i ordningen som visas
    
    cout <<"Hur m\x86nga pyramider ska skapas? (1-30): ";
    cin >> antal;

    
    for (int i = 0; i <antal; i++){
        setnumber(rand_number);//skapar tv� random nummer
        setnumber(rand_number2);
        rand_float = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);//genererar ett nummer mellan 0.0 och 1.0
        rand_bredd=rand_number/rand_float;//delar random bredd och h�jd med floaten f�r att f� ett random decimaltal
        rand_hojd=rand_number2/rand_float;
        hej[i].setx(rand_bredd);//l�gger in random bredd och h�jd i pyramid-klassen
        hej[i].sety(rand_hojd);
    }
    
    for (int i=0; i <antal; i++){//utskrift av m�tt p� de skapade pyramiderna, samt area, volym och ny h�jd och bredd efter change();
        cout << "M\x86tt f\x94r pyramid " << j << ": "<<
        endl << "Bredd: " << setiosflags(ios::fixed) << setw(12) << setprecision(2) << hej[i].x() << " cm" <<endl
        << "H\x94jd: " << setw(13) << setprecision(2) <<hej[i].y() << " cm" << endl
        << "Basarea: " << setw(10) << setprecision(2) << hej[i].area()<< " cm^2"<<endl
        << "Volym: " << setw(12) << setprecision(2) << hej[i].Volym()<< " cm^3" <<endl << endl
        << "Nu byter bredd och h\x94jd plats!" << endl;
        hej[i].change(rand_bredd, rand_hojd);
        cout << "Ny bredd: " << setw(9) << setprecision(2) << hej[i].x() << " cm" << endl
        << "Ny h\x94jd: " << setw(10) << setprecision(2) << hej[i].y() << " cm" << endl << endl << endl;
        j++;

    }
}

//funktioner

void setnumber(int &randomnumber){
    randomnumber=rand()%50;//rand()%50 anv�nds f�r att skapa en random int mellan 0-49
    while (randomnumber == 0){//om numrerna blir 0 eller mindre s� g�r vi om, pyramiden kan inte vara negativ
        randomnumber= rand()%50;
    }
}

