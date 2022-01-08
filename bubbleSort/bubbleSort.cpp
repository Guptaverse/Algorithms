#include<iostream>
using namespace std;

void bubbleSort(int a[],int n){
    if(n==1){
        return;
    }
    // after you have moved the largest element in the current parat to the end of the array by pairwise swap
    for(int j=0;j<n;j++){
        if(a[j]>a[j+1]){
            swap(a[j],a[j+1]);
        }

    }
    bubbleSort(a,n-1); // sort the first n-1 elements 
}
 
//  it is faster because it is completely recursive
void bubbleSort_recursive(int a[],int j,int n){
    if(n==1){
        return ;
    }
    if(j==n-1){
        return bubbleSort_recursive(a,0,n-1);
    }
    if(a[j]>a[j+1]){
        swap(a[j],a[j+1]);
    }
    bubbleSort_recursive(a,j+1,n);
    return ;

}




int main(){
    int a[] = {5,4,3,1,2};
    int n=5;
    // bubbleSort(a,n);
    bubbleSort_recursive(a,0,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}