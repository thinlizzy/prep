/*
 * Graph.h
 *
 *  Created on: Jul 15, 2015
 *      Author: Diego Martins
 */

#ifndef GRAPH_H_UVA336_DIEGO
#define GRAPH_H_UVA336_DIEGO

#include <unordered_map>
#include <vector>

class Graph {
public:
	using Id = int;
private:
	using Ids = std::vector<Id>;
	std::unordered_map<Id,Ids> graph;
public:
	Graph() = default;
	void addConnection(Id node1, Id node2);
	size_t size() const { return graph.size(); }
	Ids const & nodes(Id node) const;
};

#endif /* GRAPH_H_ */
