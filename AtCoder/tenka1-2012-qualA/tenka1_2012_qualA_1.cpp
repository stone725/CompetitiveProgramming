#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> many(n + 1);
    for(int i = 0; i <= n; i++){
        if(i <= 1){
            many[i] = 1;
        }else{
            many[i] = many[i - 1] + many[i - 2];
        }
    }
    cout << many[n] << "\n";
}