#include<bits/stdc++.h>
using namespace std;

int d[1005], n;

struct edge{
	int st, en, w;
};

vector<edge>ds;

bool Bellmanford(int s){ //Kiem tra co chu trinh am
	//Buoc 0: Khoi tao
	for(int i=1;i<=n;i++) d[i] = INT_MAX;
	d[s] = 0;
	
	//Buoc lap: Lap n-1 lan, moi lan chon ra 1 dinh x, moi dinh x tim cac dinh y co duog di vao x
	//Ta luon tim cach cap nhat d[x] (dinh dich)
	for(int i=1;i<=n;i++){
		for(auto it: ds){
			int x = it.st, y = it.en, z = it.w;
			if(d[x]!=INT_MAX && d[y] > d[x] + z) d[y] = d[x] + z;
		}
	}
	
	//Buoc lap cuoi cung van cap nhat --> Co chu trinh am
	for(auto it: ds){
		int x = it.st, y = it.en, z = it.w;
		if(d[x]!=INT_MAX && d[y] > d[x] + z){
			d[y] = d[x] + z;
			return true;
		}
	}
	return false;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		ds.clear();
		int canh;
		cin>>n>>canh;
		while(canh--){
			int x, y, w;
			cin>>x>>y>>w;
			ds.push_back({x, y, w});
		}
		int check = 0;
		for(int i=1;i<=n;i++){
			if(Bellmanford(i)){
				check =  1;
				break;
			}
		}
		cout<<check<<endl;
	}
}