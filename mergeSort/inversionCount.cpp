//Que : count the no of pair where i<j and a[i]>a[j]

#include <iostream>
using namespace std;

int merge(int *a, int s, int e)
{
    int mid = (s + e) / 2;
    /* to merge the two parts s->mid,mid+1 -> e
    we need three pointers */
    int i = s;       //point at start of first half of a[]
    int j = mid + 1; //point at start of other half of a[]
    int k = s;       //point to new temp array where we will save the merge and sorted array

    int temp[100]; //making temperary array
    int cnt = 0; // to count the cross inversion
    while (i <= mid and j <= e)
    {
        if (a[i] < a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
            cnt += mid - i + 1;
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
    return cnt;

}

int inversion_count(int a[], int s, int e)
{
    if (s >= e)
    {
        return 0;
    }

    int mid = (s + e) / 2;
    int x = inversion_count(a, s, mid);  // count inversion in first part   
    int y = inversion_count(a, mid + 1, e); // count inversion in second part
    int z = merge(a, s, e); // cross inversion
    return x+y+z;
}

int main()
{
    int a[]={5,2,3,1,4};
    int n = 5;
    cout<<inversion_count(a,0,n-1); // output will be 6
    return 0;
}