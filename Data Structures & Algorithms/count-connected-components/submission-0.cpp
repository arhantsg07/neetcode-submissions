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

    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        size.resize(n);
        count = n;
        for (int i = 0; i < n; i++) {
            make_set(i);
        }
        for (auto e : edges) {
            union_set(e[0], e[1]);
        }
        return count;
    }
};
