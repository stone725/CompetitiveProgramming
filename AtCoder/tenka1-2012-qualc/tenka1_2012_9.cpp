#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<bool> check(n, true);
    check[0] = check[1] = false;
    for (int i = 2; i * i < n; i += 2)
    {
        if (!check[i])
            continue;
        for (int j = i * i; j < n; j += i)
        {
            check[j] = false;
        }
        i -= i == 2;
    }
    vector<int> primes;
    for (int i = 2; i < n; i += 2)
    {
        if (check[i])
            primes.push_back(i);
        i -= i == 2;
    }
    cout << primes.size() << "\n";
}