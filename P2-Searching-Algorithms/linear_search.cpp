#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size,array[100],data,i;

    cout << "Enter the size of the array: ";
    cin >> size;   // input array size

    cout << "Enter the elements of the array: ";
    for (i=0;i<size;i++)
        cin >> array[i];  // take array elements

    cout << "Enter the element to search for: ";
    cin >> data;  // value to find

    for (i=0;i<size;i++)
    {
        if (array[i]==data)  // compares each element
        {
            cout << "Found at index " << i;
            break;  // stop searching
        }
        }
    }
    if (i==size)
        cout << "Not found";// if the element is not found in the array

    return 0;
}