#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<bool> isprime(1000000, true);
    isprime[0] = isprime[1] = false;
    for (int i = 2; i * i < isprime.size(); i += 2)
    {
        if (!isprime[i])
            continue;
        if (n <= i)
        {
            cout << i << "\n";
            return 0;
        }
        for (int j = i * i; j < isprime.size(); j += i)
        {
            isprime[j] = false;
        }
        i -= i == 2;
    }
    vector<int> primenumber;
    for (int i = 0; i < isprime.size(); i++)
    {
        if (isprime[i])
        {
            primenumber.push_back(i);
        }
    }
    cout << *lower_bound(begin(primenumber), end(primenumber), n) << "\n";
}