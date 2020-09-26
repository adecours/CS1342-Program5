/* File: ledger.cpp
Author: Abby DeCoursin
Date: 11/13/2019
Description: This file contains the implementation of the ledger which is 
essentially just a linked list. The ledger class has the ability to add to
the end of the list, display the list in the console, and a function to 
output the ledger to an output file.
*/
#include "ledger.h"
#include <iostream>
#include <ostream>
#include <sstream>
#include <fstream>

using namespace std;

/* The append function adds a node to the end of the list which contains a pointer
to the transaction object being added, which is the parameter. There is no return.
*/
void Ledger::append(Transactions *currTransaction) { // give credit to prof
    Node *node = new Node();
    node->currTransaction = currTransaction;
    node->next = NULL;

    if (this->head == NULL) {
        this->head = node;
        this->tail = node;
    }
    else {
        this->tail->next = node;
        this->tail = node;
    }
    this->length++;
}

/* The displayLedger function displays the ledger of a peer in the console
by traversing through the linked list and calling the display function for each
transaction. There is no return or parameter.
*/
void Ledger::displayLedger() { // credit to Prof. Gabrielsen for template 
    Node* temp = this->head;
    while(temp) {
        temp->currTransaction->display(); 
        temp = temp->next;
    }
}

/* The outputLedger function outputs the contents of the ledger of a peer to an
output file. It calls the outputTxn function on each transaction. The outputFile
parameter is the stream for the specified output file and there is no return.
*/
void Ledger::outputLedger(ofstream& outputFile) {
    Node* tempNode = this->head;
    while(tempNode) {
        tempNode->currTransaction->outputTxn(outputFile);
        tempNode = tempNode->next;
    }
}