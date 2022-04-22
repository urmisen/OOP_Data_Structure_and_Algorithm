#include <iostream>

using namespace std;

int main() {
	int arr[10];
	int n,x;
	cout<<"Enter the no of elements: ";
	cin>>n;
	cout<<"Enter the elements:\n";
	for(int i=0;i<n;i++){
        cin>>arr[i];
	}
	cout<<"Enter the new elements:\n";
	cin>>x;
	arr[n]=x;
	n++;
	cout<<"New array :\n";
	for(int i=0;i<n;i++){
        cout<<arr[i];
	}
    return 0;
}
