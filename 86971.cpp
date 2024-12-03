#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<bool> isVisited;

class Node {
public: 
    int num, depth, subTreeSum;
    vector<Node*> children;

    Node(int n) {
        num = n;
        depth = 0;  
        subTreeSum = 1;
    }

    int dfs(int curDepth) {
        depth = curDepth;
        isVisited[num] = true;
        for(auto child: children) {
            if(!isVisited[child->num]) {
                subTreeSum+=(child->dfs(curDepth+1));
            }
        }
        return subTreeSum;
    }
};

int solution(int n, vector<vector<int>> wires) {
    int answer = n;

    isVisited = vector<bool>(n+1, false);
    
    vector<Node*> nodes;
    for(int i=0; i<=n; i++) {
        nodes.push_back(new Node(i));
    }

    for(auto wire: wires) {
        nodes[wire[0]]->children.push_back(nodes[wire[1]]);
        nodes[wire[1]]->children.push_back(nodes[wire[0]]);
    }

    nodes[1]->dfs(0);
    int sumAll = nodes[1]->subTreeSum;

    for(auto wire: wires) {
        if(nodes[wire[0]]->depth<nodes[wire[1]]->depth) {
            answer = min(answer, abs(sumAll-(nodes[wire[1]]->subTreeSum)*2));
        } else {
            answer = min(answer, abs(sumAll-(nodes[wire[0]]->subTreeSum)*2));
        }
    }

    return answer;
}