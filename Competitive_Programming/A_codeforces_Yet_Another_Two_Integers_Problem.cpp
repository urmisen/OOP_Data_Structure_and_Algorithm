
#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int main(){
    int t,a,b;
    int left,count=0;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a>>b;
        if(a==b){
            count=0;
        }
        if(b>a){
            left=(b-a);
            if(left>10 && (left%10)==0){
                count=(left/10);
            }
            if(left>10 && (left%10)!=0){
                count=(left/10)+1;
            }
        }

        if(b<a){
            left=(a-b);
            if(left>10 && (left%10)==0){
                count=(left/10);
            }
            if(left>10 && (left%10)!=0){
                count=(left/10)+1;
            }
        }
    }

    cout<<count;

    return 0;
}

//Accepted
#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int main()
{
	long long int t;
	cin>>t;

	while(t--){
		long long int a,b;
		cin>>a>>b;

		long long int x=abs(a-b);
		cout<<x/10+(x%10!=0)<<endl;
	}

	return 0;
}







