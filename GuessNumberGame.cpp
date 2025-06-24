#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;


int chosen_number(int diff){
   int num;
    switch (diff)
    {
    case(1):
        num=rand()%10+1;
        break;

    case(2):
        num=rand()%20+1;
        break;

    case(3):
        num=rand()%50+1;
        break;

    default:
    cout<<"scegli un numero tra 1/2/3 per scegliere la difficoltà corrisondente.";
        break;
    }

    return num;
}
void win_check(int tries, int choice, int number){
    if (choice==number){
       cout<<"congratulazioni, hai indovinato il numero segreto: "<<number<<endl;
    }else{
        cout<<"hai perso, questo era il numero segreto: "<<number<<endl;
    }
}
void hint(int number){
    string hint;
    string ans;
    cout<<"vuoi un indizio(si/no)? ";
    cin>>ans;
    if(ans=="si"){
        if (number%2==0){
            hint="pari";
         }else{
            hint="dispari";
        }
        cout<<"il numero è "<<hint<<endl;
    }
}

int main(){

    int difficulty;
    int number;
    int choice;
    int tries=0;

    srand(time(0));

    cout<<"scegli la difficoltà (1/2/3):"<<endl;
    cout<<"1. facile     (1-10)\n";
    cout<<"2. medio      (1-20)\n";
    cout<<"3. difficile  (1-50)\n";

    cin>>difficulty;
  
    number=chosen_number(difficulty);
   
    hint(number);

    cout<<"prova a indovinare: ";
    do
    {
        tries++;
        cin>>choice;

        if(choice>number){
            cout<<"troppo alto!\n";
        }else if(choice<number){
            cout<<"troppo basso!\n";
        }

        if (tries==4){
            break;
        }
    } while (choice!=number);
    
    win_check(tries,choice,number);

    return 0;
}