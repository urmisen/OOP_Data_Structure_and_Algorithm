#include<iostream>


using namespace std;
int main()
{
 int n, i;


 cout<<"Enter the number of data points: ";
 cin>>n;
 float x[n], y[n], sumX=0, sumX2=0, sumY=0, sumXY=0,sumX3=0,sumX4=0,sumX2Y=0, a, b, c;

 cout<<"Enter data:"<< endl;

 for(i=1;i<=n;i++)
 {
  cout<<"x["<< i <<"] = ";
  cin>>x[i];
  cout<<"y["<< i <<"] = ";
  cin>>y[i];
 }

 for(i=1;i<=n;i++)
 {
  sumX = sumX + x[i];
  sumX2 = sumX2 + x[i]*x[i];
  sumX3 = sumX3 + x[i]*x[i]*x[i];
  sumX4 = sumX4 + x[i]*x[i]*x[i]*x[i];
  sumY = sumY + y[i];
  sumXY = sumXY + x[i]*y[i];
  sumX2Y = sumX2Y + x[i]*x[i]*y[i];
 }

 c = ((sumX*sumX2 - n*sumX3)*(sumX*sumY - n*sumXY) - (sumX2*sumY - n*sumX2Y)*(sumX*sumX - n*sumX2))/((sumX*sumX2 - n*sumX3)*(sumX*sumX2 - n*sumX3) - (sumX2*sumX2 - n*sumX4)*(sumX*sumX - n*sumX2));
 b = ((sumX*sumY - n*sumXY)-(sumX*sumX2 - n*sumX3))/(sumX*sumX - n*sumX2);
 a = (sumY - b*sumX-c*sumX2)/n;

 cout<<"\nValue of a is : "<< a <<endl<<"Value of b is "<< b <<endl<<"Value of c is "<< c<<endl;
 cout<<"Best straight line fit : y = "<< a <<" + "<< b<<"x"<<" + "<< c<<"x^2"<<endl;

 return(0);
}
