#include <stdint.h>
#include <string.h>

void div_convert ( uint32_t n , int base , char * out ) {
    char temp [65]; // Temporary buffer
    int pos = 0;

    // Handle zero case
    if ( n == 0) {
        strcpy ( out , "0" ) ;
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
void sub_convert(uint32_t n,int base,char *out) {
    char temp[65];
    int pos = 0;

    if ( n == 0) {
        strcpy ( out , "0" ) ;
        return ;
    }

    uint32_t power = 1;
    while(power*base<=n){
        power*=base;
    }
    while (power>0){
        int digit = n/power;
        if (digit < 10)
            temp[pos++] = '0' + digit;
        else
            temp[pos++] = 'A' + (digit- 10);
        n = n-(digit*power);
        power = power/base;
    }
    for(int i=0; i<pos; i++){
        out[i]=temp[i];
    }
    out[pos] = '\0';
}