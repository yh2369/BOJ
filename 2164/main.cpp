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

void print_list(list<int> l)
{
    for(auto it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n\n";
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    list<int> my_list;
    for(int i = 1; i<=N; i++)
    {
        my_list.push_back(i);
    }
    
    while(my_list.size() > 1)
    {
        my_list.pop_front();
        int front = my_list.front();
        my_list.pop_front();
        my_list.push_back(front);
    }
    
    cout << my_list.front() << "\n";
    return 0;
}
