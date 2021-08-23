//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <int,int>
#define vi vector <int>
#define F first
#define S second
#define reset(x) memset(x,0,sizeof(x))
#define sz(x) int(x.size())
#define Task "TOPONYM"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int n;
string s[1000005];
stack<string> stk;
void nhap() {
    fi >> n;
    for (int i = 1; i <= n; i ++)
        fi >> s[i];
}
int main() {
    sort(s + 1, s + n + 1);
    for (int i = 1; i <= n; i ++)
        fo << s[i] << endl;
}
