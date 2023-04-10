#include<bits/stdc++.h>
using namespace std;
int main () {
	int t;    // quay dau ')' khi chua co '(' va dem so '(' con du roi lay tong chia 2 cong vao ans
	cin>>t;
	cin.ignore();
	string s;
	while(t--) {
		int n;
		cin>>n;
		vector<string>v;
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			v.push_back(s);
		}
		stack<long long> st;
		for(int i = v.size() - 1 ; i >= 0 ;i--){
			int tmp = 0;
			if(v[i] == "+" ||v[i] == "-" ||v[i] == "*" ||v[i] == "/" ){
				tmp +=st.top() ;
				st.pop();
				if(v[i] == "+") tmp += st.top();
				else if(v[i] == "-") tmp -= st.top();
				else if(v[i] == "*") tmp *= st.top();
				else if(v[i] == "/") tmp /= st.top();
				st.pop();
				st.push(tmp);
			} else {
				int x = stoi(v[i]);
				st.push(tmp + (stoi(v[i])));
			}
 
		}
		while(!st.empty()){
			cout << st.top();
			st.pop();
		}
		cout << endl;
	}
}
/*3
7
- + 2 * 3 1 9
7
- + 8 * 7 5 9
3
+ -10 -4 */