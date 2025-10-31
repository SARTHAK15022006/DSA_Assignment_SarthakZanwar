class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> st; // stack stores indices of temperatures

        for (int i = 0; i < n; ++i) {
            // Check if the current day's temperature is higher than previous days
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevDay = st.top();
                st.pop();
                answer[prevDay] = i - prevDay; // calculate the number of days waited
            }
            st.push(i);
        }

        return answer;
    }
};
