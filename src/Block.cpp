#include "Block.h"
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>
#include <iostream>

Block::Block(int index, const std::string& previousHash, const std::vector<Transaction>& transactions)
    : index(index), previousHash(previousHash), transactions(transactions), nonce(0) {
    timestamp = std::time(nullptr);
    hash = calculateHash();
}

std::string Block::calculateHash() const {
    std::stringstream ss;
    ss << index << previousHash << timestamp << hashTransactions() << nonce;
    
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, ss.str().c_str(), ss.str().size());
    SHA256_Final(hash, &sha256);
    
    std::stringstream hashString;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        hashString << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    
    return hashString.str();
}

void Block::mineBlock(int difficulty) {
    std::string target(difficulty, '0');
    
    while (hash.substr(0, difficulty) != target) {
        nonce++;
        hash = calculateHash();
    }
    
    std::cout << "Block mined: " << hash << std::endl;
}

std::string Block::hashTransactions() const {
    std::stringstream ss;
    for (const auto& transaction : transactions) {
        ss << transaction.calculateHash();
    }
    
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, ss.str().c_str(), ss.str().size());
    SHA256_Final(hash, &sha256);
    
    std::stringstream hashString;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        hashString << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    
    return hashString.str();
}