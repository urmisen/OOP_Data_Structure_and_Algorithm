//Enum in C++ is a data type that contains fixed set of constants.
//C++ Enums can be thought of as classes that have fixed set of constants.
#include <iostream>
using namespace std;
enum week { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };
int main()
{
    week day;
    day = Friday;
    cout << "Day: " << day+1<<endl;
    return 0;
}
