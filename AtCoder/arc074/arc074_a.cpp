#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long h, w;
    cin >> h >> w;
    if (h % 3 == 0 || w % 3 == 0)
    {
        cout << 0 << "\n";
        return 0;
    }
    long long score = min(w, h);
    for (int i = 1; i < h; i++)
    {
        long long a = i * w;
        long long b = (h - i) * (w / 2);
        long long c = (h - i) * (w / 2 + w % 2);
        score = min(score, max({a, b, c}) - min({a, b, c}));
    }
    for (int i = 1; i < w; i++)
    {
        long long a = i * h;
        long long b = (w - i) * (h / 2);
        long long c = (w - i) * (h / 2 + h % 2);
        score = min(score, max({a, b, c}) - min({a, b, c}));
    }
    cout << score << "\n";
}