#include<bits/stdc++.h>
#include <iostream>
#include<vector>
using namespace std;


int main(){

    //Format: vector<DataType> Nameofvector
    //myvector.push_back(value) ==> adds an element to the vector (also resizes it.
    //myvector.at(index) ==>> returns element at specified index number.
    //myvector.size() ==> returns an unsigned int equal top the number of elements.


    vector<int> myvector;
    myvector.push_back(3);
    myvector.push_back(7);
    myvector.push_back(4);
    myvector.push_back(12);
    myvector.push_back(9);

    cout<<"Vector :";
    for(unsigned int i=0;i<myvector.size();i++){
        cout<<myvector[i]<<" ";
    }

    cout<<endl;

    //myvector.insert(myvector.begin() + integer, new value) ==> adds elements before specified index number.
    //myvector.begin() ==> reads vector from first element(index 0).

    myvector.insert(myvector.begin()+3,5);

    cout<<"Vector :";
    for(unsigned int i=0;i<myvector.size();i++){
        cout<<myvector[i]<<" ";
    }

    cout<<endl;

    //myvector.erase(myvector.begin()+integer) ==> removes elements at  specified index number.
    myvector.erase(myvector.begin()+4);
    cout<<"Vector :";
    for(unsigned int i=0;i<myvector.size();i++){
        cout<<myvector[i]<<" ";
    }

    cout<<endl;

    //myvector.clear()==> removes all elements in vector
    //myvector.empty() ==> returns booleans value if wheather vector is empty
    myvector.clear();
    if(myvector.empty()){
        cout<< "Is Empty.";
    }
    else{
        cout<< "Is Not Empty.";
    }


    return 0;
}

