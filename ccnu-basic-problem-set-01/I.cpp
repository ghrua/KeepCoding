#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
using namespace std;
#define LL long long
struct node {
    int id, a, b;
};
struct cmp {
    bool operator() (const node &n1, const node &n2) const {
        return n1.b-n1.a < n2.b-n2.a;
    }
};
priority_queue<node, vector<node>, cmp> pq;

int main() {
    ios_base::sync_with_stdio(false);
    string str;
    cin >> str;
    int cnt=0;
    LL ans=0;
    for (int i=0; i < str.size(); i++) {
        if (str[i] == '(')
            cnt++;
        else if (str[i] == ')')
            cnt--;
        else {
            node n;
            cin >> n.a >> n.b;
            n.id = i;
            str[i] = ')';
            ans += n.b;
            cnt--;
            pq.push(n);
        }
        if (cnt < 0) {
            if (pq.empty()) {
                cout << "-1\n";
                return 0;
            }
            node n = pq.top();
            pq.pop();
            ans -= n.b-n.a;
            str[n.id] = '(';
            cnt += 2;
        }
    }
    if (cnt != 0 || str[str.size()] == '(') {
        cout << "-1\n";
        return 0;
    }
    cout << ans << '\n';
    cout << str << '\n';
}
