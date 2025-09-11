#include <stdint.h>
#include <string.h>

void div_convert ( uint32_t n , int base , char * out ) {
    char temp [65]; // Temporary buffer
    int pos = 0;

    // Handle zero case
    if ( n == 0) {
        strcpy ( out , " 0 " ) ;
        return ;
    }

    // Extract digits from right to left
    while ( n > 0) {
        int remainder = n % base ;
        n = n / base ;

        // Convert digit to character
        if (remainder < 10)
            temp[pos++] = '0' + remainder;
        else
            temp[pos++] = 'A' + (remainder- 10);
    }

    // Reverse the result
    for (int i = 0; i < pos; i++) {
        out[i] = temp[pos - i - 1];
    }
    out[pos] = '\0';
}