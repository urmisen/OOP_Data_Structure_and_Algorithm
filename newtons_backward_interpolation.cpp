#include<iostream>
using namespace std;

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
/*Backward Difference */
 for (int i = 1; i < n; i++) {   /*column*/
    for (int j = n - 1; j >= i; j--)  /*row*/
        /* y[3][1] = y[3][0] - y[2][0] */
        y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
	}
 cout << endl << "BACKWARD DIFFERENCE TABLE :\n" << endl;
 for(i = 0; i < n; i++)
 {
  cout << x[i];
  for(j = 0; j <= i ; j++)
  {
   cout << "\t" << y[i][j];
  }
  cout << endl;
 }
    float x_val;
    cout<<"\nEnter the value of x: "<<endl;
    cin>>x_val;
    float h= (x[1] - x[0]);
    float sum = y[n - 1][0];
	float p2 = (x_val - x[n - 1]) / (x[1] - x[0]);
	for (int i = 1; i < n; i++) {
		sum = sum + (p_value_backword(p2, i) * y[n - 1][i]) / factorial(i);
	}
    cout << "\nBackward Interpolation Value at " << x_val << " is "
    << sum << endl;
    return 0;
}
