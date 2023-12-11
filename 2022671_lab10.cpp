#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

// class for edge
class Edge{
    public:
        int DestinationVertexId; // ID of the adjacent vertex
        string DestinationVertexName; // name of the adjacent vertex
        //int weight;
        // making a constructor
        Edge(int dID, string name){
            DestinationVertexId = dID;
            DestinationVertexName = name;
        }
        Edge(int dId, string name, int w){
            DestinationVertexId = dId;
            DestinationVertexName = name;
            //weight = w;
        }
};
// class for vertex
class Vertex{
    public:
        int ID; // person ID
        string name; // name of the person on the network
        list <Edge> edgeList; // list of all the adjacent edges i.e. friendships
        // making the constructors
        Vertex(){}
        Vertex(int id, string n){
            ID = id;
            name = n;
        }
        // function to print the edge list
        void printEdgeList(){
            list <Edge> :: iterator it;
            cout << "[";
            for(it = edgeList.begin(); it != edgeList.end(); ++it){
                cout << "(" << it->DestinationVertexId << "," << it->DestinationVertexName << ")";
            }
            cout << "]";
        }
};
// class for graph DS
class Graph{
    public:
        vector <Vertex> vertices; // dynamic array of all the vertices
    
    // function to add a vertex i.e. add a person in the network
    void addVertex(int p_ID, string p_name){
        Vertex person(p_ID, p_name);
        // we need to check if the vertex already exists in the graph
        bool check = checkIfVertexExistsbyID(person.ID);
        if(check){
            cout << person.name << " exists in the social network!" << endl;
        }
        else{
            // pushing it to the vector array
            vertices.push_back(person);
            cout << person.name << "  successfully added in the social network!" << endl;
        }
    }
    // function to check if a vertex exists in the grapgh
    bool checkIfVertexExistsbyID(int id){
        // traversin the graph verctor to check if the vertex exists there or not
        for(int i = 0; i < vertices.size(); i++){
            if(vertices.at(i).ID==id)
                return true; // if the ID matches with any in the grapgh already, return true
        }
        return false; // else return false
    }
    // function to add edges i.e. define friendships in the social network
    void addEdges(int id1, int id2){
        // we have to check if both the id1 and id2 exist in the network
        bool check1 = checkIfVertexExistsbyID(id1);
        bool check2 = checkIfVertexExistsbyID(id2);
        if(check1 && check2){
            bool check3 = checkifEdgeExistsbyID(id1, id2);
            if(check3){
                cout << "The two persons are friends already" << endl;
            }
            else{
                Vertex v1 = getVertexbyID(id1);
                Vertex v2 = getVertexbyID(id2);
                // looping the graph vector and finding v1 and v2 and adding a link between them
                for(int i= 0; i < vertices.size(); i++){
                    if(vertices.at(i).ID==id1){
                        Edge e(id2, v2.name);
                        vertices.at(i).edgeList.push_back(e);
                    }
                    else if(vertices.at(i).ID==id2){
                        Edge e(id1, v1.name);
                        vertices.at(i).edgeList.push_back(e);
                    }
                }
                cout << "Edge created successfully between " << v1.ID << ": " << v1.name << "  and " << v2.ID << ": " << v2.name << endl;
            }
            }
            
        }

    bool checkifEdgeExistsbyID(int id1, int id2){
        Vertex v1 = getVertexbyID(id1);
        // traversing the edge list of v1 to see if id2 exists
        list <Edge> :: iterator it;
        for(it = v1.edgeList.begin(); it != v1.edgeList.end(); ++it){
            if(it->DestinationVertexId==id2)
                return true; // return true if an edge bw id1 and id2 exists
        }
        return false;
    }

    Vertex getVertexbyID(int id){
        Vertex temp;
        for(int i = 0; i < vertices.size(); i++){
            if(vertices.at(i).ID==id){
                temp = vertices.at(i);
                break;
            }
        }
        return temp;
    }

