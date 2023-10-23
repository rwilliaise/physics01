
#include "res.h"

#include <stdio.h>
#include <stdlib.h>

char *res_from_file(const char *path) {
    FILE *fp = fopen(path, "rb");

    if (fp == NULL)
        return NULL;

    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *out = malloc(size + 1);
    if (out == NULL) {
        fclose(fp);
        return NULL;
    }

    fread(out, 1, size, fp);
    fclose(fp);

    out[size] = 0;
    return out;
}
