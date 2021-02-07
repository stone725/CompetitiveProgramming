#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long t1, t2, a1, b1, a2, b2;
    cin >> t1 >> t2;
    cin >> a1 >> a2;
    cin >> b1 >> b2;
    if (a1 * t1 + a2 * t2 == b1 * t1 + b2 * t2)
    {
        cout << "infinity\n";
        return 0;
    }
    long long cnt = 0;
    long long rap1 = (a1 - b1) * t1, rap2 = (a2 - b2) * t2, rap = rap1 + rap2;
    if (rap1 == 0)
    {
        cout << 1 << "\n";
        return 0;
    }
    if (rap1<0 == rap> 0)
    {
        long long div = abs(rap1) / abs(rap), mod = abs(rap1) % abs(rap);
        cnt += abs(rap1) / abs(rap) * 2;
        if (mod)
        {
            cnt++;
        }
    }
    cout << cnt << "\n";
}