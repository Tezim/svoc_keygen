#include <iostream>
#include <fstream>
#include "Gen/KeyPair.h"
#include "Gen/helpers.h"
#include <chrono>

int main() {

    /* TODO
     * 1. arduino check -- nope not needed for demo
     * 2. key formatting and writing (software random first) DONE
     * 3. arduino read  DONE
     * 4. hmac connection  DONE
    */
    std::ofstream outFile("1mil_drbg_gen.bin", std::ios::binary);
    if (!outFile) {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
        exit(-1);
    }
    auto start = std::chrono::high_resolution_clock::now();
    hmac_drbg_ctx hmac_ctx;
    hmac_drbg_instantiate(&hmac_ctx, NULL, 0);
    unsigned char* buffer_drbg_output;
    unsigned long num_bytes = 65536;
    for (int i = 0; i < 16; i++){
        buffer_drbg_output = (unsigned char*) calloc (num_bytes, sizeof(unsigned char));
        hmac_drbg_generate(&hmac_ctx, buffer_drbg_output, 8 * num_bytes, 0x00);
        for (int k = 0; k < num_bytes; k++){
            outFile.write((char*)&buffer_drbg_output[k], 1);
        }
        free(buffer_drbg_output);
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_us = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Microseconds elapsed: " << elapsed_us.count() << std::endl;

    /*KeyPair keyPair = generateRandomKeypair(256,256);

    std::ofstream privateKey("key_SK");

    if (!privateKey.is_open()) {
        std::cerr << "Failed to open file for writing." << std::endl;
        exit(-1);
    }

    for (auto i : keyPair.getSk()) {
        privateKey << i;
    }
    privateKey << std::endl;
    privateKey.close();
    std::cout << "Private key was successfully generated." << std::endl;

    std::ofstream publicKey("key_VK.pub");
    for (const auto& i : keyPair.getVk()) {
        // quadratic
        for (int j = 0; j < i.getQuadratic().NumRows(); j++){
            for (long k = 0; k < i.getQuadratic().NumCols(); ++k) {
                publicKey << i.getQuadratic()[j][k];
            }
            publicKey << std::endl; // Move to the next line after each row
        }
        // linear
        for (auto j : i.getLinear()){
            publicKey << j;
        }
        publicKey << std::endl;
    }
    publicKey.close();
    std::cout << "Public key was successfully generated." << std::endl;*/

    return 0;
}

