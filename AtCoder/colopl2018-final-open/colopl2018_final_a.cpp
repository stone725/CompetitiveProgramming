#include <iostream>
#include <string>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    string str;
    cin >> str;
    long long ans = 0;
    long long cnt = 0;
    if (str == string(str.size(), 'A'))
    {
        cout << (n * str.size()) * (n * str.size() + 1) / 2;
        return 0;
    }
    bool first = true;
    long long start = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'A')
        {
            cnt++;
        }
        else
        {
            if (first)
            {
                start = cnt;
                first = false;
            }
            else
            {
                ans += cnt * (cnt + 1) / 2;
            }
            cnt = 0;
        }
    }
    ans *= n;
    ans += start * (start + 1) / 2;
    ans += cnt * (cnt + 1) / 2;
    ans += (n - 1) * (start + cnt) * (start + cnt + 1) / 2;
    cout << ans << "\n";
}