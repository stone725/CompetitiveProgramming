#include <iostream>
#include <bitset>

using namespace std;

int n;

int dfs(unsigned int score, bitset<3> bits)
{
    if (score > n)
        return 0;
    int res = bits.count() == 3;
    auto nextbits = bits;
    for (int i = 3; i <= 7; i += 2)
    {
        nextbits[i - 3 / 2] = true;
        res += dfs(score * 10 + i, nextbits);
        nextbits[i - 3 / 2] = bits[i - 3 / 2];
    }
    return res;
}

int main()
{
    cin >> n;
    cout << dfs(0, bitset<3>(0)) << "\n";
}