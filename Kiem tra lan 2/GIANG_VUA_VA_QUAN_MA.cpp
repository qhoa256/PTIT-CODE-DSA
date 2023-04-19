#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n,xm,ym,xv,yv; 
char a[1005][1005];
bool flag[1005][1005];
bool visited[1005][1005];
int dp[1005][1005];
const int mx[8] = {-1,-2,-2,-1,1,2,2,1};
const int my[8] = {-2,-1,1,2,2,1,-1,-2};
int dp1[1005][1005];
const int vx[8] = {1,-1,0,0,1,-1,1,-1};
const int vy[8] = {1,1,1,-1,-1,-1,0,0};

void BFS(int i, int j){
    queue <pair<int,int>> q;
    q.push({i,j});
    visited[i][j] = true;
    while(!q.empty()){
        pair<int,int> x = q.front();
        q.pop();
        for(int k = 0; k < 8; k++){
            int i1 = x.first + mx[k], j1 = x.second + my[k];
            if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && !visited[i1][j1]){
                dp[i1][j1] = dp[x.first][x.second] + 1;
                q.push({i1,j1});
                visited[i1][j1] = true;
            }
        }
    }
}

void BFS1(int i, int j){
    queue <pair<int,int>> q;
    q.push({i,j});
    flag[i][j] = true;
    while(!q.empty()){
        pair<int,int> x = q.front();
        q.pop();
        for(int k = 0; k < 8; k++){
            int i1 = x.first + vx[k], j1 = x.second + vy[k];
            if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && !flag[i1][j1]){
                dp1[i1][j1] = dp1[x.first][x.second] + 1;
                q.push({i1,j1});
                flag[i1][j1] = true;
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j] == '#') {
                flag[i][j] = true;
                visited[i][j] = true;
            }
            else if(a[i][j] == 'M'){
                xm = i; ym = j;
            }
            else if(a[i][j] == 'T'){
                xv = i; yv = j;
            }
        }
    }
    int ans = 1e6;
    BFS(xm,ym);
    BFS1(xv,yv);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(dp[i][j] == dp1[i][j] && dp[i][j] != 0){
                ans = min(ans,dp[i][j]);
            }
        }
        cout << endl;
    }
    cout << ans << endl;
}