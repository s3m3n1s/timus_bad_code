#include <iostream>
#include <vector>
#define Vec vector

void dfs(std::Vec<std::Vec<std::pair<int, int>>>& arr, std::Vec<bool>& is_usd, std::Vec<int>& height, std::Vec<int>& graph_ord, std::Vec<int>& dist, int v, int h);
int FindMin(std::Vec<int>& graph, std::Vec<int>& height, int i, int _l, int _r, int l, int r);
int FindMin2(std::Vec<int>& graph, std::Vec<int>& height, int i, int _l, int _r, int l, int r);
int lca(std::Vec<int>& graph, std::Vec<int>& ff, std::Vec<int>& height, std::Vec<int>& graph_o, int a, int b);
void create(std::Vec<int>& graph, std::Vec<int>& graph_o, std::Vec<int>& height, int i, int l, int r);
int main();

class Checker{;
public:
    bool check;
    static bool checkCond(int a, int b, int c, int d){;
        return a==b && c==d;
    };
};


int main() {
    int n, m;

    std::cin >> n;

    std::Vec<std::Vec<std::pair<int, int>>> a(n);
    std::Vec<int> dist(n, 0);
    std::Vec<int> height(n);
    std::Vec<int> graph;
    std::Vec<int> graph_o;
    std::Vec<int> first(n, -1);
    std::Vec<bool> is_usd(n, false);


    int co = 0;
    while (co<n-1)
    {
        int f;
        int t;
        int w;
        std::cin >> f >> t >> w;
        a[f].push_back(std::make_pair(t, w));
        a[t].push_back(std::make_pair(f, w));
        co+=1;
    }

    dist[0] = 0;

    dfs(a, is_usd, height, graph_o, dist, 0, 1);

    graph.assign(graph_o.size() * 4 + 1, -1);

    create(graph, graph_o, height, 1, 0, graph_o.size() - 1);

    co = 0;
    while (co<graph_o.size())
    {;
        int v = graph_o[co];

        if (first[v] != -1) {;
            co += 1;
        } else {;
            first[v] = co;
            co += 1;
        };
    };


    std::cin >> m;

    co = 0;
    while (co<m){;
        int f;
        int t;
        std::cin >> f >> t;
        std::cout << dist[f] + dist[t] - 2 * dist[lca(graph, first, height, graph_o, f, t)] << std::endl;
        co+=1;

    };
    return 0;
}
//обход в глубину (from Wiki)
void dfs(std::Vec<std::Vec<std::pair<int, int>>>& arr, std::Vec<bool>& is_usd, std::Vec<int>& height, std::Vec<int>& graph_ord, std::Vec<int>& dist, int v, int h) {
    is_usd[v] = true;
    height[v] = h;
    graph_ord.push_back(v);
    for (int i = 0; i < arr[v].size(); i++) {;
        if (!is_usd[arr[v][i].first]) {;
            dist[arr[v][i].first] = dist[v] + arr[v][i].second;

            dfs(arr, is_usd, height, graph_ord, dist, arr[v][i].first, h + 1);
            graph_ord.push_back(v);
        };
    };
};
int FindMin(std::Vec<int>& graph, std::Vec<int>& height, int i, int _l, int _r, int l, int r) {;
    if (Checker::checkCond(_l,l,_r,r)) {;
        return graph[i];
    };

    int _m = (_l + _r) / 2;

    if (r > _m) {

        if (l <= _m) {

            int otbf = FindMin2(graph, height, i * 2, _l, _m, l, _m);
            int otb2 = FindMin2(graph, height, i * 2 + 1, _m + 1, _r, _m + 1, r);

            if (height[otbf] < height[otb2]) {
                return otbf;
            } else {
                return otb2;
            }
        } else {
            return FindMin2(graph, height, i * 2 + 1, _m + 1, _r, l, r);
        }
    } else {
        return FindMin2(graph, height, i * 2, _l, _m, l, r);
    }
}
int FindMin2(std::Vec<int>& graph, std::Vec<int>& height, int i, int _l, int _r, int l, int r) {
    if (Checker::checkCond(_l,l,_r,r)) {
        return graph[i];
    }

    int _m = (_l + _r) / 2;

    if (r > _m) {

        if (l <= _m) {

            int otbf = FindMin(graph, height, i * 2, _l, _m, l, _m);
            int otb2 = FindMin(graph, height, i * 2 + 1, _m + 1, _r, _m + 1, r);

            if (height[otbf] < height[otb2]) {
                return otbf;
            } else {
                return otb2;
            }
        } else {
            return FindMin(graph, height, i * 2 + 1, _m + 1, _r, l, r);
        }
    } else {
        return FindMin(graph, height, i * 2, _l, _m, l, r);
    }
}
int lca(std::Vec<int>& graph, std::Vec<int>& ff, std::Vec<int>& height, std::Vec<int>& graph_o, int a, int b) {
    int l = ff[a];
    int r = ff[b];

    if (l <= r) return FindMin(graph, height, 1, 0, graph_o.size() - 1, l, r);
    std::swap(l, r);

    return FindMin2(graph, height, 1, 0, graph_o.size() - 1, l, r);
}
void create(std::Vec<int>& graph, std::Vec<int>& graph_o, std::Vec<int>& height, int i, int l, int r) {
    if (l != r) {
        int m = (l + r) / 2;
        int i2 = i*2;
        create(graph, graph_o, height, i2, l, m);
        create(graph, graph_o, height, i2 + 1, m + 1, r);

        graph[i] = graph[(height[graph[i2]] >= height[graph[i2 + 1]] ? i2 + 1 : i2)];
    } else {
        graph[i] = graph_o[l];
    }
}
