#include<iostream>
#include<unordered_set>

using namespace std;
int main(){
    unordered_set<int> s;
    s.insert(10);
    s.insert(5);
    s.insert(15);
    s.insert(25);
    //begin(), end(), auto
    for(auto it=s.begin();it!=s.end();it++){
        cout<<(*it)<<endl;
    }
    //size()
    cout<<"No of Element: "<<s.size()<<endl;

    //find()
    int key=25;
    if(s.find(key)==s.end()){
        cout<<"key Not found."<<endl;
    }
    else{
            cout<<"key found."<<endl;
            auto temp = s.find(key);
            s.erase(temp);
            cout<<"No of Elements after deletion of the found element : "<<s.size()<<endl;

    }

    //delete()
    int del_key=15;
    s.erase(del_key);
    cout<<"No of Elements after deletion: "<<s.size()<<endl;

    //count()
    if(s.count(5)){
        cout<<"Key found"<<endl;
    }
    else{cout<<"Key Not found"<<endl;
    }
    //clear()
    s.clear();
    cout<<"No of Element: "<<s.size()<<endl;


return 0;
}
