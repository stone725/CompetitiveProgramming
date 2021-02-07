#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;
    vector<int> x(n), y(m);
    for (auto &&i : x)
    {
        cin >> i;
    }
    for (auto &&i : y)
    {
        cin >> i;
    }
    sort(rbegin(x), rend(x));
    sort(begin(y), end(y));
    if (max(X, x[0]) < min(Y, y[0]))
    {
        cout << "No War\n";
    }
    else
    {
        cout << "War\n";
    }
}