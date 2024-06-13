//ID : 207723198
//Mail : yair852258@gmail.com
#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test isConnected")
{
    // Undirected connected graph
    ariel::Graph g;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    // Undirected disconnected graph
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);

    // Directed connected graph
    vector<vector<int>> graph3 = {
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    // Directed disconnected graph
    vector<vector<int>> graph4 = {
    {0, 1, 1, 0, 0},
    {5, 0, 1, 0, 0},
    {1, 1, 0, 1, 0},
    {0, 0, 7, 0, 0},
    {0, 0, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isConnected(g) == false);

    // Create a graph with a single vertex
    std::vector<std::vector<int>> single_vertex_graph = {{0}};
    g.loadGraph(single_vertex_graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    // Graph with disconnected single edges
    std::vector<std::vector<int>> disconnected_single_edges_graph = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 0}} ;
    g.loadGraph(disconnected_single_edges_graph);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}


TEST_CASE("Test shortestPath")
{
    ariel::Graph g;

    // Undirected graph with valid path
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    // Undirected graph with no path
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");

    // Directed positive weighted graph without a path
    std::vector<std::vector<int>> graph3 = {
        {0, 2, 4, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");

    // Directed positive weighted graph with a path
    std::vector<std::vector<int>> graph4 = {
        {0, 2, 4, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 2, 0},
        {0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "0->1->2->3->4");

    // Undirected positive weighted graph with a path
    vector<vector<int>> graph5 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4)== "0->2->3->4");

    // Undirected graph with negative edges
    vector<vector<int>> graph6 = {
        {0, -1, 1, 0, 0},
        {-1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) =="-1");

    // Directed graph without cycles with negative edges and no valid path
    vector<vector<int>> graph7 = {
    {0, 3, 0, 0, 0},
    {0, 0, 2, 0, 0},
    {0, 0, 0, -1, 0},
    {0, 0, 0, 0, 2},
    {0, 0, 0, 0, 0}};
    g.loadGraph(graph7);
    CHECK(ariel::Algorithms::shortestPath(g, 1, 0)== "-1");

    // Directed graph with positive cycle and negative edges
    vector<vector<int>> graph8 = {
    {0, 3, 0, 0, 0},
    {0, 0, 2, 0, 0},
    {10, 0, 0, -1, 0},
    {0, 0, 0, 0, 2},
    {0, 0, 0, 0, 0}};
    g.loadGraph(graph8);
    CHECK(ariel::Algorithms::shortestPath(g, 1, 0)== "1->2->0");

    // Directed graph with negative cycle
    vector<vector<int>> graph9 = {
    {0, 3, 0, 0, 0},
    {0, 0, 2, 0, 0},
    {-10, 0, 0, -1, 0},
    {0, 0, 0, 0, 2},
    {0, 0, 0, 0, 0}};
    g.loadGraph(graph9);
    CHECK(ariel::Algorithms::shortestPath(g, 1, 0)== "-1");

    // Source too big - throw "invalid start vertex"
    CHECK_THROWS(ariel::Algorithms::shortestPath(g, 10, 0));
}


TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;

    // Undirected graph no cycle
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");

    // Undirected graph with a positive cycle
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0->1->2->0");

    // Undirected graph with negative cycle
    vector<vector<int>> graph3 = {
    {0,-5, 1, 0, 0},
    {-5, 0, 1, 0, 0},
    {1, 1, 0, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isContainsCycle(g)== "0->1->2->0");

    // Directed graph without cycles with negative edges
    vector<vector<int>> graph4 = {
    {0, 3, 0, 0, 0},
    {0, 0, 2, 0, 0},
    {0, 0, 0, -1, 0},
    {0, 0, 0, 0, 2},
    {0, 0, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isContainsCycle(g)== "0");

    // Directed graph positive cycle and negative edges
    vector<vector<int>> graph5 = {
    {0, 3, 0, 0, 0},
    {0, 0, 2, 0, 0},
    {0, 0, 0, -1, 0},
    {2, 0, 0, 0, 2},
    {0, 0, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isContainsCycle(g)== "0->1->2->3->0");
}


TEST_CASE("Test isBipartite")
{
    ariel::Graph g;

    // Undirected graph no cycle
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    // Undirected unweighted with a odd cycle
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    // Undirected graph with a positive odd cycle
    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    // Directed graph with a positive odd cycle
    vector<vector<int>> graph4 = {
        {0, -5, 0, 0},
        {0, 0, 5, 0},
        {1, 0, 0, 0},
        {0, 1, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    // Undirected weighted graph with no cycle
    vector<vector<int>> graph5 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");

    // Undirected graph with negative odd cycle
    vector<vector<int>> graph6 = {
    {0,-5, 1, 0, 0},
    {-5, 0, 1, 0, 0},
    {1, 1, 0, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isBipartite(g)== "0");

    // Undirected graph with negative even cycle
    vector<vector<int>> graph7 = {
    {0,-5, 0, 1, 0},
    {-5, 0, 1, 0, 0},
    {0, 1, 0, 1, 0},
    {1, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}};
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::isBipartite(g)== "The graph is bipartite: A={0, 2, 4}, B={1, 3}");

    // Directed graph with negative even cycle
    vector<vector<int>> graph8 = {
        {0, -2, 0, 0, 0},
        {0, 0, -3, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, -2, 0, 0, 0}};
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::isBipartite(g)== "The graph is bipartite: A={0, 2, 4}, B={1, 3}");
}

TEST_CASE("Test negativeCycle")
{
    ariel::Graph g;

    // Undirected graph no cycle
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");

    // Undirected graph with positive cycle
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::negativeCycle(g) == "0");

    // Undirected graph with negative cycle
    vector<vector<int>> graph3 = {
    {0,-5, 1, 0, 0},
    {-5, 0, 1, 0, 0},
    {1, 1, 0, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::negativeCycle(g)== "0->1->2->0");

    // Directed graph with negative edges without cycles
    vector<vector<int>> graph4 = {
    {0, 3, 0, 0, 0},
    {0, 0, 2, 0, 0},
    {0, 0, 0, -1, 0},
    {0, 0, 0, 0, 2},
    {0, 0, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::negativeCycle(g)== "0");

    // Directed graph positive cycle with negative edges
    vector<vector<int>> graph5 = {
    {0, 3, 0, 0, 0},
    {0, 0, 2, 0, 0},
    {0, 0, 0, -1, 0},
    {2, 0, 0, 0, 2},
    {0, 0, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::negativeCycle(g)== "0");

    // Directed graph with negative cycle
    vector<vector<int>> graph6 = {
    {0,-5, 1, 0, 0},
    {2, 0, 1, 0, 0},
    {1, 1, 0, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}};
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::negativeCycle(g)== "0->1->0");
}

TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}


