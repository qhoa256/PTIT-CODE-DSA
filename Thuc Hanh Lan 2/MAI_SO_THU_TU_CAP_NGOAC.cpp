#include<bits/stdc++.h>

using namespace std;
int main()
{
    int t;
    cin >> t;
    string s;
    cin.ignore();
    while(t--)
    {
        getline(cin, s);
        int cnt = 1;
        stack<int> st;
        for(char &i : s)
        {
            if(i == '(')
            {
                st.push(cnt);
                cout << cnt << ' ';
                ++cnt;
            }
            else if(i == ')')
            {
                cout << st.top() << ' ';
                st.pop();
            }
        }
        cout << endl;
    }
    return 0;
}