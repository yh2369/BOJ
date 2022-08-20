/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <list>
using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    vector<int> arr(N, 0);
    for(int i = 0; i<N; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i<arr.size(); i++)
    {
        cout << arr[i] << "\n";
    }
    return 0;
}
