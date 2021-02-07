#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long h, w, k;
    cin >> h >> w >> k;
    vector<int> numh(h, w), numw(w, h);
    for (int i = 0; i < k; i++)
    {
        int r, c;
        cin >> r >> c;
        numh[r - 1]--;
        numw[c - 1]--;
    }
    long long sumcnt = h * w - k;
    long long ans = 0;
    long long mid = 0, cnt = 0;
    for (int i = 0; i < h; i++)
    {
        cnt += numh[i];
        if (sumcnt <= cnt * 2)
        {
            mid = i;
            break;
        }
    }
    for (int i = 0; i < h; i++)
    {
        if (mid == i)
            continue;
        ans += numh[i] * abs(mid - i);
    }
    mid = cnt = 0;
    for (int i = 0; i < w; i++)
    {
        cnt += numw[i];
        if (sumcnt <= cnt * 2)
        {
            mid = i;
            break;
        }
    }
    for (int i = 0; i < w; i++)
    {
        if (mid == i)
            continue;
        ans += abs(mid - i) * numw[i];
    }
    cout << ans << "\n";
}