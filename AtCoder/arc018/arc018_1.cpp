#include <iostream>

using namespace std;

int main()
{
    double height, bmi;
    cin >> height >> bmi;
    height /= 100;
    cout << bmi * height * height << "\n";
}