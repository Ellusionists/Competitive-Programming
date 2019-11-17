// LeetCode Medium https://leetcode.com/problems/course-schedule/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // Create adj matrix and build graph
        vector<vector<int>> adjmat(numCourses);
        for(const auto p: prerequisites){
            int first = p[0];
            int second = p[1];
            adjmat[second].push_back(first);
        }
        
        vector<char> color(numCourses, 0);

        for(int i = 0; i < numCourses; i++){
            if(color[i] == 0 && dfsCycleSearch(i, adjmat, color)){
                return false;
            }
        }
        return true;
    }
    
    bool dfsCycleSearch(int v, vector<vector<int>>& adjmat, vector<char> &color){
        color[v] = 1;
        
        for(auto node : adjmat[v]){
            if(color[node] == 1){
                return true;
            }
            if(color[node] == 0 && dfsCycleSearch(node, adjmat, color)){
                return true;
            }
        }
        
        color[v] = 2;
        return false;
    }
};
