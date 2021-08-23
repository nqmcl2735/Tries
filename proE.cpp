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
#define Task "proE"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int n;
int a[maxn];
struct nut
{
    int num = 0;
    int c[3];
    int val;
};
nut Tr[10000000];
int cnt = 0;
int res = 0;
void add(int x)
{
    int node = 0;
    for (int i = 30; i >= 0; i--)
    {
        int ch = (x >> i) & 1;
        if (Tr[node].c[ch] == 0) Tr[node].c[ch] = ++ cnt;
        node = Tr[node].c[ch];
        Tr[node].num ++;
    }
    Tr[node].val = x;
 //   fo << node << " " << x << "\n";
}
void get(int x){
    int node = 0;
    for (int i = 30; i >= 0; i--)
    {
        int ch = (x >> i) & 1;
        if (Tr[node].c[ch ^ 1]) node = Tr[node].c[ch ^ 1];
        else node = Tr[node].c[ch];
    }
    res = max(res, x ^ Tr[node].val);
}
void nhap() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        add(a[i]);
    }
}
int main() {
   nhap();
   for (int i = 1; i <= n; i ++)
        get(a[i]);
   cout << res;
}
