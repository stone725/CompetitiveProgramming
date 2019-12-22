#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int cnt[26] = {};
    for (auto &&i : str)
    {
        cnt[i - 'a']++;
    }
    string center = "";
    string ans = "";
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] % 2)
        {
            for (int j = 25; j >= i; j--)
            {
                if (i == j)
                {
                    center = string(1, 'a' + i);
                    break;
                }
                else if (cnt[j] % 2)
                {
                    cnt[j]--;
                    cnt[i]++;
                    break;
                }
            }
        }
        ans += string(cnt[i] / 2, 'a' + i);
    }
    cout << ans + center + string(rbegin(ans), rend(ans)) << "\n";
}