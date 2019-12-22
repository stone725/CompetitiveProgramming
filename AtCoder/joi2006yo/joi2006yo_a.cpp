#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ascore = 0, bscore = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a < b)
        {
            bscore += a + b;
        }
        else if (b < a)
        {
            ascore += a + b;
        }
        else
        {
            ascore += a;
            bscore += b;
        }
    }
    cout << ascore << " " << bscore << "\n";
}