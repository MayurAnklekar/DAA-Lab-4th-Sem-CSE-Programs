#include<bits/stdc++.h>
using namespace std;


vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> bfs;
    vector<int> vis(V+1, 0);

    for(int i=1; i<=V; i++)
    {
        if(!vis[i])
        {
            queue<int> q;
            q.push(i);
            vis[i]=1;
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                for(auto it: adj[node])
                {
                    if(!vis[it])
                    {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }
    return bfs;
}

void dfs(int node, vector<int> adj[],vector<int> &vis, vector<int> &storeDfs)
{
    storeDfs.push_back(node);
    vis[node] = 1;
    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            dfs(it, adj, vis, storeDfs);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> storeDfs;
    vector<int> vis(V+1, 0);
    int cnt=0;
    for(int i=1;i<=V;i++)
    {
        if(!vis[i])
        {
            cnt++;
            dfs(i, adj, vis, storeDfs);
        }
    }
    if(cnt==1)
    {
        cout<<"Graph is connected"<<endl;
    }
    else
    {
        cout<<"Graph is not connected"<<endl;
        cout<<"The graph has "<<cnt<<" components"<<endl;
    }
    return storeDfs;
}

int main()
{
    int V, E;
    cout<<"Enter the number of vertices:";
    cin>>V;
    cout<<"Enter the number of edges:";
    cin>>E;
    vector<int> adj[V+1];
    cout<<"Enter the edges";
    for(int i=0; i<E; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=V;i++)
        sort(adj[i].begin(), adj[i].end());
    
    vector<int> DFS = dfsOfGraph(V, adj);
    vector<int> BFS = bfsOfGraph(V, adj);

    cout<<"BFS Traversal\n";
    for(auto it:BFS)
        cout<<it<<" ";
    cout<<endl;

    cout<<"DFS Traversal\n";
    for(auto it:DFS)
        cout<<it<<" ";
    cout<<endl;

    
}