#include<iostream>
#include<iomanip>
#include<math.h>
#include<bits/stdc++.h>

using namespace std;
float p_value_forward(float p, int n)
{
    float  temp = p;
	for (int i = 1; i < n; i++){
        if(i==1)
			temp = temp * (p - i);
		else
			temp = (p+1) * temp * (p - i);
	}
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
cout<< setprecision(4)<< fixed;
/* Forward Interpolation */
 for(i = 1; i < n; i++)  /* column */
 {
  for(j = 0; j < n-i; j++) /* row */
  {
   y[j][i] = y[j+1][i-1] - y[j][i-1]; /* y[0][1] = y[1][0] - y[0][0] */
  }
 }
 cout << endl << "GAUSS'S CENTRAL FORWARD DIFFERENCE TABLE :" << endl;
 cout<<"------------------------------------------------------------"<<endl;
 for(i = 0; i < n; i++)
 {
  cout << x[i];
  for(j = 0; j < n-i ; j++)
  {
   cout << "\t" << y[i][j];
  }
  cout << endl;
 }

float value = 1.17;
float sum = y[int(n/2)][0];
float p = (value - x[int(n/2)]) / (x[1] - x[0]);
for (int i = 1; i < n; i++) {
    sum = sum + (p_value_forward(p, i) * y[int((n-i)/2)][i]) / factorial(i);
}
cout << "\nForward Interpolation Value at " << value << " is "<< sum << endl;

    return 0;
}
