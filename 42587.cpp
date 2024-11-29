#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int remain[10] = {0,};
    queue<pair<int, int> > q;
    int order = 1, targetP = 0;

    for(int i=0; i<priorities.size(); i++) {
        q.push({i, priorities[i]});
        remain[priorities[i]]++;
    }

    for(int i=9; i>=1; i--) {
        if(remain[i]>0) {
            targetP = i;
            break;
        }
    }

    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        if(targetP==p.second) {
            if(p.first==location) {
                return order;
            }
            remain[targetP]--;
            if(remain[targetP]==0) {
                for(int i=targetP-1; i>=1; i--) {
                    if(remain[i]>0) {
                        targetP = i;
                        break;
                    }
                }
            }
            order++;
        } else {
            q.push(p);
        }
    }

    return 0;
}