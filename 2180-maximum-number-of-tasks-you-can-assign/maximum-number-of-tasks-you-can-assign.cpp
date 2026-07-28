class Solution {
public:
    bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int k) {
        deque<int> dq;
        int j = workers.size() - 1;
        for (int i = k - 1; i >= 0; i--) {
            while (j >= (int)workers.size() - k && workers[j] + strength >= tasks[i]) {
                dq.push_front(workers[j]);
                j--;
            }
            if (dq.empty()) return false;
            if (dq.back() >= tasks[i]) {
                dq.pop_back();
            }
            else {
                dq.pop_front();
                pills--;
                if (pills < 0) return false;
            }
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int lo = 0;
        int hi = min(tasks.size(), workers.size());
        int ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(tasks, workers, pills, strength, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};