#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int a, b, k;
    cin >> a >> b >> k;
    int score = gcd(a, b);
    int cnt = 0;
    for (int i = score; i > 0; i--)
    {
        if (score % i == 0)
        {
            cnt++;
            if (cnt == k)
            {
                cout << i << "\n";
                return 0;
            }
        }
    }
}