#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Edge{
    public:
        int destID;

        Edge(int i){
            destID = i;
        }
};
class Vertex{
    public:
        int ID;
        list <Edge> adjList;

        Vertex(){}
        Vertex(int id){
            ID = id;
        }
        void printAdjList(){
            list <Edge> :: iterator it;
            for( it = adjList.begin(); it != adjList.end(); ++it){
                cout << "(" << it->destID << ") ";
            }
        }
};
class Graph{
    public:
        vector <Vertex> graph;

    // add vertex
    void addVertex(int id){
        bool check = checkIfVertexExistsbyID(id);
        if(check){
            cout << "vertext already exists" << endl;
        }
        else{
            Vertex v(id);
            graph.push_back(v);
            cout << "Vertex " << id << " successfully added in the graph" << endl;
        }
    }
    
    bool checkIfVertexExistsbyID(int id){
        for(int i = 0; i < graph.size(); i++){
            if(graph.at(i).ID == id)
                return true;
        }
        return false;
    }
    // add edge 
    void addEdge(int id1, int id2){

        bool check1 = checkIfVertexExistsbyID(id1);
        bool check2 = checkIfVertexExistsbyID(id2);

        if(check1 && check2){
            bool check3 = checkIfEdgeExistsbyID(id1, id2);
            if(!check3){
                for(int i = 0; i < graph.size(); i++){
                    if(graph.at(i).ID == id1){
                        Edge e(id2);
                        graph.at(i).adjList.push_back(e);
                    }
                    if(graph.at(i).ID == id2){
                        Edge e(id1);
                        graph.at(i).adjList.push_back(e);
                    }
                }
                cout << "Edge between " << id1 << " and " << id2 << " is successfully added" << endl;
            }
            else{
                cout << "Edge between " << id1 << " and " << id2 << " already exists " << endl;
            }
        }
        else{
            cout << "Either " << id1 << " or " << id2 << " or both does not exist in the graph" << endl;
        }
    }

    bool checkIfEdgeExistsbyID(int id1, int id2){
        Vertex v = getVertexbyID(id1);
        
        // traversing adjList of id1
        list <Edge> :: iterator it;
        for(it = v.adjList.begin(); it != v.adjList.end(); ++it){
            if(it->destID == id2 )
                return true;
        }
        return false;
    }

    Vertex getVertexbyID(int id){
        Vertex temp;
        for(int i = 0; i < graph.size(); i++){
            if(graph.at(i).ID == id){
                temp = graph.at(i);
                break;
            }
        }
        return temp;
    }
    void printGraph(){
        for(int i = 0; i < graph.size(); i++){
            cout << graph.at(i).ID << "-->  " ;
            graph.at(i).printAdjList();
            cout << endl;
        }
    }
    void bfs(){
        vector <bool> visited (graph.size()+1, false);
        list <Vertex> queue;

        // taking first node, pushing it in queue and marking it as visited
        visited[1] = true;
        queue.push_back(getVertexbyID(1));

        while(!queue.empty()){
            Vertex v = queue.front();
            cout << v.ID << " ";
            queue.pop_front();

            list <Edge> :: iterator it;
            for(it = v.adjList.begin(); it != v.adjList.end(); ++it){
                if(!visited[it->destID]){
                    visited[it->destID] = true;
                    queue.push_back(getVertexbyID(it->destID));
                }
            }
        }
    }
    // deleting an edge
    void deleteEdgebyID(int id1, int id2){
        bool check = checkIfEdgeExistsbyID(id1, id2);
        if(check){
            for(int i = 0; i < graph.size(); i++){
                if(graph.at(i).ID == id1){
                    list <Edge> :: iterator it;
                    for(it = graph.at(i).adjList.begin(); it != graph.at(i).adjList.end(); ++it){
                        if(it->destID == id2){
                            graph.at(i).adjList.erase(it);
                        }
                    }
                }
                if(graph.at(i).ID == id2){
                    list <Edge> :: iterator it;
                    for(it = graph.at(i).adjList.begin(); it != graph.at(i).adjList.end(); ++it){
                        if(it->destID == id1){
                            graph.at(i).adjList.erase(it);
                        }
                    }
                }
            }
            cout << "Edge deleted successfully" << endl;
        }
        else{
            cout << "Edge between " << id1 << "  and " << id2 << " does not exist" << endl;
        }
    }
    // deleting the vertex
    void deleteVertexByID(int id){
        int ind = 0;
        for(int i = 0; i <graph.size(); i++){
            if(graph.at(i).ID == id){
                ind = i;
                list <Edge> :: iterator it;
                for(it = graph.at(i).adjList.begin(); it != graph.at(i).adjList.end(); ++it){
                    deleteEdgebyID(it->destID, id);
                }
                graph.erase(graph.begin() +ind);
                cout << "Vertex successfully deleted" << endl;
            }
            else{
                cout << "Vertex " << id << " does not exist" << endl;
            }
        }
    }
};
int main(){
    Graph g;

    // adding vertices in the graph
    g.addVertex(1 );
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);
    g.addVertex(6);

    // adding edge between vertices
    g.addEdge(1,2);
    g.addEdge(2,4);
    g.addEdge(5,6);
    g.addEdge(3,6);
    g.addEdge(4,2);
    g.addEdge(4,5);

    // printing the graph
    g.printGraph();

    // bfs traversal
    g.bfs();

    return 0;

}