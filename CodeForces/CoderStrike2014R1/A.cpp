#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    k--;
    int now = k;
    vector<bool> printed(n, false);
    while (true)
    {
        if (!printed[now])
        {
            cout << "PRINT " << str[now] << "\n";
            printed[now] = true;
            if (printed == vector<bool>(n, true))
            {
                return 0;
            }
        }
        if (now == n - 1)
        {
            cout << "LEFT\n";
            now--;
        }
        else if (now == 0)
        {
            cout << "RIGHT\n";
            now++;
        }
        else if (n - 1 - now > now && !printed[0])
        {
            cout << "LEFT\n";
            now--;
        }
        else if (n - 1 - now < now && !printed[n - 1])
        {
            cout << "RIGHT\n";
            now++;
        }
        else if (printed[0])
        {
            cout << "RIGHT\n";
            now++;
        }
        else
        {
            cout << "LEFT\n";
            now--;
        }
    }
}