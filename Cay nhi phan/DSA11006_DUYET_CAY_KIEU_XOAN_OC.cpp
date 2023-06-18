#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

int n;
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
void spiralOrder(binTree root)
{
	stack<binTree> st1, st2;
	st1.push(root);
	binTree top;
	while (st1.size() or st2.size())
	{
		while (st1.size())
		{
			top = st1.top();
			st1.pop();
			cout << top->val << ' ';
			if (top->right)
				st2.push(top->right);
			if (top->left)
				st2.push(top->left);
		}
		while (st2.size())
		{
			top = st2.top();
			st2.pop();
			cout << top->val << ' ';
			if (top->left)
				st1.push(top->left);
			if (top->right)
				st1.push(top->right);
		}
	}
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
		spiralOrder(root);
		cout << "\n";
	}
	return 0;
}