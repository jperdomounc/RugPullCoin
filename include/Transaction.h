#pragma once

#include <string>

class Transaction {
public:
    Transaction(const std::string& from, const std::string& to, double amount);
    
    std::string calculateHash() const;
    bool signTransaction(const std::string& privateKey);
    bool isValid() const;
    
    std::string getFrom() const { return fromAddress; }
    std::string getTo() const { return toAddress; }
    double getAmount() const { return amount; }
    std::string getSignature() const { return signature; }
    
private:
    std::string fromAddress;
    std::string toAddress;
    double amount;
    std::string signature;
};