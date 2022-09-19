#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int> > adj[n];
    for(int i=0; i<m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int parent[n], key[n];
    bool mstSet[n];
    for(int i=0; i<n; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
        parent[i] = -1;
    }
    key[0]=0;
    parent[0]=-1;

    for(int count=0;count<n-1;count++)
    {
        int mini = INT_MAX;
        int u;
        for(int v=0;v<n;v++)
        {
            if(mstSet[v]==false && key[v]<mini)
            {
                mini = key[v];
                u = v;
            }
        }
        mstSet[u] = true;

        for(auto it: adj[u])
        {
            int v = it.first;
            int weight = it.second;
            if(mstSet[v]==false && weight<key[v])
            {
                parent[v] = u;
                key[v] = weight;
            }
        }
    }
    for(int i=1; i<n; i++)
    {
        cout<<parent[i]<<" - "<<i<<endl;
    }
    cout<<"Cost of MST is:";
    int cost=0;
    for(int i=1; i<n; i++)
    {
        cost+=key[i];
    }
    cout<<cost;
}