void Merge_sort(int arr[],int lb,int ub){
    if(lb<ub){
        mid=(lb+ub)/2

        merge_sort(arr[],lb,mid)
        merge_sort(arr[],mid+1,ub)

        merge(arr[],lb.mid,ub)
    }

int merge(arr[],lb,mid,ub){
i=lb
j=mid+1
k=lb;

while(i<=mid}&& j<=ub){
    if(a[i]<a[j]{
       b[k}=a[i];
       i++
       k++)
    else{
        b[k}=a[j];
       j++
       k++)
    }
}

if(i>mid){
    while(j<=ub){
        b[k}=a[j];
       j++
       k++
    }
}

else{
    while(i<=mid){
        b[k}=a[i];
       i++
       k++
    }
}



for(k=lb;k<-ub;k++){
    a[k]=b[k]
}
}




