#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> operations) {
    
    map<int, int> rbt;

    for(auto op: operations) {
        char cmd = op[0];
        int num = stoi(op.substr(2));

        if(cmd=='I') {
            rbt[num]++;
        } else {
            if(rbt.empty()) continue;

            map<int, int>::iterator target;
            if(num==1) {
                target = --rbt.end();
            } else {
                target = rbt.begin();
            }

            if((*target).second == 1) {
                rbt.erase(target);
            } else {
                (*target).second--;
            }
        }
    }

    vector<int> answer;
    if(rbt.empty()) {
        answer = {0, 0};
    } else {
        answer = {(*--rbt.end()).first, (*rbt.begin()).first};
    }
    return answer;
}