#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int nodes[101];

int getparent(int index){
    if(nodes[index] != index) return getparent(nodes[index]);
    return index;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(),costs.end(),[](const vector<int>& a,const vector<int>& b){ return a[2] < b[2] ;});
    
    for(int i =0; i<= 100;i++) nodes[i]=i;
    for(int i =0; i<costs.size();i++)
    {
        int from = getparent(costs[i][0]);
        int to = getparent(costs[i][1]);
        int weigth = costs[i][2];
        
        if(from !=to){
            answer += weigth;
            nodes[from] = to;
        }
    }
    
    return answer;
}

