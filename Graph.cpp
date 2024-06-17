//ID : 207723198
//Mail : yair852258@gmail.com
#include "Graph.hpp"
#include <iostream>

namespace ariel
{
    //empty constructor
    Graph::Graph()
    {

    }

    //loading the graph
    void Graph::loadGraph(const vector<vector<int>>& adjMatrix)
    {
        // Check if the input matrix is a valid adjacency matrix
        if (adjMatrix.empty() || adjMatrix[0].empty())
        {
            throw std::invalid_argument("Invalid graph: The graph matrix is empty.");
        }

        // Check if the input matrix is a vsquare matrix
        size_t rows = adjMatrix.size();
        size_t columns = adjMatrix[0].size();
        if (rows != columns) {
            throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
        }

        // Check if diagonal elements are all zero
        for (size_t i = 0; i < adjMatrix.size(); ++i)
        {
            if (adjMatrix[i][i] != 0)
            {
                throw std::invalid_argument("Invalid graph: Diagonal elements must be zero.");
            }
        }

        // Load the graph from the input matrix
        this->adjacencyMatrix = adjMatrix;
    }

    //get the adj matrix that represnting the graph
    const vector<vector<int>>& Graph::getGraph() const
    {
        return adjacencyMatrix;
    }

	bool Graph::isDirected() const
    {
        // Checks if the graph matrix represents a directed graph
        for (size_t i = 0; i < adjacencyMatrix.size(); ++i)
        {
            for (size_t j = 0; j < adjacencyMatrix.size(); ++j)
            {
                if (adjacencyMatrix[i][j] != adjacencyMatrix[j][i])
                {
                    return true; //If there is an edge from i to j but not from j to i this is mean that the graph is directed
                }
            }
        }
        return false; // If there are no differing edges, the graph is undirected
    }

    // Checks if the graph is weighted and if contains negative edges
	int Graph::isWeighted() const
    {
        for (const vector<int> &row : adjacencyMatrix)
        {
            for (int element : row)
            {
                if (element < 0)
                {
                    return -1; // The graph contains negative edges
                }
                if (element != 0 && element != 1)
                {
                    return 1; // The graph is weighted
                }
            }
        }
        return 0; // The graph is unweighted and contains no negative edges
    }

    void Graph:: printGraph() const
    {
		std::cout << "Graph with " << adjacencyMatrix.size() << " vertices and " << countEdges() << " edges." << std::endl;
        for (size_t i = 0; i < adjacencyMatrix.size(); ++i)
        {
            cout << "Adjacency list of vertex " << i << ": ";
            for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j)
            {
                if (adjacencyMatrix[i][j] != 0) // Only print non-zero edges cause if edge = 0 there is no edge
                {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }

	int Graph::countEdges() const
    {
        int edge_counter = 0;
		bool graphIsDirected = isDirected();
        for (size_t i = 0; i < adjacencyMatrix.size(); ++i)
        {
            for (size_t j = 0; j < adjacencyMatrix.size(); ++j)
            {
                // For directed graph, count only if there's an edge from i to j
                // For undirected graph, count if there's any edge between i and j
                if ((adjacencyMatrix[i][j] > 0) && (!graphIsDirected || (graphIsDirected && adjacencyMatrix[j][i] > 0)))
                {
                    edge_counter++;
                }
            }
        }

        return edge_counter;
    }

    //get the adj matrix that represnting the graph
    size_t Graph::getNumVertices() const
    {
        return adjacencyMatrix.size();
    }

};