#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, p[10], m[10][10] = {0}, s[10][10] = {0};

    cout << "Enter number of matrices: ";
    cin >> n;

    // Enter dimensions of matrices (n matrices need n+1 dimensions)
    for (int i = 0; i <= n; i++)
        cin >> p[i];

    // Calculate chains (smalller first then larger)
    for (int d = 1; d < n; d++)
    {
        for (int i = 1; i <= n - d; i++)
        {
            int j = i + d; //ending matrix (chain ends here)
            m[i][j] = 999999; // temp large value to find minimum

            // Trying every split (k tells where to split the chain like A1 × (A2 × A3) or (A1 × A2) × A3)
            for (int k = i; k < j; k++)
            {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]; // Cost of multiplying the two resulting matrices

                // Replace it if the new cost is smaller
                if (cost < m[i][j])
                {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    // Print minimum cost for the full chain
    cout << "Minimum multiplication cost = " << m[1][n];

    return 0;
}

// tc = O(n^3) and sc = O(n^2)