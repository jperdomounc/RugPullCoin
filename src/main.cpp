#include <iostream>
#include "Blockchain.h"
#include "Wallet.h"
#include "Transaction.h"

int main() {
    std::cout << "=== Custom Blockchain Demo ===" << std::endl;
    
    Blockchain blockchain;
    
    Wallet wallet1;
    Wallet wallet2;
    Wallet minerWallet;
    
    std::cout << "\nWallet 1 Public Key: " << wallet1.getPublicKey() << std::endl;
    std::cout << "Wallet 2 Public Key: " << wallet2.getPublicKey() << std::endl;
    std::cout << "Miner Wallet Public Key: " << minerWallet.getPublicKey() << std::endl;
    
    std::cout << "\nInitial balances:" << std::endl;
    std::cout << "Wallet 1: " << blockchain.getBalance(wallet1.getPublicKey()) << std::endl;
    std::cout << "Wallet 2: " << blockchain.getBalance(wallet2.getPublicKey()) << std::endl;
    std::cout << "Miner: " << blockchain.getBalance(minerWallet.getPublicKey()) << std::endl;
    
    std::cout << "\nMining first block (reward)..." << std::endl;
    blockchain.minePendingTransactions(minerWallet.getPublicKey());
    
    std::cout << "\nBalances after mining:" << std::endl;
    std::cout << "Wallet 1: " << blockchain.getBalance(wallet1.getPublicKey()) << std::endl;
    std::cout << "Wallet 2: " << blockchain.getBalance(wallet2.getPublicKey()) << std::endl;
    std::cout << "Miner: " << blockchain.getBalance(minerWallet.getPublicKey()) << std::endl;
    
    std::cout << "\nCreating transaction: Miner -> Wallet 1 (50 coins)" << std::endl;
    Transaction tx1(minerWallet.getPublicKey(), wallet1.getPublicKey(), 50);
    tx1.signTransaction(minerWallet.getPrivateKey());
    blockchain.addTransaction(tx1);
    
    std::cout << "\nCreating transaction: Wallet 1 -> Wallet 2 (25 coins)" << std::endl;
    Transaction tx2(wallet1.getPublicKey(), wallet2.getPublicKey(), 25);
    tx2.signTransaction(wallet1.getPrivateKey());
    blockchain.addTransaction(tx2);
    
    std::cout << "\nMining block with transactions..." << std::endl;
    blockchain.minePendingTransactions(minerWallet.getPublicKey());
    
    std::cout << "\nFinal balances:" << std::endl;
    std::cout << "Wallet 1: " << blockchain.getBalance(wallet1.getPublicKey()) << std::endl;
    std::cout << "Wallet 2: " << blockchain.getBalance(wallet2.getPublicKey()) << std::endl;
    std::cout << "Miner: " << blockchain.getBalance(minerWallet.getPublicKey()) << std::endl;
    
    std::cout << "\nBlockchain validation: " << (blockchain.isChainValid() ? "Valid" : "Invalid") << std::endl;
    
    std::cout << "\nBlockchain has " << blockchain.getChain().size() << " blocks" << std::endl;
    
    return 0;
}