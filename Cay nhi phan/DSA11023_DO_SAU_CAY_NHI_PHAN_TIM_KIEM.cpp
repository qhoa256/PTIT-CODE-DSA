#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

struct Node
{
	int val;
	Node *left, *right;
	Node(int val)
	{
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
};

typedef Node *node;

void buildTree(node &root, int x)
{
	if (!root)
		root = new Node(x);
	else
	{
		if (root->val > x)
			buildTree(root->left, x);
		else
			buildTree(root->right, x);
	}
}
int levelOrder(node root)
{
	queue<pair<node, int>> q;
	q.push({root, 0});
	int cnt = -1;
	while (q.size())
	{
		auto top = q.front();
		q.pop();
		cnt = max(cnt, top.second);
		if (top.first->left)
			q.push({top.first->left, top.second + 1});
		if (top.first->right)
			q.push({top.first->right, top.second + 1});
	}
	return cnt;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		node root = NULL;
		while (n--)
		{
			int x;
			cin >> x;
			buildTree(root, x);
		}
		cout << levelOrder(root) << "\n";
	}
	return 0;
}