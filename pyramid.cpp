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
    void setx (float x) {m_bredd=x;}; //tilldelar de privata medlemmarna värden
    void sety (float y) {m_hojd=y;};
    float area (){return m_bredd*m_bredd;} //uträkning av arean
    float Volym(){return (m_bredd*m_bredd*m_hojd)/3;}//uträkning av volym
    void change(float x, float y){ //byter plats på bredd och höjd
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
    pyramid hej[29]; //objekt från klassen pyramid instansieras 
    int rand_number;
    int rand_number2;
    float rand_float;
    float rand_hojd;
    float rand_bredd;;
    int antal = 0;
    int j=1;//counter för vilken pyramid i ordningen som visas
    
    cout <<"Hur m\x86nga pyramider ska skapas? (1-30): ";
    cin >> antal;

    
    for (int i = 0; i <antal; i++){
        setnumber(rand_number);//skapar två random nummer
        setnumber(rand_number2);
        rand_float = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);//genererar ett nummer mellan 0.0 och 1.0
        rand_bredd=rand_number/rand_float;//delar random bredd och höjd med floaten för att få ett random decimaltal
        rand_hojd=rand_number2/rand_float;
        hej[i].setx(rand_bredd);//lägger in random bredd och höjd i pyramid-klassen
        hej[i].sety(rand_hojd);
    }
    
    for (int i=0; i <antal; i++){//utskrift av mått på de skapade pyramiderna, samt area, volym och ny höjd och bredd efter change();
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
    randomnumber=rand()%50;//rand()%50 används för att skapa en random int mellan 0-49
    while (randomnumber == 0){//om numrerna blir 0 eller mindre så gör vi om, pyramiden kan inte vara negativ
        randomnumber= rand()%50;
    }
}

