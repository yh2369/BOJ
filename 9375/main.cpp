#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
int main()
{
    int test_case_num;
    cin >> test_case_num;
    for(int i = 0; i<test_case_num; i++)
    {
        int n;
        cin >> n;
        map<string, int> table;
        for(int j=0; j<n; j++)
        {
            string key;
            string value;
            cin >> value >> key;
            if(table.find(key) != table.end())
            {
                table[key]++;
            }
            else
            {
                table.insert(make_pair(key, 1));
            }
        }
        int answer = 1;
        for(auto it = table.begin(); it!=table.end(); it++)
        {
            answer = answer * (it->second + 1);
        }
        answer--;
        cout << answer << endl;
    }
    return 0;
}