// DFS - FIFO - level order 
// https://medium.com/leetcode-patterns/leetcode-pattern-2-dfs-bfs-25-of-the-problems-part-2-a5b269597f52

// represented using adjacency list
void bfs(vector<vector<int> >& adjList, int startNode, vector<bool>& visited) {

    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        int currentNode = q.front();

        cout << currentNode << " ";

        q.pop();

        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}


// represented using adjacency matrix
void bfs(int start, vector<vector<int>> & adj) {

    vector<bool> visited(adj.size(), false);
    vector<int> q;
    q.push_back(start);

    visited[start] = true;
  
    int vis;
    while (!q.empty()) {
        vis = q[0];
  
        cout << vis << " ";
        q.erase(q.begin());

        for (int i = 0; i < adj[vis].size(); i++) {
            if (adj[vis][i] == 1 && (!visited[i])) {
  
                q.push_back(i);
                visited[i] = true;
            }
        }
    }
}