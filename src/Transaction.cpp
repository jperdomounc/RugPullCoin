#include "Transaction.h"
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

Transaction::Transaction(const std::string& from, const std::string& to, double amount)
    : fromAddress(from), toAddress(to), amount(amount) {}

std::string Transaction::calculateHash() const {
    std::stringstream ss;
    ss << fromAddress << toAddress << amount;
    
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

bool Transaction::signTransaction(const std::string& privateKey) {
    if (fromAddress != privateKey) {
        return false;
    }
    
    std::string hashTx = calculateHash();
    signature = hashTx;
    return true;
}

bool Transaction::isValid() const {
    if (fromAddress.empty()) {
        return true;
    }
    
    if (signature.empty()) {
        return false;
    }
    
    return signature == calculateHash();
}