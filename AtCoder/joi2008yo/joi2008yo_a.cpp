#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0, score = 1000 - n;
    ans += score / 500;
    score %= 500;
    ans += score / 100;
    score %= 100;
    ans += score / 50;
    score %= 50;
    ans += score / 10;
    score %= 10;
    ans += score / 5;
    score %= 5;
    ans += score;
    cout << ans << "\n";
}