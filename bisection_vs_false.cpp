#include<iostream>
#include<iomanip>
#include<math.h>

#define f(x) x*x*x - 2*x - 5

using namespace std;

int Bisection(float x0,float x1, float e){
     float x, f0, f1, f,count=0;
     int step = 1;
     f0 = f(x0);
	 f1 = f(x1);

	 if( f0 * f1 > 0.0)
	 {
		  cout<<"Incorrect Initial Guesses."<< endl;
	 }
	 cout<<"\nBisection Method"<< endl;
	 do
	 {    x = (x0 + x1)/2;
		  f = f(x);

		  cout<<"Iteration-"<< step<<":\t x = "<< setw(10)<< x<<" and f(x) = "<< setw(10)<< f(x)<< endl;
		  if( f0 * f < 0)
		  {
			   x1 = x;
		  }
		  else
		  {
			   x0 = x;
		  }
		  step = step + 1;
		  count++;
	 }while(fabs(f)>e);
	 cout<< endl<< "Root is: "<<  x<< endl;
	 return count;
}

int False_Position(float x0,float x1, float e){
     float x, f0, f1, f,count=0;
     int step = 1;
     f0 = f(x0);
	 f1 = f(x1);

	 if( f0 * f1 > 0.0)
	 {
		  cout<<"Incorrect Initial Guesses."<< endl;

	 }
	 cout<<"\nFalse Position Method"<< endl;
	 do
	 {
		  x = x0 - (x0-x1) * f0/ (f0-f1);
		  f = f(x);
		  cout<<"Iteration-"<< step<<":\t x = "<< setw(10)
		  << x<<" and f(x) = "<< setw(10)<< f(x)<< endl;
		  if( f0 * f < 0)
		  {
			   x1 = x;
			   f1 = f;
		  }
		  else
		  {
			   x0 = x;
			   f0 = f;
		  }
		  step = step + 1;
		  count++;
	 }while(fabs(f)>e);

	 cout<< endl<<"Root is: "<< x<< endl;
	 return count;
    }

int main(){
     float x0, x1, e, step1,step2;

     cout<< setprecision(6)<< fixed;

	 up:
	 cout<<"Enter first guess: ";
     cin>>x0;
     cout<<"Enter second guess: ";
     cin>>x1;
     cout<<"Enter tolerable error: ";
     cin>>e;
     step1=Bisection(x0,x1,e);
     step2=False_Position(x0,x1,e);
     if(step1<step2){
        cout<<endl<<"Here,As The Number of Iteration In Case of Bisection Method Is Less Than False-Position Method."
        <<endl<<"Thus For This Example, Bisection Method Performed Better Than False-Position Method"<<endl;;
     }
     if(step1>step2){
        cout<<endl<<"Here,As The Number of Iteration In Case of False-Position Method Is Less Than Bisection Method."
        <<endl<<"Thus For This Example, False-Position Method Performed Better Than Bisection Method"<<endl;
     }
     if(step1==step2){
        cout<<endl<<"Here,As The Number of Iteration In Case of False-Position Method Is Same As Bisection Method."
        <<endl<<"Thus For This Example,False-Position Method and Bisection Method Performed The same "<<endl
        <<"Thus, We Can Choose Anyone of These Methods"<<endl;
     }

     return 0;
     }
