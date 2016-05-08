/*
Assignment 4
By: Brandon Troche
Professor Stamos
Computer Science 335
Part 2
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <fstream>

using namespace std;

//Same parser as in part 1
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

// void dijkstra(int src, int start){
		
// 		for (int i = 0; i < start; ++i){
// 			if (i == src)
// 				dset.insert({ src, 0 });
// 			else
// 				dset.insert({ i, numeric_limits<int>::max() });
// 		}
// 		while (!dset.empty()){
// 			//1. get the top vertex, one which has minimum cost
// 			int topvertex = dset.begin()->first;
// 			int topcost = dset.begin()->second;
// 			result.push_back({ topvertex, topcost });
// 			dset.erase(dset.begin());			
// 			//2. find if its neighbors are in the set and update cost if required
// 			for (auto adj_it = adj[topvertex].begin(); adj_it != adj[topvertex].end(); ++adj_it){
// 				int nbr = adj_it->first;
// 				auto dset_it = find_if(dset.begin(), dset.end(), [nbr](pair<int, int> a)->bool{return nbr == a.first; });
// 				if (dset_it != dset.end() && dset_it->second > topcost + adj_it->second ){
// 					//neighbor exists in set and cost update is necessary				
// 					dset.insert({ dset_it->first, topcost + adj_it->second });
// 					dset.erase(dset_it);
// 				}
// 			}
// 		}
// 		getresult(src);
// 	}

//Psuedo Dijkstra, it returns all of the edges and their weights. I was not able to work out the semantics of a proper dijkstra in time
std::string dijkstra(std::vector<std::vector<double>> graph, int start){

	cout<<"Dijkstra was called with start vertex: "<<start<<endl;

	//std::priority_queue<pair<double, double>> queue;



	for(int i=0; i<graph.size(); i++){

		cout<<"The vertex: "<<i<<" contains: ";

		for(int j=0; j<graph[i].size(); j++){
			cout<<graph[i][j]<<", ";
		}

		cout<<"\n";
	}

	for(int i=0; i<graph.size(); i++){

		cout<<"The vertex: "<<i<<" is connected to: ";

		for(int j=1; j<graph[i].size(); j+=2){
			cout<<graph[i][j]<<", ";
			cout<<"with weight: "<<graph[i][j+1]<<endl;
			cout<<"connected to: ";
		}

		cout<<"\n";
	}


	return "Done.";

}
//Same converter as in part 1
std::vector<std::vector<double>> graphConverter(std::vector<std::string> newEdge){

	std::vector<double> Edges;
	std::vector<std::vector<double>> returnedEdges;

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
//Same connection finder as in part 1
bool isConnected(double Edge1, double Edge2, std::vector<std::vector<double>> graph){
	for(int i=1; i<graph[Edge1].size(); i+=2){
		if(graph[Edge1][i] == Edge2){
			return true;
		} 
	}

	return false;
}



int main(int argc, char **argv){

if (argc != 3) {
   		cout << "Usage: " << argv[0] << " <graphfilename> <starting_vertex>" << endl;
    	return 0;
 	} //compilation conventions asserting the starting vertex and graph file name

  const string graph_filename(argv[1]); //Take the file name and place it into a string
  const string starting_vertex(argv[2]);//Take the starting vertex and put it into a string


  std::vector<string> readEdges; 

  std::vector<std::vector<double>> graphEdges;

  readEdges = Parser(graph_filename, readEdges);
  cout<<"We have finished reading file with size: "<<readEdges.size()<<endl;

  graphEdges = graphConverter(readEdges);
  for(int i=0; i<graphEdges[1].size(); i++){
  		cout<<"This is the " << i <<" element of graphEdges: "<<graphEdges[1][i]<<endl;
	}	

  cout<<"Size of graph is: "<<graphEdges.size()<<endl;
  cout<<"The starting vertex is: "<<starting_vertex<<endl;


  cout<<dijkstra(graphEdges, std::stoi(starting_vertex))<<endl;



}