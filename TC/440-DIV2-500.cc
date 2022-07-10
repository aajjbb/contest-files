#include <iostream>
#include <stack>
#include <utility>
#include <vector>

#define REP(i, n) for(i = 0; i < n; i++)

using namespace std;

int dx[4] = {1,  0, -1, 0};
int dy[4] = {0, -1,  0, 1};

struct MazeWanderingEasy {
	int decisions(vector<string> maze) {
        int i, j, des = 0;
        int N = maze.size();
        int M = maze[0].size();

        vector<vector<bool> > memo;

        REP(i, N) {
            REP(i, M) {
                if(maze[i][j] == 'M') {
                    return dfs(maze, memo, i, j, N, M);
                }
            }
        }
        return -1;
	}

	int dfs(vector<string> maze, vector<vector<bool> > memo, int x, int y, int N, int M) {
        int i, des = 0;
        stack<pair<int, int> > s;
        vector<pair<int, int> > temp;

        s.push(make_pair(x, y));

        while(!s.empty()) {
            pair<int, int> p = s.top();
            memo[p.first][p.second] = true;
            s.pop();

            REP(i, 4) {
                int xa = p.first + dx[i];
                int ya = p.second + dy[i];

                if(xa >= 0 && ya >= 0 && xa < N && ya < M && maze[xa][ya] == '.' && memo[xa][ya] == false) {
                    temp.push_back(make_pair(xa, ya));
                }
            }
            if(temp.size() > 1) {
                des++;
            }

            REP(i, temp.size()) {
                s.push(make_pair(temp[i].first, temp[i].second));
            }
            temp.clear();
        }
        return des;
	}
};

int main() {

    return 0;
}
