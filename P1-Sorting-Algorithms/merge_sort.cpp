#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int left, int mid, int right)
{
    int temp[100];
    int i = left, j = mid + 1, k = left;

    // Merge both parts
    while (i <= mid && j <= right)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= right)
        temp[k++] = a[j++];

    for (int x = left; x <= right; x++)
        a[x] = temp[x];
}

void mergeSort(int a[], int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge(a, left, mid, right);
}

int main()
{
    int n, a[100];

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    mergeSort(a, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}

// Time Complexity: O(n log n)
// Space Complexity: O(n)

// ------- OUTPUT -------
//PS C:\Users\Bhavini\DAA-2025-2026\P1-Sorting-Algorithms> g++ merge_sort.cpp -o merge_sort//
//PS C:\Users\Bhavini\DAA-2025-2026\P1-Sorting-Algorithms> .\merge_sort
//Enter the number of elements: 4
//Enter the elements: 45 98 5 83
//Sorted array: 5 45 83 98 