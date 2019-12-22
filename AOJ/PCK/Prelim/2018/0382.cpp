#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    int n, c;
    cin >> n >> c;
    vector<int> cakes(c);
    for (auto &&i : cakes)
    {
        cin >> i;
    }
    int sum = accumulate(begin(cakes), end(cakes), 0);
    cout << sum / (n + 1) + !!(sum % (n + 1)) << "\n";
}