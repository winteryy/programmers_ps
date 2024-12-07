#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int solution(vector<string> arr)
{
    int answer = -1;
    int cnt = arr.size()/2+1;

    vector<vector<int> > minDp(cnt, vector<int>(cnt, INT32_MAX));
    vector<vector<int> > maxDp(cnt, vector<int>(cnt, INT32_MIN));

    for(int i=0; i<cnt; i++) {
        int num = stoi(arr[i*2]);
        maxDp[i][i] = minDp[i][i] = num;
    }

    for(int i=2; i<=cnt; i++) { //구간 길이
        for(int j=0; j+i<=cnt; j++) { //시작점
            for(int k=0; k<i-1; k++) { //분할점
                int leftEnd = j+k;
                if(arr[leftEnd*2+1][0]=='+') {
                    minDp[j][j+i-1] = min(minDp[j][j+i-1], minDp[j][leftEnd] + minDp[leftEnd+1][j+i-1]);
                    maxDp[j][j+i-1] = max(maxDp[j][j+i-1], maxDp[j][leftEnd] + maxDp[leftEnd+1][j+i-1]);
                } else {
                    minDp[j][j+i-1] = min(minDp[j][j+i-1], minDp[j][leftEnd] - maxDp[leftEnd+1][j+i-1]);
                    maxDp[j][j+i-1] = max(maxDp[j][j+i-1], maxDp[j][leftEnd] - minDp[leftEnd+1][j+i-1]);
                }
            }
        }
    }

    return maxDp[0][cnt-1];
}

int main() {
    solution({"1", "-", "3", "+", "5", "-", "8"});
}