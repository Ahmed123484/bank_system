#include"../headers/startApp.h"
namespace startApp {
            // Function to start the application
            void clStartApp::startApplication(){
                clScreenHomePage::printMainPageHeader();
                clScreenHomePage::printMainPageFooter();
                cout << "Welcome to the Banking Application!" << endl;
                cout << "Please select an option from the menu." << endl;
            }
            void clStartApp::test (){
                clScreenManageUser::printMainPageHeader();
                clScreenManageUser::printMainPageFooter();
            }
            void clStartApp::showClients(){
                vector<clClientInfo> clients = clOperationsWithFile::loadClientInfoFromFile("C:\\Users\\zahra\\OneDrive\\Desktop\\aboHadhoud\\fullProject_corse8\\assets\\clients.txt");
                clScreenShowClients::printVector(clients);
                system("pause");
            }
            void clStartApp::addNewClient(vector<clClientInfo> &clients , clClientInfo &newClient){
                clAddNewClient addNewCli(newClient, clients); ;
                addNewCli.addNewClient();
                addNewCli.addClientInVector();
                clOperationsWithFile::saveClientInfoToFile(clients, "C:\\Users\\zahra\\OneDrive\\Desktop\\aboHadhoud\\fullProject_corse8\\assets\\clients.txt"); 
            }
            void clStartApp::deleteClient(vector <clClientInfo> &clients , string fileName){
                short input = 0;
                clscreenDeleteClient::screenDeleteClients(clients , input , fileName);
            }
            void clStartApp::updateClient(vector <clClientInfo> &clients , string fileName , string accountNumber){
                bool found = false;
                for (clClientInfo &client : clients) {
                    if (client.getClientAccountNumber() == accountNumber) {
                     string input ;
                     cout << " Enter pin code: " ;
                     getline(cin >> ws, input);
                     client.setClientPinCode(input);
                     cout << "Enter client account Name : " ;
                     getline(cin >> ws, input);
                     client.setClientAccountName(input);
                     cout << "Enter client phone number: " ;
                     getline(cin >> ws, input);
                     client.setClientPhoneNumber(input);
                     cout << "Enter client account balance: " ;
                     getline(cin >> ws, input);
                     client.setClientAccountBalance(input);
                     found = true;
                     break;
                    }
                }
                if (!found) {
                    cout << "Client with account number " << accountNumber << " not found." << endl;
                }
                if (found) {
                    cout << "Client with account number " << accountNumber << " has been updated." << endl;
                    clOperationsWithFile::saveClientInfoToFile(clients, fileName);
                }
            }

