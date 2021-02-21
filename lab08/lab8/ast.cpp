/**
  * Autor: Victor Carbune
  * Echipa SD, 2012
  *
  * Modificari: Gabriel Bercaru, 2018
  *
  * License: LGPL
  */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <unordered_map>

#include "BinaryTree.h"
#include "ExpressionNode.h"

#define MAX 1000

using namespace std;

/************ Pentru debugging, puteti decomenta linia urmatoare ************/
//#define DEBUG 1

std::unordered_map<std::string, bool> variables;

/** Helper functions. */
bool isExpression(const char *input)
{
    return strchr(input, '|') != NULL;
}

bool isTerm(const char *input)
{
    return !isExpression(input) && strchr(input, '&') != NULL;
}

bool isLiteral(const char *input)
{
    return !isExpression(input) && !isTerm(input);
}

bool isNegated(const char *input)
{
    return input[0] == '!';
}

BinaryTree<ExpressionNode> *parseLiteral(const char *inputLiteral)
{
    BinaryTree<ExpressionNode> *node;
    ExpressionNode nodeData;

#ifdef DEBUG
    cout << "ParseLiteral: " << inputLiteral << endl;
#endif

    // Update node data.
    // TODO 4.2

    node = new BinaryTree<ExpressionNode>();
    node->setData(nodeData);

    return node;
}

BinaryTree<ExpressionNode> *parseTerm(char *inputTerm)
{
    BinaryTree<ExpressionNode> *node;
    ExpressionNode nodeData;

    // Save the value in a local variable.
    char localString[MAX];
    memset(localString, 0, MAX);
    strcpy(localString, inputTerm);

    if (strlen(localString) == 0)
        return NULL;

#ifdef DEBUG
    cout << "ParseTerm: " << inputTerm << endl;
#endif

    // Initialize the node data.
    // TODO 4.1

    // Tokenize the input.
    char *literal = strtok(localString, "&");

    // Initialize the tree node.
    // TODO 4.1

    // Set the data of the current node.
    // TODO 4.1

    // Parse the left subtree.
    // TODO 4.1

    // Parse the right subtree.
    char *newString = localString + strlen(literal) + 1;
    if (isLiteral(newString))
        node->setRightSubtree(parseLiteral(newString));
    else
        node->setRightSubtree(parseTerm(newString));

    return node;
}


BinaryTree<ExpressionNode> *parseExpression(char *inputExpr)
{
    BinaryTree<ExpressionNode> *node;
    ExpressionNode nodeData;

    // Work on a local string.
    char localString[MAX];
    memset(localString, 0, MAX);
    strcpy(localString, inputExpr);

    if (strlen(localString) == 0)
        return NULL;

#ifdef DEBUG
    cout << "ParseExpression: " << inputExpr << endl;
#endif

    // Initialize the node data.
    nodeData.isOperator = true;
    strcpy(nodeData.value, "|");

    // Tokenize the input.
    char *term = strtok(localString, "|");

    // Initialize the tree node.
    node = new BinaryTree<ExpressionNode>();

    // Set the data of the node.
    node->setData(nodeData);

    // Parse the left subtree.
    if (isLiteral(term))
        node->setLeftSubtree(parseLiteral(term));
    else
        node->setLeftSubtree(parseTerm(term));

    // Parse the right subtree.
    char *newString = localString + strlen(term) + 1;
    if (isExpression(newString)) {
        node->setRightSubtree(parseExpression(newString));
        return node;
    }

    if (isTerm(newString)) {
        node->setRightSubtree(parseTerm(newString));
        return node;
    }

    node->setRightSubtree(parseLiteral(newString));

    return node;
}

bool evaluateAST(BinaryTree<ExpressionNode> *root)
{
    // TODO 5

	return false;
}

/**
 * Associates variable names defined in "variables" input file
 * with given value.
 */
void readVariables(const char *inputFilename)
{
    std::ifstream f(inputFilename);
    std::string variableName;
    std::string variableValue;

    while (f >> variableName >> variableValue)
    {
        if (variableValue.compare("false") == 0)
        {
            variables[variableName] = false;
        } else
        {
            variables[variableName] = true;
        }
    }

    variableName = "0";
    variables[variableName] = false;
    variableName = "1";
    variables[variableName] = true;

    f.close();
}

void checkSimpleExpressionEval()
{

#ifdef DEBUG
    std::ostream& bonus_5 = std::cout;
#else
    std::ofstream file;
    file.open("Out/Lab8/bonus_5.out");
    std::ostream& bonus_5 = file;
#endif

    char inputExpr[MAX];
    BinaryTree<ExpressionNode> *root = NULL;
    
    std::ifstream f("In/simpleExpression");
    std::string inputExpression;

    // Read one line from the input and store it as a char[] in `inputExpr`.
    getline(f, inputExpression);
    strcpy(inputExpr, inputExpression.c_str());

    // Parse the expression and store the root node.
    root = isExpression(inputExpr) ? parseExpression(inputExpr) :
        (isTerm(inputExpr) ? parseTerm(inputExpr) : parseLiteral(inputExpr));

    // TODO 4.3
    bonus_5 << "The result of the expression is: " << evaluateAST(root) << std::endl;

    delete root;
    
    f.close();

#ifndef DEBUG
    file.close();
#endif
}

void checkVariablesExpressionEval()
{

#ifdef DEBUG
    std::ostream& bonus_6 = std::cout;
#else
    std::ofstream file;
    file.open("Out/Lab8/bonus_6.out");
    std::ostream& bonus_6 = file;
#endif

    char inputExpr[MAX];
    BinaryTree<ExpressionNode> *root = NULL;

    std::ifstream f("In/variablesExpression");
    std::string inputExpression;

    // Read one line from the input and store it as a char[] in `inputExpr`.
    getline(f, inputExpression);
    strcpy(inputExpr, inputExpression.c_str());

    // Parse the expression and store the root node.
    root = isExpression(inputExpr) ? parseExpression(inputExpr) :
        (isTerm(inputExpr) ? parseTerm(inputExpr) : parseLiteral(inputExpr));

    // TODO 4.3
    bonus_6 << "The result of the expression is: " << evaluateAST(root) << std::endl;

    delete root;

    f.close();

#ifndef DEBUG
    file.close();
#endif
}

void checkTreeConstruction() {

#ifdef DEBUG
    std::ostream& bonus_4_3 = std::cout;
#else
    std::ofstream file;
    file.open("Out/Lab8/bonus_4_3.out");
    std::ostream& bonus_4_3 = file;
#endif

    std::ifstream f("In/simpleExpression");
    char inputExpr[MAX];
    BinaryTree<ExpressionNode> *root = NULL;

    std::string inputExpression;

    // Read one line from the input and store it as a char[] in `inputExpr`.
    getline(f, inputExpression);
    strcpy(inputExpr, inputExpression.c_str());

    // Parse the expression and store the root node.
    root = isExpression(inputExpr) ? parseExpression(inputExpr) :
        (isTerm(inputExpr) ? parseTerm(inputExpr) : parseLiteral(inputExpr));

    // Debug the root node. The output should match your initial expression.
    std::stringstream ss;
    std::streambuf *defaultStdout = std::cout.rdbuf(ss.rdbuf());
    root->displayTree(0);
    std::cout.rdbuf(defaultStdout);
    bonus_4_3 << ss.str() << std::endl;

    delete root;

    f.close();

#ifndef DEBUG
    file.close();
#endif
}

int main()
{
    readVariables("In/variables");

    checkTreeConstruction();
    checkSimpleExpressionEval();
    checkVariablesExpressionEval();
    
    return 0;
}
