#include<vector>
#include<queue>

using namespace std;
vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
int solution(vector<vector<int> > maps)
{
    int answer = 0;
    queue<pair<int,int>> BFS;
    vector<vector<int>> visit;
    
    for(int i =0;i<maps.size();i++)
    {
    vector<int> temp;
     for(int j =0;j<maps[0].size();j++)
    {
       temp.push_back(-1);
    } 
        visit.push_back(temp);
    }
  
    visit[0][0] = 1;
    BFS.push({0,0});
  
    while(!BFS.empty())
    {
        pair<int,int> front = BFS.front();
        BFS.pop();
        for(const auto& d : dir)
        {
          pair<int,int> pos = {front.first + d.first ,front.second+ d.second};
            if(pos.first>=maps.size() || pos.first<0 ||pos.second>=maps[0].size() || pos.second<0)continue;
            if(visit[pos.first][pos.second] ==1 ) continue;
            if(maps[pos.first][pos.second] ==0 ) continue;
            maps[pos.first][pos.second] += maps[front.first][front.second];
            visit[pos.first][pos.second] =1;
            BFS.push({pos.first,pos.second});
                
            if(pos.first == maps.size()-1 && pos.second == maps[0].size()-1)
            {
                return maps[pos.first][pos.second];
            }
        }
    }
    return -1;
}