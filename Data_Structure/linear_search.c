int linear_search(int arr[],int n, int x){
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            return i
        }
        i=-1
    }
    return i
