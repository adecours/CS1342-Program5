/* File: node.h
Author: Abby DeCoursin
Date: 11/13/2019
Description: Contains definition of node class. Each node contains a pointer to 
next node and a pointer to a transactions object.
*/
#ifndef NODE_H
#define NODE_H

#include "transactions.h"

class Node { // credit to Prof. Gabrielsen for template
  public: 
    Transactions *currTransaction;
    Node *next;
};

#endif
