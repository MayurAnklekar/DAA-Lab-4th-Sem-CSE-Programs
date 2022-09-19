#include<bits/stdc++.h>
using namespace std;
int w[10];
int x[10];
int d;
void subset_sum(int s, int k, int r)
{
    static int b = 1;
    x[k]=1;
    if(s+w[k]==d)
    {
        cout<<"\n(Subset "<<b++<<"): ";
        for(int i=1;i<=k;i++)
        {
            if(x[i]==1)
            {
                cout<<w[i]<<" ";
            }
        }
    }
    else if(s+w[k]+w[k+1]<=d)
    {
        subset_sum(s+w[k], k+1, r-w[k]);
    }
    if((s+r-w[k]>=d)&&(s+w[k+1]<=d))
    {
        x[k]=0;
        subset_sum(s, k+1, r-w[k]);
    }
}

int main()
{
    int n, sum=0;
    cout<<"Enter the number of elements";
    cin>>n;
    cout<<"Enter the elements(in increasing order)";
    for(int i=1; i<=n; i++)
    {
        cin>>w[i];
        sum+=w[i];
    }
    cout<<"Enter the required sum";
    cin>>d;
    if(sum<d||w[1]>d)
    {
        cout<<"No subset exists";
        return 0;
    }
    subset_sum(0, 1, sum);

}