#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int a = 0, b = 0;
    for(int i = 0; i < 4; i++){
        int score;
        cin >> score;
        a += score;
    }
    for(int i = 0; i < 4; i++){
        int score;
        cin >> score;
        b += score;
    }
    cout << max(a, b) << "\n";
}