#include"../headers/addNewClient.h"
using namespace std; 
namespace addNewClient {
    // constructor
    clAddNewClient::clAddNewClient(clClientInfo &Client, vector<clClientInfo> &allClients)
    : newClient(Client), clients(allClients) {
        
    }
    // setter
    void clAddNewClient::setClientAccountNumber(string &accountNumber) {
        newClient.setClientAccountNumber(accountNumber);
    }
    void clAddNewClient::setClientPinCode(string &pinCode) {
        newClient.setClientPinCode(pinCode);
    }
    void clAddNewClient::setClientAccountName(string &accountName) {
        newClient.setClientAccountName(accountName);
    }
    void clAddNewClient::setClientPhoneNumber(string &phoneNumber) {
        newClient.setClientPhoneNumber(phoneNumber);
    }
    void clAddNewClient::setClientAccountBalance(string &accountBalance) {
        newClient.setClientAccountBalance(accountBalance);
    }
    void clAddNewClient::setAllClientInfo(string &accountNumber, string &pinCode, string &accountName, string &phoneNumber, string &accountBalance) {
        newClient.setClientInfo(accountNumber, pinCode, accountName, phoneNumber, accountBalance);
    }
    // getter
    string clAddNewClient::getClientAccountNumber() {
        return newClient.getClientAccountNumber();
    }
    string clAddNewClient::getClientPinCode() {
        return newClient.getClientPinCode();
    }
    string clAddNewClient::getClientAccountName() {
        return newClient.getClientAccountName();
    }
    string clAddNewClient::getClientPhoneNumber() {
        return newClient.getClientPhoneNumber();
    }
    string clAddNewClient::getClientAccountBalance() {
        return newClient.getClientAccountBalance();
    }
    clClientInfo &clAddNewClient::getClientInfo() {
        return newClient;
    }
    // add new client 
    void clAddNewClient::addNewClient(){
        string input ;
        cout << "Enter Client Account Number: " ;
        getline(cin >> ws, input);
        newClient.setClientAccountNumber(input);
        cout << "Enter client account pin code: " ;
        getline(cin >> ws, input);
        newClient.setClientPinCode(input);
        cout << "Enter client account Name : " ;
        getline(cin >> ws, input);
        newClient.setClientAccountName(input);
        cout << "Enter client phone number: " ;
        getline(cin >> ws, input);
        newClient.setClientPhoneNumber(input);
        cout << "Enter client account balance: " ;
        getline(cin >> ws, input);
        newClient.setClientAccountBalance(input);
    }
    // display info 
    void clAddNewClient::displayClientInfo(){
        newClient.displayClientInfo();
    }
    // confirmation 
    bool clAddNewClient::confirmation(){
        cout <<"============================================================" << endl ;
        cout << "Client Information: " << endl;
        cout <<"============================================================" << endl ;
        clAddNewClient::displayClientInfo();
        cout <<"============================================================" << endl ;
        string input ;
        cout << "Are you sure you want to add this client? (y/n) : " ;
        cin >> input ;
        if (tolower(input[0]) == 'y') {
            return true;
        } 
        return false;
    }
    // add client in vector 
    void clAddNewClient::addClientInVector(){
        if (confirmation()) {
            clients.push_back(newClient);
        }
    }



}
