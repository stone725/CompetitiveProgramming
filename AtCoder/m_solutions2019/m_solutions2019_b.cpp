#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string str;
    cin >> str;
    if(8 <= count(begin(str), end(str), 'o') + 15 - str.size()){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}