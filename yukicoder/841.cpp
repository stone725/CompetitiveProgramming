#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    cin >> str;
    if(str == "Sat" || str == "Sun"){
        cin >> str;
        if(str == "Sat" || str == "Sun"){
            cout << "8/33\n";
        }else{
            cout << "8/32\n";
        }
    }else{
        cout << "8/31\n";
    }
}