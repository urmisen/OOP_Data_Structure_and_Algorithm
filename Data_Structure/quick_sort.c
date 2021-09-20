void quick_sort(int arr[],int low, int high){
    if(low>=high){
        return;
    }

    int p;
    p=partition(arr,low,high)

    quick_sort(arr[],low,p-1)
    quick_sort(arr[],p+1,high)
}

int partition(int arr[],int low, int high){

pivot=arr[high]
for(i=low-1;j=low;j<high;j++}{
if(arr[j]<pivot){
    i++;
    temp=arr[j]
    arr[j]=arr[i]
    arr[i]=temp
}
}

temp=arr[high]
arr[high]=arr[i+1]
arr[i+1]=temp

}
