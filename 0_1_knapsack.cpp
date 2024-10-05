#include<bits/stdc++.h>
using namespace std;

#define sort(a)        sort(a, a+n)
#define yes            cout << "YES" << endl
#define no             cout << "NO" << endl
#define ll             long long int
#define tc             int t; cin >> t; while(t--)
#define cin(n)         int n; cin >> n
#define vi             vector<int>
#define fl(i, a, b)    for(int i = a; i <= b; i++)
#define fr(i, b, a)    for(int i = b; i >= a; i--)
#define input(a, n)    for(int i = 0; i < n; i++) cin >> a[i]
#define loop(n)        for(int i = 0; i < n; i++)
#define mod            1000000007
#define endl           '\n'
#define FastRead()     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

void solve()
 {
    int n;
    cin >> n;
    int w[n+1], p[n+1];
    int c;
    cin >> c;
    
    for(int i = 1 ; i <= n ; i++) {
        cin >> w[i] >> p[i];
    }
    
    int k[n+1][c+1];
    
    for(int i = 0; i <= n; i++)
     {
        for(int j = 0; j <= c; j++)
         {
            if(i == 0 || j == 0) 
            {
                k[i][j] = 0;
            } 
            else if(w[i] <= j)
             {
                k[i][j] = max(k[i-1][j], k[i-1][j-w[i]] + p[i]);
            } 
            else 
            {
                k[i][j] = k[i-1][j];
            }
             cout << k[i][j] << " ";
        }
         cout << endl;
       
    }
    
   
}

int main() {
    FastRead();
    solve();
    return 0;
}
