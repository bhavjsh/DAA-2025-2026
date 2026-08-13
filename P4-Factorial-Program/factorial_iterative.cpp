#include <bits/stdc++.h>
using namespace std;

int main()
{
    int number, factorial = 1;
    cout << "Enter number: ";
    cin >> number;  // input number

    for (int i=1;i<=number;i++) //multiplying using for loop
    factorial=factorial*i;

    cout << "Factorial=" << factorial;

    return 0;
}