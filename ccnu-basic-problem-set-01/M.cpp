#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
using namespace std;
#define LL long long
const int MAXN = 5005;
struct node {
    int id, w, h;
    node (){}
    node (int x, int y, int z) : id(x), w(y), h(z){}
};
vector<node> vec;
int ans[MAXN]={0}, pre[MAXN]={0}, max_len=1;
bool cmp (node& n1, node& n2) {
    return n1.w < n2.w;
}

void print (int id) {
    if (id == 0)
        return;
    print (pre[id]);
    cout << vec[id].id << (ans[id] == max_len ? '\n' : ' ');
}
int main() {
    ios_base::sync_with_stdio(false);
    int n, cw, ch, id = 1;
    cin >> n >> cw >> ch;
    vec.push_back(node(0, cw, ch));
    for (int i=1; i <= n; i++) {
        node nd;
        cin >> nd.w >> nd.h;
        if (cw >= nd.w || ch >= nd.h)
            continue;
        nd.id = i;
        vec.push_back(nd);
    }
    if (vec.size() == 1) {
        cout << "0\n";
        return 0;
    }
    sort(vec.begin(), vec.end(), cmp);
    for (int i=1; i < vec.size(); i++) {
        ans[i] = 1;
        for (int k=i-1; k >= 1; k--) {
            if (vec[k].w < vec[i].w && vec[k].h < vec[i].h && ans[i] < ans[k]+1) {
                pre[i] = k;
                ans[i] = ans[k]+1;
            }
        }
        if (max_len < ans[i]) {
            id = i;
            max_len = ans[i];
        }
    }
//    for (int i=0; i < vec.size(); i++)
//        cout << ans[i] << '\n';
//        cout << vec[i].w << " " << vec[i].h << '\n';
    cout << max_len << '\n';
    print(id);
}
