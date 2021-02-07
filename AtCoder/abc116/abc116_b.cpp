#include <iostream>

using namespace std;

int main()
{
    int s;
    cin >> s;
    int now = s;
    bool used[1000000] = {};
    for (int i = 0; i < 1e6; i++)
    {
        if (used[now])
        {
            cout << i + 1 << "\n";
            return 0;
        }
        used[now] = true;
        if (now % 2)
        {
            now *= 3;
            now++;
        }
        else
        {
            now /= 2;
        }
    }
}