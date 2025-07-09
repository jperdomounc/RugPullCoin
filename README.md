# Custom Blockchain Implementation

A blockchain implementation in C++ featuring blocks, transactions, wallets, and proof-of-work mining.

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

## Building the Project

 Create a build directory:
   ```bash
   mkdir build
   cd build
   ```
 Configure with CMake:
   ```bash
   cmake ..
   ```
 Build the project:
   ```bash
   make
   ```

## Running the blockchain

After building, run the executable:
```bash
./CustomBlockchain
```


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


## Configuration

- **Mining Difficulty**: Adjustable in `Blockchain` constructor (default 4)
- **Mining Reward**: Configurable reward amount (defaul 100 coins)
- **Hash Algorithm**: SHA-256 (quantum proof ofc)

## Security Features

- **Digital Signatures**: Transactions are cryptographically signed
- **Hash Validation**: Each block's hash is verified
- **Chain Integrity**: Previous hash references ensure chain consistency
- **Transaction Validation**: Invalid transactions are rejected


## License

do whatever you want with it

## Contributing

This is a learning project. Suggestions for improvements or educational enhancements are welcome.