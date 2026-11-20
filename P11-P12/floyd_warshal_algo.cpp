#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, dist[10][10];

    cout << "Enter vertices: ";
    cin >> n;

    cout << "Enter matrix (999 for no path):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dist[i][j];

    // Find shortest paths
    for (int middle = 0; middle < n; middle++) // Try each middle vertex
        for (int start = 0; start < n; start++) // Starting vertex
            for (int end = 0; end < n; end++) // Ending vertex
            {
                // Check if route through middle exists
                if (dist[start][middle] != 999 && dist[middle][end] != 999)
                {
                    int newDist = dist[start][middle] + dist[middle][end];

                    // Update if new route is shorter
                    if (newDist < dist[start][end])
                        dist[start][end] = newDist;
                }
            }

    cout << "Shortest distances:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << dist[i][j] << " ";
        cout << endl;
    }

    return 0;
}
