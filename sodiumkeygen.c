#include <sodium.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <bytes>\n", argv[0]);
        return 1;
    }

    int key_len = atoi(argv[1]);

    unsigned char *key = malloc(key_len);
    if (key == NULL) {
        fprintf(stderr, "Error: could not allocate memory for key\n");
        return 1;
    }

    if (sodium_init() < 0) {
        fprintf(stderr, "Error: sodium_init() failed\n");
        return 1;
    }

    randombytes_buf(key, key_len);

    fwrite(key, 1, key_len, stdout);

    free(key);

    return 0;
}