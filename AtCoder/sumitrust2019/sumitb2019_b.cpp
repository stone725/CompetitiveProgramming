#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < 50000; i++){
        int money = i * 1.08;
        if(n == money){
            cout << i << "\n";
            return 0;
        }
    }
    cout << ":(\n";
}