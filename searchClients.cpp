#include "../headers/searchClients.h"
namespace searchClients {
        // Function to search for a client by account number
        bool clSearchClients::searchClientByAccountNumber(const vector<clClientInfo>& clients, const string& accountNumber) {
            for (const auto& client : clients) {
                if (client.getClientAccountNumber() == accountNumber) {
                    // cout << "Client found: " << client.getClientAccountName() << endl;
                    return true; // Client found
                }
            }
            cout << "Client not found." << endl;
            return false; // Client not found
        }
        // Function to search for a client by name
        bool clSearchClients::searchClientByName(const vector<clClientInfo>& clients, const string& accountName) {
            for (const auto& client : clients) {
                if (client.getClientAccountName() == accountName) {
                    cout << "Client found: " << client.getClientAccountName() << endl;
                    return true; // Client found
                }
            }
            cout << "Client not found." << endl;
            return false; // Client not found
        }
        // function to display results of the search 
        void clSearchClients:: displayResults (bool found, const string& searchType) {
            if (found) {
                cout << "Search for " << searchType << " was successful." << endl;
            } else {
                cout << "Search for " << searchType << " did not yield any results." << endl;
            }
        }
} // namespace searchClients
