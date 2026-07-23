#include <iostream>
using namespace std;

int main()
{
    int size,array[100],data;

    cout << "Enter size: ";
    cin >> size; // input  array size


    cout << "Enter sorted elements: ";
    for (int i=0;i<size;i++)
        cin >> array[i];   // take array elements

    cout << "Enter element to search: ";
    cin >> data;   // value to find

    int low=0; // first index
    int high=size-1;  // last index

    while (low<=high)
    {
        int mid=(low+high) / 2;   // middle index

        if (array[mid]==data)
        {
            cout << "Found at index " << mid;
            return 0;  // stop program
        }
        else if (data < array[mid])
            high=mid-1;  // search left half
        else
            low=mid+1;  // search right half
    }

    cout << "Not found";
    return 0;
}