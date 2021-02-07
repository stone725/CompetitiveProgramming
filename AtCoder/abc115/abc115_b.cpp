#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto &&i : p)
    {
        cin >> i;
    }
    sort(rbegin(p), rend(p));
    p[0] /= 2;
    cout << accumulate(begin(p), end(p), 0) << "\n";
}