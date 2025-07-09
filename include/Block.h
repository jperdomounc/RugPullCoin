#pragma once

#include <string>
#include <vector>
#include <ctime>
#include "Transaction.h"

class Block {
public:
    Block(int index, const std::string& previousHash, const std::vector<Transaction>& transactions);
    
    std::string calculateHash() const;
    void mineBlock(int difficulty);
    
    int getIndex() const { return index; }
    std::string getPreviousHash() const { return previousHash; }
    std::string getHash() const { return hash; }
    std::time_t getTimestamp() const { return timestamp; }
    std::vector<Transaction> getTransactions() const { return transactions; }
    int getNonce() const { return nonce; }
    
private:
    int index;
    std::string previousHash;
    std::string hash;
    std::time_t timestamp;
    std::vector<Transaction> transactions;
    int nonce;
    
    std::string hashTransactions() const;
};