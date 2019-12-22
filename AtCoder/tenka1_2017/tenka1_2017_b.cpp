#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int score = 1e9 + 7, num = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (score > b)
        {
            num = a;
            score = b;
        }
    }
    cout << num + score << "\n";
}