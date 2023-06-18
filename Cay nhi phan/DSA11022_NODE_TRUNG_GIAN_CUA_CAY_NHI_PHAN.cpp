#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define endl '\n'
using namespace std;

using ll = long long;

struct node
{
	ll data;
	node *left;
	node *right;
	node(ll value)
	{
		data = value;
		left = right = NULL;
	}
};
node *insert_node(node *root, ll u)
{
	if (root == NULL)
	{
		root = new node(u);
	}
	else
	{
		if (u < root->data)
			root->left = insert_node(root->left, u);
		else
			root->right = insert_node(root->right, u);
	}
	return root;
}
ll res = 1;
bool isleave(node *root)
{
	if (root == NULL)
		return false;
	else
	{
		if (root->left == NULL && root->right == NULL)
			return true;
		else
			return false;
	}
}
void cnt_parent(node *root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		if (root->left)
		{
			if (!isleave(root->left))
				res++;
			cnt_parent(root->left);
		}
		if (root->right)
		{
			if (!isleave(root->right))
				res++;
			cnt_parent(root->right);
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
	ll t;
	cin >> t;
	while (t--)
	{
		node *root = NULL;
		ll n;
		cin >> n;
		ll u;
		while (n--)
		{
			cin >> u;
			root = insert_node(root, u);
		}
		cnt_parent(root);
		cout << res << endl;
		res = 1;
		root = NULL;
		delete root;
	}
	return 0;
}