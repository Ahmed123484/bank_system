#include "../headers/deleteClient.h"
using namespace std;
namespace deleteClientAndUser {
    
            // Function to delete a client by account number
            bool clDeleteClientAndUser::deleteClientByAccountNumber(vector<clClientInfo>& clients, const string& accountNumber) {
                for (auto it = clients.begin(); it != clients.end(); ++it) {
                    if (it->getClientAccountNumber() == accountNumber) {
                        clients.erase(it); // Remove the client from the vector
                        cout << "Client with account number " << accountNumber << " has been deleted." << endl;
                        return true; // Client deleted successfully
                    }
                }
                cout << "Client with account number " << accountNumber << " not found." << endl;
                return false; // Client not found
            }
            bool clDeleteClientAndUser::deleteUserByAccountName(vector<clUserInfo>& users, const string& accountName) {
                for (auto it = users.begin(); it != users.end(); ++it) {
                    if (it->getUserName() == accountName) {
                        users.erase(it); // Remove the user from the vector
                        cout << "User with account number " << accountName << " has been deleted." << endl;
                        return true; // User deleted successfully
                    }
                }
                cout << "User with account name " << accountName << " not found." << endl;
                return false; // User not found
            }
            bool clDeleteClientAndUser::deleteClientByAccountName(vector<clClientInfo>& clients, const string& accountName) {
                for (auto it = clients.begin(); it != clients.end(); ++it) {
                    if (it->getClientAccountName() == accountName) {
                        clients.erase(it); // Remove the client from the vector
                        cout << "Client with account name " << accountName << " has been deleted." << endl;
                        return true; // Client deleted successfully
                    }
                }
                cout << "Client with account name " << accountName << " not found." << endl;
                return false; // Client not found
            }
    
}
