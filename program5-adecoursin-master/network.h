/* File: network.h
Author: Abby DeCoursin
Date: 11/13/2019
Description: This file contains the class definition for the Network. The functions
create a network, initialize the array of peers, fill the ledgers with transactions,
display to the console, and output to the correct output files.
*/
#include "peer.h"
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>

using namespace std;

class Network {
    public:
        Network(string myName = "", int myNumberOfPeers = 0);
        void init(ifstream& inputFile);
        void processTransactions(ifstream& inputFile);
        void print(ofstream& outputFile);
        int getNumberOfPeers();

    private:
        int numberOfPeers;
        string name;
        Peer * peers[];
};