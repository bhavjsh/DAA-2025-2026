
    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        int n, a[10][10], visited[10] = {0}, total = 0;

        cout << "Enter vertices: ";
        cin >> n;

        // Take graph as adjacency matrix
        cout << "Enter adjacency matrix:\n";
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> a[i][j];

        visited[0] = 1; // Start from vertex 0

        for(int e = 0; e < n-1; e++) // MST needs n-1 edges
        {
            int minCost = INT_MAX; // Large value to find minimum
            int u = -1, v = -1; // Vertices of selected edge

            // Check all edges to find the smallest one
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    // From visited to unvisited, edge must exist
                    if(visited[i] && !visited[j] && a[i][j] > 0
                    && a[i][j] < minCost)
                    {
                        minCost = a[i][j]; // Save minimum weight
                        u = i; // Starting vertex
                        v = j; // Ending vertex
                    }

            if(v == -1) // No connecting edge found
            {
                cout << "Graph is disconnected";
                return 0;
            }

            visited[v] = 1; // Include new vertex in MST
            total += minCost; // Add weight to total cost

            cout << u << " - " << v << " : " << minCost << endl;
        }

        cout << "Minimum cost = " << total;
        return 0;
    }
