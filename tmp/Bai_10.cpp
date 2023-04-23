int n;
int vs[100], d[100], e[100];
void PRIM(int a[][], int u) {
	for (int v = 1; v <= n; v++) {
		vs[v] = 0;
		d[v] = a[u][v];
		e[v] = u;
	}
	vs[u] = 1;
	d[u] = 0;
	e[u] = 0;
	int wt = 0, dem = 1;
	while (dem < n) {
		int s = 0;
		int min = 30000;
		for (int v = 1; v <= n; v++) {
			if (vs[v] == 0 && d[v] < min) {
				min = d[v];
				s = v;
			}
		}
		if (s == 0) {
			cout << "Khong co cay khung";
			return;
		}
		vs[s] = 1;
		wt = wt + a[s][e[s]];
		for (int v = 1; v <= n; v++) {
			if (vs[v] == 0 && d[v] > a[s][v]) {
				d[v] = a[s][v];
				e[v] = s;
			}
		}
	}
	cout << wt << endl;
	for (int v = 1; v <= n; v++) {
		if (e[v] != 0) {
			cout << v << " " << e[v] << endl;
		}
	}
	return;
}