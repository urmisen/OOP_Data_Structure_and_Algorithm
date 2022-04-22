#include<iostream>
#include<iomanip>
#include<math.h>


using namespace std;


float p_value_forward(float p, int n)
{
    float temp = p;
    for (int i = 1; i < n; i++)
        temp = temp * (p - i);
    return temp;
}

float p_value_backword(float p, int n)
{
    float temp = p;
    for (int i = 1; i < n; i++)
        temp = temp * (p + i);
    return temp;
}

int factorial(int n)
{
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}

int main()
{

 int i,j, n;
 cout<< setprecision(4)<< fixed;
 cout << "Enter number of data? " << endl;
 cin >> n;
 float x[n], y[n][n];

 cout << "Enter data: " << endl;
 for(i = 0; i < n ; i++)
 {
  cout << "x[" << i << "] = ";
  cin >> x[i];
  cout << "y[" << i <<"] = ";
  cin >> y[i][0];
 }


/* Forward differenciation */

 for(i = 1; i < n; i++)  /* column */
 {
  for(j = 0; j < n-i; j++) /* row */
  {
   y[j][i] = y[j+1][i-1] - y[j][i-1]; /* y[0][1] = y[1][0] - y[0][0] */
  }
 }


 cout << endl << "FORWARD DIFFERENCE TABLE" << endl;

 cout<<"---------------------------------"<<endl;
 for(i = 0; i < n; i++)
 {
  cout << x[i];
  for(j = 0; j < n-i ; j++)
  {
   cout << "\t" << y[i][j];
  }
  cout << endl;
 }



    float x_val;
    cout<<"Enter the value of x: "<<endl;
    cin>>x_val;

    int ind = 0;
    while (ind < n)
    {
        if (x[ind] == x_val) {
            break;
        }
        ind++;
    }


    float h= (x[1] - x[0]);
    float p1 = (x_val - x[0]) /h ;
    int in=2;

    for (int i = 1; i < n; i++) {
        if(i%2 != 0){
            sum1 = sum1 - ((1/(12)) * y[ind][i+])/h;
        }
        else{
            sum1 = sum1 + ((1/(i+1)) * y[ind][i])/h;
        }

    }

    cout << "\nsecond Order Differentiation at " << x_val << " is "<< sum1 << endl;




    return 0;
}
