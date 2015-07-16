/*
 * ANodeTooFar.cpp
 *
 *  Created on: Jul 15, 2015
 *      Author: Diego Martins
 */
#include <iostream>
#include <unordered_set>
#include <queue>
#include "Graph.h"

using Ttl = int;
Graph readGraph(int nodes);
void queryGraph(Graph const & graph, int caseN, Graph::Id node, Ttl ttl);

using namespace std;

int main()
{
	int nodes;
	int caseN = 0;
	while( (cin >> nodes) && nodes > 0 ) {
		auto graph = readGraph(nodes);
		Graph::Id node;
		Ttl ttl;
		while( (cin >> node >> ttl) && (node > 0 || ttl > 0) ) {
			++caseN;
			queryGraph(graph,caseN,node,ttl);
		}
	}
}

Graph readGraph(int nodes)
{
	Graph result;
	for( int n = 0; n < nodes; ++n ) {
		Graph::Id n1, n2;
		cin >> n1 >> n2;
		result.addConnection(n1,n2);
	}
	return result;
}

void queryGraph(Graph const & graph, int caseN, Graph::Id node, Ttl ttl)
{
	unordered_set<Graph::Id> visited;
	struct Elem {
		Graph::Id node;
		Ttl ttl;
	};
	queue<Elem> bfs;

	auto missing = graph.size()-1;
	bfs.push({node,ttl});
	visited.insert(node);

	while( ! bfs.empty() ) {
		auto elem = bfs.front();
		if( elem.ttl == 0 ) break;

		bfs.pop();
		for( auto graphNode : graph.nodes(elem.node) ) {
			if( visited.count(graphNode) == 0 ) {
				visited.insert(graphNode);
				bfs.push({graphNode, elem.ttl-1});
				--missing;
			}
		}
	}

	cout << "Case " << caseN << ": " << missing
			<< " nodes not reachable from node " << node
			<< " with TTL = " << ttl << "." << endl;
}
