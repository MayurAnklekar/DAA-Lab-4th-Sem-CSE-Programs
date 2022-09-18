#include<bits/stdc++.h>
using namespace std;
int cnt;

// int partiton(int arr[], int left, int right)
// {
//     int pivot = arr[right];
//     int i = left-1;
//     for(int j=left; j<right; j++)
//     {
//         if(arr[j]<=pivot)
//         {
//             i++;
//             swap(arr[i], arr[j]);
//             cnt++;
//         }
//     }
//     swap(arr[i+1], arr[right]);
//     cnt++;
//     return i+1;
// }

int partiton(int arr[], int left, int right)
{
    int pivot = arr[left];
    int i = left+1;
    int j = right;
    while(i<=j)
    {
        while(arr[i]<=pivot)
        {
            i++;
            cnt++;
        }
        while(arr[j]>pivot)
        {
            j--;
            cnt++;
        }
        if(i<j)
        {
            swap(arr[i], arr[j]);
            cnt++;
        }
    }
    swap(arr[left], arr[j]);
    cnt++;
    return j;
}

void quicksort(int arr[], int left, int right)
{
    if(left<right)
    {
        int s = partiton(arr, left, right);
        quicksort(arr, left, s-1);
        quicksort(arr, s+1, right);
    }
}

int main()
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cnt=0;
    quicksort(arr, 0, n-1);
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
        quicksort(a,0,i-1);
        c1=cnt;
        cnt=0;
        quicksort(b,0,i-1);
        c2=cnt;
        cnt=0;
        quicksort(c,0,i-1);
        c3=cnt;
        cout<<i<<"\t"<<c1<<"\t\t"<<c2<<"\t\t"<<c3<<endl;
    }
}