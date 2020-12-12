#include <iostream>
#include <vector>
#include <deque>

using namespace std;

bool in_bound(int x, int y, int m, int n){
    return x >= 0 && x < m && y >= 0 && y < n;
}

void dfs(const vector<vector<int>>& adj, int x, int y, deque<deque<bool>>& marked){
    int m = adj.size();
    int n = adj[0].size();
    marked[x][y] = true;
    vector<vector<int>> neighbors = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1},{1, -1}, {1, 1}};
    for(const auto& neighbor : neighbors){
        int new_x = x + neighbor[0];
        int new_y = y + neighbor[1];
        if(in_bound(new_x, new_y, m, n) && !marked[new_x][new_y] && adj[new_x][new_y] == 1){
            dfs(adj, new_x, new_y, marked);
        }
    }
}

int connected_components(const vector<vector<int>>& adj){
    int cc = 0;
    int m = adj.size();
    int n = adj[0].size();
    deque<deque<bool>> marked(m, deque<bool>(n, false));
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            if(!marked[i][j] && adj[i][j] == 1){
                dfs(adj, i, j, marked);
                cc++;
            }
        }
    }
    return cc;
}


int main() {
    vector<vector<int>> A = {{0, 1, 1, 1}, {0, 0, 1, 0}, {0, 0, 0, 1}, {1, 1, 0, 0}};
    cout << connected_components(A) << endl;
    vector<vector<int>> B = {{1, 1, 1, 0, 1}, {1, 0, 0, 0, 0}, {0, 0, 1, 1, 0}};
    cout << connected_components(B) << endl;
}
