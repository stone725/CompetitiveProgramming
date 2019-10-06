#include <iostream>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if(a > b && a > c){
        cout << "A\n";
    }else if(b > c){
        cout << "B\n";
    }else{
        cout << "C\n";
    }
}