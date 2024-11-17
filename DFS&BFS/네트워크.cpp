#include <string>
#include <vector>
#include <queue>

using namespace std;
vector<int> visit;
queue<int> BFS;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i =0;i<n;i++)
    {
        visit.push_back(-1);
    }
    
    while(1)
    {
        int index=-1;
       
        for(int i=0;i<n;i++){
            if(visit[i]== -1) //미방문 
            {
                index = i;
                visit[index] = 1; //방문 체크
                BFS.push(index);
                answer++; // 신규 네트워크 발견 
                 break;
            }
           
        }
        
        if(index == -1) return answer; //모두 방문
        
         while(!BFS.empty())
         {
            int front = BFS.front();
            BFS.pop();
             for(int i =0;i<n;i++)
             {
                 int c = computers[front][i] ;
                 if(i ==front ) continue; //자신
                 if(visit[i] == 1 ) continue;//방문 한 노드
                 if(c == 1 )
                 {
                 BFS.push(i);
                 visit[i] =1;
                 }
             }
         }
    }
    
    return answer;
}