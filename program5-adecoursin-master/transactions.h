/* File: transactions.h
Author: Abby DeCoursin
Date: 11/13/2019
Description: This file contains the class definition for a transaction. A transaction
contains an amount, id, sender id, sender name, receiver id, and receiver name. The class
also contains functions to display these values either to the console or to the specified
output file.
*/
#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include <string>
using namespace std;

class Transactions {
    public:
        Transactions(double tranAmt = 0, int tranID = 0, string receiverName = "null", string senderName = "null", int receivID = 0, int sendID = 0);
        Transactions(Transactions * &copyTrans);
        // ~Transactions(); dont need this since nothing to delete

        double getAmount();
        int getID();
        string getReceiverName();
        string getSenderName();
        int getReceiverID();
        int getSenderID();

        void setAmount(double newAmt);
        void setID(int newID);
        void setReceiverName(string newRName);
        void setSenderName(string newSName);
        void setReceiverID(int newRID);
        void setSenderID(int newSID);
        void display();
        void outputTxn(ofstream& outputFile);
        Transactions& operator=(Transactions* &objToCopy);

    private:
        double amount;
        int transactionID;
        string receiver;
        string sender;
        int receiverID;
        int senderID;

};

#endif