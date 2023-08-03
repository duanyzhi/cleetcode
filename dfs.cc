#include <map>
#include <iostream>
#include <list> 

class Graph {
public:
    std::map<int, bool> visited;
    std::map<int, std::list<int> > adj;
 
    void addEdge(int v, int w);
 
    void DFS(int v);
};
 
void Graph::addEdge(int v, int w)
{
    // Add w to v’s list.
    adj[v].push_back(w);
}
 
void Graph::DFS(int v)
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    std::cout << v << " ";
 
    // Recur for all the vertices adjacent
    // to this vertex
    std::list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}
 
// Driver code
int main()
{
    // Create a graph given in the above diagram
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    std::cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
 
    // Function call
    g.DFS(2);
 
    return 0;
}
 
