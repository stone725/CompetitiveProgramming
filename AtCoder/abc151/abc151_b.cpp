#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, k, m;
    cin >> n >> k >> m;
    int score = n * m;
    for (int i = 0; i < n - 1; i++)
    {
        int a;
        cin >> a;
        score -= a;
    }
    if (k < score)
    {
        cout << "-1\n";
    }
    else
    {
        cout << max(0, score) << "\n";
    }
}