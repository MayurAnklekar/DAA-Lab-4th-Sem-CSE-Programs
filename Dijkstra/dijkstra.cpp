#include<bits/stdc++.h>
using namespace std;


void dijs(int n, int s, int cost[10][10], int dist[], int p[])
{
    int visited[10], v;
    for(int i=0;i<n;i++)
    {
        visited[i] = 0;
        dist[i] = cost[s][i];
        if(dist[i]!=999)
        p[i]=s;
    }

    visited[s] = 1;
    dist[s] = 0;
    p[s] = -1;

    int cnt = 1;
    while(cnt<n)
    {
        int min = 999;
        for(int w=0;w<n;w++)
        {
            if(!visited[w]&&dist[w]<min)
            {
                min = dist[w];
                v = w;
            }
        }

        visited[v] = 1;
        cnt++;
        for(int w=0;w<n;w++)
        {
            if(!visited[w]&&dist[v]+cost[v][w]<dist[w])
            {
                dist[w] = dist[v]+cost[v][w];
                p[w] = v;
            }
        }
    }
}

int main()
{
    int n, cost[10][10], dist[10], p[10];
    cout<<"Enter the number of vertices";
    cin>>n;
    cout<<"Enter the cost of matrix"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>cost[i][j];
            if(cost[i][j]==0)
            {
                cost[i][j]=999;
            }
        }
    }
    int s;
    cout<<"Enter source vertex";
    cin>>s;
    dijs(n, s, cost, dist, p);

    for(int i=0;i<n;i++)
    {
        if(i!=s)
        {
            cout<<"Shortest path from "<<s<<" to "<<i<<" is: ";
            int j = i;
            while(j!=s)
            {
                cout<<j<<"<-";
                j = p[j];
            }
            cout<<s<<endl;
            cout<<"Shortest distance is: "<<dist[i]<<endl;
        }
    
    }
}