#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, capacity;
    int weight[10], profit[10];
    int dp[11][1001] = {0}; //base case 

    // Number of items and bag capacity
    cout << "Enter number of items: ";
    cin >> n;

    // Taking weight of each item
    cout << "Enter weights: ";
    for (int i = 0; i < n; i++)
        cin >> weight[i]; //stores each item's weight

    // Taking profit of each item
    cout << "Enter profits: ";
    for (int i = 0; i < n; i++)
        cin >> profit[i];

    cout << "Enter bag capacity: ";
    cin >> capacity; // max wt a bag can carry 

    // 0 capacity means 0 profit
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    // 0 items means 0 profit
    for (int j = 0; j <= capacity; j++)
        dp[0][j] = 0;

    // Filling  the DP table , max profit using first i items with capacity j
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            // If item can fit, choose take or don't take
            if (weight[i - 1] <= j) // checks whether the current item's weight is less than or equal to the current capacity
            {
                dp[i][j] = max(
                    dp[i - 1][j],
                    profit[i - 1] + dp[i - 1][j - weight[i - 1]]
                ); // take choice with greate rprofit   
            }
            else
            {
                // Item is too heavy then don't take it
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Last cell contains maximum profit
    cout << "Maximum profit = " << dp[n][capacity];

    return 0;
}

// TC & SC : O(n × capacity)