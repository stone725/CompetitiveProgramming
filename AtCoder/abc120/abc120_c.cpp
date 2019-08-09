#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string str;
    cin >> str;
    cout << 2 * min(count(begin(str), end(str), '0'), count(begin(str), end(str), '1')) << "\n";
}