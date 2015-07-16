/*
 * Graph.cpp
 *
 *  Created on: Jul 15, 2015
 *      Author: Diego Martins
 */

#include "Graph.h"

void Graph::addConnection(Id node1, Id node2)
{
	graph[node1].push_back(node2);
	graph[node2].push_back(node1);
}

auto Graph::nodes(Id node) const -> Ids const &
{
	auto it = graph.find(node);
	if( it == graph.end() ) throw "graph is corrupt";
	return it->second;
}
