#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &&i : a)
    {
        cin >> i;
    }
    for (auto &&i : b)
    {
        cin >> i;
    }
    int ip = 0;
    for (int i = 0; i < n; i++)
    {
        ip += a[i] * b[i];
    }
    if (ip == 0)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}