#include <iostream>

using namespace std;

int main()
{
    int n;
    while (cin >> n && n)
    {
        int score = 0;
        for (int i = 1; i * i <= n && i < n; i++)
        {
            if (n % i)
                continue;
            score += i;
            if (i * i < n && i != 1)
            {
                score += n / i;
            }
        }
        if (n == score)
        {
            cout << "perfect number\n";
        }
        else if (n > score)
        {
            cout << "deficient number\n";
        }
        else
        {
            cout << "abundant number\n";
        }
    }
}