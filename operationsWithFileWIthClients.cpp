#include"../headers/operationsWithFileWIthClients.h"
namespace operationsWithFile {
            // Function to save client information to a file
            void clOperationsWithFile::saveClientInfoToFile(const vector<clClientInfo>& clients, const string& filename) {
                ofstream outFile(filename);
                if (!outFile) {
                    cerr << "Error opening file for writing: " << filename << endl;
                    // Attempt to create the file if it doesn't exist
                    outFile.clear(); // Clear the error state
                    outFile.open(filename, ios::out | ios::app);
                    if (!outFile) {
                        cerr << "Failed to create file: " << filename << endl;
                        return; // Exit if file creation fails
                    }
                }
                for (const auto& client : clients) {
                    outFile << client.getClientAccountNumber() << ","
                            << client.getClientPinCode() << ","
                            << client.getClientAccountName() << ","
                            << client.getClientPhoneNumber() << ","
                            << client.getClientAccountBalance() << endl;
                }
                outFile.close();
            }

            // Function to load client information from a file
            vector<clClientInfo> clOperationsWithFile::loadClientInfoFromFile(const string& filename) {
                vector<clClientInfo> clients;
                ifstream inFile(filename);
                if (!inFile) {
                    cerr << "Error opening file for reading: " << filename << endl;
                    // Attempt to create the file if it doesn't exist
                    ofstream createFile(filename);
                    if (!createFile) {
                        cerr << "Failed to create file: " << filename << endl;
                        return clients; // Return empty vector if file creation fails
                    }
                    createFile.close();
                    inFile.open(filename);

                }
                string line;
                // Read each line from the file and parse the client information
                if (inFile.peek() == ifstream::traits_type::eof()) {
                    cerr << "File is empty or does not contain valid client information." << endl;

                }
                else {
                while (getline(inFile, line)) {
                clClientInfo client;
                clConvertorWithClients conClients(clients);
                client = conClients.convertorWithClients(line, client);
                clients.push_back(client);  

                }
                }
                inFile.close();
                return clients; // Return the loaded clients
            }
}
