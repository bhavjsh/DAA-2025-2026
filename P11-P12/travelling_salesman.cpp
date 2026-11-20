#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a[10][10], city[10], minCost = INT_MAX;

    cout << "Enter cities: ";
    cin >> n;

    cout << "Enter cost matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    for(int i = 0; i < n-1; i++)
        city[i] = i+1; // Cities except starting city 0

    do
    {
        int cost = 0, prev = 0; // Start from city 0

        for(int i = 0; i < n-1; i++)
        {
            cost += a[prev][city[i]]; // Add travel cost
            prev = city[i]; // Move to next city
        }

        cost += a[prev][0]; // Return to starting city
        minCost = min(minCost, cost); // Update minimum cost

    } while(next_permutation(city, city+n-1)); // Try all routes

    cout << "Minimum cost = " << minCost;
    return 0;
}
