#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t; cin>>t;
	cin.ignore();
	while(t--)
	{
		string s; getline(cin,s);
		stack<pair<ll,ll>> st;
		ll f[256]={0};
		string res="";
		for(auto x:s) 
		{
			if(x!=' ') res+=x;
		}
		ll cnt1=0,cnt2=0;
		bool ok=false;
		for(ll i=0;i<res.size();i++)
		{
			if(res[i]=='(' && i==0)
			{
				st.push({0,-1});
			}
			else
			{
				if(res[i]=='(')
				{
					if(res[i-1]=='-')
					{
						st.push({i,1});
						cnt1++;
					}
					else
					{
						st.push({i,-1});
					}
				}
				else
				{
					if(res[i]==')')
					{
						auto top=st.top();
						st.pop();
						if(top.second==1)
						{
							if(cnt2==0 && cnt1!=0) // ko co toan hang nao
							{
								f[i]=f[top.first]=-1;
							}
							else
							{
								f[i]=f[top.first]=top.second;
								cnt1--;
								cnt2--;
								ok=false;
							}
						}
						else
						{
							f[i]=f[top.first]=top.second;
						}
					}
					else if(res[i]=='+' || res[i]=='-')
					{
						if(cnt1>=1 && ok==false)
						{
							cnt2++;
							ok=true;
						}
					}
				}
			}
		}
		for(ll i=0;i<res.size();i++)
			{
				if(res[i]=='(' || res[i]==')')
				{
					if(f[i]==1) cout<<res[i];
				}
				else cout<<res[i];
			}
			cout<<endl;

	}
	return 0;
}