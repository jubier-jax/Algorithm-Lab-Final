#include<bits/stdc++.h>
using namespace std;

vector<int> graph[1005];
bool visited[1005];

void dfs(int node)
{
    visited[node] = true;

    for(int next : graph[node])
    {
        if(!visited[next])
        {
            dfs(next);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    for(int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int components = 0;

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(i);
            components++;
        }
    }

    cout << "Connected Components: " << components << endl;

    return 0;
}