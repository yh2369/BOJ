#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

void print2DV(vector<vector<int>>& v, int a)
{
    for(int i = 0; i<a; i++)
    {
        for(int j = 0; j<v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}

int N, M, K;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;
    set<int> truth_set;
    for(int i  =0 ; i<K; i++)
    {
        int tmp;
        cin >> tmp;
        truth_set.insert(tmp);
    }

    vector<vector<int>> party_table(M, vector<int>());

    for(int i =0; i<M; i++)
    {
        int P;
        cin >> P;

        for(int j = 0; j<P; j++)
        {
            int num;
            cin >> num;
            party_table[i].push_back(num);
        } 
    }

    //print2DV(party_table, M);

    for(int i = 0; i<M; i++)
    {
        bool flag = false;
        for(int j = 0; j<party_table[i].size(); j++)
        {
            int num = party_table[i][j];
            if(truth_set.find(num) != truth_set.end())
            {
                flag = true;
                break;
            }
        }
        if(flag)
        {
            for(int j = 0; j<party_table[i].size(); j++)
            {
                int num = party_table[i][j];
                truth_set.insert(num);
            }
        }
    }

    return 0;
}