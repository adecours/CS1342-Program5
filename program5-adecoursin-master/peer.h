/* File: peer.h
Author: Abby DeCoursin
Date: 11/13/2019
Description: This file contains the class definition for the peer class. It contains
functions to get and set the name, id, and number of transactions of each peer, 
a display function, and an output function.
*/
#ifndef PEER_H
#define PEER_H

#include <string>
#include <ostream>
#include <sstream>
#include <fstream>
#include "ledger.h"
using namespace std;

class Peer {
    public:
        Peer(string myPeerName = "No Name", int myPeerID = 0);
        void setName(string newName);
        string getName();
        void setID(int newID);
        int getID();
        void addTransaction(Transactions* transaction);
        void displayPeer();
        int getNumTransactions();
        void outputLedg(ofstream& outputFile);

    private:
        string name;
        int peerID;
        Ledger peerLedger;
        int numTransactions;
};

#endif