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
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
struct nut
{
    bool kt ;
    int num = 0;
    int c[30];
};
nut Tr[2000005];
int dept[2000005];
int n, cnt = 0;
void add(string s)
{
    int x = 0;
    for (int i = 0; i < s.size(); i ++)
    {
        int w = s[i] - 'a';
        if(!Tr[x].c[w]) Tr[x].c[w] = ++cnt;
        x = Tr[x].c[w];
        dept[x] = i + 1;
    }
    Tr[x].kt = 1;
}
int find_string(string s)
{
    int x = 0;
    for (int i = 0; i < s.size(); i ++)
    {
        char ch = s[i];
        int w = ch - 'a';
        if(!Tr[x].c[w]) return 0;
        x = Tr[x].c[w];
    }
    return Tr[x].num;
}
void nhap() {
    cin >> n;
    while (n --)
    {
        cin >> s;
        add(s);
    }
}
int main() {
    nhap();
    cin >> m;
    while (m --)
    {
        cin >> s;
        cout << find_string(s) << "\n";
    }
}
