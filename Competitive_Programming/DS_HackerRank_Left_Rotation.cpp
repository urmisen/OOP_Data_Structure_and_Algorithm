#include<bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> rotateLeft(int d, vector<int> arr) {
    vector<int> res;
    for(unsigned int i=d;i<arr.size();i++){
        res.push_back(arr[i]);
        }

    for(unsigned int i=0;i<d;i++){
        res.push_back(arr[i]);
        }
    return res;

}



