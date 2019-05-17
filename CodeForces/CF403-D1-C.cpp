/*
Same as Editorial
*/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

typedef long long ll;
#define cerr cout
#define sz(a) (int)((a).size())
#define all(x) (x).begin(), (x).end()
string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
inline int add(int a, int b){a += b; if(a >= MOD)a -= MOD; return a;}
inline int sub(int a, int b){a -= b; if(a < 0)a += MOD; return a;}
inline int mul(int a, int b){return (int)((long long) a * b %MOD);}
inline int binpow(int a, int b){int res = 1; while(b > 0){ if(b & 1)res = mul(res, a); a = mul(a, a);b /= 2;} return res;}
inline int inv(int a){return binpow(a, MOD - 2);}
int gcd(int a, int b, int &x, int &y){if(a == 0){x = 0, y = 1; return b;} int x1, y1;  int d = gcd(b%a, a, x1, y1); x = y1 - (b/a) * x1; y = x1; return d;}

const int N = 2005;
vector<int> g[N], rev[N]; 
int n, a[N][N]; 

bool bfs(vector<int> adj[N], int src){
    vector<int> level(n + 1, N);
    queue<int> q; 
    q.push(src); level[src] = 0; 
    while(!q.empty()){
        int v = q.front(); q.pop(); 
        for(int u : adj[v])if(level[v] + 1 < level[u]){
            level[u] = level[v] + 1; 
            q.push(u); 
        }
    }

    for(int i=1;i<=n;++i)if(level[i] == N)return false; 
    return true; 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    int id ; 
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j){
            cin>>a[i][j]; 
            if(i == j){
                if(a[i][j])id = i; continue; 
            } 
            if(a[i][j]){
                g[i].push_back(j); rev[j].push_back(i); 
            }
        }
    if(bfs(g, id) && bfs(rev, id))cout<<"YES\n"; 
    else cout<<"NO\n"; 

    return 0;
}
