#include<bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    vector<int>output;
    int count;
    long unsigned int i,j;

    for(i=0;i<queries.size();i++){
        count=0;
        for(j=0;j<strings.size();j++){
            if(queries[i]==strings[j]){
                count++;
            }
        }
        output.push_back(count);
    }

    return output;

}


