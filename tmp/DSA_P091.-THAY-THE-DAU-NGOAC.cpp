#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    cin.ignore();
    while (t--){
        string s;
        cin >> s;
        stack<int> st;     // stack nay luu vi tri cac dau sai
        int a[1005] = {0}; // a[i] = 1: Ngoac vi tri i dung/vi tri do khong la dau ngoac, a[i] = 0: Ngoac vi tri i sai
        for (int i = 0; i < s.size(); i++) a[i] = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty()){
                    // Danh dau dau mo 0 dau dong la 1
                    a[i] = 1;
                    a[st.top()] = 0;
                    st.pop();
                } else {
                    a[i] = -1;
                }
            }
        }
        while (!st.empty()){
         // Trong stack toan vi tri ngoac sai
            int p = st.top();
            a[p] = -1;
            st.pop();
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == ')') cout << a[i];
            else cout << s[i];
        }
        cout << endl;
    }
}