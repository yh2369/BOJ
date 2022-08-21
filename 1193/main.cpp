#include <iostream>

using namespace std;

int X;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> X;
    int numerator, denominator;
    if(X == 1)
    {
        numerator = 1; denominator = 1;
        cout << numerator << "/" << denominator << "\n";
        return 0;
    }

    int upper_bound = 3;
    int d = 2;
    while(true)
    {
        if( upper_bound - d <X && X <= upper_bound)
        {
            int delta = X - (upper_bound - d + 1);
            if(d % 2 == 0)
            {
                numerator = 1 + delta;
                denominator = d - delta;
            }
            else
            {
                numerator = d - delta;
                denominator = 1 + delta;
            }
            break;
        }
        d++;
        upper_bound = upper_bound + d;
    }

    cout << numerator << "/" << denominator << "\n";

    
    return 0;
}