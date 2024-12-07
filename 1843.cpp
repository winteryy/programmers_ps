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
                int halfEnd = j+k;
                int endPoint = j+i-1;
                if(arr[halfEnd*2+1][0]=='+') {
                    minDp[j][endPoint] = min(minDp[j][endPoint], minDp[j][halfEnd] + minDp[halfEnd+1][endPoint]);
                    maxDp[j][endPoint] = max(maxDp[j][endPoint], maxDp[j][halfEnd] + maxDp[halfEnd+1][endPoint]);
                } else {
                    minDp[j][endPoint] = min(minDp[j][endPoint], minDp[j][halfEnd] - maxDp[halfEnd+1][endPoint]);
                    maxDp[j][endPoint] = max(maxDp[j][endPoint], maxDp[j][halfEnd] - minDp[halfEnd+1][endPoint]);
                }
            }
        }
    }

    return maxDp[0][cnt-1];
}

int main() {
    solution({"1", "-", "3", "+", "5", "-", "8"});
}