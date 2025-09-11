#include <stdio.h>
#include <stdint.h>
#include <string.h>

void div_convert(uint32_t n, int base, char *out);
void sub_convert(uint32_t n, int base, char *out);
void print_tables(uint32_t n );

int main(){
    FILE *file = fopen("a1_test_file.txt", "r");
    if (file == NULL){
        printf("Error: Couldn't open file\n");
        return 1;
    }
    
    char line[256];
    char result[65];
    int testNum=1;
    int passedTests=0;
    while (fgets(line, sizeof(line), file) !=NULL){
        line[strcspn(line, "\n")] = '\0';
        if (line[0]=='#' || line[0]=='\0'){
            continue;
        }
        char function[32];
        char expected[65];
        uint32_t num;
        int base;
        char output[200];

        if(sscanf(line, "%31s %u %d %64s", function, &num, &base, expected) == 4){
            if(strcmp(function, "div_convert") == 0){
                div_convert(num, base, result);
            } else if (strcmp(function, "sub_convert") == 0){
                sub_convert(num, base, result);
            }
            int passed = (strcmp(result, expected) == 0);
            if (passed){
                passedTests++;
            }
            
            sprintf(output, "Test %d: %s(%u, %d) -> Expected: \"%s\", Got: \"%s\" [%s]", testNum, function, num, base, expected, result, passed ? "PASS":"FAIL");
            printf("%s\n", output);
            testNum++;
        }    
    }
    printf("Summary: %d/%d tests passed", passedTests, testNum-1);
    fclose(file);
    
    return 0;
}