// We can only perform toposort on a directed acyclic graph (DAG).
// Toposort can be also used for cycle detection in DAG.(If final toposeq doesnt contains all nodes then cycle present)
#include <bits/stdc++.h>
using namespace std;

void topoDfs(int node, vector<bool> &visited, vector<int> &topoList, vector<vector<int>> &adj)
{
    visited[node] = true;
    for (int it : adj[node])
    {
        if (!visited[it])
        {
            topoDfs(it, visited, topoList, adj);
        }
    }
    topoList.push_back(node);
}

void topoBfs(vector<int> &inDeg, vector<int> &topoList2, vector<vector<int>> &adj)
{
    queue<int> q;
    for (int i = 0; i < adj.size(); i++)
    if (!inDeg[i]) q.push(i);
    
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topoList2.push_back(node);
        for (int it : adj[node])
        {
            inDeg[it]--;
            if (!inDeg[it])
                q.push(it);
        }
    }
}

int main()
{
    int e, v;
    cout << "Enter No of edges,Vertices:";
    cin >> e >> v;
    vector<vector<int>> adj(v);
    vector<bool> visited(v, false);
    vector<int> inDeg(v,0);
    vector<int> topoList;
    vector<int> topoList2;

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cout << "Enter edge " << i + 1 << " : ";
        cin >> u >> v;
        adj[u].push_back(v);
        inDeg[v]++;
    }
    topoDfs(0, visited, topoList, adj);
    reverse(topoList.begin(),topoList.end());
    topoBfs(inDeg, topoList2, adj);
    cout << "Topological Sort using DFS: ";
    for (int it : topoList)
    cout << it << " ";
    cout << endl;

    cout << "Topological Sort using BFS: ";
    for (int it : topoList2)
    cout << it << " ";
    cout << endl;
    return 0;
}
