#include <iostream>
#include <string>

using namespace std;

int main()
{
    string n;
    cin >> n;
    int num = stoi(n);
    int ans = 0;
    for (int i = 1; i < n.size(); i += 2)
    {
        int cnt = 9;
        for (int j = 1; j < i; j++)
        {
            cnt *= 10;
        }
        ans += cnt;
    }
    if (n.size() % 2)
    {
        for (int i = stoi("1" + string(n.size() - 1, '0')); i <= num; i++)
        {
            ans++;
        }
    }
    cout << ans << "\n";
}