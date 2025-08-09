#include<iostream>
#include<vector>
#include"deleteClient.h"
#include"clientInfo.h"
#include "../headers/operationsWithFileWIthClients.h"
using namespace std;
using namespace clientInfo;
using namespace deleteClientAndUser;
using namespace operationsWithFile;
namespace screenDeleteClient {
    class clscreenDeleteClient {
    public:
        static void screenDeleteClients(vector<clClientInfo> &clients , short input , string fileName);
        static bool validateInputAnswer (short input);
    };
}
