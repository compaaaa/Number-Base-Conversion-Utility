#include <stdio.h>
#include <stdint.h>

void div_convert(uint32_t n, int base, char *out);
void sub_convert(uint32_t n, int base, char *out);

int main(){
    char result[65];

    div_convert(156, 8, result);
    printf("div_convert: 156 converted to base 8 is: %s\n", result);
    div_convert(255, 16, result);
    printf("div_convert: 255 converted to base 16 is: %s\n", result);
    div_convert(104, 5, result);
    printf("div_convert: 104 converted to base 5 is: %s\n", result);

    sub_convert(190, 3, result);
    printf("sub_convert: 190 converted to base 3 is: %s\n", result);
    sub_convert(156, 8, result);
    printf("sub_convert: 156 converted to base 8 is: %s\n", result);
    sub_convert(104, 5, result);
    printf("sub_convert: 104 converted to base 5 is: %s\n", result);
    return 0;
}