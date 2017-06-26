#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
using namespace std;
#define LL long long
bool flag[100005]={0};
struct vehicle {
    int id, cap;
};
bool compare(const vehicle v1, const vehicle v2) {
    return v1.cap > v2.cap;
}
vector<vehicle> t1, t2;
int main() {
    ios_base::sync_with_stdio(false);
    int N, V, type, max_id=-1;
    cin >> N >> V;
    for (int i=0; i < N; i++) {
        vehicle v;
        cin >> type >> v.cap;
        v.id = i;
        if (type == 1) 
            t1.push_back(v);
        else 
            t2.push_back(v);
    }
    sort(t1.begin(), t1.end(), compare);
    sort(t2.begin(), t2.end(), compare);
    vector<vehicle> store;
    int ans = 0;
    for (int i=0; i < t2.size() && V >= 2; i++) {
        store.push_back(t2[i]);
        max_id = max(max_id, t2[i].id);
        flag[t2[i].id] = true;
        V -= 2;
        ans += t2[i].cap;
    }
    int p1=store.size()-1, p2=0;
    for (; p2 < t1.size() && V > 0; p2++) {
        store.push_back(t1[p2]);
        max_id = max(max_id, t1[p2].id);
        flag[t1[p2].id] = true;
        V -= 1;
        ans += t1[p2].cap;
    }
    while (p2 < t1.size() && p1 >= 0) {
        if (p2+1 < t1.size() && t1[p2].cap+t1[p2+1].cap > store[p1].cap) {
            ans += t1[p2].cap+t1[p2+1].cap - store[p1].cap;
            flag[store[p1].id] = false;
            flag[t1[p2].id] = flag[t1[p2+1].id] = true;
            max_id = max(max_id, max(t1[p2].id, t1[p2+1].id));
            p2 += 2;
            p1--;
        }
        else if (t1[p2].cap > store[p1].cap) {
            ans += t1[p2].cap - store[p1].cap;
            flag[store[p1].id] = false;
            flag[t1[p2].id] = true;
            max_id = max(max_id, t1[p2].id);
            p2++;
            p1--;
        }
        else
            break;
    }
    cout << ans << '\n';
    for (int i=0; i < N; i++) {
        if (!flag[i])
            continue;
        cout << i+1;
        if (i != max_id)
            cout << ' ';
        else {
            cout << '\n'; break;
        }
    }
}
