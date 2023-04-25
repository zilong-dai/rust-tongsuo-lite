// #include <sm4.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
extern int sm4_enc(const unsigned char *key, const unsigned char *iv,
                   unsigned char *in, int inlen, unsigned char *out,
                   int *outlen);

extern int sm4_dec(const unsigned char *key, const unsigned char *iv, const unsigned char *in, int inlen, unsigned char *out,
                   int *outlen);
int main()
{
    unsigned char key[] = {
        0x3f,
        0x34,
        0x2e,
        0x9d,
        0x67,
        0xd6,
        0xce,
        0x7b,
        0xe7,
        0x01,
        0x75,
        0x6a,
        0xf7,
        0xba,
        0xc8,
        0xf2,
    };
    unsigned char iv[] = {
        0x1f,
        0xb2,
        0xd4,
        0x2f,
        0xb3,
        0x6e,
        0x2e,
        0x88,
        0xa2,
        0x20,
        0xb0,
        0x4f,
        0x2e,
        0x49,
        0xaa,
        0x13,
    };
    unsigned char in[] = {
        0xe2,
        0x44,
        0xdb,
        0xeb,
        0x97,
        0x58,
        0x83,
        0x1e,
        0xa8,
        0x7b,
        0x7c,
        0xeb,
        0x27,
        0x8e,
        0x6e,
        0x5d,
    };
    unsigned char *out = NULL;
    int outlen;
    int ret;
    out = malloc(sizeof(in));
    assert(out != NULL);
    ret = sm4_dec(key, iv, in, sizeof(in), out, &outlen);
    assert(ret == 1);
    printf("%*s\n", outlen, out);
    free(out);
    return 0;
}