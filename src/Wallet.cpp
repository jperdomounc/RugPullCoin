#include "Wallet.h"
#include <sstream>
#include <iomanip>
#include <random>
#include <openssl/sha.h>

Wallet::Wallet() {
    generateKeys();
}

void Wallet::generateKeys() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);
    
    std::stringstream privateKeyStream;
    std::stringstream publicKeyStream;
    
    for (int i = 0; i < 32; i++) {
        privateKeyStream << std::hex << std::setw(2) << std::setfill('0') << dis(gen);
    }
    
    privateKey = privateKeyStream.str();
    publicKey = sha256(privateKey);
}

std::string Wallet::signMessage(const std::string& message) const {
    return sha256(message + privateKey);
}

bool Wallet::verifySignature(const std::string& message, const std::string& signature, const std::string& publicKey) const {
    return signature == sha256(message + publicKey);
}

std::string Wallet::sha256(const std::string& input) const {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input.c_str(), input.size());
    SHA256_Final(hash, &sha256);
    
    std::stringstream hashString;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        hashString << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    
    return hashString.str();
}