#include<bits/stdc++.h>
using namespace std;
int x[20];

int place(int k, int i)
{
    for(int j=1;j<=k-1;j++)
    {
        if(x[j]==i||abs(x[j]-i)==abs(j-k))
        return 0;
    }
    return 1;
}

void printQueen(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(x[i]==j)
            cout<<"Q ";
            else
            cout<<"- ";
        }
        cout<<endl;
    }
    exit(0);
}


void NQueen(int k, int n)
{
    for(int i=1;i<=n;i++)
    {
        if(place(k, i))
        {
            x[k]=i;
            if(k==n)
            printQueen(n);
            else
            NQueen(k+1, n);
        }
        
    }
}

int main()
{
    int n;
    cout<<"Enter number of queens to be placed";
    cin>>n;
    if(n<=3)
    {
        cout<<"No solution exists";
        return 0;
    }
    else
    NQueen(1,n);
}