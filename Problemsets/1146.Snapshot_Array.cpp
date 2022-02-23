/*

*/

#include <bits/stdc++.h>

#define FOR(i,a,b)       for(int i=a; i<b; i++)
#define NFOR(i,a,b)      for(int i=(a-1); i>=(b); i--)
#define ll               long long int
#define ld               long long double
#define f                first
#define s                second
#define pb               push_back
#define mp               make_pair
#define max(x,y)         (x>y)?x:y
#define min(x,y)         (x<y)?x:y


const int INF = 1<<29;

using namespace std;

class SnapshotArray {
public:
    vector<vector<pair<int, int>>> m;
    int cur_snap = 0;
    SnapshotArray(int length) {
        m = vector<vector<pair<int, int>>>(length);
    }
    int snap() { return cur_snap++; }
    void set(int index, int val) {
    if (m[index].empty() || m[index].back().first != cur_snap)
        m[index].push_back({ cur_snap, val });
    else m[index].back().second = val;
    }
    int get(int index, int snap_id) {
    auto it = upper_bound(begin(m[index]), end(m[index]), pair<int, int>(snap_id, INT_MAX));
    return it == begin(m[index]) ? 0 : prev(it)->second;
    }
};

int main(){

    SnapshotArray* obj = new SnapshotArray(length);
    obj->set(index,val);
    int param_2 = obj->snap();
    int param_3 = obj->get(index,snap_id);

    return 0;
}