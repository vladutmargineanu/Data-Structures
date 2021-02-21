/**
  * Autor: Victor Carbune
  * Echipa SD, 2012
  *
  * License: LGPL
  */

#ifndef __EXPRESSION_NODE_H
#define __EXPRESSION_NODE_H

#include <iostream>

#define MAXSIZE 1000

using namespace std;

struct ExpressionNode
{
	bool isOperator;
	char value[MAXSIZE];

	friend ostream &operator << (ostream &out, ExpressionNode &node);
};

// Debugging purposes for ExpressionNode
ostream &operator<<(ostream &out, ExpressionNode &node)
{
	out << node.value;
	return out;
}

#endif	// __EXPRESSION_NODE_H
