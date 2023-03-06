//demonstrates character to integer conversion, string pointers

#include <stdio.h>
#include <stdlib.h>


int bin_hex_StrToInt32(const char *s, int mode);

int bin_hex_StrToInt32(const char *s, int mode) {

    int total = 0;
    
    //binary converstion - doubling method
    //previous total x 2 + (1 or 0)
    if (mode == 1) {
        while(*s) {
            int num = (int)*s - '0';
    
            total = total * 2 + num;
            
            s++;
        }
        return total;
    } else if (mode == 2) {
        while(*s) {
            int num;
            
            if ('0' <= *s && *s <= '9') {
                num = (int)*s - '0';
            } else {
                num = (int)*s - 'A' + 10;
            }
            
            total *= 16;                 
                                  
            total += num;
            
            s++;
        }
        return total;
    } else {
        printf("ERROR_INVALID_PARAMETER\n");
        return 0;
    }
}

int main() {

    char string[] = "1011001";
    
    int result = bin_hex_StrToInt32(string, 1);
    
    printf("The binary to base 10 conversion of 1011001 is: Exp: 89, Result: %d\n", result);
    
    char string2[] = "4FB5241";
     
    result = bin_hex_StrToInt32(string2, 3);
    
    printf("The hexidecimal to base 10 conversion of 4FB5241 is: Exp: 83579457, Result: %d", result);
    
    return 0;
}
