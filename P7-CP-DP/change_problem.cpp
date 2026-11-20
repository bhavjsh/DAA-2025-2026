    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        int n,amount;
        int coins[10], dp[100]; 

        cout <<"Enter number of coins: ";
        cin >> n;

        cout <<"Enter coin values: ";
        for(int i=0;i<n;i++)
            cin >> coins[i]; //stores each coin value in the array

        cout <<"Enter amount: ";
        cin >> amount;

        dp[0] = 0; // base case, one way to make amount 0, 0 coins needed to make amnt 0

        for (int i=1; i<=amount;i++){
            dp[i] = amount + 1; // Start with a large value (assume)
            for (int j=0;j<n;j++){
                if (coins[j] <= i) // Checks whether the current coin can be used for the amount we are trying to make
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1);
            }
        }
        cout <<"Minimum coins required: " << dp[amount] << endl;

        return 0;
    }

    // tc = O(n*amount) and sc = O(amount)