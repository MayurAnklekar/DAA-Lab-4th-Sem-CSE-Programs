#include<bits/stdc++.h>
using namespace std;

void knapsack(int wt[], int val[], int n, int W, int dp[1000][1000])
{
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=W; j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j] = 0;
            }
            else if(wt[i-1]<=j)
            {
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
}

void optimalSolution(int dp[1000][1000], int n, int W, int wt[])
{
    if(dp[n][W]==0)
    {
        cout<<"Not possible";
        return;

    }
    cout<<"Optimal solution is "<<dp[n][W]<<endl;
    int i=n, j=W;
    cout<<"Selected Objects:";
    while(i>0 && j>0)
    {
        if(dp[i][j] == dp[i-1][j])
        {
            i--;
        }
        else
        {
            cout<<i<<" ";
            j = j-wt[i-1];
            i--;
        }
    }
}

int main()
{
    int wt[100], val[100], n;
    cout<<"Enter number of items";
    cin>>n;
    cout<<"Enter weights";
    for(int i=0; i<n; i++)
    {
        cin>>wt[i];
    }
    cout<<"Enter values";
    for(int i=0; i<n; i++)
    {
        cin>>val[i];
    }
    int W;
    cout<<"Enter capacity";
    cin>>W;
    int dp[1000][1000];
    knapsack(wt, val, n, W, dp);
    optimalSolution(dp, n, W, wt);
}