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

    // finds the min element and place it at the correct position
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }

        swap(a[i], a[min]);
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}

// Time Complexity: O(n²)
// Space Complexity: O(1)

// ------- OUTPUT -------
//PS C:\Users\Bhavini\DAA-2025-2026\P1-Sorting-Algorithms> g++ selection_sort.cpp -o selection_sort
//PS C:\Users\Bhavini\DAA-2025-2026\P1-Sorting-Algorithms> .\selection_sort
//Enter the number of elements: 3
//Enter the elements: 89545 624 894298
//Sorted array: 624 89545 894298 