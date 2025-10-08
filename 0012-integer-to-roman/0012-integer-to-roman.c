char* intToRoman(int num) {
    const int vals[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const char *syms[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    char *res = malloc(32);
    char *p = res;
    for (int i = 0; i < 13; ++i) {
        while (num >= vals[i]) {
            const char *s = syms[i];
            while (*s) *p++ = *s++;
            num -= vals[i];
        }
    }
    *p = '\0';
    return res;
}
