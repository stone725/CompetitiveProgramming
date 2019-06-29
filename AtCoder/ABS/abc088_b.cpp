#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    cin >> n;
    priority_queue<int> pq;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        pq.push(a);
    }
    int ans = 0;
    bool alice = true;
    while(!pq.empty()){
        if(alice){
            ans += pq.top();
        }else{
            ans -= pq.top();
        }
        pq.pop();
        alice = !alice;
    }
    cout << ans << "\n";
}