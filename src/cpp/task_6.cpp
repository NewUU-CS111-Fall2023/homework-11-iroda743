/*
 * Author:
 * Date:
 * Name:
 */

class Problem6 {
public:
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

constexpr int INF = 1e9; // Infinity value

int networkDelayTime(const std::vector<std::vector<int>>& times, int n, int k) {
    std::vector<std::vector<std::pair<int, int>>> graph(n + 1);
    for (const auto& time : times) {
        int u = time[0], v = time[1], w = time[2];
        graph[u].emplace_back(v, w);
    }

    std::vector<int> distance(n + 1, INF);
    distance[k] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.emplace(0, k);

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& edge : graph[u]) {
            int v = edge.first, w = edge.second;
            if (distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                pq.emplace(distance[v], v);
            }
        }
    }

    int maxTime = 0;
    for (int i = 1; i <= n; ++i) {
        if (distance[i] == INF) {
            // There exists a node that cannot be reached
            return -1;
        }
        maxTime = std::max(maxTime, distance[i]);
    }

    return maxTime;
}

int main() {
    // Sample input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
    std::vector<std::vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4, k = 2;

    // Find the minimum time it takes for all nodes to receive the signal
    int result = networkDelayTime(times, n, k);

    // Print the result
    std::cout << "Minimum time: " << result << std::endl;

    return 0;
}

};
