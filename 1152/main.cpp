#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>

using namespace std;
vector<string> split(string input, string delimiter);
string preprocess(string& s);

vector<string> split(string input, string delimiter)
{
    vector<string> ret;
    string token = "";
    long long pos = 0;
    while(true)
    {
        pos = input.find(delimiter);
        if(pos == string::npos)
        {
            break;
        }
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimiter.length());
    }    
    ret.push_back(input);
    return ret;
}

string preprocess(string& s)
{
    int n = s.length();
    string ret= "";
    if(s[0] == ' ')
    {
        if(s[n-1] == ' ')
        {
            ret = s.substr(1, n-1);
        }
        else
        {
            ret = s.substr(1, n);
        }
        
    }
    else
    {
        if(s[n-1] == ' ')
        {
            ret = s.substr(0, n-1);
        }
        else
        {
            ret = s.substr(0, n);
        }
    }
    return ret;

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s;
    getline(cin, s);
    int n = s.length();
    int answer = 1;

    for(int i =0; i<n; i++)
    {
        if(s[i] == ' ')
        {
            answer++;
        }
    }




    if(s[0] == ' ')
    {
        answer--;
    }

    if(s[n-1] == ' ')
    {
        answer--;
    }
    cout << answer << "\n";

    return 0;
}