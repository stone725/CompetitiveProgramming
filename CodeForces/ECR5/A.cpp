#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    int num;
    for (num = 0; num + 1 < a.size() && a[num] == '0'; num++)
        ;
    a = a.substr(num);
    for (num = 0; num + 1 < b.size() && b[num] == '0'; num++)
        ;
    b = b.substr(num);
    if (a.size() < b.size())
    {
        cout << "<\n";
        return 0;
    }
    else if (a.size() > b.size())
    {
        cout << ">\n";
        return 0;
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] < b[i])
        {
            cout << "<\n";
            return 0;
        }
        else if (a[i] > b[i])
        {
            cout << ">\n";
            return 0;
        }
    }
    cout << "="
         << "\n";
}