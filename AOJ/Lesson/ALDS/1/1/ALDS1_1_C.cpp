#include <iostream>
#include <vector>

using namespace std;

vector<bool> isPrime(10001, true);
vector<int> primeNumbers;

int main()
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= 10000; i += 2)
    {
        if (!isPrime[i])
            continue;
        for (int j = i * i; j <= 10000; j += i)
        {
            isPrime[j] = false;
        }
        i -= i == 2;
    }
    int n, ans = 0;
    for (int i = 0; i <= 10000; i++)
    {
        if (isPrime[i])
        {
            primeNumbers.push_back(i);
        }
    }
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        if (a <= 1e4)
        {
            ans += isPrime[a];
            continue;
        }
        ans++;
        for (int i = 0; i < primeNumbers.size() && primeNumbers[i] * primeNumbers[i] <= a; i++)
        {
            if (a % primeNumbers[i] == 0)
            {
                ans--;
                break;
            }
        }
    }
    cout << ans << "\n";
}