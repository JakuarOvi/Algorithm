#include <bits/stdc++.h>
using namespace std;

int main()
 {
    int n;
   
    cin >> n;

    set<pair<int, int>> act;

    for (int i = 0; i < n; i++) {
        int start, finish;
        cin >> start >> finish;
        act.insert({finish, start}); 
    }

    int count = 0;
    int lastFinishTime = 0;

    cout << "Selected activities :\n";
    for (auto activity : act)
    {
        if (activity.second >= lastFinishTime) 
        { 
            cout << "(" << activity.second << " , " << activity.first << ")\n";
            lastFinishTime = activity.first; 
            count++;
        }
    }

    cout << "Maximum number of activities: " << count << endl;

    return 0;
}
