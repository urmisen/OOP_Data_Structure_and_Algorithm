void selection_sort(int arr[],int n){
    int i,j,index_min,temp;
    for(i=0;i<n-1;i++){
        index_min=i
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[index_min]){
                index_min=j
            }
        }
        if(index_min!=i){
            temp=arr[i]
            arr[i]=arr[index_min]
            arr[index_min]=temp
        }
    }

}
