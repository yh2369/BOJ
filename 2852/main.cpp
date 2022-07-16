#include <iostream>
#include <string>

using namespace std;

vector<string> split(string input, string delimiter)
{
    vector<string> ret;
    long long pos;
    string token = "";
    while( (pos = input.find(delimiter)) != string::npos)
    {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, delimiter.length() + pos);
    }
    ret.push_back(input);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string winning_time1;
    string winning_time2;

    int N;
    cin >> N;
    string time = "";
    int team_num;
    while(N--)
    {
        cin >> team_num >> time;
        



    }


    return 0;
}