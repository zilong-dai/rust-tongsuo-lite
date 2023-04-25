#include "include/openssl/evp.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int sm4_enc(const unsigned char *key, const unsigned char *iv,
            unsigned char *in, int inlen, unsigned char *out,
            int *outlen);

int sm4_dec(const unsigned char *key, const unsigned char *iv, const unsigned char *in, int inlen, unsigned char *out,
            int *outlen);