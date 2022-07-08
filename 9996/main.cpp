#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> split (string input, string delimiter)
{
    vector<string> ret;
    long long pos;
    string token = "";
    while( (pos = input.find(delimiter)) != string::npos)
    {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    ret.push_back(input);
    return ret;
}

bool pattern_equal(string file_name, string first_part, string second_part)
{
    int n1 = first_part.length();
    int n2 = second_part.length();
    int n  = file_name.length();
    if(n1 > n)
    {
        return false;
    }
    if( n2 > n)
    {
        return false;
    }
    if(n- n2 < n1)
    {
        return false;
    }
    return (file_name.substr(0, n1) == first_part) && (file_name.substr(n - n2, n) == second_part);
}

int main()
{
    int N;
    cin >> N;
    string pattern;
    cin >> pattern;

    auto ret = split(pattern, "*");
    auto first_part = ret[0];
    auto second_part = ret[1];

    string file_name;
    for(int i=0; i<N; i++)
    {
        cin >> file_name;
        if(pattern_equal(file_name, first_part, second_part))
        {
            cout << "DA" << endl;
        }
        else
        {
            cout << "NE" << endl;
        }

    }
    return 0;
}