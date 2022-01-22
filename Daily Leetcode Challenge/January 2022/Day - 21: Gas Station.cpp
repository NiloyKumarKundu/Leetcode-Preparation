// Time Complexity: O(N^2)
// Space Complexity: O(1)

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (int s = 0; s < gas.size(); s++) {
            int tank = 0;
            bool possible = true;
            for (int i = s; i < gas.size() + s; i++) {
                int station = i % gas.size();
                tank = tank + gas[station] - cost[station];
                if (tank < 0) {
                    possible = false;
                    break;
                }
            }
            if (possible) {
                return s;
            }
        }
        return -1;
    }
};



// Optimised Solution
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int diff = 0;
        for (int i = 0; i < gas.size(); i++) {
            diff += (gas[i] - cost[i]);
        }
        
        if (diff < 0) {
            return -1;
        }
        
        int starting = 0, tank = 0;
        for (int i = 0; i < gas.size(); i++) {
            tank = tank + gas[i] - cost[i];
            if (tank < 0) {
                starting = i + 1;
                tank = 0;
            }
        }
        return starting;
    }
};