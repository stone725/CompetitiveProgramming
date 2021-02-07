#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string a, b, c;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        a += num + '0';
    }
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        b += num + '0';
    }
    c = a;
    sort(begin(c), end(c));
    int cntA = -1, cntB = -1, now = 0;
    do
    {
        if (c == a)
        {
            cntA = now;
        }
        if (c == b)
        {
            cntB = now;
        }
        if (~cntA && ~cntB)
        {
            cout << abs(cntA - cntB) << "\n";
            return 0;
        }
        now++;
    } while (next_permutation(begin(c), end(c)));
}