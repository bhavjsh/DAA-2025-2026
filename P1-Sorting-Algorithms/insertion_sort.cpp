#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a[100];

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // Insert value at correct place
    for (int i = 1; i < n; i++)
    {
        int value = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > value)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = value;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}

// TC: O(n²) - Average/Worst Case, O(n) - Best Case
// SC: O(1)

// ------- OUTPUT -------
//PS C:\Users\Bhavini\DAA-2025-2026\P1-Sorting-Algorithms> g++ insertion_sort.cpp -o insertion_sort
//PS C:\Users\Bhavini\DAA-2025-2026\P1-Sorting-Algorithms> .\insertion_sort
//Enter the number of elements: 3
//Enter the elements: 1 9 5
//Sorted array: 1 5 9 