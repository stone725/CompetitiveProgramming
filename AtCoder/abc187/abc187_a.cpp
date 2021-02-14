#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int score_a = a / 100 + (a % 100) / 10 + a % 10;
    int score_b = b / 100 + (b % 100) / 10 + b % 10;
    cout << max(score_a, score_b) << "\n";
}