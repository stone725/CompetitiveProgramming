#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    if (str == "Sunny")
    {
        cout << "Cloudy\n";
    }
    else if (str == "Cloudy")
    {
        cout << "Rainy\n";
    }
    else
    {
        cout << "Sunny\n";
    }
}