#include<bits/stdc++.h>
using namespace std;

void solve(string s)
{
	map<int, int> mp;
	for(int i = 0; i< s.size(); i++)
	{
		if(s[i] == '(' || s[i] == ')')
			mp[i] = -1;
		else mp[i] = 2;
	}
	
	stack<pair<char, int>> st;
	
	for(int i = 0; i< s.size(); i++)
	{
		if(s[i] == '(')
		{
			st.push({'(', i});
		}
		else if(s[i] == ')')
		{
			if(!st.empty() && st.top().first == '(')
			{
				mp[st.top().second] = 0;
				mp[i] = 1;
				st.pop();
			}
		}
	}
	
	for(int i = 0; i< s.size(); i++)
	{
		if(mp[i] == 2)
			cout << s[i];
		else cout << mp[i];
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		solve(s);
		cout << endl;
	}
}
