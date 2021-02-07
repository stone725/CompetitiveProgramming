#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    cin >> str;
    list<int> l(1), r(1);
    int cnt = 0;
    for (auto &&i : str)
    {
        if (i == '<')
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }
        l.push_back(cnt);
    }
    reverse(begin(str), end(str));
    cnt = 0;
    for (auto &&i : str)
    {
        if (i == '>')
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }
        r.push_front(cnt);
    }
    long long sum = 0;
    while (!l.empty())
    {
        sum += max(l.front(), r.front());
        l.pop_front();
        r.pop_front();
    }
    cout << sum << "\n";
}
