#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    cin >> str;
    if(1 < str.size() && str == "1" + string(str.size() - 1, '3')){
        cout << str.size() - 1 << "\n";
    }else{
        cout << "-1\n";
    }
}