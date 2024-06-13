//ID : 207723198
//Mail : yair852258@gmail.com

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <stdexcept>
#include <vector>

using namespace std;

namespace ariel
{
    class Graph {
    private:
        vector<vector<int>> adjacencyMatrix; // Adjacency matrix

    public:
     	//empty constructor
        Graph();

		/**
         * Loads a graph from a given adjacency matrix.
         * @param matrix The adjacency matrix representing the graph.
         */
        void loadGraph(const vector<vector<int>>& adjacencyMatrix);

		/**
         * Gets the adjacency matrix of the graph.
         * @return The adjacency matrix.
         */
        const vector<vector<int>>& getGraph() const;

		/**
         * Checks if the graph is directed.
         * @return True if the graph is directed, false otherwise.
         */
        bool isDirected() const;

		/**
         * Checks if the graph is weighted.
         * @return 1 if the graph is weighted, 0 otherwise.
         */
        int isWeighted() const;

		/**
         * Prints the graph.
         */
        void printGraph() const;

		/**
         * Gets the number of Edges in the graph.
         * @return The number of Edges.
         */
		int countEdges() const;

		/**
         * Gets the number of vertices in the graph.
         * @return The number of vertices.
         */
        size_t getNumVertices() const;

    };
}

#endif /* GRAPH_HPP */