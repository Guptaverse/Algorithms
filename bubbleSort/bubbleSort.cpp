#include<iostream>
using namespace std;

void bubbleSort(int a[],int n){
    if(n==1){
        return;
    }
    for(int j=0;j<n;j++){
        if(a[j]>a[j+1]){
            swap(a[j],a[j+1]);
        }

    }
    bubbleSort(a,n-1);
}
int main(){
    int a[] = {5,4,3,1,2};
    int n=5;
    bubbleSort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}