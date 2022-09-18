#include<bits/stdc++.h>
using namespace std;

void findTopoSort(int node, vector<int> &vis, stack<int>&st, vector<int> adj[])
{
    vis[node] = 1;
    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            findTopoSort(it, vis, st, adj);
        }
    }
    st.push(node);
}

vector<int> topoSortDfs(int v, vector<int> adj[])
{
    stack<int> st;
    vector<int> vis(v, 0);
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        {
            findTopoSort(i, vis, st, adj);
        }
    }
    vector<int> topo;
    while(!st.empty())
    {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;

}

int main()
{
    int v,e;
    cout<<"Enter number of vertices";
    cin>>v;
    cout<<"Enter number of edges";
    cin>>e;
    vector<int> adj[v];
    cout<<"Enter the edges";
    for(int i=0; i<e; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int> topo = topoSortDfs(v, adj);
    cout<<"Topological Sort is:"<<endl;
    for(auto it: topo)
    {
        cout<<it<<" ";
    }


}