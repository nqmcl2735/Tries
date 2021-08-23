//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <int,int>
#define vi vector <int>
#define F first
#define S second
#define MOD 1000000007
#define reset(x) memset(x,0,sizeof(x))
#define sz(x) int(x.size())
#define Task ""
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int n;
string s[10005];
string str;
struct nut
{
    bool kt ;
    int c[27];
};
nut Tr[1000005];
int dp[1000005];
int cnt = 0;
void cong(int &x, int y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}
void add(string s)
{
    int x = 0;
    for (int i = 0; i < s.size(); i ++)
    {
        char ch = s[i];
        int w = ch - 'a';
        if(!Tr[x].c[w]) Tr[x].c[w] = ++cnt;
        x = Tr[x].c[w];
    }
    Tr[x].kt = 1;
}
bool find_string(const string& s) {
    int x = 0;
    for (int i = 0; i < s.size(); i ++)
    {
        char ch = s[i];
        int w = ch - 'a';
        if(!Tr[x].c[w]) return 0;
        x = Tr[x].c[w];
    }
    return Tr[x].kt;
}
void nhap() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> s[i];
        add(s[i]);
    }
}
int main() {
    nhap();
    cin >> str;
    int m = sz(str);
    dp[0] = 1;
    for(int i = 0; i < m; i++){
        int x = 0;
        for(int j = i; j < m; j++){
            char ch = str[j];
            int w = ch - 'a';
            if(!Tr[x].c[w]) break;
            x = Tr[x].c[w];
            if(Tr[x].kt) cong(dp[j + 1], dp[i]);
        }
    }
    cout << dp[m];

}
