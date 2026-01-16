// 文件 src/main.cpp

#include <iostream>
#include <string>

#include <openssl/evp.h>

int main()
{
    std::string text = "C++幻想";
    unsigned char digest[EVP_MAX_MD_SIZE] = { 0 };
    unsigned int length = 0;

    EVP_MD_CTX* ctx = nullptr;

    do {
        ctx = EVP_MD_CTX_new();
        if (!ctx) {
            std::cout << "EVP_MD_CTX_new -- Failed" << std::endl;
            break;
        }

        // 把 EVP_md5 替换为 EVP_sha1 就是sha1
        // 把 EVP_md5 替换为 EVP_sha256 就是sha256
        if (!EVP_DigestInit_ex(ctx, EVP_md5(), nullptr)) {
            std::cout << "EVP_DigestInit_ex -- Failed" << std::endl;
            break;
        }

        if (!EVP_DigestUpdate(ctx, text.data(), text.size())) {
            std::cout << "EVP_DigestUpdate -- Failed" << std::endl;
            break;
        }

        if (!EVP_DigestFinal_ex(ctx, digest, &length)) {
            std::cout << "EVP_DigestUpdate -- Failed" << std::endl;
            break;
        }

        // 输出结果
        std::cout << text << " MD5: ";
        std::cout << std::hex;
        for (unsigned int i = 0; i < length; ++i) {
            std::cout << +(digest[i]);
        }
        std::cout << std::endl;
    } while(false);

    if (ctx) {
        EVP_MD_CTX_free(ctx);
        ctx = nullptr; // 这句不是必要
    }

    return 0;
}