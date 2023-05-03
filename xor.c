#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *file_a, *file_b, *file_out;
    int byte_a, byte_b, byte_out;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <a> <b> [out]\n", argv[0]);
        exit(1);
    }

    file_a = fopen(argv[1], "rb");
    if (!file_a) {
        fprintf(stderr, "Error opening file %s\n", argv[1]);
        exit(1);
    }
    file_b = fopen(argv[2], "rb");
    if (!file_b) {
        fprintf(stderr, "Error opening file %s\n", argv[2]);
        exit(1);
    }

    if (argc > 3) {
        file_out = fopen(argv[3], "wb");
        if (!file_out) {
            fprintf(stderr, "Error opening file %s\n", argv[3]);
            exit(1);
        }
    } else {
        file_out = stdout;
    }

    while ((byte_a = fgetc(file_a)) != EOF && (byte_b = fgetc(file_b)) != EOF) {
        byte_out = byte_a ^ byte_b;
        fputc(byte_out, file_out);
    }

    fclose(file_a);
    fclose(file_b);
    if (file_out != stdout) {
        fclose(file_out);
    }

    return 0;
}

