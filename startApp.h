#pragma once
#include <iostream>
#include"screenHomePage.h"
#include"screenManageUser.h"
#include "addNewClient.h"
#include"../headers/operationsWithFileWIthClients.h"
#include "../headers/screenShowclients.h"
#include "../headers/clientInfo.h"
#include "../headers/screenDeleteClient.h"
#include "../headers/searchClients.h"
#include "../headers/screenTransactions.h"
#include "../headers/transactionsWithAcc.h"
#include "operationsWithFileWithUser.h"
#include"../headers/convertorWithUser.h"
#include "userInfo.h"
#include<iomanip>
#include"screenShowUser.h"
#include"userPermision.h"
using namespace permission;
using namespace userInfo;
using namespace convertorWithUser;
using namespace operationsWithFileWithUser;
using namespace transactionsWithAcc;
using namespace screenTransactions;
using namespace searchClients;
using namespace screenDeleteClient;
using namespace clientInfo;
using namespace screenShowClients;
using namespace operationsWithFile;
using namespace std;
using namespace addNewClient;
using namespace screenHomePage;
using namespace screenManageUser;
using namespace screenShowUser;
namespace startApp {
    class clStartApp {
        public:
            // Function to start the application
            static void startApplication();
            static void test ();
            static void showClients();
            static void addNewClient(vector<clClientInfo> &clients , clClientInfo &newClient);
            static void searchClient( vector <clClientInfo> clients , const string accountNumber);
            static void deleteClient(vector <clClientInfo> &clients , string fileName);
            static void updateClient(vector <clClientInfo> &clients , string fileName , string accountNumber);
            static void transactions(vector <clClientInfo> &clients , string fileName , string accountNumber , clClientInfo &client);
            static void showUsers (vector <clUserInfo> &users , string fileName);
            static void addNewUser(vector <clUserInfo> &users ,string fileName ,clUserInfo &newUser);
            static void deleteUser(vector <clUserInfo> &users , string fileName);
            static void updateUser(vector <clUserInfo> &users , string fileName , string userName);
            static void searchUser(vector <clUserInfo> users , const string userName);
            static void manageUsers(vector <clUserInfo> &users , string fileName ,  int permission );
            static void transactionsOnly(vector <clClientInfo> &clients , string fileName , string accountNumber , clClientInfo &client);

    };
}