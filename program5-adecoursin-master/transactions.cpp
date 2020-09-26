/* File: transactions.cpp
Author: Abby DeCoursin
Date: 11/13/2019
Description: This file contains the implementation of the transactions objects. Contains
getters and setters for each attribute of a transaction and display and output functions
for displaying and outputting each transaction.
*/
#include "transactions.h"
#include <string>
#include <iostream>
#include <ostream>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;

/* Constructor for transaction. Sets attributes to parameters provided.
*/
Transactions::Transactions(double tranAmt, int tranID, string receiverName, string senderName, int receivID, int sendID) {
        amount = tranAmt;
        transactionID = tranID;
        receiver = receiverName;
        sender = senderName;
        receiverID = receivID;
        senderID = sendID;
}

/* Copy constructor for Transactions objects. Sets values of new Transactions
to the value of the one passed in by reference pointer.
*/
Transactions::Transactions(Transactions * &copyTrans) {
    this->setAmount(copyTrans->amount);
    this->setID(copyTrans->transactionID);
    this->setReceiverName(copyTrans->receiver);
    this->setReceiverID(copyTrans->receiverID);
    this->setSenderName(copyTrans->sender);
    this->setSenderID(copyTrans->senderID);

   // cout << "copy constructor called" << endl;
}

/* Copy assignment operator for Transactions. Checks to make sure that is not
self-assigning, then copies values over. Param is the reference pointer to 
object to be copied. Returns a transaction object.
*/
Transactions& Transactions::operator=(Transactions* &objToCopy) {
     if (this != *&objToCopy) {
        this->setAmount(objToCopy->amount);
        this->setID(objToCopy->transactionID);
        this->setReceiverName(objToCopy->receiver);
        this->setReceiverID(objToCopy->receiverID);
        this->setSenderName(objToCopy->sender);
        this->setSenderID(objToCopy->senderID);
    }
    return *this;
}

/* Gets transaction amount. No param and returns a double.
*/
double Transactions::getAmount() {
    return amount;
}

/* Sets transaction amount. Param is new amount and no return.
*/
void Transactions::setAmount(double newAmt) {
    amount = newAmt;
}
 
/* Gets transaction id. No param and returns an int.
*/
int Transactions::getID() {
    return transactionID;
}

/* Sets transaction id. Param is new id and no return.
*/
void Transactions::setID(int newID) {
    transactionID = newID;
}

/* Gets transaction receiver name. No param and returns a string.
*/
string Transactions::getReceiverName() {
    return receiver;
}

/* Sets transaction receiver name. Param is new name and no return.
*/
void Transactions::setReceiverName(string newRName) {
    receiver = newRName;
}

/* Gets transaction sender name. No param and returns a string.
*/
string Transactions::getSenderName() {
    return sender;
}

/* Sets transaction sender name. Param is new name and no return.
*/
void Transactions::setSenderName(string newSName) {
    sender = newSName;
}

/* Gets transaction receiver id. No param and returns an int.
*/
int Transactions::getReceiverID() {
    return receiverID;
}

/* Sets transaction receiver id. Param is new id and no return.
*/
void Transactions::setReceiverID(int newRID) {
    receiverID = newRID;
}

/* Gets transaction sender id. No param and returns an int.
*/
int Transactions::getSenderID() {
    return senderID;
}

/* Sets transaction sender id. Param is new id and no return.
*/
void Transactions::setSenderID(int newSID) {
    senderID = newSID;
}

/* Displays values of transaction to the console. No return.
*/
void Transactions::display() {
    cout << "Transaction #" << transactionID 
        << " " << sender  << " (ID: " << senderID  << ")" << " sent $" << amount << " to " << receiver  << " (ID: " << receiverID << ")" << endl;
}

/* Outputs value of transaction to the specified output file (the param). No return.
*/
void Transactions::outputTxn(ofstream& outputFile) {
    outputFile << transactionID << "," << sender << "," << receiver << "," << fixed << setprecision(2) << amount << endl; //added in 
}


