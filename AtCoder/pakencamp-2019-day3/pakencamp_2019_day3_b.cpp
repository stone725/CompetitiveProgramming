#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, black = 0, white = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if (str == "black")
        {
            black++;
        }
        else
        {
            white++;
        }
    }
    if (black < white)
    {
        cout << "white\n";
    }
    else
    {
        cout << "black\n";
    }
}