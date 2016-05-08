/*
Assignment 4
By: Brandon Troche
Professor Stamos
Computer Science 335
Part 1
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
 
 using namespace std;


//This is my parser for the text files. It returns a vector of strings with each line in it.
 std::vector<string> Parser(string fileName, std::vector<string> container){

 	string temp;

	ifstream graphName(fileName);
  		if (graphName.is_open()){
  			cout<<"It's open \n";



  			while(getline(graphName, temp)){

  			container.push_back(temp);
  			cout<<temp<<"\n";
  			temp = "";
  			
  		}

  		graphName.close();

  		}

  		return container;

 }

/*This is my converter for the strings in the vector that we get from the Parser. It turns all of the strings in the 
vector into floats or doubles to maintain numeric values that are useful for comparisons. This function is
primarily for the strings that come from the adjacency query file. This also parses for spaces in the file. */
std::vector<float> vectorConverter(std::vector<std::string> newEdge){

	std::vector<float> Edges;

	//for(std::vector<std::string>::iterator it = newEdge.begin() + 1; it != newEdge.end(); it++){
	for(int i=0; i<newEdge.size(); i++){
		std::string s = newEdge[i];
		std::stringstream ss;
		ss<<s;
		while(ss){

			double temp;
			ss>>temp;
			
			cout<<"Temp is this: "<<temp<<endl;

			if(temp!=0.0){

				Edges.push_back(temp);
				cout<<"This was pushed: " << temp<<endl;
			}

			temp = 0.0;

		}

	}


	return Edges;


}
/* This is another converter function that takes the contents of the graph edges and places them into
a two dimensional vector of float type vectors for better representation of the graph. This acts as its own
parser as well by taking the string values in the graph vector and converting them to double/float as well
but also parsing the file for spaces. */
std::vector<std::vector<float>> graphConverter(std::vector<std::string> newEdge){

	std::vector<float> Edges;
	std::vector<std::vector<float>> returnedEdges;

	//for(std::vector<std::string>::iterator it = newEdge.begin() + 1; it != newEdge.end(); it++){
	for(int i=0; i<newEdge.size(); i++){
		std::string s = newEdge[i];
		std::stringstream ss;
		ss<<s;
		while(ss){

			double temp;
			ss>>temp;
			
			cout<<"Temp is this: "<<temp<<endl;

			if(temp!=0.0){

			cout<<"Temp is still this: "<<temp<<endl;
				Edges.push_back(temp);
				cout<<"This was pushed: " << temp<<endl;
			}

			temp = 0.0;

		}

		returnedEdges.push_back(Edges);
		Edges.clear();

	}


	return returnedEdges;

}

/* This boolean function returns whether an edge is connected to another edge or not by comparing
the edges in the graph and seeing whether the edges have a connection with a weight or not. */

bool isConnected(float Edge1, float Edge2, std::vector<std::vector<float>> graph){
	for(int i=1; i<graph[Edge1].size(); i++){
		if(graph[Edge1][i] == Edge2){
			return true;
		} 
	}

	return false;
}

/* This function was created as a means to use the above isConnected function to output whether the
edges are connected or not and if they are connected it returns the weight of the edge that is connected. */
void checkConnections(std::vector<float> adjacencyQueries, std::vector<std::vector<float>> pointsOnGraph){

	if(isConnected(adjacencyQueries[0], adjacencyQueries[1], pointsOnGraph)){
		cout<<"Connected, weight of edge: "<<pointsOnGraph[adjacencyQueries[0]][adjacencyQueries[1]]<<endl;
	} else {
		cout<<"Not Connected\n";
	}

	if(isConnected(adjacencyQueries[2], adjacencyQueries[3], pointsOnGraph)){
		cout<<"Connected, weight of edge: "<<pointsOnGraph[adjacencyQueries[2]][adjacencyQueries[3]]<<endl;
	} else {
		cout<<"Not Connected\n";
	}

	if(isConnected(adjacencyQueries[4], adjacencyQueries[5], pointsOnGraph)){
		cout<<"Connected, weight of edge: "<<pointsOnGraph[adjacencyQueries[4]][adjacencyQueries[5]]<<endl;
	} else {
		cout<<"Not Connected\n";
	}

	if(isConnected(adjacencyQueries[6], adjacencyQueries[7], pointsOnGraph)){
		cout<<"Connected, weight of edge: "<<pointsOnGraph[adjacencyQueries[6]][adjacencyQueries[7]]<<endl;
	} else {
		cout<<"Not Connected\n";
	}

	if(isConnected(adjacencyQueries[8], adjacencyQueries[9], pointsOnGraph)){
		cout<<"Connected, weight of edge: "<<pointsOnGraph[adjacencyQueries[8]][adjacencyQueries[9]]<<endl;
	} else {
		cout<<"Not Connected\n";
	}


}


 int main(int argc, char **argv){ //Command line arguments for the text files

 	if (argc != 3) {
   		cout << "Usage: " << argv[0] << " <graphfilename> <queryfilename>" << endl;
    	return 0;
 	}	//Convention for compilation shown to the user

  const string graph_filename(argv[1]);	//Places the graph text file name into a const string
  const string query_filename(argv[2]); //places the adjacency text file name into a const string

  std::vector<string> readEdges; 	//Vector of strings for the graph edges
  std::vector<string> readQueries;	//Vector of strings for the adjacency queries
  std::vector<std::vector<float>> graphEdges;	//Vector of float for the graph conversion
  std::vector<float> adjacQueries;		//vector of floats for the adjacency conversion

  readEdges = Parser(graph_filename, readEdges);
  readQueries = Parser(query_filename, readQueries);

  cout<<"We have finished reading file with size: "<<readEdges.size()<<endl;

  graphEdges = graphConverter(readEdges);
  adjacQueries = vectorConverter(readQueries);

  	for(int i=0; i<graphEdges[1].size(); i++){
  		cout<<"This is the " << i <<" element of graphEdges: "<<graphEdges[1][i]<<endl;
	}	

	//cout<<graphEdges.size()<<endl;

	for(int i=0; i<adjacQueries.size(); i++){
  		cout<<"This is the " << i <<" element of adjacQueries: "<<adjacQueries[i]<<endl;
	}	

	checkConnections(adjacQueries, graphEdges);



 }