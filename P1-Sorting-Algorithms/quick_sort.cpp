#include <bits/stdc++.h>
using namespace std;

int divide(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;

    // Move smaller values to the left
    for (int j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(int a[], int low, int high)
{
    if (low >= high)
        return;

    int p = divide(a, low, high);

    quickSort(a, low, p - 1);
    quickSort(a, p + 1, high);
}

int main()
{
    int n, a[100];

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    quickSort(a, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}

// Choose a pivot and place smaller elements on its left and larger elements on its right.
// Average Time Complexity: O(n log n)
// Worst Time Complexity: O(n²)
// Space Complexity: O(log n) (recursive stack)

// ------- OUTPUT -------
//PS C:\Users\Bhavini\DAA-2025-2026\P1-Sorting-Algorithms> g++ quick_sort.cpp -o quick_sort
//PS C:\Users\Bhavini\DAA-2025-2026\P1-Sorting-Algorithms> .\quick_sort
//Enter the number of elements: 6
//Enter the elements: 2 86 42 6 25 0
//Sorted array: 0 2 6 25 42 86 