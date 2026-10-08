#include<bits/stdc++.h>
using namespace std;

vector<int> graph[1005];
vector<int> reverseGraph[1005];

bool visited[1005];
vector<int> order;

void dfs1(int node)
{
    visited[node] = true;

    for(int next : graph[node])
    {
        if(!visited[next])
        {
            dfs1(next);
        }
    }

    order.push_back(node);
}

void dfs2(int node)
{
    visited[node] = true;

    cout << node << " ";

    for(int next : reverseGraph[node])
    {
        if(!visited[next])
        {
            dfs2(next);
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
        reverseGraph[v].push_back(u);
    }

    // Step 1: DFS and store finishing order
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs1(i);
        }
    }

    // Reset visited
    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    // Step 2: Process in reverse finishing order
    int components = 0;

    for(int i = n - 1; i >= 0; i--)
    {
        int node = order[i];

        if(!visited[node])
        {
            components++;

            cout << "Component " << components << ": ";

            dfs2(node);

            cout << endl;
        }
    }

    cout << "Total SCC: " << components << endl;

    return 0;
}