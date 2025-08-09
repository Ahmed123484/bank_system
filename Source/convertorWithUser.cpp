#include "../headers/convertorWithUser.h"

namespace convertorWithUser {
    // cutter words
    vector<string>  clConvertorWithUser::getWordsFromLine(const string& line) {
        string word;
        vector<string> words;
        
        for (int i = 0; i < line.length(); i++) {
            if (isalnum(line[i]) || line[i] == '_' || line[i] == '-' || 
                line[i] == '.' || line[i] == '@' || line[i] == ' ') {
                word += line[i];
            } else {
                if (!word.empty()) {
                    words.push_back(word);
                    word = "";
                }
            }
        }
        
        // إضافة الكلمة الأخيرة
        if (!word.empty()) {
            words.push_back(word);
        }
        
        return words;
    }
    // validate
    void clConvertorWithUser::validateUserData(const vector<string>& words) {
        if (words.size() < 3) {
            throw std::invalid_argument("Invalid input format: insufficient data");
        }
        // يمكن إضافة المزيد من التحققات هنا
        if (words[0].empty()) {
            throw std::invalid_argument("Username cannot be empty");
        }
        
        if (words[1].empty()) {
            throw std::invalid_argument("Password cannot be empty");
        }
        
        // التحقق من أن الصلاحية رقم صحيح
        try {
            int permission = stoi(words[2]);
            if (permission < 0) {
                throw std::invalid_argument("Permission must be non-negative");
            }
        } catch (const std::invalid_argument&) {
            throw std::invalid_argument("Permission must be a valid integer");
        }
    }
    // create object form words to user
    clUserInfo clConvertorWithUser::createUserFromWords(const vector<string>& words, clUserInfo userInfo) {
        userInfo.setUserName(words[0]);
        userInfo.setUserPassword(words[1]);
        userInfo.setUserPermission(stoi(words[2]));
        userInfo.setAccountNumber(words[3]);
        return userInfo;
    }
    // convertor
    clUserInfo clConvertorWithUser::convertorWithUser (const string& line, clUserInfo userInfo) {
        try {
            // 1. تحليل النص
            vector<string> words = getWordsFromLine(line);
            
            // 2. التحقق من صحة البيانات
            validateUserData(words);
            
            // 3. إنشاء كائن المستخدم
            return createUserFromWords(words, userInfo);
            
        } catch (const std::exception& e) {
            std::cerr << "Error in convertorWithUser: " << e.what() << std::endl;
            throw; // إعادة إلقاء الاستثناء للمستدعي
        }
    }
    
    // دالة مساعدة للاختبار - تُرجع الكلمات المستخرجة
    vector<string> clConvertorWithUser::parseLineToWords(const string& line) {
        return parseLineToWords(line);
    }
    // setters
    void clConvertorWithUser::setUsers(vector<clUserInfo> users){
        this->users = users;
    }
    // getters
    vector<clUserInfo> clConvertorWithUser::getUsers(){
        return this->users;
    }
}
