int n, u;
void EULER(int a[][]) {
	int top = 0, v;
	top++;
	s[top] = u;
	k = 0;
	while (top > 0) {
		int v = s[top];
		int ok = 1;
		for (int x = 1; x <= n; x++) {
			if (a[v][x] == 1) {
				top++;
				s[top] = x;
				ok = 0;
				a[v][x] = 0;
				a[x][v] = 0;
				break;
			}
		}
		if (ok == 1) {
			k++;
			ce[k] = v;
			top--;
		}
	}
	for (v = k; v > 0; v--) {
		cout << ce[v] << " ";
	}
}