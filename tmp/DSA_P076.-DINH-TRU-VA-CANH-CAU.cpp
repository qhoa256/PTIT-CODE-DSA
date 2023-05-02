#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];
int visited[1005]={};
vector<pair<int,int>>dscanh;

void DFS(int x){
	visited[x]=1;
	for(int i: ke[x]){
		if(visited[i]==0) DFS(i);
	}
}

void DFS2(int u, int x, int y){//Loang tu dinh u nhung loai canh (x,y)
	visited[u]=1;
	for(int i: ke[u]){
		//(i,u)=(x,y)--> Loai
		if((i==x&&u==y)||(i==y&&u==x)){
			continue;
		}
		if(visited[i]==0){
			DFS2(i,x,y);
		}
	}
}

int main(){
	int dinh, canh;
	cin>>dinh>>canh;
	while(canh--){
		int dau, cuoi;
		cin>>dau>>cuoi;
		ke[dau].push_back(cuoi);
		ke[cuoi].push_back(dau);
		dscanh.push_back({dau,cuoi});
	}
	int cntgoc=0;
	for(int i=1;i<=dinh;i++){
		if(visited[i]==0){
			DFS(i);
			cntgoc++;
		}
	}
	int cnttru = 0;
	for(int i=1;i<=dinh;i++){
		memset(visited,0,sizeof(visited));
		visited[i]=1;//Khong cho DFS vao i
		int cnt  = 0;
		for(int j=1;j<=dinh;j++){
			if(visited[j]==0){
				cnt++;
				DFS(j);
			}
		}
		if(cnt>cntgoc) cnttru++;
	}
	int cntcau = 0;
	for(auto i: dscanh){
		memset(visited,0,sizeof(visited));
		int cnt = 0;
		int x = i.first;
		int y = i.second;
		for(int j = 1;j<=dinh;j++){
			if(visited[j]==0){
				cnt++;
				DFS2(j,x,y);
			}
		}
		if(cnt>cntgoc) cntcau++;
	}
	cout<<cnttru<<" "<<cntcau;
}
/*
10 12
1 10
10 2
10 3
2 4
4 5
5 2
3 6
6 7
7 3
7 8
8 9
9 7 */