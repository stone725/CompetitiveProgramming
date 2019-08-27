#include <vector>
#include <limits>
#include <algorithm>

struct RangeMinimumQuery{
    int n;
    std::vector<int> dat;

    void init(int n_){
        n = 1;
        while(n < n_) n *= 2;
        dat.resize(2 * n - 1, std::numeric_limits<int>::max());
    }

    void update(int k, int a){
        k += n - 1;
        dat[k] = a;
        while(k > 0) {
            k = (k - 1) / 2;
            dat[k] = std::min(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    int query(int a, int b, int k, int l, int r){
        if(r <= a || r <= b) return std::numeric_limits<int>::max();
        if(a <= l && r <= b) return dat[k];
        else{
            int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return std::min(vl, vr);
        }
    }

    int query(int a, int b){
        return query(a, b, 0, 0, n);
    }
};
