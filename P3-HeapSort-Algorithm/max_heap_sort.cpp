#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int a[100];
    cout <<"Enter size:"; //taking no. of elements
    cin >> n;

    cout <<"Enter elements:"; //taking elements
    for(int i=0;i<n;i++)
        cin >> a[i];

    //creating max heap ( biggest ele. should be at top,will start from last parent node and move towards the root node)

    for (int i=n/2 -1;i>=0;i--)
    {
        int parent=i;
        while (2 * parent + 1 < n) //continues until the current parent has no child 
        {
            int left= 2*parent + 1; //index of left child
            int right= left+1; // index of right child

            int bigger=left; //assuming left child is bigger

            if (right<n &&a[right] > a[bigger])
                bigger = right; //if right child exists is bigger, use the right child

            if (a[parent] >= a[bigger]) //if parent is bigger than both children, then break
                break;

            int temp=a[parent]; //swap parent with bigger child
            a[parent]=a[bigger];
            a[bigger]=temp;

            parent=bigger; //continue checking the heap down
        }
    }
   // sorting array , biggest ele now at a[0],move it to last position & create heap for rest of the elements

   for (int last=n-1;last>0;last--)
   {
    int temp=a[0]; //move biggest element to last position
    a[0]=a[last];
    a[last]=temp;
    
    int parent=0; //checkng heap from root node again

    while (2*parent +1 < last )
    {
        int left=2* parent +1;// index of left child
        int right=left+1;// index of right child

        int bigger=left; //assuming left child is bigger

        if (right < last && a[right] > a[bigger]) //if right child exists andis bigger, use the right child
            bigger=right;

        if (a[parent] >= a[bigger]) //if parent is bigger than both children, then break    
            break;

        temp=a[parent]; //swap parent with bigger child
        a[parent]=a[bigger];  
        a[bigger]=temp;

        parent=bigger; //continue checking the heap down
    }
   }
   cout<< "Sorted array: ";
   for (int i=0;i<n;i++)
        cout << a[i] << " "; //printing sorted array
        return 0;
}