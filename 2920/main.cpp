#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int arr[8];
int main()
{
    for(int i = 0; i<8; i++)
    {
        cin >> arr[i];
    }
    
    bool mixed = true;
    bool ascending = true;
    bool descending = true;
    
    for(int i = 1; i<8; i++)
    {
        if(arr[i] <= arr[i-1])
        {
            ascending = false;
        }
        
        if(arr[i] >= arr[i-1])
        {
            descending = false;
        }
    }
    
    if(ascending)
    {
        cout << "ascending\n"; 
    }
    else if(descending)
    {
        cout << "descending\n";
    }
    else
    {
        cout << "mixed\n";
    }
    
    return 0;
}