#include<iostream>
#include<unordered_map>
#include<vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;


vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>> umap;

        for(auto x:strs){
            string temp = x;
            sort(x.begin(),x.end());
            umap[x].push_back(temp);
        }

        for(auto x:umap){
            ans.push_back(x.second);
        }
        return ans;
    }

    int main(){
        vector<string> vect{ "eat","tea","tan","ate","nat","bat" };
        vector<vector<string>>temp;
        temp=groupAnagrams(vect);
        for (int i = 0; i < temp.size(); i++) {
        for (
            auto it = temp[i].begin();
            it != temp[i].end(); it++)
            cout << *it << " ";
        cout << endl;
    }

    return 0;
    }
