class Solution {
public:
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
			vector<vector<int>>adj(numCourses);
			for (int i = 0;i < prerequisites.size();i++) {
				int u = prerequisites[i][1];
				int v = prerequisites[i][0];
				adj[u].push_back(v);
			}
			vector<int>indegree(numCourses);
			queue<int>q;
			vector<int>ans;
			for (int i = 0;i < numCourses;i++) {
				for (auto it : adj[i]) {
					indegree[it]++;
				}
			}
			for (int i = 0;i < numCourses;i++) {
				if (indegree[i] == 0) {
					q.push(i);
				}
			}

			while (!q.empty())
			{
				int node = q.front();
				q.pop();

				ans.push_back(node);
				for (auto it : adj[node]) {
					indegree[it]--;
					if (indegree[it] == 0) q.push(it);
				}
			}
			if (ans.size() == numCourses) return true;
			return false;
		}
};