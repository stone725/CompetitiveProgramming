#include <iostream>

using namespace std;

int main()
{
    int cnt[6] = {};
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        double high, low;
        cin >> high >> low;
        if (high < 0)
        {
            cnt[5]++;
        }
        else if (low < 0)
        {
            cnt[4]++;
        }
        cnt[3] += 25 <= low;
        if (35 <= high)
        {
            cnt[0]++;
        }
        else if (30 <= high)
        {
            cnt[1]++;
        }
        else if (25 <= high)
        {
            cnt[2]++;
        }
    }
    cout << cnt[0];
    for (int i = 1; i < 6; i++)
    {
        cout << " " << cnt[i];
    }
    cout << "\n";
}