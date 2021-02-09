#include <iostream>
#include <string>

using namespace std;

int main(){
    string c;
    cin >> c;
    if(c[0] == c[1] && c[1] == c[2]){
        cout << "Won\n";
    }
    else{
        cout << "Lost\n";
    }
}