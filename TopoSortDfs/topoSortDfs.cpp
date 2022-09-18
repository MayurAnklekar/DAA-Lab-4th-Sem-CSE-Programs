#include<bits/stdc++.h>
using namespace std;

vector<int> topoSortDfs(int v, vector<int> adj[])
{
    vector<int> topo;
    vector<int> vis(v+1, 0);
    stack<int> st;
    for(int i=1; i<=v; i++)
    {
        if(!vis[i])
        {
            st.push(i);
            vis[i] = 1;
            while(!st.empty())
            {
                int node = st.top();
                st.pop();
                topo.push_back(node);
                for(auto it: adj[node])
                {
                    if(!vis[it])
                    {
                        st.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }
    reverse(topo.begin(), topo.end());
    return topo;

}

int main()
{
    int v,e;
    cout<<"Enter number of vertices";
    cin>>v;
    cout<<"Enter number of edges";
    cin>>e;
    vector<int> adj[v+1];
    cout<<"Enter the edges";
    for(int i=0; i<e; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int> topo = topoSortDfs(v, adj);
}