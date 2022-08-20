/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int a, b;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b;
    int A = a; int B = b;
    int gcd, lcm;
    int q, r;
    while(true)
    {
        q = a / b;
        r = a % b;
        if(r == 0)
        {
            gcd = b;
            break;
        }
        a = b;
        b = r;
        
    }
    cout << gcd << "\n";
    lcm = (A / gcd) * B;
    cout << lcm << "\n";
    
    
    return 0;
}
