//A field which is declared as static is called static field. Unlike instance field which gets memory each time whenever you create object,
// there is only one copy of static field created in the memory. It is shared to all the objects

//It is used to refer the common property of all objects such as rateOfInterest in case of Account, companyName in case of Employee etc.
#include <iostream>
using namespace std;
class Account {
   public:
       int accno; //data member (also instance variable)
       string name; //data member(also instance variable)
       static float rateOfInterest;
       Account(int accno, string name)
        {
             this->accno = accno;
            this->name = name;
        }
       void display()
        {
            cout<<accno<<" "<<name<< " "<<rateOfInterest<<endl;
        }
};
float Account::rateOfInterest=6.5;
int main(void) {
    Account a1 =Account(201, "Sanjay"); //creating an object of Employee
    Account a2=Account(202, "Nakul"); //creating an object of Employee
    a1.display();
    a2.display();
    return 0;
}
