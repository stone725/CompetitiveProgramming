#include <iostream>

using namespace std;

int main()
{
    int card[3][3];
    for (auto &&i : card)
    {
        for (auto &&j : i)
        {
            cin >> j;
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        for (auto &&j : card)
        {
            for (auto &&k : j)
            {
                if (k == num)
                {
                    k = -1;
                }
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (card[i][0] == -1 && card[i][1] == -1 && card[i][2] == -1)
        {
            cout << "Yes\n";
            return 0;
        }
        if (card[0][i] == -1 && card[1][i] == -1 && card[2][i] == -1)
        {
            cout << "Yes\n";
            return 0;
        }
    }
    if (card[0][0] == -1 && card[1][1] == -1 && card[2][2] == -1)
    {
        cout << "Yes\n";
        return 0;
    }
    if (card[0][2] == -1 && card[1][1] == -1 && card[2][0] == -1)
    {
        cout << "Yes\n";
        return 0;
    }
    cout << "No\n";
}