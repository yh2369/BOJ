#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<string> split(string input, string delimiter)
{
    vector<string> ret;
    string token = "" ;
    long long pos = 0;
    while( (pos = input.find(delimiter)) != string::npos)
    {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos+delimiter.length());
    }
    ret.push_back(input);
    return ret;   
}

int main()
{
    string name;
    cin >> name;
    int counter[26] = {0,};
    int n = name.length();
    for(int i =0; i< n; i++)
    {
        counter[name[i] - 'A']++;
    }

    int num_odd = 0;
    int odd_index = -1;
    for(int i =0; i<26; i++)
    {
        if(counter[i] % 2  == 1)
        {
            num_odd++;
            odd_index =  i;
        }
    }

    if(num_odd >1)
    {
        cout << "I'm Sorry Hansoo" << endl;
        return 0;
    }
    else
    {
        if(num_odd == 1)
        {
            counter[odd_index]--;
        }
        stack<char> stk;
        string answer = "";
        for(int i= 0; i<26; i++)
        {
            answer += string( counter[i] / 2 , i + 'A');
            stk.push(i  + 'A');
        }

        
        if(num_odd == 1)
        {
            answer += string(1, odd_index + 'A');
        }


        while(!stk.empty())
        {
            char top = stk.top();
            answer += string(counter[top-'A']/2 , top);
            stk.pop();
        }
        cout << answer << endl;

    }


    return 0;
}