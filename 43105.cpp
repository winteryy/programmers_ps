#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    int len = triangle.size();
    vector<vector<int> > dp(len, vector<int>(len, 0));
    dp[0][0] = triangle[0][0];

    for(int i=1; i<len; i++) {
        for(int j=0; j<=i; j++) {
            int prev;
            if(j==0) {
                prev = dp[i-1][j];
            } else if(j==i) {
                prev = dp[i-1][j-1];
            } else {
                prev = max(dp[i-1][j], dp[i-1][j-1]);
            }
            dp[i][j] = prev+triangle[i][j];
        }
    }

    return *max_element(dp[len-1].begin(), dp[len-1].end());
}

int main() {
    solution({{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}});
}