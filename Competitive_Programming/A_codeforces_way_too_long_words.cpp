#include<bits/stdc++.h>
#include <iostream>
#include<string>
#include<sstream>
using namespace std;


int main(){
    int n,mid;
    string word,output,firstchar,lastchar;

    cin>>n;
    for(int i=0;i<n;i++){
        cin >> word;
        int len = word.length();

        if(len > 10){

            len = word.length();
            mid = len-2;
            // integer to string conversion
            stringstream ss;
            ss<<mid;
            string s;
            ss>>s;
            for(int j=0;j<len;j++){
                if(j==0){
                    firstchar= word[j];
                }
                if(j==len-1){
                    lastchar= word[j];
                }

            }
            output=firstchar+s+lastchar;

            cout<<output<<"\n";
        }
        else{
            cout<<word<<"\n";
        }
    }


    return 0;
}
