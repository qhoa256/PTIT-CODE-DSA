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
map<ll, node *> mp;
void insert_node(node *&root, ll u, ll v, char c)
{
	if (mp.find(u) == mp.end())
	{
		root = new node(u);
		if (c == 'L')
		{
			root->left = new node(v);
			mp[v] = root->left;
		}
		else
		{
			root->right = new node(v);
			mp[v] = root->right;
		}
		mp[u] = root;
	}
	else
	{
		if (root->data == u)
		{
			if (c == 'L')
			{
				mp[u]->left = new node(v);
				mp[v] = mp[u]->left;
			}
			else
			{
				mp[u]->right = new node(v);
				mp[v] = mp[u]->right;
			}
		}
		else
		{
			if (root->left != NULL)
				insert_node(root->left, u, v, c);
			if (root->right != NULL)
				insert_node(root->right, u, v, c);
		}
	}
}
bool isLeave(node *root)
{
	if (root == NULL)
		return false;
	if (root->left == NULL && root->right == NULL)
		return true;
	else
		return false;
}
ll sum(node *root)
{
	if (root == NULL)
		return 0;
	ll res = 0;
	if (isLeave(root->right))
		res = root->right->data;
	if (root->right)
		res += sum(root->right);
	if (!isLeave(root->left) && (root->left))
		res += sum(root->left);
	return res;
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
		ll n;
		cin >> n;
		ll u, v;
		char c;
		node *root = NULL;
		while (n--)
		{
			cin >> u >> v >> c;
			insert_node(root, u, v, c);
		}
		cout << sum(root) << endl;
		root = NULL;
		delete root;
		mp.clear();
	}
	return 0;
}