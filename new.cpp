#include<bits/stdc++.h>
using namespace std;
using ll=long long;

void right(int a[],int n,int r[]){
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && a[i]<a[st.top()]){
            r[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        r[st.top()]=n;
        st.pop();
    }
}

void left(int a[],int n,int l[]){
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && a[i]<a[st.top()]){
            l[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        l[st.top()]=-1;
        st.pop();
    }
}
int main(){
        int n;
        cin>>n;
        int a[n];
        for(auto &x:a) cin>>x;
        int l[n],r[n];
        left(a,n,l);
        right(a,n,r);
        ll res=0;
        for(int i=0;i<n;i++){
               ll tmp=1ll*a[i]*(r[i]-l[i]-1);
               res=max(res,tmp);
        }
        cout<<res<<endl;
    return 0;
}
 
