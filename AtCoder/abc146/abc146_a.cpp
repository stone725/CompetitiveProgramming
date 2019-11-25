#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    string str;
    cin >> str;
    map<string, int> swi;
    swi["SUN"] = 7;
    swi["MON"] = 6;
    swi["TUE"] = 5;
    swi["WED"] = 4;
    swi["THU"] = 3;
    swi["FRI"] = 2;
    swi["SAT"] = 1;
    cout << swi[str] << "\n";
}