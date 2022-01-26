// Optimised Solution && clean code
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int availableGas = 0, has_gas = 0, cur_station = 0;
        
        for (int i = 0; i < gas.size(); i++) {
            int cur_gas = gas[i] - cost[i];
            availableGas += cur_gas;
            has_gas += cur_gas;
            
            if (has_gas < 0) {
                has_gas = 0;
                cur_station = i + 1;
            }
        }
        return availableGas >= 0 ? cur_station : -1;
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





