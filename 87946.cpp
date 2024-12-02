#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dgSize;
int result = 0;
bool used[8];

void dfs(vector<vector<int> >& dungeons, int depth, int remain) {
    if(depth==dgSize) return;
    
    if(remain>=0) {
        result = max(result, depth+1);
    } else {
        return;
    }

    for(int i=0; i<dgSize; i++) {
        if(!used[i] && dungeons[i][0]<=remain) {
            used[i] = true;
            dfs(dungeons, depth+1, remain-dungeons[i][1]);
            used[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dgSize = dungeons.size();
    dfs(dungeons, 0, k);

    return result;
}