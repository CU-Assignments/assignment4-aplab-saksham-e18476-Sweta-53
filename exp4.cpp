#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<pair<int, int>> events;
    
    // Step 1: Create events
    for (auto& b : buildings) {
        events.emplace_back(b[0], -b[2]);  // Start event (negative height to prioritize higher first)
        events.emplace_back(b[1], b[2]);   // End event (positive height)
    }
    
    // Step 2: Sort events
    sort(events.begin(), events.end());

    multiset<int> heights = {0};  // Keeps track of active heights
    vector<vector<int>> result;
    int prevMaxHeight = 0;

    // Step 3: Process events
    for (auto& event : events) {
        int x = event.first, h = event.second;
        
        if (h < 0) 
            heights.insert(-h);  // Add height (Start event)
        else 
            heights.erase(heights.find(h));  // Remove height (End event)

        int currMaxHeight = *heights.rbegin();  // Get max height

        // Step 4: Add key points when height changes
        if (currMaxHeight != prevMaxHeight) {
            result.push_back({x, currMaxHeight});
            prevMaxHeight = currMaxHeight;
        }
    }
    
    return result;
}

// Driver code
int main() {
    vector<vector<int>> buildings = {{2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8}};
    
    vector<vector<int>> skyline = getSkyline(buildings);

    for (auto& point : skyline) {
        cout << "[" << point[0] << "," << point[1] << "] ";
    }

    return 0;
}
