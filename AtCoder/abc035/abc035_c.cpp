#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> bits(n + 1);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        bits[l - 1]++;
        bits[r]--;
    }
    cout << bits[0] % 2;
    for (int i = 1; i < n; i++)
    {
        bits[i] += bits[i - 1];
        cout << bits[i] % 2;
    }
    cout << "\n";
}