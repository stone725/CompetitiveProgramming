#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<bool> is_prime(10000001, true);
vector<long long> primes;
map<int, int> divs;

int main()
{
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= 10000000; i += 2)
    {
        if (!is_prime[i])
            continue;
        for (int j = i * i; j <= 10000000; j += i)
        {
            is_prime[j] = false;
        }
        i -= i == 2;
    }
    for (int i = 2; i <= 10000000; i += 2)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
        }
        i -= i == 2;
    }
    int n;
    cin >> n;
    for (int i = 0; primes[i] * primes[i] <= n; i++)
    {
        while (n % primes[i] == 0)
        {
            divs[primes[i]]++;
            n /= primes[i];
        }
        if (n == 1)
            break;
    }
    if (n != 1)
    {
        cout << n << "\n";
        return 0;
    }
    for (int i = 2; i <= 100000; i++)
    {
        int num = i;
        for (int j = 0; primes[j] <= num; j++)
        {
            if (!divs.count(primes[j]))
                continue;
            while (num % primes[j] == 0)
            {
                divs[primes[j]]--;
                if (divs[primes[j]] == 0)
                {
                    divs.erase(primes[j]);
                    break;
                }
                num /= primes[j];
            }
            if (divs.empty())
            {
                cout << i << "\n";
                return 0;
            }
        }
    }
}