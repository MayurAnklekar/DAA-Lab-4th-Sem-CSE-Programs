#include<bits/stdc++.h>
using namespace std;
int cnt=0;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && arr[l]>arr[largest])
    {
        cnt++;
        largest = l;
    }
    if(r<n && arr[r]>arr[largest])
    {
        cnt++;
        largest = r;
    }
    if(largest!=i)
    {
        cnt++;
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap(int arr[], int n)
{
    for(int i=n/2-1; i>=0; i--)
    {
        heapify(arr, n, i);
    }
    for(int i=n-1; i>=0; i--)
    {
        cnt++;
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int n;
    cout<<"Enter number of elements";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    heap(arr, n);
    cout<<"Sorted array is: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\nNumber of counts: "<<cnt<<endl;
    cout<<"Size\tAscending\tDescending\tRandom"<<endl;
    int a[1000];
    for(int i=16;i<550;i*=2)
    {
        cnt=0;
        for(int j=0;j<i;j++)
        {
            a[j]=j;
        }
        heap(a, i);
        int c1=cnt;
        cnt=0;
        for(int j=0;j<i;j++)
        {
            a[j]=i-j;
        }
        heap(a, i);
        int c2=cnt;
        cnt=0;
        for(int j=0;j<i;j++)
        {
            a[j]=rand()%i;
        }
        heap(a, i);
        int c3=cnt;
        cout<<i<<"\t"<<c1<<"\t\t"<<c2<<"\t\t"<<c3<<endl;
    }
}