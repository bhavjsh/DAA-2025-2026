#include <bits/stdc++.h>
using namespace std;

int factorial(int number)
{
    if(number==0 || number==1)  // base case
        return 1;
    else
        return number*factorial(number-1);  // recursive call
}

int main()
{
    int number;

    cout << "Enter number: ";
    cin >> number;  // input number

    cout << "Factorial=" << factorial(number);  // calling recursive function
    
    return 0;
}