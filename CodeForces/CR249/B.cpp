#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    int n;
    cin >> str >> n;
    int p = 0;
    while (n)
    {
        bool check = true;
        for (int i = p; i < str.size(); i++)
        {
            char maxscore = str[i];
            int changepoint = i;
            for (int j = i + 1; j < str.size() && j - i <= n; j++)
            {
                if (maxscore < str[j])
                {
                    changepoint = j;
                    maxscore = str[j];
                }
            }
            if (changepoint != i)
            {
                n -= changepoint - i;
                for (int j = changepoint; j > i; j--)
                {
                    swap(str[j], str[j - 1]);
                }
                p = i;
                check = false;
                break;
            }
        }
        if (check)
        {
            break;
        }
    }
    cout << str << "\n";
}