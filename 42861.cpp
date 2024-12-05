#include <string>
#include <vector>
#include <queue>

using namespace std;

int root[100];

int findRoot(int n) {
    if(root[n] == n) return n;

    return root[n] = findRoot(root[n]);
}

bool makeUnion(int x, int y) {
    int rootX = findRoot(x);
    int rootY = findRoot(y);

    if(rootX<rootY) {
        root[y] = rootX;
        return true;
    } else if(rootX>rootY) {
        root[x] = rootY;
        return true;
    } else {
        return false;
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for(int i=0; i<n; i++) {
        root[i] = i;
    }

    auto cmp = [](const vector<int>& l, const vector<int>& r) {
        return l[2] > r[2];
    };
    priority_queue<vector<int>, vector<vector<int> >, decltype(cmp)> pq(cmp);

    for(auto cost : costs) {
        pq.push(cost);
    }

    int curSetNum = 0;
    while(!pq.empty() && curSetNum<n-1) {
        auto cur = pq.top();
        pq.pop();
        if(makeUnion(cur[0], cur[1])) {
            curSetNum++;
            answer += cur[2];
        }
    }

    return answer;
}

int main() {
    solution(5, {{0, 1, 5}, {1, 2, 3}, {2, 3, 3}, {3, 1, 2}, {3, 0, 4}, {2, 4, 6}, {4, 0, 7}});
}