#include <iostream>
#include <string>

using namespace std;

void dfs(string str, int l, int r)
{
    if (l == 0 && r == 0)
    {
        cout << str << "\n";
    }
    if (l)
    {
        dfs(str + "(", l - 1, r);
    }
    if (l < r)
    {
        dfs(str + ")", l, r - 1);
    }
}

int main()
{
    int n;
    cin >> n;

    if (n % 2)
    {
        cout << "\n";
        return 0;
    }

    dfs("", n / 2, n / 2);
}