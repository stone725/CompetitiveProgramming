#include <iostream>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if(a < b){
        cout << "Aoki\n";
    }
    else if(b < a){
        cout << "Takahashi\n";
    }
    else if(c){
        cout << "Takahashi\n";
    }
    else{
        cout << "Aoki\n";
    }
}