#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &&i : a)
    {
        cin >> i;
    }
    priority_queue<int> b;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            b.push(a[i] * a[j]);
        }
    }
    while (b.size())
    {
        int num = b.top();
        b.pop();
        string str = to_string(num);
        bool check = true;
        for (int i = 1; i < str.size(); i++)
        {
            if (str[i] - str[i - 1] != 1)
            {
                check = false;
                break;
            }
        }
        if (check)
        {
            cout << str << "\n";
            return 0;
        }
    }
    cout << "-1\n";
}