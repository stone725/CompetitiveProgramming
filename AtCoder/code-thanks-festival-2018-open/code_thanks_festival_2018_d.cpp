#include <iostream>
#include <string>

using namespace std;

string str;

int cnt(int p)
{
    for (int i = p + 1; i < str.size(); i++)
    {
        if (str[i] <= str[p])
        {
            return 1 + cnt(i);
        }
    }
    return 1;
}

int main()
{
    cin >> str;
    cout << cnt(0) << "\n";
}