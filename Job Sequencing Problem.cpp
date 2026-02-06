class Solution {
    int find(int x, vector<int>& parent) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x], parent);
    }

  public:
    vector<int> jobSequencing(vector<int>& deadline, vector<int>& profit) {
        int n = deadline.size();

        vector<pair<int,int>> jobs;
        int maxDeadline = 0;

        for(int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
            maxDeadline = max(maxDeadline, deadline[i]);
        }

        // sort by profit descending
        sort(jobs.begin(), jobs.end(), greater<>());

        // DSU parent array
        vector<int> parent(maxDeadline + 1);
        for(int i = 0; i <= maxDeadline; i++)
            parent[i] = i;

        int cnt = 0, maxProfit = 0;

        for(auto &job : jobs) {
            int p = job.first;
            int d = job.second;

            int availableSlot = find(d, parent);

            if(availableSlot > 0) {
                cnt++;
                maxProfit += p;
                parent[availableSlot] = find(availableSlot - 1, parent);
            }
        }

        return {cnt, maxProfit};
    }
};
