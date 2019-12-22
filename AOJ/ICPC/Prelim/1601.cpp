#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    vector<int> v;
    int checkPoint[] = {5, 7, 5, 7, 7};
    while (cin >> n && n)
    {
        v.resize(n);
        for (auto &&i : v)
        {
            string str;
            cin >> str;
            i = str.size();
        }
        for (int i = 0; i < n; i++)
        {
            int cnt = 0, p = 0;
            for (int j = i; j < n; j++)
            {
                cnt += v[j];
                if (checkPoint[p] < cnt)
                {
                    break;
                }
                if (checkPoint[p] == cnt)
                {
                    cnt = 0;
                    p++;
                    if (p == 5)
                    {
                        break;
                    }
                }
            }
            if (p == 5)
            {
                cout << i + 1 << "\n";
                break;
            }
        }
    }
}