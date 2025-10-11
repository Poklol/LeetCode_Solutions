#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char *map_digits[] = {
    "",    // 0
    "",    // 1
    "abc", // 2
    "def", // 3
    "ghi", // 4
    "jkl", // 5
    "mno", // 6
    "pqrs",// 7
    "tuv", // 8
    "wxyz" // 9
};

static char *strdup_c(const char *s) {
    size_t len = strlen(s);
    char *p = (char *)malloc(len + 1);
    if (!p) return NULL;
    memcpy(p, s, len + 1);
    return p;
}

static void backtrack(const char *digits, int idx, char *current, char **result, int *resCount, int len) {
    if (idx == len) {
        result[*resCount] = strdup_c(current);
        (*resCount)++;
        return;
    }
    int d = digits[idx] - '0';
    const char *letters = map_digits[d];
    for (int i = 0; letters[i] != '\0'; ++i) {
        current[idx] = letters[i];
        backtrack(digits, idx + 1, current, result, resCount, len);
    }
}

char **letterCombinations(char *digits, int *returnSize) {
    *returnSize = 0;
    if (!digits) return NULL;
    int len = strlen(digits);
    if (len == 0) return NULL;

    int maxComb = 1;
    for (int i = 0; i < len; ++i) {
        int d = digits[i] - '0';
        int choices = strlen(map_digits[d]);
        if (choices == 0) { // invalid digit (like '1' or '0') -> no combos
            *returnSize = 0;
            return NULL;
        }
        maxComb *= choices;
    }

    char **result = (char **)malloc(maxComb * sizeof(char *));
    if (!result) return NULL;

    char *current = (char *)malloc(len + 1);
    if (!current) {
        free(result);
        return NULL;
    }
    current[len] = '\0';

    int resCount = 0;
    backtrack(digits, 0, current, result, &resCount, len);

    free(current);
    *returnSize = resCount;
    return result;
}
