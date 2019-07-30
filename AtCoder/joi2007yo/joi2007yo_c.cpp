#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    cin >> str;
    for(auto&& i : str){
        cout << (char)('A' + (i - 'A' + 23) % 26);
    }
    cout << "\n";
}