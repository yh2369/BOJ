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
using namespace std;

int N, M, X;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    vector<int> A(N, 0);
    for(int i = 0; i< N; i++)
    {
        cin >> A[i];
    }
    
    unordered_set<int> T;
    for(int i = 0; i<N; i++)
    {
        T.insert(A[i]);
    }
    cin >> M;
    for(int i = 0; i<M; i++)
    {
        cin >> X;
        if(T.find(X) != T.end())
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
    return 0;
}
