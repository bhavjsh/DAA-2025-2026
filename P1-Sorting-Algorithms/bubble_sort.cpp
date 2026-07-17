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

    // Bubble Sort
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}

//TC O(n²)
//SC O(1)

// ------- OUTPUT -------
//PS C:\Users\Bhavini\DAA-2025-2026\P1-Sorting-Algorithms> g++ bubble_sort.cpp -o bubble_sort
//PS C:\Users\Bhavini\DAA-2025-2026\P1-Sorting-Algorithms> .\bubble_sort
//Enter the number of elements: 5
//Enter the elements: 22 41 58 95 2        
//Sorted array: 2 22 41 58 95