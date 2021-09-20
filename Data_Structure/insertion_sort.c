void insertion_sort(int arr[], int n){
    for(i=1;i<n;i++){
        item=arr[i]
        j=i-1
        while(j>=0 && item<arr[j]){
            arr[j+1]=arr[j]
            j=j-1
        }
        arr[j+1]=item
    }
