#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a[10][10], group[10], total = 0;

    cout << "Enter vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for(int i = 0; i < n; i++)
    {
        group[i] = i; // Each vertex in separate group,to avoid cycles 
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    }

    // Select n-1 minimum edges without cycles
    for(int e = 0; e < n-1; e++)
    {
        int minCost = INT_MAX, u = -1, v = -1; //u,v are the endpoints 

        // Find smallest edge between different groups
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                if(a[i][j] > 0 && a[i][j] < minCost
                   && group[i] != group[j]) // Check for a positive-weight edge;Find the smallest edge;Prevent cycle formation
                {
                    minCost = a[i][j];
                    u = i;
                    v = j;
                }

        if(u == -1)
        {
            cout << "Graph is disconnected";
            return 0;
        }

        cout << u << " - " << v << " : " << minCost << endl;
        total += minCost; // Add weight

        // Merge groups to avoid cycles
        int old = group[v], now = group[u];
        for(int i = 0; i < n; i++)
            if(group[i] == old)
                group[i] = now;
    }

    cout << "Minimum cost = " << total;
    return 0;
}
