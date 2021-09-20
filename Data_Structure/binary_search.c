int binary_search(int arr[],int left,int right, int x){
    if(right>1){
        mid=left+right/2

        if(arr[mid]==x)
            return mid
        if(arr[mid]<x){
            left=mid+1
        }
        if(arr[mid]>x){
            right=mid-1
        }
        return binary_Search(arr[], left, right, x);
    }

    return -1

}
