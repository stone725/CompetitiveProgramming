#include <iostream>

using namespace std;

int main()
{
    bool solved[31] = {};
    for (int i = 0; i < 28; i++)
    {
        int num;
        cin >> num;
        solved[num] = true;
    }
    bool first = true;
    for (int i = 1; i <= 30; i++)
    {
        if (solved[i])
            continue;
        cout << i << "\n";
    }
}