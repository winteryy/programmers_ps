#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int n;
unordered_set<int> answerSet;
bool used[7];
string comb;

bool isPrimary(int num) {
    if(num==2 || num==3) return true;
    if(num==1) return false;
    if(num%2==0 || num%3==0) return false;

    for(int i=5; i*i<=num; i+=6) {
        if(num%i==0 || num%(i+2)==0) return false;
    }

    return true;
}

void dfs(string& numbers, int depth) {
    if(!comb.empty()) {
        int num = stoi(comb);
        if(isPrimary(num)) {
            answerSet.insert(num);
        }
    }

    if(depth == n) {
        return;
    } else {
        for(int i=0; i<n; i++) {
            if(!used[i]) {
                comb.push_back(numbers[i]);
                used[i] = true;
                dfs(numbers, depth+1);
                comb.pop_back();
                used[i] = false;
            }
        }
    }
}

int solution(string numbers) {
    n = numbers.size();
    dfs(numbers, 0);

    int answer = answerSet.size();
    return answer;
}

int main() {
    solution("17");
}