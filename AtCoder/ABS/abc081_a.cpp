#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string str;
    cin >> str;
    cout << count(begin(str), end(str), '1') << "\n";
}