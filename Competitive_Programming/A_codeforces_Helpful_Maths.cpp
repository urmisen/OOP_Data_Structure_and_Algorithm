#include<bits/stdc++.h>
#include <iostream>
#include<string>
#include<sstream>
using namespace std;




int main(){
    string str;
    int len, index_min, temp;
    cin>>str;
    len=str.length();

    for (int i=0;i<len-1;i++){
        if(str[i]=='1' || str[i]=='2' || str[i]=='3' || str[i]=='+'){
            //selection sort
            for(int i=0;i<len-1;i+=2){
                index_min=i;
                for(int j=i+2;j<len;j+=2){
                    if(str[j]<str[index_min]){
                        index_min=j;
                    }
                }
                if(index_min!=i){
                    temp=str[i];
                    str[i]=str[index_min];
                    str[index_min]=temp;
                }
            }
        }
    }
    cout<<str;

    return 0;

}
