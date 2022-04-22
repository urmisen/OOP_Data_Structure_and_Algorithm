#include<iostream>

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


/* Forward Interpolation */

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

/*Backward Difference */
 for (int i = 1; i < n; i++) {   /*column*/
		for (int j = n - 1; j >= i; j--)  /*row*/
			y[j][i] = y[j][i - 1] - y[j - 1][i - 1];   /* y[3][1] = y[3][0] - y[2][0] */
	}

 cout << endl << "BACKWARD DIFFERENCE TABLE" << endl;

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
    cout<<"Enter the value of x: "<<endl;
    cin>>x_val;

    float sum1 = y[0][0];
    float h= (x[1] - x[0]);
    float p1 = (x_val - x[0]) /h ;
    for (int i = 1; i < n; i++) {
        sum1 = sum1 + (p_value_forward(p1, i) * y[0][i]) /
                                 factorial(i);
    }

    cout << "\nForward Interpolation Value at " << x_val << " is "<< sum1 << endl;


    float sum2 = y[n - 1][0];
	float p2 = (x_val - x[n - 1]) / (x[1] - x[0]);
	for (int i = 1; i < n; i++) {
		sum2 = sum2 + (p_value_backword(p2, i) * y[n - 1][i]) /
									factorial(i);
	}

    cout << "\nBackward Interpolation Value at " << x_val << " is "<< sum2 << endl;



    return 0;
}
