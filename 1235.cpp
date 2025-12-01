#include <bits/stdc++.h>

using namespace std;

struct Job {
    int start, end, profit;
};

class Solution {
public:
    bool compareFinish(const Job& a, const Job& b) {
        return a.end < b.end;
    }

    vector<int> memo;
    vector<int> p;

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<Job> jobs;

        for (int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]})
        }

        sort(jobs.begin(), jobs.end(), compareFinish);

        p.assign(n, -1);
        pFunction(jobs, n);

        memo.assign(n -1);

        return opt(n-1, jobs);
    }

    void pFunction(const vector<Job>& jobs, int n) {
        for(int i = 1; i < n; i++) {
            Job target;
            target.end = jobs[i].start;

            auto it = upper_bound(jobs.begin(), jobs.begin() + i, target,[](const Job& val, const Job& job) {
                return val.end < job.end;
            });

            if(it != jobs.begin()) {
                p[i] = distance(jobs.begin(), prev(it));
            } else {
                p[i] = -1;
            }
        }
    }

    int opt(int j, const vector<Job>& jobs) {
        if(j < 0) return 0;

        if(memo[j] != -1) {
            return memo[j];
        }

        int include = jobs[j].profit + opt(p[j], jobs);
        int exclude = opt(j-1, jobs);

        return memo[j] = max(include, exclude);
    }
};