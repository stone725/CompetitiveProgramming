#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b)
{
    return b ? gcd(b, a % b) : a;
}

using namespace std;

int main()
{
    vector<bool> isPrime(1000001, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= 1000000; i += 2)
    {
        if (!isPrime[i])
            continue;
        for (int j = i * i; j <= 1000000; j += i)
        {
            isPrime[j] = false;
        }
        i -= i == 2;
    }
    vector<long long> primeNumber;
    for (int i = 0; i <= 1000000; i++)
    {
        if (isPrime[i])
        {
            primeNumber.push_back(i);
        }
    }
    long long a, b;
    cin >> a >> b;
    long long score = gcd(a, b);
    int cnt = 0;
    for (long long i = 1; i * i <= score; i++)
    {
        if (score % i)
            continue;
        if (i == 1 || isPrime[i])
            cnt++;
        if (i * i < score)
        {
            long long num = score / i;
            bool check = true;
            for (int i = 0; i < primeNumber.size() && primeNumber[i] * primeNumber[i] <= num; i++)
            {
                if (num % primeNumber[i] == 0)
                {
                    check = false;
                    break;
                }
            }
            if (check)
            {
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
}