//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <int,int>
#define vi vector <int>
#define F first
#define S second
#define reset(x) memset(x,0,sizeof(x))
#define sz(x) int(x.size())
#define Task "proF"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
struct nut{
    bool kt = 0;
    int c[30];
    ll num;
};
nut Tr[2000005];
ll dp[2000005], dept[2000005];
int n, cnt = 0;
void add(string s)
{
    int x = 0;
    for (int i = 0; i < s.size(); i ++)
    {
        int w = s[i] - 'a';
        if(!Tr[x].c[w]) Tr[x].c[w] = ++ cnt;
        x = Tr[x].c[w];
        dept[x] = i + 1;
    }
    Tr[x].kt = 1;
}
ll tinhdp(int x)
{
    if (dp[x]) return dp[x];
    if (Tr[x].kt)
    {
        dp[x] = 1ll << (40 - dept[x]);
        return dp[x];
    }
    for (int i = 0; i < 26; i ++)
        if(Tr[x].c[i]) Tr[x].num += tinhdp(Tr[x].c[i]);
    dp[x] = min(Tr[x].num, 1ll << (40 - dept[x]));
    return dp[x];
}
void nhap() {
    cin >> n;
    while (n --)
    {
        string s;
        cin >> s;
        add(s);
    }
}
int main() {
    nhap();
    tinhdp(0);
    cout << Tr[0].num;
}
