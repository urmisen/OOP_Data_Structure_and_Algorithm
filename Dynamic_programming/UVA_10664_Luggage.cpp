#include<iostream>
#include <sstream>
#include <string.h>
using namespace std;

int wt[21];
int C[101];
int Luggage_SubArray(int n, int W){
    int i,w;
    int K[n+1][W+1];
     for(i=0;i<=n;i++){
        for(w=0;w<=W;w++){
            if(i==0 || w==0){
                K[i][w]=0;
            }
            else if(wt[i]<=w){
                K[i][w]=max(K[i-1][w], wt[i]+K[i-1][w-wt[i]]);
            }
            else{
                K[i][w]=K[i-1][w];
            }
        }
     }
        return K[n][W];
    }
int main()
{
    int test, el, i, sum;
    string s;
    stringstream ss;
    scanf("%d", &test);getline(cin,s);
    while(test--){
        getline(cin,s);
        ss.clear();
        ss << s;
        i = 0;
        sum = 0;
        while(ss >> el){
            wt[++i] = el;
            sum += el;
        }
        if((sum % 2 )==0) {
            if(Luggage_SubArray(i, sum >> 1) == (sum >> 1))cout<<"YES\n";
            else cout<<"NO\n";
        }
        else cout<<"NO\n";

    }
    return 0;
}
