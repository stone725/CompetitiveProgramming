#include <iostream>
#include <string>

using namespace std;

int main()
{
    long long n;
    string str;
    cin >> n >> str;
    for (int i = 2; i <= 10; i++)
    {
        long long score = 0;
        for (int j = 0; j < str.size(); j++)
        {
            if (i <= str[j] - '0' || n < score)
            {
                score = -1;
                break;
            }
            score *= i;
            score += str[j] - '0';
        }
        if (score == n)
        {
            cout << i << "\n";
        }
    }
}