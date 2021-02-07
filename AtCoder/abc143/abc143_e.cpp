#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static const long long INF = 1ll << 50;
int n, m;
long long l;
vector<vector<long long>> edge, edge2;

int main()
{
    cin >> n >> m >> l;
    edge.resize(n, vector<long long>(n, INF));
    edge2.resize(n, vector<long long>(n, INF));
    for (int i = 0; i < n; i++)
    {
        edge[i][i] = edge2[i][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        if (l < c)
        {
            continue;
        }
        edge[--a][--b] = c;
        edge[b][a] = c;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                edge[j][k] = min(edge[j][k], edge[j][i] + edge[i][k]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j || l < edge[i][j])
                continue;
            edge2[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                edge2[j][k] = min(edge2[j][k], edge2[j][i] + edge2[i][k]);
            }
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int s, t;
        cin >> s >> t;
        if (edge2[s - 1][t - 1] == INF)
        {
            cout << "-1\n";
            continue;
        }
        cout << edge2[s - 1][t - 1] - 1 << "\n";
    }
}