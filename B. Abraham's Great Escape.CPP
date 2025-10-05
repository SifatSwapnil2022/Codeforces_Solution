#include <bits/stdc++.h>
using namespace std;

class SnakeGrid {
    int n;
    long long k;
    vector<pair<int,int>> path;
    vector<string> grid;

    char deltaToDir(int dx, int dy) {
        if(dx == -1 && dy == 0) return 'U';
        if(dx == 1  && dy == 0) return 'D';
        if(dx == 0  && dy == -1) return 'L';
        if(dx == 0  && dy == 1) return 'R';
        return 'U';
    }

    void buildPath() {
        path.clear();
        for(int i = 0; i < n; ++i) {
            if(i % 2 == 0) {
                for(int j = 0; j < n; ++j) path.emplace_back(i, j);
            } else {
                for(int j = n-1; j >= 0; --j) path.emplace_back(i, j);
            }
        }
    }

    void fillGrid() {
        int total = n * n;
        int s = total - (int)k;
        grid.assign(n, string(n, 'U'));

        if(s == 0) {
            for(int i = 0; i < total-1; ++i) {
                auto [x1, y1] = path[i];
                auto [x2, y2] = path[i+1];
                grid[x1][y1] = deltaToDir(x2 - x1, y2 - y1);
            }
            auto [lx, ly] = path.back();
            if(lx == 0) grid[lx][ly] = 'U';
            else if(lx == n-1) grid[lx][ly] = 'D';
            else if(ly == 0) grid[lx][ly] = 'L';
            else grid[lx][ly] = 'R';
        } else {
            for(int i = 0; i <= s-3; ++i) {
                auto [x1, y1] = path[i];
                auto [x2, y2] = path[i+1];
                grid[x1][y1] = deltaToDir(x2 - x1, y2 - y1);
            }
            auto [x1, y1] = path[s-2];
            auto [x2, y2] = path[s-1];
            grid[x1][y1] = deltaToDir(x2 - x1, y2 - y1);
            grid[x2][y2] = deltaToDir(x1 - x2, y1 - y2);

            for(int i = s; i <= total-2; ++i) {
                auto [x1, y1] = path[i];
                auto [x2, y2] = path[i+1];
                grid[x1][y1] = deltaToDir(x2 - x1, y2 - y1);
            }

            if(s != total) {
                auto [lx, ly] = path.back();
                if(lx == 0) grid[lx][ly] = 'U';
                else if(lx == n-1) grid[lx][ly] = 'D';
                else if(ly == 0) grid[lx][ly] = 'L';
                else grid[lx][ly] = 'R';
            }
        }
    }

public:
    SnakeGrid(int size, long long escapes) : n(size), k(escapes) {}

    bool generate() {
        int total = n * n;
        if(k == 1LL * total - 1) return false;
        buildPath();
        fillGrid();
        return true;
    }

    void print() {
        for(auto &row : grid) cout << row << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin >> t)) return 0;
    while(t--) {
        int n; long long k;
        cin >> n >> k;
        SnakeGrid sg(n, k);
        if(!sg.generate()) cout << "NO\n";
        else {
            cout << "YES\n";
            sg.print();
        }
    }
    return 0;
}
