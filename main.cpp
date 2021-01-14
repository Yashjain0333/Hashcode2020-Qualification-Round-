% % writefile test.cpp

//BY: YASH JAIN, CF: yashjain0333
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define May_the_fork_be_with_you ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define rall(v) v.rbegin(),v.rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define deb(x) cout<<#x<<": "<<x<<endl;
#define debn(x) cout<<#x<<": "<<x<<"  ";
#define MOD 1000000007
#define mod 998244353
#define INF 1e18
#define ll long long
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define int long long
#define N 100005
#define sq(x) ((x)*(x))
typedef vector<int> vi;
ll gcd(ll a, ll b) {if (!b)return a; return gcd(b, a % b);}
ll power(ll x, ll y, ll p = INF) {ll res = 1; x %= p; while (y > 0) {if (y & 1)res = (res * x) % p; y = y >> 1; x = (x * x) % p;} return res;}
// Do Not use power when calculating powers of 2 (its inefficient)

unordered_map<int, int> scb;
unordered_map<int, pair<int, int>> sc;
int B, L, D;
vi ship;
vector<vector<int>> books;
vector<pair<int, int>> signup;
vector<bool> vis;

bool comp(int a, int b) {
    return scb[a] > scb[b];
}

bool comp1(pair<int, int> pa, pair<int, int> pb) {
    int a = pa.s, b = pb.s;
    int books_a = sc[a].f, books_b = sc[b].f;
    int per_a = sc[a].s, per_b = sc[b].s;
    if (per_a != per_b) return per_a > per_b;
    else return books_a > books_b;
}

int find_idx(int allow) {
    vector<int> score(L);
    int mux = -INF, idx = -1;
    forn(i, L) {
        if (vis[i]) continue;
        int time = (allow - signup[i].f) * ship[i];
        int cur = 0;
        sort(all(books[i]), comp);
        for (int j = 0; j < min(time, (int)books[i].size()); j++) {
            cur += scb[books[i][j]];
        }
        if (cur == 0) cur = -INF;
        // adding penulty for large signup time
        else cur -= signup[i].f * 1100;
        if (cur > mux) {
            mux = cur;
            idx = i;
        }
    }
    return idx;
}

void solve() {
    cin >> B >> L >> D;
    forn(i, B) {
        int x; cin >> x;
        scb[i] = x;
    }
    ship.resize(L); signup.resize(L); vis.resize(L);
    forn(i, L) {
        vis[i] = false;
        int sz; cin >> sz;
        cin >> signup[i].f >> ship[i];
        signup[i].s = i;
        vi cur(sz);
        forn(j, sz) cin >> cur[j];
        books.eb(cur);
    }
    forn(i, L) {
        int num = books[i].size();
        int per = ship[i];
        sc[i] = {num, per};
    }
    // sort(all(signup), comp1);
    // sort(all(signup));
    // shuffle(all(signup), default_random_engine(143));
    int score = 0, days = 0, i = 0;
    // cout << i << endl;
    vector<vector<int>> res;
    while (days <= D) {
        int idx = find_idx(D - days);
        if (idx == -1) break;
        days += signup[idx].f;
        vis[idx] = true;
        int time = (D - days) * ship[i];
        int add = 0;
        vector<int> cur;
        cur.eb(idx); cur.eb(min(time, (int)books[idx].size()));
        for (int j = 0; j < min(time, (int)books[idx].size()); j++) {
            add += scb[books[idx][j]];
            cur.eb(books[idx][j]);
            scb[books[idx][j]] = 0;
        }
        // deb(idx)
        res.eb(cur);
        score += add;
    }
    cout << res.size() << endl;
    for (auto x : res) {
        cout << x[0] << " " << x[1] << endl;
        for (int j = 0; j < x[1]; j++) {
            cout << x[2 + j] << " ";
        }
        cout << endl;
    }
    deb(score)
}

int32_t main() {

#ifndef ONLINE_JUDGE
    // for geting input form input.txt
    freopen("d.txt", "r", stdin);
    // for wrting output to output.txt
    freopen("d(out).txt", "w", stdout);
#endif

    May_the_fork_be_with_you
    int t = 1;
    int x = 1;
    // cin >> t;
    cout << fixed << setprecision(12);
    while (t--) {
        // cout << "Case #" << x << ": ";
        solve();
        x++;
    }

    cerr << "Time Taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
}