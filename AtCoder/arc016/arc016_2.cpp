#include <iostream>
#include <string>

using namespace std;

int main()
{
    string before = ".........";
    int cnt = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] == 'x' || (str[j] == 'o' && before[j] != 'o'))
            {
                cnt++;
            }
        }
        before = str;
    }
    cout << cnt << "\n";
}