#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long scoreA = 0, scoreB = 0;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        if (scoreA == scoreB && !scoreA)
        {
            scoreA = a;
            scoreB = b;
            continue;
        }
        long long time = max(scoreA / a + !!(scoreA % a), scoreB / b + !!(scoreB % b));
        scoreA = a * time;
        scoreB = b * time;
    }
    cout << scoreA + scoreB << "\n";
}