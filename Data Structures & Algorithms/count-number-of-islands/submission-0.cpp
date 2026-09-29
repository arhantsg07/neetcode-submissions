class Solution {
   public:
    vector<int> parent;
    vector<int> size;
    int count;
    void make_set(int v) {
        parent[v] = v;
        size[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_set(int a, int b) {
        int x = find_set(a);
        int y = find_set(b);
        if (x != y) {
            if (size[x] < size[y]) swap(x, y);
            parent[y] = x;
            size[x] += size[y];
            count--;
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid[0].size();
        int m = grid.size();
        count = 0;
        parent.resize(m * n);
        size.resize(m * n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    int id = i * n + j;
                    make_set(id);
                    count++;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    if (j+1 < n && grid[i][j + 1] == '1') {
                        int id1 = i * n + j;
                        int id2 = i * n + (j+1); 
                        union_set(id1, id2);
                    } 
                    if (i+1 < m && grid[i + 1][j] == '1') {
                        int id1 = i * n + j;
                        int id2 = (i+1) * n + j; 
                        union_set(id1, id2);
                    }
                }
            }
        }
        return count;
    }
};
