#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int n, s, t;
        cin >> n >> s >> t;
        cout << n - min(s, t) + 1 << "\n";
    }
}