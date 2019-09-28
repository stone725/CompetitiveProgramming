#include <vector>
#include <limits>
#include <algorithm>

struct RangeAddQuery{
    int n;
    std::vector<int> dat;

    void init(int n_){
        n = 1;
        while(n < n_) n *= 2;
        dat.resize(2 * n - 1, 0);
    }

    void add(int a, int b, int k, int l, int r, int x){
        if(r <= a || b <= l) return;
        if(a <= l && r <= b){
            dat[k] += x;
        }
        else{
            add(a, b, k * 2 + 1, l, (l + r) / 2, x);
            add(a, b, k * 2 + 2, (l + r) / 2, r, x);
        }
    }

    void add(int a, int b, int x){
        add(a, b, 0, 0, n, x);
    }

    int query(int k){
        k += n - 1;
        int res = dat[k];
        while(k > 0) {
            k = (k - 1) / 2;
            res += dat[k];
        }
        return res;
    }
};