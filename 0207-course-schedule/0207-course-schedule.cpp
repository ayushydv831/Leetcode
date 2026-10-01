class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
         vector<int> indegree(numCourses, 0);

        //build graph
        for(auto p: prerequisites){
            int course=p[0];
            int pre=p[1];

            graph[pre].push_back(course);
            indegree[course]++;
        }
        queue<int>q;
        // Courses with no prerequisites
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        int count=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();

            count++;

            for(int v:graph[u]){
                indegree[v]--;

                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        return count==numCourses;
    }        
};