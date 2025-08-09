#include "../headers/operationsWithFileWithUser.h"

namespace operationsWithFileWithUser {
        // Save single user
        bool clOperationsWithFileWithUser::saveUser(const clUserInfo &userInfo, const string &fileName) {
            ofstream file(fileName, ios::out | ios::app);
            if (!file) {
                cerr << "Error opening file for writing: " << fileName << endl;
                return false;
            }
            
            file << userInfo.getUserName() << ",";
            file << userInfo.getUserPassword() << ",";
            file << userInfo.getUserPermission() << ",";
            file << userInfo.getAccountNumber() << ",";
            
            return file.good();
        }
        // Save multiple users (replaces file content)
        bool clOperationsWithFileWithUser::saveUsers(const vector<clUserInfo> &userInfos, const string &fileName) {
            ofstream file(fileName, ios::out | ios::trunc); // Replace content
            if (!file) {
                cerr << "Error opening file for writing: " << fileName << endl;
                return false;
            }
            
            for (const auto &userInfo : userInfos) {
                file << userInfo.getUserName() << ",";
                file << userInfo.getUserPassword() << ",";
                file << userInfo.getUserPermission() << ",";
                file << userInfo.getAccountNumber() << endl;
            }
            
            return file.good();
        }
        // Load users from file
        vector<clUserInfo> clOperationsWithFileWithUser:: loadUsers(const string &fileName) {
            vector<clUserInfo> userInfos;
            ifstream file(fileName);
            convertorWithUser::clConvertorWithUser convertorWithUsers;
            if (!file) {
                cerr << "File not found. Creating new file: " << fileName << endl;
                // Create empty file
                ofstream createFile(fileName);
                createFile.close();
                return userInfos; // Return empty vector
            }
            
            string line;
            while (getline(file, line)) {
                clUserInfo user ;
                clUserInfo userInfo = convertorWithUsers.convertorWithUser(line, user);
                userInfos.push_back(userInfo);
            }
            
            return userInfos;
        }
        // Check if file exists
        bool clOperationsWithFileWithUser::fileExists(const string &fileName) {
            ifstream file(fileName);
            return file.good();
        }
}
