class Solution {
    public:
        int mostBooked(int n, vector<vector<int>>& meetings) {
                sort(meetings.begin(), meetings.end());
                        vector<int> count(n, 0);
                                priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;
                                        priority_queue<int, vector<int>, greater<>> available;
                                                for (int i = 0; i < n; i++) available.push(i);
                                                        for (auto& m : meetings) {
                                                                    long long start = m[0], end = m[1];
                                                                                while (!busy.empty() && busy.top().first <= start) {
                                                                                                available.push(busy.top().second);
                                                                                                                busy.pop();
                                                                                                                            }
                                                                                                                                        if (!available.empty()) {
                                                                                                                                                        int room = available.top();
                                                                                                                                                                        available.pop();
                                                                                                                                                                                        busy.push({end, room});
                                                                                                                                                                                                        count[room]++;
                                                                                                                                                                                                                    } else {
                                                                                                                                                                                                                                    auto [endTime, room] = busy.top();
                                                                                                                                                                                                                                                    busy.pop();
                                                                                                                                                                                                                                                                    busy.push({endTime + end - start, room});
                                                                                                                                                                                                                                                                                    count[room]++;
                                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                                                return max_element(count.begin(), count.end()) - count.begin();
                                                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                                                    };