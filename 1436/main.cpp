#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

string next_num(string& num)
{
    int n = num.length();
    string next = "";
    for(int i = 0; i<n-2; i++)
    {
        if(num[i] =='6' && num[i+1] == '6' && num[i+2] == '6')
        {

            if(i == n-3)
            {
                if(num[n-4] == '5')
                {
                    if(n >= 6)
                    {
                        if(num[n-5] == '6' && num[n-6] == '6')
                        {
                            return num.substr(0, n-4) + "6000";
                        }
                    }
                    if(n>=5)
                    {
                        if(num[n-5] =='6')
                        {
                            return num.substr(0,n-4) + "6600";
                        }

                    }
                    return num.substr(0, n-4) + "6660";
                }
                return  to_string(stoi(num.substr(0, n-3))+1) + "666";
            }
            

            string s = num.substr(i+3, n);
            bool flag = true;
            for(int j = 0; j<s.length(); j++)
            {
                if(s[j] != '9')
                {
                    flag = false;
                    break;
                }
            }

            if(flag)
            {
                return num.substr(0, n-4) + "7666";
            }
            else
            {
                std::ostringstream str;
                str << std::setw(n-i-3) << std::setfill('0') << stoi(s) + 1;
                return num.substr(0, i+3) + str.str();
            }


        }
    }
    return next;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;

    cin >> N;

    if(N == 1)
    {
        cout << "666\n";
        return 0;
    }
    if(N == 2)
    {
        cout << "1666" << '\n';
        return 0;
    }

    string num = "1666";
    int cnt = 2;
    while(cnt < N)
    {
        num = next_num(num);
        cnt++;
    }
    cout << num << '\n';
    return 0;
}