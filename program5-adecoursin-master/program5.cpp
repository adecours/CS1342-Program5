/* File: program5.cpp
Author: Abby DeCoursin
Date: 11/13/2019
Description: This program creates a network which holds a certain number of peers.
Each peer contains a ledger which is a linked list of transactions. The transactions
are read in from an input file which is designated as a command line argument. This file
reads in the number of peers from the first line of the input file and creates a network
with that number and the given name. It then creates peers with names from the following 
lines. After, it uses the processTransaction function to read through each following line
of the input file to create Transactions objects and add them to the ledger of the sender
and receiver peer. The program displays each transaction in the console and outputs the
contents of each ledger to seperate output files within the print function.
*/
#include "transactions.h"
#include "peer.h"
#include "ledger.h"
#include "network.h"
#include <iostream>
#include <fstream>
#include <istream>
using namespace std;

int main(int argc, char* argv[]) {

string inputFile = argv[1]; // uses CL arguments to get file name
    
  ifstream inpFile; // creates input file stream
  inpFile.open(inputFile); // opens input file

  // checks to make sure input file could be opened, else returns an error
  if (!inpFile.is_open()) {
      cout << "Could not open file." << endl;
      return 1;
   }

   int numOfPeers;
   string numPeer;
   getline(inpFile, numPeer); // gets first line of input file which is num of peers
   numOfPeers = stoi(numPeer); // converts this string to an int

    Network abbyNet("abbys", numOfPeers); // creates a network with designated num of peers
    abbyNet.init(inpFile); // creates peers
    abbyNet.processTransactions(inpFile); // adds transactions to correct ledgers

    ofstream outFile; // creates output file stream

    abbyNet.print(outFile); // outputs ledgers to csv files
}