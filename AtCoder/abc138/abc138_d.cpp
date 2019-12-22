#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> check(n + 1, 0);
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        check[b] = a;
    }
    for (int i = 0; i < q; i++)
    {
        int p, x;
        cin >> p >> x;
        cnt[p] += x;
    }
    for (int i = 1; i < n; i++)
    {
        int score = cnt[i], p = i;
        while (check[p])
        {
            p = check[p];
            score += cnt[p];
        }
        check[i] = 0;
        cnt[i] = score;
        cout << score << " ";
    }
    int score = cnt[n], p = n;
    while (check[p])
    {
        p = check[p];
        score += cnt[p];
    }
    cout << score << "\n";
}