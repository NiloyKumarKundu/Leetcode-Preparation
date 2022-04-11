// Clean Code

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        int ans = 0;
        int value1 = 0, value2 = 0;
        
        for (string i : ops) {
            if (i == "C") {
                st.pop();
            } else if (i == "D") {
                st.push(st.top() * 2);
            } else if (i == "+") {
                value1 = st.top();
                st.pop();
                value2 = st.top();
                st.push(value1);
                st.push(value1 + value2);
            } else {
                st.push(stoi(i));
            }
        }
        
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};





// 1st Approach
class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> q;
        for (int i = 0; i < ops.size(); i++) {
            if (ops[i] == "+") {
                if (q.empty()) {
                    continue;
                }
                int x = q.top();
                q.pop();
                int y = q.top();
                q.pop();
                int z = x + y;
                q.push(y);
                q.push(x);
                q.push(z);
            } else if (ops[i] == "D") {
                if (q.empty()) {
                    continue;
                }
                int x = q.top();
                x *= 2;
                q.push(x);
            } else if (ops[i] == "C") {
                if (q.empty()) {
                    continue;
                }
                q.pop();
            } else {
                int x = stoi(ops[i]);
                q.push(x);
            }
        }
        int result = 0;
        
        while (!q.empty()) {
            result += q.top();
            q.pop();
        }
        return result;
    }
};