# Custom Blockchain Implementation

A simple blockchain implementation in C++ inspired by Bitcoin's core concepts, featuring blocks, transactions, wallets, and proof-of-work mining.

## Features

- **Block Structure**: Each block contains an index, timestamp, previous hash, transactions, and nonce
- **Transaction System**: Support for creating, signing, and validating transactions
- **Wallet Management**: Generate public/private key pairs and sign transactions
- **Proof-of-Work Mining**: Configurable difficulty level with SHA-256 hashing
- **Blockchain Validation**: Verify the integrity of the entire chain

## Project Structure

```
BlockChain/
├── CMakeLists.txt
├── README.md
├── include/
│   ├── Block.h
│   ├── Transaction.h
│   ├── Wallet.h
│   └── Blockchain.h
└── src/
    ├── Block.cpp
    ├── Transaction.cpp
    ├── Wallet.cpp
    ├── Blockchain.cpp
    └── main.cpp
```

## Dependencies

- **OpenSSL**: Required for SHA-256 hashing
- **CMake**: Build system (version 3.10 or higher)
- **C++17**: Modern C++ standard

### Installing Dependencies

**macOS:**
```bash
brew install openssl cmake
```

**Ubuntu/Debian:**
```bash
sudo apt-get install libssl-dev cmake build-essential
```

**Windows:**
- Install OpenSSL from https://slproweb.com/products/Win32OpenSSL.html
- Install CMake from https://cmake.org/download/

## Building the Project

1. Clone or download the project
2. Create a build directory:
   ```bash
   mkdir build
   cd build
   ```
3. Configure with CMake:
   ```bash
   cmake ..
   ```
4. Build the project:
   ```bash
   make
   ```

## Running the Application

After building, run the executable:
```bash
./CustomBlockchain
```

## Core Components

### Block
- Contains transaction data, timestamp, and proof-of-work
- Implements SHA-256 hashing for block integrity
- Supports configurable mining difficulty

### Transaction
- Represents transfers between addresses
- Includes digital signature verification
- Validates transaction integrity

### Wallet
- Generates public/private key pairs
- Signs transactions with private keys
- Provides cryptographic utilities

### Blockchain
- Maintains the chain of blocks
- Validates transactions and blocks
- Implements mining rewards system
- Calculates account balances

## Example Usage

```cpp
#include "Blockchain.h"
#include "Wallet.h"
#include "Transaction.h"

int main() {
    // Create blockchain and wallets
    Blockchain blockchain;
    Wallet wallet1, wallet2, minerWallet;
    
    // Mine initial block for rewards
    blockchain.minePendingTransactions(minerWallet.getPublicKey());
    
    // Create and sign a transaction
    Transaction tx(minerWallet.getPublicKey(), wallet1.getPublicKey(), 50);
    tx.signTransaction(minerWallet.getPrivateKey());
    blockchain.addTransaction(tx);
    
    // Mine the transaction
    blockchain.minePendingTransactions(minerWallet.getPublicKey());
    
    // Check balances
    std::cout << "Wallet 1 balance: " << blockchain.getBalance(wallet1.getPublicKey()) << std::endl;
    
    return 0;
}
```

## Configuration

- **Mining Difficulty**: Adjustable in `Blockchain` constructor (default: 4)
- **Mining Reward**: Configurable reward amount (default: 100 coins)
- **Hash Algorithm**: SHA-256 (Bitcoin standard)

## Security Features

- **Digital Signatures**: Transactions are cryptographically signed
- **Hash Validation**: Each block's hash is verified
- **Chain Integrity**: Previous hash references ensure chain consistency
- **Transaction Validation**: Invalid transactions are rejected

## Limitations

This is a simplified educational implementation and lacks many production features:
- No network protocol or peer-to-peer communication
- Simplified key generation (not production-ready)
- No persistent storage
- No advanced consensus mechanisms
- No transaction fees
- No scripting system

## License

This project is for educational purposes. Feel free to modify and extend it for learning about blockchain technology.

## Contributing

This is a learning project. Suggestions for improvements or educational enhancements are welcome.