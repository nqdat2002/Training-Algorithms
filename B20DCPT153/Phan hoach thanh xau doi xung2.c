#include <stdio.h>
#include <string.h>

int bitCount(int x) {
    int cnt = 0;
    while (x) {
        cnt += x & 1;
        x >>= 1;
    }
    return cnt;
}

int main() {
    char s[100005];
    scanf("%s", s);

    int mask = 0;
    int n = strlen(s);
    int segments = 0;
	int i;
    for ( i = 0; i < n; i++) {
        int bit = s[i] - 'a';
        mask ^= (1 << bit);  // toggle

        if (bitCount(mask) > 1) {
            segments++;             
            mask = (1 << bit);      
        }
    }

    if (mask != 0) segments++; // do?n cu?i

    printf("%d", segments);
    return 0;
}
