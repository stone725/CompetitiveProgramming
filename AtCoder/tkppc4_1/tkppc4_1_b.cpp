#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int ans = -1, score = -1;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (num < k && score < num)
        {
            ans = i + 1;
            score = num;
        }
    }
    cout << ans << "\n";
}