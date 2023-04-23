int n, s, a[100][100], d[100], e[100], vs[100];
void DIJKSTRA(int u) {
	int s, v;
	for (v = 1; v <= n; v++) {
		d[v] = a[u][v];
		e[v] = u;
	}
	d[u] = 0;
	e[u] = 0;
	vs[u] = 1;
	while (1) {
		int s = 0;
		min = 32767;
		for (v = 1; v <= n; v++) {
			if (vs[v] == 0 && d[v] < min) {
				s = v;
				min = d[v];
			}
		}
		if (s == 0) return;
		vs[s] = 1;
		for (v = 1; v <= n; v++) {
			if (vs[v] == 0 && d[v] > d[s] + a[s][v]) {
				d[v] = d[s] + a[s][v];
				e[v] = s;
			}
		}
	}
}