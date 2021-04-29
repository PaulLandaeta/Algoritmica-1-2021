#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int main()
{
    input;
    // output;
    int a, b, q, x, lastx, y, lasty, temp, temp1, temp2, temp3;

    while(cin >> a >> b) {
        x = 0;
        y = 1;
        lastx = 1;
        lasty = 0;
        while (b != 0)
        {
            q = a / b;
            temp1 = a % b; // resto 
            a = b;  // a se vuelve b
            b = temp1; // b se vuelve el resto 

            temp2 = x;
            x = lastx - q * x;
            lastx = temp2;

            temp3 = y;
            y = lasty - q * y;
            lasty = temp3;
        }
        cout << "x = " << lastx << endl;
        cout << "y = " << lasty << endl;
    }
    
    return 0;
}