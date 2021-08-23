//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <int,int>
#define vi vector <int>
#define F first
#define S second
#define reset(x) memset(x,0,sizeof(x))
#define sz(x) int(x.size())
#define Task ""
#define maxn 2000005
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
struct nut
{
    int c[30];
    int pass = 0;
};
int n, q;
nut Tr[maxn];
int cnt = 0;
int res[maxn];
map <string, int> mp;
string s;
int Add(string s){
    int sum = 0, x = 0;
    for (int i = 0; i < sz(s); i ++){
        int ch = s[i] - 'a';
        if (!Tr[x].c[ch]) Tr[x].c[ch] = ++cnt;
        x = Tr[x].c[ch];
        Tr[x].pass++;
        sum += Tr[x].pass;
    }
    return sum;
}
int find_string(string s)
{
    int sum = 0;
    int x = 0;
    for (int i = 0; i < sz(s); i ++){
        int ch = s[i] - 'a';
        if (!Tr[x].c[ch]) Tr[x].c[ch] = ++cnt;
        x = Tr[x].c[ch];
        sum += Tr[x].pass;
    }
    return sum;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> s;
        res[i] = Add(s) + i;
        if (!mp[s]) mp[s] = i;
    }
    cin >> q;
    while (q --)
    {
        cin >> s;
        if (!mp[s]) cout << find_string(s) + n << "\n";
        else cout << res[mp[s]] << "\n";
    }
}
