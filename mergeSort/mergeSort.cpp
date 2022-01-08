#include <iostream>
using namespace std;

/* 
Merge is all about 3 steps
    1.divide
    2.Sort 
    3.merge the divided part all together again
*/

void merge(int *a, int s, int e)
{
    int mid = (s + e) / 2;
    /* to merge the two parts s->mid,mid+1 -> e
    we need three pointers */
    int i = s;       //point at start of first half of a[]
    int j = mid + 1; //point at start of other half of a[]
    int k = s;       //point to new temp array where we will save the merge and sorted array

    int temp[100]; //making temperary array
    while (i <= mid and j <= e)
    {
        if (a[i] < a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = a[i++];
    }
    while(j<=e){
        temp[k++] = a[j++];
    }
    // we need to copy all element to original array
    for( i=s;i<=e;i++){
        a[i] = temp[i];
    }

}

void mergeSort(int a[], int s, int e)
{
    if (s == e)
    {
        return;
    }

    // divide
    int mid = (s + e) / 2;
    // sort : recursively suppose a[] = 5,1,2,6,4
    mergeSort(a, s, mid);     // 1 2 5
    mergeSort(a, mid + 1, e); // 4 6
    // merge the two parts
    merge(a, s, e);
}

int main()
{
    int a[]={5,2,3,1,4};
    int n = 5;
    mergeSort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}