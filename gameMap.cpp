#include<vector>
using namespace std;
int n, m;
int answer = __INT_MAX__;
bool success = false;

// 어휴... 이걸 이렇게 풀려고 하다니 ㅋㅋㅋㅋㅋ 웃겨서 박제
// 답은 맞지만 효율성 실패!
void bfs(const vector<vector<int>>& maps, vector<vector<int>>& visited, int i, int j, int& path)
{
    if(i == n && j == m)
    {
        answer = answer > path? path : answer;
        success = true;
        visited[i][j]++;
        return;
    }
    if(i > n  || i < 0 || j > m || j < 0 )
        return;
    if(maps[i][j] == false || visited[i][j])
    {
        return;
    }
    visited[i][j]++;
    path++;
    vector<vector<int>> temp(n+1, vector<int>(m+1, 0));
    copy(visited.begin(), visited.end(), temp.begin());
    auto tempPath = path;
    bfs(maps, temp, i + 1, j, tempPath);
    copy(visited.begin(), visited.end(), temp.begin());
    tempPath = path;
    bfs(maps, temp, i - 1, j, tempPath);
    copy(visited.begin(), visited.end(), temp.begin());
    tempPath = path;
    bfs(maps, temp, i, j + 1, tempPath);
    copy(visited.begin(), visited.end(), temp.begin());
    tempPath = path;
    bfs(maps, temp, i, j - 1, tempPath);
}

int solution1(vector<vector<int>> maps)
{
    n = maps.size();
    m = maps[0].size();
    vector<vector<int>> visited (n, vector<int>(m, 0));
    n--; m--;
    if(maps[n-1][m] == false && maps[n][m-1] == false)
        return -1;
    int path = 1;
    bfs(maps, visited, 0,0, path);
    if(success == false)
        return -1;
    return answer;
}
///////////////////////////////////////////////////

#include <queue> 

struct Point{
    int x, y, dist;
};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int solution(vector<vector<int>> maps)
{
    int n = maps.size();
    int m = maps[0].size();
    int ans = __INT_MAX__;
    queue<Point> q;
    q.push({0,0,1});

    vector<vector<bool>> visited (n, vector<bool>(m, false));
    
    while(!q.empty())
    {
        auto p = q.front();
        q.pop();

        if(p.x == n-1 && p.y == m-1)
        {
            ans = ans > p.dist? p.dist : ans;
        }

        for(int i=0; i < 4; i++)
        {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];

            if(nx >= n || nx < 0 || ny >= m || ny < 0 )
                continue;
            if(!maps[nx][ny])
                continue;
            if(visited[nx][ny])
                continue;
            visited[nx][ny] = true;
            q.push({nx, ny, p.dist+1});
        }

    }
    if(visited[n-1][m-1])
        return ans;
    return -1;
}

// int main()
// {
//     vector<vector<int>> maps = {{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1}};
//     int ans = solution(maps);
//     return 0;
// }