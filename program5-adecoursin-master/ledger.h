/* File: ledger.h
Author: Abby DeCoursin
Date: 11/13/2019
Description: This file contains the declaration of the ledger class. A ledger
contains a pointer to the head and the tail and has the ability to add to and
display the ledger of a peer.
*/
#ifndef LEDGER_H
#define LEDGER_H

#include <string>
#include "transactions.h"
#include "node.h"
using namespace std;

class Ledger {
    public:
        void append(Transactions *currTransaction);
        int length;
        Node *head;
        Node *tail;
        void displayLedger();
        void outputLedger(ofstream& outputFile);
};

#endif 