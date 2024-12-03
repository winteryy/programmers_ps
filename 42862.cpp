#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n-lost.size();

    bool lostList[31] = {false, };
    bool reserveList[31] = {false, };

    for(int num: lost) {
        lostList[num] = true;
    }  
    for(int num: reserve) {
        reserveList[num] = true;
    }  
    
    sort(lost.begin(), lost.end());
    for(int num: lost) {
        int targetNum = -1;  

        if(reserveList[num]) {
            targetNum = num;
        } else if(reserveList[num-1]) {
            targetNum = num-1;
        } else if(num<n && reserveList[num+1] && !lostList[num+1]) {
            targetNum = num+1;
        }

        if(targetNum!=-1) {
            reserveList[targetNum] = false;
            answer++;
        }
    }

    return answer;
}

int main() {
    solution(5, {2, 4}, {1, 3, 5});
}