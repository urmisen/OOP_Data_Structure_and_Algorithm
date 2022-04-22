#include<iostream>
#include<iomanip>
#include<math.h>

using namespace std;

int main()
{
 int i,j, n;
 cout<< setprecision(4)<< fixed;
 cout << "Enter the number of data points : ";
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

 cout<<"--------------------------------------------------------"<<endl;
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
    cout<<"\nEnter the value of x: ";
    cin>>x_val;
    int ind = 0;
    while (ind < n)
    {
        if (x[ind] == x_val) {
            break;
        }
        ind++;
    }
    cout<<ind;
    float sum1 = y[ind][0];
    float h= (x[1] - x[0]);
    float p1 = (x_val - x[0]) /h ;
    for (int i = 1; i < n; i++) {
        if(i%2 != 0){
            sum1 = sum1 - ((1/(i+1)) * y[ind][i])/h;
        }
        else{
            sum1 = sum1 + ((1/(i+1)) * y[ind][i])/h;
        }
    }
    int in=2;
    cout<<y[ind][in]<<endl;
    cout<<y[ind][in+1]<<endl;
    cout<<y[ind][in+2]<<endl;
    cout<<y[ind][in+3]<<endl;
    float sum2 = ( y[ind][in] - y[ind][in+1] + (y[ind][in+2] * 11 / 12) -
                  (y[ind][in+3] * 5 / 6)) / (h *h);

    cout << "\nFirst Order Differentiation of " << x_val << " is "<< sum1;

    cout << "\nSecond Order Differentiation of " << x_val << " is "<< sum2;
    return 0;
}
