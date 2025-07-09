#pragma once

#include <string>

class Wallet {
public:
    Wallet();
    
    void generateKeys();
    std::string signMessage(const std::string& message) const;
    bool verifySignature(const std::string& message, const std::string& signature, const std::string& publicKey) const;
    
    std::string getPublicKey() const { return publicKey; }
    std::string getPrivateKey() const { return privateKey; }
    
private:
    std::string publicKey;
    std::string privateKey;
    
    std::string sha256(const std::string& input) const;
};