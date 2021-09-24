#include<iostream>
using namespace std;

void selectionSort(int *a,int n){
    for(int i=0;i<n-1;i++){// for example : '1 '3 '2 '5 4 we need to iterate i till n-2 th index
        int minElement=i; // default index of min element
        
        for(int j=i+1;j<n;j++){ //and 1 3, 2, 5, 4, so we need to iterate j from i+1 to n-1th index
            if(a[j]<a[i]){
                minElement = j;//updating the index of min element
            }
        }
        int temp = a[i];  // swaping the value
        a[i]=a[minElement];
        a[minElement]=temp;
    }

}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    selectionSort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}