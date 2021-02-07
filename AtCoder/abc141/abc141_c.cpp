#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> cnt(n);
    for (int i = 0; i < q; i++)
    {
        int a;
        cin >> a;
        cnt[a - 1]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (0 < k - q + cnt[i])
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}