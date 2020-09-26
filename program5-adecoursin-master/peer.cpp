/* File: peer.cpp
Author: Abby DeCoursin
Date: 11/13/2019
Description: This file contains the implementation of the peer class. 
Each peer contains a ledger which holds the linked list of all of the transactions
associated with the peer. The functions within this file manipulate attributes of
the peer as well as dealing with the addition and display of transactions. 
*/
#include "peer.h"
#include "ledger.h"
#include <iostream>
#include <ostream>
#include <sstream>
#include <fstream>

using namespace std;

/* Constructs a peer object with the specified name and id.
*/
Peer::Peer(string myPeerName, int myPeerID) {
    peerLedger = Ledger();
    name = myPeerName;
    peerID = myPeerID;
    numTransactions = 0;
}

/* Sets name of peer. Parameter is new name and there is no return.
*/
void Peer::setName(string newName) {
    name = newName;
}

/* Gets name of peer. No parameter, returns a string.
*/
string Peer::getName() {
    return name;
}

/* Sets ID of peer. Param is new id and no return.
*/
void Peer::setID(int newID) {
    peerID = newID;
}

/* Gets id od peer. No param, returns an int.
*/
int Peer::getID() {
    return peerID;
}

/* adds a transaction to the ledger by calling append function,
increases number of transactions by one. Param is transaction to be
added and there is no return.
*/
void Peer::addTransaction(Transactions* transaction) {
    peerLedger.append(transaction);
    numTransactions++;
}

/* Gets number of transactions. No param, returns an int.
*/
int Peer::getNumTransactions() {
    return numTransactions;
}

/* Outputs contents of ledger by calling outputLedger function
Param is an output file stream and no return.
*/
void Peer::outputLedg(ofstream& outputFile) {
    peerLedger.outputLedger(outputFile);
}

/* Displays attributes of peer (name, id, ledger) to console. 
No param or return.
*/
void Peer::displayPeer() {
    cout << "Peer Name: " << name << endl;
    cout << "Peer ID: " << peerID << endl;
    peerLedger.displayLedger();
}