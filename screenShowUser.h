#pragma once 
#include <iostream>
#include <vector>
#include <iomanip>
#include "userInfo.h" // Assuming this is the header file for clClient
using namespace std;
using namespace userInfo;
namespace screenShowUser {
    class clScreenShowUser {
        public :
        static void displayHeaderPage(const vector<clUserInfo> &users) ;
        static void displayHeader() ;
        static void displayFooter(const clUserInfo &users) ;
        static void printVector ( const vector<clUserInfo>&users) ;
    };

}