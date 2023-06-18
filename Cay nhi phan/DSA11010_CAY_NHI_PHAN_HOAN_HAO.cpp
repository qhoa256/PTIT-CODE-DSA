#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

int n;
int check;
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

typedef Node *binTree;

void buildTree(binTree &root, int x, int y, char z)
{
	if (root == NULL)
	{
		root = new Node(x);
		if (z == 'L')
			root->left = new Node(y);
		else
			root->right = new Node(y);
	}
	else
	{
		if (root->val == x)
		{
			if (z == 'L')
				root->left = new Node(y);
			else
				root->right = new Node(y);
		}
		else
		{
			if (root->left)
				buildTree(root->left, x, y, z);
			if (root->right)
				buildTree(root->right, x, y, z);
		}
	}
}

void check1(binTree root)
{
	if (root)
	{
		if (!check)
			return;
		if (root->left == NULL and root->right)
		{
			check = 0;
			return;
		}
		if (root->left and root->right == NULL)
		{
			check = 0;
			return;
		}
		check1(root->left);
		check1(root->right);
	}
}

int check2(binTree root)
{
	queue<pair<binTree, int>> q;
	q.push({root, 0});
	int level = -1;
	while (q.size())
	{
		auto top = q.front();
		q.pop();
		if (top.first->left == NULL)
		{
			if (level == -1)
				level = top.second;
			else if (level != top.second)
				return 0;
		}
		else
			q.push({top.first->left, top.second + 1});
		if (top.first->right == NULL)
		{
			if (level == -1)
				level = top.second;
			else if (level != top.second)
				return 0;
		}
		else
			q.push({top.first->right, top.second + 1});
	}
	return 1;
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
		cin >> n;
		binTree root = NULL;
		while (n--)
		{
			int x, y;
			char z;
			cin >> x >> y >> z;
			buildTree(root, x, y, z);
		}
		check = 1;
		check1(root);
		if (check + check2(root) == 2)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}