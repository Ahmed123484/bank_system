#include "../headers/screenDeleteClient.h"
#include "../headers/screenShowclients.h"
using namespace screenShowClients;
namespace screenDeleteClient {
    void clscreenDeleteClient::screenDeleteClients(vector<clClientInfo> &clients , short input , string fileName) {
        cout << "Welcome in delete screen \n";
        cout << "Do you want to delete a client with account number or with user account name ? \n";
        cout << "1- Account Number \n2- User Account Name : \n";
        cin >> input ;
        if (validateInputAnswer(input)) {
            if (input == 1) {
                string accountNumber ;
                cout << "Enter Client Account Number: " ;
                cin >> accountNumber;
                if (clDeleteClientAndUser::deleteClientByAccountNumber(clients , accountNumber)) {
                clOperationsWithFile::saveClientInfoToFile(clients,fileName );
                  }
            }
            else if (input == 2) {
                string accountName ;
                cout << "Enter Client Account Name: " ;
                getline(cin >> ws, accountName);
                if (clDeleteClientAndUser::deleteClientByAccountName(clients , accountName)){
                    clOperationsWithFile::saveClientInfoToFile(clients,fileName );
                }
            }
        }
    }
    bool clscreenDeleteClient::validateInputAnswer (short input) {
        if (input == 1 || input == 2) {
            return true;
        }
        return false;
    }
}