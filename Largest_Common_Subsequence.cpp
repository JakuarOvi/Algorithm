#include <bits/stdc++.h>
using namespace std;


int main() {
    string s1 , s2;
    cin >> s1 >> s2;
    int m = s1.length();
    int n = s2.length();
    s1 = " " + s1;
    s2 = " " + s2;
    int k[m+1][n+1];
    for(int i = 0 ; i <= m ; i++ )
    {
        for(int j = 0 ;j <= n ; j++)
        {
            if(i == 0 || j == 0)
            {
                k[i][j] = 0 ;
            }
            else if(s1[i] == s2[j])
            {
                k[i][j] = k[i-1][j-1] + 1;
            }
            else
            {
                k[i][j] = max(k[i-1][j],k[i][j-1]);
            }
            cout << k[i][j] << " ";
        }
        cout << endl;
    }

    int i = m , j = n;
    string x;
    while(i > 0 && j>0)
    {
        if(k[i][j-1] == k[i][j])
        {
            j--;
        }
        else if(k[i-1][j] == k[i][j])
        {
            i--;
        }
        else
        {
            x += s1[i];
            i--;
            j--;
        }

    }
    reverse(x.begin(),x.end());
        cout << x << endl;
    return 0;
}
