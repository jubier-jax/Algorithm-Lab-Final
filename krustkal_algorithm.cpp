#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int par[1005];
int group_size[1005];

int find(int node)
{
    if(par[node] == -1)
        return node;

    return par[node] = find(par[node]);
}

void dsu_union(int a, int b)
{
    int leaderA = find(a);
    int leaderB = find(b);

    if(group_size[leaderA] >= group_size[leaderB])
    {
        par[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}

class Edge
{
public:
    int a, b, c;

    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

bool cmp(Edge a, Edge b)
{
    return a.c < b.c;
}

int main()
{
    int n, e;
    cin >> n >> e;

    for(int i = 0; i < n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
    }

    vector<Edge> edges;

    for(int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        edges.push_back(Edge(a, b, c));
    }

    sort(edges.begin(), edges.end(), cmp);

    vector<Edge> mst;

    int totalCost = 0;

    for(auto edge : edges)
    {
        int leaderA = find(edge.a);
        int leaderB = find(edge.b);

        if(leaderA != leaderB)
        {
            dsu_union(edge.a, edge.b);

            mst.push_back(edge);
            totalCost += edge.c;

            if(mst.size() == n - 1)
                break;
        }
    }

    if(mst.size() == n - 1)
    {
        cout << "Edges in the MST:" << endl;

        for(auto edge : mst)
        {
            cout << edge.a << " "
                 << edge.b << " "
                 << edge.c << endl;
        }

        cout << "Total weight: " << totalCost << endl;
    }
    else
    {
        cout << "The graph is disconnected; no MST exists." << endl;
    }

    return 0;
}