#include "Blockchain.h"
#include <iostream>

Blockchain::Blockchain() : difficulty(4), miningReward(100) {
    chain.push_back(createGenesisBlock());
}

void Blockchain::addTransaction(const Transaction& transaction) {
    if (!transaction.isValid()) {
        std::cerr << "Cannot add invalid transaction to the chain" << std::endl;
        return;
    }
    
    pendingTransactions.push_back(transaction);
}

void Blockchain::minePendingTransactions(const std::string& miningRewardAddress) {
    Transaction rewardTransaction("", miningRewardAddress, miningReward);
    pendingTransactions.push_back(rewardTransaction);
    
    Block block(chain.size(), getLatestBlock().getHash(), pendingTransactions);
    block.mineBlock(difficulty);
    
    std::cout << "Block successfully mined!" << std::endl;
    chain.push_back(block);
    
    pendingTransactions.clear();
}

double Blockchain::getBalance(const std::string& address) const {
    double balance = 0;
    
    for (const auto& block : chain) {
        for (const auto& transaction : block.getTransactions()) {
            if (transaction.getFrom() == address) {
                balance -= transaction.getAmount();
            }
            
            if (transaction.getTo() == address) {
                balance += transaction.getAmount();
            }
        }
    }
    
    return balance;
}

bool Blockchain::isChainValid() const {
    for (size_t i = 1; i < chain.size(); i++) {
        const Block& currentBlock = chain[i];
        const Block& previousBlock = chain[i - 1];
        
        if (currentBlock.getHash() != currentBlock.calculateHash()) {
            return false;
        }
        
        if (currentBlock.getPreviousHash() != previousBlock.getHash()) {
            return false;
        }
        
        for (const auto& transaction : currentBlock.getTransactions()) {
            if (!transaction.isValid()) {
                return false;
            }
        }
    }
    
    return true;
}

Block Blockchain::createGenesisBlock() {
    std::vector<Transaction> genesisTransactions;
    return Block(0, "0", genesisTransactions);
}

Block Blockchain::getLatestBlock() const {
    return chain.back();
}