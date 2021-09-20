#include<iostream>
using namespace std;

class Account{
public:
    int accno;
    string name;
    static float rateOfinterest;

    Account(int accno, string name){
        this->accno=accno;
        this->name=name;

    }

    display(){
        cout<<accno<<" "<<name<<" "<<rateOfinterest<<endl;
        }

    };

float Account::rateOfinterest=6.5;

int main(){

Account a1=Account(101,"Urmi");
a1.display();
return 0;
}
