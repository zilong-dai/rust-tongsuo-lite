#include "sm4.h"

extern void ERR_print_errors_fp(FILE *fp);

int sm4_enc(const unsigned char *key, const unsigned char *iv,
            unsigned char *in, int inlen, unsigned char *out,
            int *outlen)
{
    EVP_CIPHER_CTX *ctx = NULL;
    int outl, tmplen;
    if ((ctx = EVP_CIPHER_CTX_new()) == NULL || !EVP_EncryptInit_ex(ctx, EVP_sm4_cbc(), NULL, key, iv) || !EVP_EncryptUpdate(ctx, out, &outl, in, inlen) || !EVP_EncryptFinal_ex(ctx, out + outl, &tmplen))
    {
        EVP_CIPHER_CTX_free(ctx);
        return 0;
    }
    EVP_CIPHER_CTX_free(ctx);
    if (outlen)
        *outlen = outl + tmplen;
    return 1;
}

int sm4_dec(const unsigned char *key, const unsigned char *iv, const unsigned char *in, int inlen, unsigned char *out,
            int *outlen)
{
    EVP_CIPHER_CTX *ctx = NULL;
    int outl, tmplen;
    if ((ctx = EVP_CIPHER_CTX_new()) == NULL || !EVP_DecryptInit_ex(ctx, EVP_sm4_cbc(), NULL, key, iv) || !EVP_DecryptUpdate(ctx, out, &outl, in, inlen) || !EVP_DecryptFinal_ex(ctx, out + outl, &tmplen))
    {
        ERR_print_errors_fp(stderr);
        EVP_CIPHER_CTX_free(ctx);
        return 0;
    }
    EVP_CIPHER_CTX_free(ctx);
    if (outlen)
        *outlen = outl + tmplen;
    return 1;
}
