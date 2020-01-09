#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int now = 0;
    for (auto &&i : a)
    {
        cin >> i;
        if (now + 1 == i)
        {
            now++;
        }
    }
    if (now == 0)
    {
        now = n + 1;
    }
    cout << n - now << "\n";
}