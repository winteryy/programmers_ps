#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
    for(auto puddle : puddles) {
        dp[puddle[1]][puddle[0]] = -1;
    }

    dp[1][1] = 1;
    int len = max(m, n);

    for(int k=2; k<m+n; k++) {
        for(int i=1; i<k; i++) {
            int curY = i;
            int curX = k-i;
            if(curY>n || curX>m || dp[curY][curX]==-1) continue;

            if(curY<n && dp[curY+1][curX]!=-1) {
                dp[curY+1][curX] += dp[curY][curX];
            }
            if(curX<m && dp[curY][curX+1]!=-1) {
                dp[curY][curX+1] += dp[curY][curX];
            } 
        }
    }

    return dp[n][m];
}

int main() {
    solution(4, 3, {{2, 2}});
}