#pragma once

#include <vector>
#include <string>
#include "Block.h"
#include "Transaction.h"

class Blockchain {
public:
    Blockchain();
    
    void addTransaction(const Transaction& transaction);
    void minePendingTransactions(const std::string& miningRewardAddress);
    double getBalance(const std::string& address) const;
    bool isChainValid() const;
    
    std::vector<Block> getChain() const { return chain; }
    int getDifficulty() const { return difficulty; }
    double getMiningReward() const { return miningReward; }
    
private:
    std::vector<Block> chain;
    std::vector<Transaction> pendingTransactions;
    int difficulty;
    double miningReward;
    
    Block createGenesisBlock();
    Block getLatestBlock() const;
};