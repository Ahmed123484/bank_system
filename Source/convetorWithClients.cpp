#include"../headers/convertorWithClients.h"
namespace convertorWithClients {
    clConvertorWithClients::clConvertorWithClients(vector<clClientInfo> clientes) : clients(clientes) {}
    vector<string> clConvertorWithClients::getWordsFromLine(const string& line) {
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
        if (!word.empty()) {
            words.push_back(word);
        }
        return words;
    }
    void clConvertorWithClients::validateClientData(const vector<string>& words) {
        if (words.size() < 5) {
            throw std::invalid_argument("Invalid input format: insufficient data");
        }
        if (words[0].empty()) {
            throw std::invalid_argument("client account number cannot be empty");
        }
        if (words[1].empty()) {
            throw std::invalid_argument("client pin code cannot be empty");
        }
        if (words[2].empty()) {
            throw std::invalid_argument("client account name cannot be empty");
        }
        if (words[3].empty()) {
            throw std::invalid_argument("client phone number cannot be empty");
        }
        if (words[4].empty()) {
            throw std::invalid_argument("client account balance cannot be empty");
        }
    }

    clClientInfo clConvertorWithClients::createClientFromWords(const vector<string>& words, clClientInfo client) {
        client.setClientAccountNumber(words[0]);
        client.setClientPinCode(words[1]);
        client.setClientAccountName(words[2]);
        client.setClientPhoneNumber(words[3]);
        client.setClientAccountBalance(words[4]);
        return client;
    }
    clClientInfo clConvertorWithClients::convertorWithClients(const string& line, clClientInfo client) {
        try {
            vector<string> words = getWordsFromLine(line);
            validateClientData(words);
            client = createClientFromWords(words, client);
        }
        catch (const std::invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
        }
        return client;
    }
    void clConvertorWithClients::setClients(vector<clClientInfo> clients) {
        this->clients = clients;
    }
    vector<clClientInfo> clConvertorWithClients::getClients() {
        return this -> clients;
    }

}
