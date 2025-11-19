#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Graph: each airport maps to a min-heap of destinations
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        for (auto &ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }

        vector<string> itinerary;
        dfs("JFK", graph, itinerary);

        reverse(itinerary.begin(), itinerary.end()); // Path is built backwards
        return itinerary;
    }
    
    // DFS: visits all edges exactly once
    void dfs(const string &airport, 
             unordered_map<string, priority_queue<string, vector<string>, greater<string>>> &graph, 
             vector<string> &itinerary) {
        auto &destinations = graph[airport];

        while (!destinations.empty()) {
            string next_airport = destinations.top();
            destinations.pop();
            dfs(next_airport, graph, itinerary);
        }

        // Add airport to itinerary after visiting all its edges
        itinerary.push_back(airport);
    }
};
