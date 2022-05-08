#include<iostream>
#include<map>
#include<list>
#include<queue>

using namespace std;

int findJudge(int n, vector<vector<int>>& trust) {

        vector<int> data(n,0);
        for(auto x:trust){
            data[x[0]]--;
            data[x[1]]++;
        }

        for(int i=1;i<=n;i++){
            if(data[i]==n-1){
                return i;
            }
        }
        return -1;

    }

int main(){

    int n;
    vector<vector<int>>trust;

    cout<<"Enter the number of vertices : ";
    cin>>n;
    trust = {{1,3},{2,3},{3,1}};

    int ans=findJudge(n, trust);
    cout<<ans<<endl;

return 0;
}
