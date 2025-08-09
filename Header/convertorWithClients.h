#pragma once
#include<iostream>
#include<string>
#include<vector>
#include <sstream>
#include"ClientInfo.h"
using namespace std ;
using namespace clientInfo ;
namespace convertorWithClients {
    class clConvertorWithClients {
      private :
      vector<clClientInfo> clients;
      public:
        clConvertorWithClients(vector<clClientInfo> clientes) ;
        // methods
        clClientInfo createClientFromWords(const vector<string>& words, clClientInfo client);
        vector<string> parseLineToWords(const string& line);
        void validateClientData(const vector<string>& words);
        static vector<string> getWordsFromLine(const string& line);
        
        clClientInfo convertorWithClients(const string& line, clClientInfo client);
        static string convertorDetailsToString(clClientInfo client , string dim );
        // setters
        void setClients(vector<clClientInfo> clients);
        // getters
        vector<clClientInfo> getClients();  
    };
}
