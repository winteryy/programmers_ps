#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int getContinuous(int origin, int n) {
    int num=0;

    for(int i=0; i<n; i++) {
        num = num * 10 + origin;
    } 
    return num;
}

int solution(int N, int number) {
    int answer = 0;

    unordered_set<int> us[9];
    for(int i=1; i<=8; i++) {
        us[i].insert(getContinuous(N, i));
    }

    for(int i=1; i<=7; i++) {
        for(int j=1; j+i<=8; j++) {
            for(auto curNum : us[i]) {
                if(curNum==number) return i;

                for(auto prev: us[j]) {
                    us[i+j].insert(curNum+prev);
                    us[i+j].insert(curNum-prev);
                    us[i+j].insert(curNum*prev);
                    if(prev!=0) {
                        us[i+j].insert(curNum/prev);
                    }
                }
            }
        }
    }
    for(auto curNum : us[8]) {
        if(curNum==number) return 8;
    }

    return -1;
}

int main() {
    solution(5, 12);
}