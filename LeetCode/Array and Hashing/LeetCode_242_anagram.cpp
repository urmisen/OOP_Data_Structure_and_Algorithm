#include<bits/stdc++.h>
#include<string>
using namespace std;

#define NO_OF_CHARS 256

bool isAnagram(string s, string t) {
        unordered_map<char, int> hm;

        int l1 = s.length();
        int l2 = t.length();

        if(l1!=l2){
            return false;
        }

        for (auto i : s) {
            hm[i]++;
        }


        for (auto i : t) {
            hm[i]--;

            if(hm[i] < 0)
                return false;
        }

        return true;

    }
//time complexity ==> O(s+t)= O(n)
//space complexity ==> O(s+t)= O(n)

bool areAnagram(string str1, string str2)
{

    int l1 = str1.length();
    int l2 = str2.length();

    if(l1!=l2){
        return false;
    }

    // Sort both the strings
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    for(int i=0;i<l1;i++){
        if(str1[i]!=str2[i])
            return false;
    }

    return true;
}

//time complexity ==> O(n log n)
//space complexity ==> O(1)

//without hashmap

bool areAnagram3(string str1, string str2)
{
    int l1=str1.length();
    int l2= str2.length();

    if(l1!=l2){
        return false;
    }

    // Create a count array and initialize all values as 0
    int count[NO_OF_CHARS] = { 0 };

    for(int i=0;str1 && str2;i++){
        count[str1[i]]++;
        count[str2[i]]--;
    }

    if(str1[i] || str2[i]){
        return false;
    }

    for (i = 0; i < NO_OF_CHARS; i++){
        if (count[i])
            return false;
    }
    return true;

}
int main ()
{
        string str1 = "geeksforgeeks";
        string str2 = "forgeeksgeeks";

        // Function call
        if (isAnagram(str1, str2))
            cout<<"The two strings are anagram of each other"<<endl;
        else
            cout<<"The two strings are not anagram of each other"<<endl;

        return 0;
}




