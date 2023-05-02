#include<bits/stdc++.h>
using namespace std;

int n; string s = "2357"; vector<string>v;

int check(string s){
	if(s.back()=='2') return 0;
	set<char>sc;
	for(auto i: s) sc.insert(i);
	if(sc.size()==4) return 1;
	else return 0;
}

void gen(){
	//Buoc 1: Khoi tao
	queue<string>q;
	for(char i: s){
		string tmp = ""; tmp+=i;
		q.push(tmp);
	}
	//Buoc 2: Lap
	while(1){
		string x = q.front();
		q.pop();
		if(x.size()==n) break;
		for(char i: s){
			string s1 = x + i;
			q.push(s1);
			if(check(s1)&&s1.size()>=4) v.push_back(s1);
		}
	}
}

int main(){
	cin>>n;
	gen();
	for(auto i: v) cout<<i<<endl;
}