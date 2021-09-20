#include<iostream>
using namespace std;

class Shape{
public:
    int a;
    int b;
    void get_data(int n,int m){
        a=n;
        b=m;
        }
};

class Rectangle:public Shape{
public:
    int rectangle_area(){
            float result=a*b;
            return result;
            }
};

class Triangle:public Shape{
public:
    int traiangle_area(){
            float result=0.5*a*b;
            return result;
            }
};

int main(){

Rectangle rec;
Triangle tri;

int length,breadth,base,height;
cout<<"Enter the length and breadth of a rectangle :"<<endl;
cin>>length>>breadth;
rec.get_data(length,breadth);
int m=rec.rectangle_area();
cout<<"Area of the rectangle is :"<<m<<endl;

cout<<"Enter the base and height of a rectangle :"<<endl;
cin>>base>>height;
tri.get_data(base,height);
int n=tri.traiangle_area();
cout<<"Area of the triangle is :"<<n<<endl;

return 0;
}







