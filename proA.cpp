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
#define Task "proA"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int n, m;
string s[maxn];
string qy;
struct nut
{
    bool kt ;
    int c[30];
};
nut Tr[500005];
int cnt = 0;
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
    cin >> m;
}
int main() {
    nhap();
    while (m --)
    {
        cin >> qy;
        cout << find_string(qy) << "\n";
    }
}
