#include<bits/stdc++.h>
using namespace std;
//Topological sort of a directed acyclic graph
//Time complexity: O(V+E)
//Space complexity: O(V+E)
//V: number of vertices
//E: number of edges
//Topological sort is a linear ordering of vertices such that for every directed edge uv, vertex u comes before v in the ordering.
//Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge uv, vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.


//Topological sort using BFS

vector<int> topoSortBfs(int V, vector<int> adj[])
{
    vector<int> indegree(V+1, 0);
    for(int i=1;i<=V;i++)
    {
        for(auto it: adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=0;i<V;i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }
    vector<int> topo;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it: adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
                q.push(it);
        }
    }
    return topo;
}

int main()
{
    int v, e;
    cout<<"Enter number of vertices: ";
    cin>>v;
    cout<<"Enter number of edges: ";
    cin>>e;
    vector<int> adj[v+1];
    cout<<"Enter the edges: ";
    for(int i=0; i<e; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int> topo = topoSortBfs(v, adj);
    cout<<"Topological sort of the graph is: ";
    for(auto it: topo)
        cout<<it<<" ";
    return 0;
}