            void clStartApp::searchClient( vector <clClientInfo> clients , const string accountNumber){
                if (clSearchClients::searchClientByAccountNumber(clients , accountNumber)){
                    clSearchClients::displayResults(true , "accountNumber");
                    for (const auto& client : clients) {
                        if (client.getClientAccountNumber() == accountNumber) {
                            clScreenShowClients::displayHeaderWithOneClient(client);
                            clScreenShowClients::displayFooter(client);
                            break;
                        }
                    }
                }
            }
            void clStartApp::transactions(vector <clClientInfo> &clients , string fileName , string accountNumber , clClientInfo &client){
                while (true) {
                clScreenTransactions::printHeaderScreenTransactions();
                clScreenTransactions::printFooterScreenTransactions();
                short input = 0;
                cout << "Enter the transaction type: " ;
                cin >> input ;
                // for (auto &client : clients) {
                    // if (client.getClientAccountNumber() == accountNumber) {
                    clTransactionsWithAcc transaction(client , clients);
                        if (input == 1) {
                            cout << "How much money do you want to deposit? ";
                            double amount;
                            cin >> amount;
                            transaction.depositMoney(accountNumber , amount);
                            clients = transaction.getClientAccounts();
                            system("pause"); // Pause to deposit money
                        }
                        else if (input == 2) {
                            cout << "How much money do you want to withdraw? ";
                            double amount;
                            cin >> amount;
                            transaction.withdrawMoney(accountNumber , amount);
                            clients = transaction.getClientAccounts();
                            system("pause");
                        }
                        else if (input == 3) {
                            clScreenShowClients::printVector(clients);
                            int totalBalance = 0 ;
                            for (auto &client : clients) {
                                totalBalance += stoi(client.getClientAccountBalance());
                            }
                            cout << "==========================================================================================" << endl ;
                            cout <<setw(65) <<"" <<"Total balance:" << totalBalance << endl;
                            system("pause");
                            
                        }
                        else if (input == 4) {
                            break; // Exit transactions menu
                        }
                        else {
                            cout << "Invalid input. Please try again." << endl;
                        }
                        clOperationsWithFile::saveClientInfoToFile(clients, fileName);
                    }
            }
            void clStartApp::showUsers (vector <clUserInfo> &users , string fileName){
                clScreenShowUser::printVector(users);
            }
            void clStartApp::addNewUser(vector <clUserInfo> &users , string fileName , clUserInfo &newUser){
             string input ;
             cout << "Enter user name: " ;
             getline(cin >> ws, input);
             newUser.setUserName(input);
             cout << "Enter user pin code: " ;
             getline(cin >> ws, input);
             newUser.setUserPassword(input);
             cout << "Enter account number: " ;
             getline(cin >> ws, input);
             newUser.setAccountNumber(input);
             User userPP(0);
             cout << "Do you want to add all permissions? (y/n): ";
             char choice;
             cin >> choice;
             if (choice == 'y' || choice == 'Y') {
                 userPP.addAllPermissionUser();
                 newUser.setUserPermission(userPP.getPermissions());
             } else {
                 newUser.setUserPermission(userPP.addAndAskkpermissonUser());
             }
             users.push_back(newUser);           
             clOperationsWithFileWithUser::saveUsers(users , fileName);
            }
            void clStartApp::deleteUser(vector <clUserInfo> &users , string fileName){
                string userName ;
                cout << "Enter User Name: " ;
                getline(cin >> ws, userName);
                if (clDeleteClientAndUser::deleteUserByAccountName(users , userName)){
                    clOperationsWithFileWithUser::saveUsers(users, fileName);
                }
            }
            void clStartApp::updateUser(vector <clUserInfo> &users , string fileName , string userName){
               vector <clUserInfo> newUsers;
                for (auto &user : users) {
                    if (user.getUserName() == userName) {
                        string input ;
                        cout << "Enter user name: " ;
                        getline(cin >> ws, input);
                        user.setUserName(input);
                        cout << "Enter user pin code: " ;
                        getline(cin >> ws, input);
                        user.setUserPassword(input);
                        cout << "Enter account number: " ;
                        getline(cin >> ws, input);
                        user.setAccountNumber(input);
                        // cout << "Enter user Role: " ;
                        // getline(cin >> ws, input);
                        // user.setUserPermission(stoi(input));
                        newUsers.push_back(user);
                    }
                    else {
                        newUsers.push_back(user);
                    }
                }
                users = newUsers;
                clOperationsWithFileWithUser::saveUsers(users , fileName);
            }
            void clStartApp::searchUser(vector <clUserInfo> users , const string userName){
               for (auto &user : users) {
                    if (user.getUserName() == userName) {
                        cout << "We found the user " << userName << endl;
                        clScreenShowUser::displayHeader();
                        clScreenShowUser::displayFooter(user);
                        break;
                    }
                }
            }
            void clStartApp::manageUsers(vector <clUserInfo> &users , string fileName , int permission) {
                User userPP(permission);
                short input = 0 ;
                while (true) {
                        clScreenManageUser::printMainPageHeader();
                        clScreenManageUser::printMainPageFooter();
                        cout << "Please Enter your choice: " ;
                        cin >> input ;
                        string userName ;
                        clUserInfo newUser ;
                        
                    if (input == 1){
                        if (userPP.hasPermission(PERM_LIST_USERS)){
                            clStartApp::showUsers(users , fileName);
                            system("pause");
                        }
                        else {
                            cout << "You do not have permission to list users." << endl;
                        }
                    }
                    else if (input == 2) {
                        if (userPP.hasPermission(PERM_ADD_USER)){
                            clStartApp::addNewUser(users , fileName , newUser);
                            system("pause");    
                        }
                        else {
                            cout << "You do not have permission to add users." << endl;
                        }
                    }
                    else if (input == 3) {
                        if (userPP.hasPermission(PERM_DELETE_USER)){
                            clStartApp::deleteUser(users , fileName);
                            system("pause"); // Pause after deleting user
                        }
                        else {
                            cout << "You do not have permission to delete users." << endl;
                        }
                    }
                    else if (input == 4) {
                        if (userPP.hasPermission(PERM_UPDATE_USER)){                     
                            cout << "Enter User Name: " ;
                            getline(cin >> ws, userName);
                            clStartApp::updateUser(users , fileName , userName);
                            system("pause"); // Pause after updating user
                        }
                        else {
                            cout << "You do not have permission to update users." << endl;
                        }
                    }
                    else if (input == 5) {
                        if (userPP.hasPermission(PERM_FIND_USER)){
                        cout << "Enter User Name: " ;
                        getline(cin >> ws, userName);
                        clStartApp::searchUser(users , userName);
                        system("pause"); // Pause after searching user
                        }
                        else {
                            cout << "You do not have permission to search users." << endl;
                        }
                    }
                    else if (input == 6) {
                        if (userPP.hasPermission(PERM_MANAGE_USERS)){
                            cout << "Enter User Name: " ;
                            getline(cin >> ws, userName);
                            newUser.updateOneUserPermission(users , userName);
                            clStartApp::updateUser(users , fileName , userName);
                            system("pause");
                        }
                        else {
                            cout << "You do not have permission to manage users." << endl;
                        }
                    }
                    else if (input == 7) {
                        cout << "Exiting user management." << endl;
                        break; // Exit the user management loop
                    }
                    else {
                        cout << "Invalid input. Please try again." << endl;
                    }
                }
            }
            void clStartApp::transactionsOnly(vector <clClientInfo> &clients , string fileName , string accountNumber , clClientInfo &client){
                while (true) {
                clScreenTransactions::printHeaderScreenTransactions();
                clScreenTransactions::printFooter();
                short input = 0;
                cout << "Enter the transaction type: " ;
                cin >> input ;
                // for (auto &client : clients) {
                    // if (client.getClientAccountNumber() == accountNumber) {
                    clTransactionsWithAcc transaction(client , clients);
                        if (input == 1) {
                            transaction.quickWithdraw(accountNumber);
                            clients = transaction.getClientAccounts();

                            system("pause"); // Pause to deposit money
                        }
                        else if (input == 2) {
                            cout << "How much money do you want to withdraw? ";
                            double amount;
                            cin >> amount;
                            transaction.withdrawMoney(accountNumber , amount);
                            clients = transaction.getClientAccounts();

                            system("pause");
                        }
                        else if (input == 3) {
                            cout << "how much menoy do you want to deposit ? " ;
                            double amount ;
                            cin >> amount ;
                            transaction.depositMoney(accountNumber,amount);
                            clients = transaction.getClientAccounts();
                            system("pause");
                            
                        }
                        else if (input == 4) {
                            clScreenShowClients::printVector(clients);
                            int totalBalance = 0 ;
                            for (auto &client : clients) {
                                totalBalance += stoi(client.getClientAccountBalance());
                            }
                            cout << "==========================================================================================" << endl ;
                            cout <<setw(65) <<"" <<"Total balance:" << totalBalance << endl;
                            system("pause");                        
                        }
                        else if (input == 5){
                            break ;
                        }
                        else {
                            cout << "Invalid input. Please try again." << endl;
                        }
                        clOperationsWithFile::saveClientInfoToFile(clients, fileName);
                    }

        }
    }
