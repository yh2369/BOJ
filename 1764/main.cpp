#include <iostream>
#include <string>
#include <unordered_set>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    string name;
    unordered_set<string> A;
    set<string> B;
    for(int i = 0; i<N; i++)
    {
        cin >> name;
        A.insert(name);
    }
    for(int i= 0; i<M; i++)
    {
        cin >> name;
        auto it = A.find(name);
        if(it != A.end())
        {
            B.insert(name);
        }
    }
    cout << B.size() << "\n";
    for(auto it = B.begin(); it != B.end(); it++)
    {
        cout << *it << "\n";
    }
    return 0;
}