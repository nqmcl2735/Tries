//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <int,int>
#define vi vector <int>
#define F first
#define S second
#define maxn 100005
#define reset(x) memset(x,0,sizeof(x))
#define sz(x) int(x.size())
#define Task "proG"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int n, m, res;
string a, s[maxn];
struct nut
{
    bool kt ;
    int c[26];
    int pos = 0;
};
nut Tr[1000005];
int cnt = 0;
void add(string s, int i)
{
    int x = 0;
    for(int i = 0; i < s.size(); i++){
        int w = s[i] - 'a';
        if(!Tr[x].c[w]) Tr[x].c[w] = ++cnt;
        x = Tr[x].c[w];
    }
    if(!Tr[x].pos) Tr[x].pos = i;
}
void find_string(int x, int i){
    int ps = Tr[x].pos;
    if(ps){
        if(sz(s[res]) == sz(s[ps])) res = min(res, ps);
        if(sz(s[res]) < sz(s[ps])) res = ps;
    }
    if(i == sz(a)) return;
    find_string(x, i+1);
    int ch = a[i] - 'a';
    if(!Tr[x].c[ch]) return;
    find_string(Tr[x].c[ch], i+1);
}
string convert(string s)
{
    string ss = s;
    sort(ss.begin(), ss.end());
    return ss;
}
void nhap() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> s[i];
    sort(s + 1, s + n + 1);
    for (int i = 1; i <= n; i ++) add(convert(s[i]), i);
}
int main() {
    nhap();
    cin >> m;
    while (m --)
    {
        cin >> a;
        a = convert(a);
        res = 0;
        find_string(0, 0);
        if (res) cout << s[res] << "\n";
        else cout << "IMPOSSIBLE\n";
    }
}
