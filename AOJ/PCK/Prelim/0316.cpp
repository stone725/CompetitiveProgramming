#include <iostream>

using namespace std;

int a, b, c, d;

int get_score(int i, int y){
    return i * a + y * b + i / 10 * c + y / 20 * d;
}

int main(){
    int h1, h2;
    cin >> h1 >> h2;
    int k1, k2;
    cin >> k1 >> k2;
    cin >> a >> b >> c >> d;
    int hiroshi = get_score(h1, h2);
    int kenjiro = get_score(k1, k2);
    if(hiroshi < kenjiro){
        cout << "kenjiro\n";
    }else if(kenjiro < hiroshi){
        cout << "hiroshi\n";
    }else{
        cout << "even\n";
    }
}