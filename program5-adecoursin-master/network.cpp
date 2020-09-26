/* File: network.cpp
Author: Abby DeCoursin
Date: 11/13/2019
Description: This file contains the implementation of the Network. The functions 
in this file create a network, add transactions from an input file to peers, and 
output all of the ledgers of the peers to different output files.
*/
#include "network.h"
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

/* Constructor for the network, parameters are the name of network and
number of peers within it.
*/
Network::Network(string myName, int myNumberOfPeers) {
    numberOfPeers = myNumberOfPeers;
    name = myName;
}

/* The init function fills the array of peers that the network holds by going
through the first certain number of lines of the file to get the names. It then 
creates peer objects with that specified name and a unique ID. The parameter is
an input stream of the input file and there is no return.
*/
void Network::init(ifstream& inputFile) {

    // fills an array of peers with size numofpeers and 
    // use a for loop to keep appending a peer to the array until for loop runs out
    for (int i = 0; i < numberOfPeers; i++) {
        string peerName;
        getline(inputFile, peerName);

        Peer * currPeer = new Peer(peerName, i + 1);

        peers[i] = currPeer; 
    }

      /* for (int i = 0; i < numberOfPeers; i++) { // checks to make sure peers saved in array correctly
        Peer * currPeer = peers[i];
        currPeer->displayPeer();
    } */ 
}

/* The processTransactions function goes through the parameter of an input stream
and reads through the lines in order to create transactions objects and appending them
to the correct ledger of the sender. It then creates a new transactions object and
performs a deep copy and adds this new object to the ledger of the receiver. After a
transactions is created, it is displayed in the console. There is no return.
*/
void Network::processTransactions(ifstream& inputFile) {
    
    srand(time(NULL));
    string currLine;
    while(getline(inputFile, currLine)) {
        istringstream ss(currLine);
        Transactions * currTxn = new Transactions();

        int transactionID = rand();
        currTxn->setID(transactionID);

        int senderID;
        ss >> senderID;
        currTxn->setSenderID(senderID);

        string senderName;
        senderName = peers[senderID - 1]->getName();
        currTxn->setSenderName(senderName);

        int receiverID;
        ss >> receiverID;
        currTxn->setReceiverID(receiverID);

        string receiverName;
        receiverName = peers[receiverID - 1]->getName();
        currTxn->setReceiverName(receiverName);

        double transactionAmount;
        ss >> transactionAmount;
        currTxn->setAmount(transactionAmount);

        currTxn->display();

        // sender: use a for loop to add to ledger of sender peer

        for (int i = 0; i < numberOfPeers; i++) {
            Peer * currPeer = peers[i];
            int currID = currPeer->getID();

            if (currID == senderID) {
                peers[i]->addTransaction(currTxn);
            }
        }        

        //receiver: create copy of txn and use a for loop to add to ledger of receiver peer

        Transactions * copyOfCurrTxn = new Transactions(currTxn);
        // Transactions * copyOfCurrTxn = currTxn; //  this would call copy assignment operator

        for (int i = 0; i < numberOfPeers; i++) {
            Peer * currPeer = peers[i];
            int currID = currPeer->getID();

            if (currID == receiverID) {
                peers[i]->addTransaction(copyOfCurrTxn);
            }
        }
    } 

       /* // for loop to display all ledgers

        for (int i = 0; i < numberOfPeers; i++) {
            cout << "LEDGER OF PEER #" << i + 1 << endl;
            peers[i]->displayPeer();
        } */   
}

/* Gets the number of peers in the network. Returns an int.
*/
int Network::getNumberOfPeers() {
    return numberOfPeers;
}

/* This function outputs the contents of each peer's ledger to a seperate file.
It creates these files using a loop which correlates to the array of peers.
The parameter is an output file stream and there is no return.
*/
void Network::print(ofstream& outputFile) {
    for (int i = 0; i < numberOfPeers; i++) {
        string outFileName = "peer";
        outFileName += to_string(i + 1);
        outFileName += ".csv";
        outputFile.open(outFileName);

        outputFile << "Id,Sender,Receiver,Amount" << endl;

    //    int numTxns = peers[i]->getNumTransactions();

        peers[i]->outputLedg(outputFile);
                
        outputFile.close();
    }
}