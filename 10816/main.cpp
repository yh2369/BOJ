#include <iostream>
#include <unordered_map>
#include <vector>


using namespace std;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N;
    unordered_map<int, int> um;
    int key;
    for(int i = 0; i< N; i++)
    {
        cin >> key;
        if(um.find(key) != um.end())
        {
            um[key]++;
        }
        else
        {
            um.insert(make_pair(key, 1));
        }
    }

    cin >> M;
    vector<int> target_v(M, 0);
    for(int i = 0; i< M; i++)
    {
        cin >> target_v[i];
        auto it = um.find(target_v[i]);
        if(it != um.end())
        {
            cout << it->second << " ";
        }
        else
        {
            cout << "0 ";
        }
    }
    cout << "\n";
    

    return 0;
}