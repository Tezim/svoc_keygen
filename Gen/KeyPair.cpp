#include <HMAC_DRNG/hmac_drbg/hmac_drbg.h>
#include "KeyPair.h"
#include "helpers.h"

void KeyPair::setSk(const NTL::vec_GF2 &sk) {
    SK = sk;
}
void KeyPair::setVk(const NTL::Vec<Polynomial> &vk) {
    VK = vk;
}

const NTL::vec_GF2 &KeyPair::getSk() const{
    return SK;
}
const NTL::Vec<Polynomial> &KeyPair::getVk() const {
    return VK;
}

KeyPair::KeyPair() = default;

KeyPair generateRandomKeypair(uint32_t n, uint32_t m){
    // init hmac

    hmac_drbg_ctx hmac_ctx;
    hmac_drbg_instantiate(&hmac_ctx, NULL, 0);

    KeyPair KP = KeyPair();
    KP.setSk(randomLinear(n, &hmac_ctx));
    KP.setVk(randomSystem(n, m, KP.getSk(), &hmac_ctx));

    // de-init hmac
    hmac_drbg_uninstantiate(&hmac_ctx);
    return KP;
}
