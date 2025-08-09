#include<iostream>
#include<string>
#include<vector>
#include"clientInfo.h" // Assuming this is the header file for clClient
using namespace std;
using namespace clientInfo;
namespace updateClientInfo {
    class clUpdateClientInfo  {
        public:
            void updateClientInfo(clClientInfo &client);
    };
}
