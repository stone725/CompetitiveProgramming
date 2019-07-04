#include <iostream>

using namespace std;

int main(){
    int h, w;
    int h2, w2;
    cin >> h >> w;
    cin >> h2 >> w2;
    if(h == h2 || h == w2 || w == h2 || w == w2){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}