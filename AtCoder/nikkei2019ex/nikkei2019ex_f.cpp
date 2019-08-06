#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        bool status = true;
        if(i % 2 == 0){
            cout << "a";
            status = false;
        }
        if(i % 3 == 0){
            cout << "b";
            status = false;
        }
        if(i % 4 == 0){
            cout << "c";
            status = false;
        }
        if(i % 5 == 0){
            cout << "d";
            status = false;
        }
        if(i % 6 == 0){
            cout << "e";
            status = false;
        }
        if(status){
            cout << i;
        }
        cout << "\n";
    }
}