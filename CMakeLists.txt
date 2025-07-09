cmake_minimum_required(VERSION 3.10)
project(CustomBlockchain)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenSSL REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SOURCES
    src/Block.cpp
    src/Transaction.cpp
    src/Wallet.cpp
    src/Blockchain.cpp
    src/main.cpp
)

set(HEADERS
    include/Block.h
    include/Transaction.h
    include/Wallet.h
    include/Blockchain.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} OpenSSL::SSL OpenSSL::Crypto)

target_include_directories(${PROJECT_NAME} PRIVATE include)