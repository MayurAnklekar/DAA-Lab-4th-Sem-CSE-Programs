#include<bits/stdc++.h>
using namespace std;
int cnt;


void merge(int arr[], int low, int mid, int high)
{
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 =  high - mid;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1+ j];
    i = 0;
    j = 0;
    k = low;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
        cnt++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
        cnt++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
        cnt++;
    }
}


void mergesort(int arr[], int low, int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        mergesort(arr, low, mid);
        mergesort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}


int main()
{
    int n;
    cout<<"Enter number of elements in array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cnt=0;
    mergesort(arr,0,n-1);
    cout<<"Sorted array is"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"The number of comparisons are "<<cnt<<endl;
    cout<<"\nSize\tAscending\tDescending\tRandom"<<endl;
    int a[1000], b[1000], c[1000];
    int c1, c2, c3;
    for(int i=16;i<=512;i*=2)
    {
        for(int j=0;j<i;j++)
        {
            a[j]=j;
            b[j]=i-j;
            c[j]=rand()%i;
        }
        cnt=0;
        mergesort(a,0,i-1);
        c1=cnt;
        cnt=0;
        mergesort(b,0,i-1);
        c2=cnt;
        cnt=0;
        mergesort(c,0,i-1);
        c3=cnt;
        cout<<i<<"\t"<<c1<<"\t\t"<<c2<<"\t\t"<<c3<<endl;
    }
}