    // function to print the graph
    void print(){
        for(int i = 0; i < vertices.size(); i++){
            cout << vertices.at(i).name << "(" << vertices.at(i).ID <<")-->";
            vertices.at(i).printEdgeList();
            cout << endl;
        }
    }
    // BFS traversal
    void BFS(int id1, int id2){
        Vertex v1 = getVertexbyID(id1);
        Vertex v2 = getVertexbyID(id2);

        // making a visited array
        bool* visited = new bool[vertices.size()];
        for(int i = 0; i < vertices.size(); i++){
            visited[i] = false;
        }
        // making a queue for storing values
        list <Vertex> queue;

        // enqueuing v1 and marking it as visited
        queue.push_back(v1);
        visited[v1.ID] = true;

        // now implementing breadfirst till the destination vertex is met i.e. v2
        while(!queue.empty()){
            // popping the first element from the queue and printing it
            Vertex v = queue.front();
            queue.pop_front();
            cout << v.ID <<" ";
            
            // enqueuing all it's neighbors and marking them visited
            list <Edge>:: iterator it;
            for(it = v.edgeList.begin(); it!=v.edgeList.end(); ++it){
                if(!visited[it->DestinationVertexId]){
                    visited[it->DestinationVertexId] = true; // mark as visited
                    queue.push_back(getVertexbyID(it->DestinationVertexId));
                }
            }
            // checking if the destination element is found
            if(queue.front().ID==v2.ID){
                cout << queue.front().ID << " ";
                break;
            }
        }
    }
    // DFS traversal
    void dfs(){
        // making a visited array
        bool* visited = new bool[vertices.size()];
        for(int i = 0; i < vertices.size(); i++){
            visited[i] = false;
        }

        // traversing all the vertices and going into the depth of each
        for(int i = 1; i < vertices.size(); i++){
            if(!visited[i]){
                dfs_util(i, visited);
            }
        }
    }
    void dfs_util(int i, bool* visited){
        // mark the current node as visited
        visited[i] = true;
        cout << i << " ";
        // traversing the adjecnecy list and calling dfs_util for each neighnor in depth
        Vertex v = getVertexbyID(i);
        list <Edge> :: iterator it;
        for(it = v.edgeList.begin(); it!=v.edgeList.end(); ++it){
            if(!visited[it->DestinationVertexId]){
                dfs_util(it->DestinationVertexId, visited);
            }
        }
        }
     // Function to suggest friends based on mutual connections using BFS
void suggestFriends(int id) {
    Vertex v = getVertexbyID(id);
    // We will traverse the edge list of v and suggest the friends of its friends
    list<Edge>::iterator it;  // For iterating the edge list of v
    list<Edge>::iterator it2; // For iterating the edge list of the friends of v
    list<Edge> suggestions;

    for (it = v.edgeList.begin(); it != v.edgeList.end(); ++it) {
        Vertex temp = getVertexbyID(it->DestinationVertexId);

        for (it2 = temp.edgeList.begin(); it2 != temp.edgeList.end(); ++it2) {
            // Skip suggestions that are already friends
            if (!checkifEdgeExistsbyID(v.ID, it2->DestinationVertexId) && v.ID!=it2->DestinationVertexId) {
                Edge e(it2->DestinationVertexId, it2->DestinationVertexName);
                suggestions.push_back(e);
            }
        }
    }

    // Printing the suggestions
    cout << "Friend suggestions for " << v.ID << " : " << v.name << " are: " << endl;
    for (it = suggestions.begin(); it != suggestions.end(); ++it) {
        cout << it->DestinationVertexId << " : " << it->DestinationVertexName << endl;
    }
}
    // function to print vertices with significant connections (>=3) i.e. influencers
    void printInfluencers(){
        // array to store number of connections
        int* connections = new int[vertices.size()];
        list <Edge> :: iterator it;

        // looping the vertices and counting their connections
        for(int i = 0; i < vertices.size(); i++){
            int count = 0;
            Vertex temp = getVertexbyID(i);
            for(it = temp.edgeList.begin(); it != temp.edgeList.end(); ++it){
                count++;
            }
            connections[i] = count;
        }
        // looping through the vertices again and printing only those with 3 or more connections
        cout << "Influencers in the network are: " << endl;
        for(int i = 0; i < vertices.size(); i++){
            Vertex temp = getVertexbyID(i);
            if(connections[i]>=3){
                cout << temp.ID << ": " <<temp.name << endl;
            }
        }
    }
};
// driver code
int main(){
    Graph* graph = new Graph();
    // Task 1 - Representing social network as an undirected graph

    // adding people
    graph->addVertex(1, "alishba");
    graph->addVertex(2,"ayesha");
    graph->addVertex(3, "noor");
    graph->addVertex(4,"mahnoor");
    graph->addVertex(5,"maham");
    cout << endl;

    // making friendships between people
    graph->addEdges(1,2);
    graph->addEdges(3,4);
    graph->addEdges(2,3);
    graph->addEdges(1,3);
    graph->addEdges(3,5);
    graph->addEdges(4,5);
    cout << endl;

    graph->print();
    cout << endl;

    // Task 2 - Getting shortest path between two vertex by BFS
    cout << "Shortest path between 1 and 4 by BFS is: ";
    graph->BFS(1,4);
    cout << endl;

    // Tast 3 - Implementing DFS to identify connected elements within the network
    cout << "Connected elements in the network by DFS are: ";
    graph->dfs();
    cout << endl << endl;;

    // Task 4 - Suggesting friends based on mutual connections using BFS
    graph->suggestFriends(1);
    cout << endl;

    // Task 5 - Printing influencers
    graph->printInfluencers();
    cout << endl;

    delete graph;
    return 0;
}