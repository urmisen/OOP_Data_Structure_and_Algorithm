#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdlib.h>

#define   f(x)   x*x*x + x*x -1
#define   g(x)   1/sqrt(x+1)
#define   g1(x)  3*x*x + 2*x

using namespace std;

int iterative(float x0, float e, int N){
    int step=1;
    float x1;
    int count =0;
    do
	 {
		  x1 = g(x0);
		  cout<<"Iteration-"<< step<<":\t x1 = "<< setw(10)
		  << x1<<" and f(x1) = "<< setw(10)<< f(x1)<< endl;
		  step = step + 1;
		  if(step>N)
		  {
			   cout<<"Not Convergent.";
			   exit(0);
		  }

		  x0 = x1;
		  count+=1;
	 }while( fabs(f(x1)) > e);

	 cout<< endl<<"Root = "<< x1;
	 cout<<endl;
    return count;
}

int Newton_Raphson(float x0, float e, int N){
     float x1, f0, f1, g0;
	 int step = 1,count=0;
	 do
	 {
		  g0 = g1(x0);
		  f0 = f(x0);
		  if(g0 == 0.0)
		  {
			   cout<<"Mathematical Error.";
			   exit(0);
		  }
		  x1 = x0 - f0/g0;
		  cout<<"Iteration-"<< step<<":\t x = "<< setw(10)
		  << x1<<" and f(x) = "<< setw(10)<< f(x1)<< endl;
		  x0 = x1;
		  step = step+1;
		  if(step > N)
		  {
			   cout<<"Not Convergent.";
			   exit(0);
		  }
		  f1 = f(x1);
		  count+=1;
	 }while(fabs(f1)>e);
	 cout<< endl<<"Root = "<< x1;
	 cout<<endl;
	 return count;
}

    int main()
{
	 int N;
	 float x0, e;
	 cout<< setprecision(4)<< fixed;
	 cout<<"Enter initial guess: ";
	 cin>>x0;

	 cout<<"Enter tolerable error: ";
	 cin>>e;

	 cout<<"Enter maximum iteration: ";
	 cin>>N;

	 cout<<endl<<"Iteration Method : "<< endl;
	 cout<<"-------------------------------------------------------"<< endl;
	 int c1 = iterative(x0,e,N);
	 cout<<endl<<"Newton Raphson Method : "<< endl;
	 cout<<"-----------------------------------------------------"<< endl;
     int c2 = Newton_Raphson(x0,e,N);
     if(c1<c2){
        cout<<endl<<"Here,As The Number of Iteration In Case of Iterative Method Is Less Than Newton-Raphson Method."
        <<endl<<"Thus For This Example, Iteration Method Performed Better Than Newton-Raphson Method"<<endl;;
     }
     if(c1>c2){
        cout<<endl<<"Here,As The Number of Iteration In Case of Newton-Raphson Method Is Less Than Iterative Method."
        <<endl<<"Thus For This Example, Newton-Raphson Method Performed Better Than Iteration Method"<<endl;
     }
     if(c1==c2){
        cout<<endl<<"Here,As The Number of Iteration In Case of Newton-Raphson Method Is Same As Iterative Method."
        <<endl<<"Thus For This Example,Newton-Raphson Method and Iteration Method Performed The same "<<endl
        <<"Thus, We Can Choose Anyone of These Methods"<<endl;
     }
	 return(0);
}

