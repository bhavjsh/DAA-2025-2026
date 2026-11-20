
#include <bits/stdc++.h>
using namespace std;

int graph[10][10], visited[10], n;

// DFS(goes deep into one path first)
void DFS(int v)
{
    visited[v] = 1; // Mark current vertex as visited
    cout << v << " ";

    for (int i = 0; i < n; i++)
        if (graph[v][i] == 1 && !visited[i]) // If connected and not visited
            DFS(i); // Visit next vertex
}

// BFS(visits nearby vertices first)
void BFS(int start) //void bcoz fxn deosnt return a val
{
    queue<int> q;
    q.push(start); // Add starting vertex
    visited[start] = 1;

    while (!q.empty()) // Continue until queue is empty
    {
        int v = q.front(); // Get first vertex
        q.pop(); // Remove it
        cout << v << " ";

        for (int i = 0; i < n; i++)
            if (graph[v][i] == 1 && !visited[i]) // Check connected unvisited vertex
            {
                visited[i] = 1; // Mark as visited
                q.push(i); // Add to queue
            }
    }
}

int main()
{
    int start;

    cout << "Enter vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j]; // Read connections

    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "DFS: ";
    DFS(start); // Run DFS

    for (int i = 0; i < n; i++)
        visited[i] = 0; // Reset visited for BFS

    cout << "\nBFS: ";
    BFS(start); // Run BFS

    return 0;
}

// TC (O(V^2)) for both using an adjacency matrix