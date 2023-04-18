#include<bits/stdc++.h>
using namespace std;

int ke[100][100], deg[100], color[100];

bool cmp(pair<int, int>a, pair<int, int>b) {
	return a.second > b.second; //Dinh co bac lon hon thi xet truoc
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(deg, 0, sizeof(deg));
		memset(color, 0, sizeof(color));
		memset(ke, 0, sizeof(ke));
		int v, e, m;//v: dinh, e: canh, m: so mau toi da duoc phep de to do thi
		cin >> v >> e >> m;
		while (e--) {
			int x, y;
			cin >> x >> y;
			ke[x][y] = ke[y][x] = 1;
			deg[x]++; deg[y]++;
		}
		vector<pair<int, int>>ds;
		for (int i = 1; i <= v; i++) ds.push_back({i, deg[i]});
		sort(ds.begin(), ds.end(), cmp);
		int cnt = 0;
		//Moi lan se chon ra dinh co bac to nhat de to mau (Neu to roi thi thoi)

		for (auto i : ds) {
			int x = i.first; //Dinh duoc xet
			if (color[x] == 0) { //Dinh ay chua duoc to mau
				cnt++;
				//To mau thu cnt cho dinh duoc xet
				color[x] = cnt;
				//Bay gio to chinh mau ay cho cac dinh khong ke voi dinh duoc xet ma chua duoc to
				for (int j = 1; j <= v; j++) {
					if (color[j] == 0 && ke[x][j] == 0) color[j] = cnt;
				}
			}
		}

		if (cnt <= m) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}