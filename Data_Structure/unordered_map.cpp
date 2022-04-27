#include<iostream>
#include<unordered_map>

using namespace std;
int main(){
    unordered_map<string, int> umap;

    //insert
    umap["prince"] = 44;
    umap["gfg"] = 56;
    umap["abc"]= 90;

    //for(auto x:umap){
    //    cout<<x.first<<" "<<x.second<<endl;
    //}

    for(auto itr=umap.begin(); itr!=umap.end();itr++){
        cout<<itr->first<<" "<<itr->second<<endl;

    }
    string key ="prince";
    //find()
    if(umap.find(key)!=umap.end()){
        cout<<"key found"<<endl;
        auto temp = umap.find(key);
        cout<<"Key is :"<<temp->first<<endl;
        cout<<"Value is :"<<temp->second<<endl;
    }
    else{
            cout<<"key Not found"<<endl;
    }

    //insert()

    umap.insert(make_pair("urmi", 88));
    cout<<endl<<"After Insertion :"<<endl;

    for(auto itr=umap.begin(); itr!=umap.end();itr++){
          cout<<itr->first<<" "<<itr->second<<endl;

    }

    //size()

    cout<<"Size is : "<<umap.size()<<endl;

    //erase()
    auto del_key = "gfg";
    umap.erase(del_key);
    cout<<"After deletion  Size is : "<<umap.size()<<endl;

    //array element counts using unordered_map
    int arr[]={7,1,0,3,5,0,1,3,2,5,7,3,8,9,4,9};
    unordered_map<int, int> cnt;
    int arr_size = sizeof(arr)/sizeof(int);

    for(int i=0;i<arr_size;i++){
        int key = arr[i];
        cnt[key]++;
    }
    //print hashmap
    for(auto itr=cnt.begin();itr!=cnt.end();itr++){
        cout<<endl<<itr->first<<" "<<itr->second<<endl;
    }

return 0;
}
