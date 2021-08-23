//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <int,int>
#define vi vector <int>
#define F first
#define S second
#define reset(x) memset(x,0,sizeof(x))
#define sz(x) int(x.size())
#define Task "proD"
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
int q, a;
struct nut
{
    int num = 0;
    int c[2];
    int val;
};
nut Tr[10000000];
int cnt = 0;
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
}
int get(int k){
    int node = 0;
    ll res = 0;
    for (int i = 30; i >= 0; i--)
    {
        if (Tr[node].c[0] == 0 || k > Tr[Tr[node].c[0]].num){
            k -= Tr[Tr[node].c[0]].num;
            node = Tr[node].c[1];
            res = res * 2 + 1;
        } else
        {
            node = Tr[node].c[0];
            res *=2;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    while(n --)
    {
        cin >> q >> a;
        if (q == 1) add(a);
        else cout << get(a) << "\n";
    }
}
