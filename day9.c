#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    
    // Take input
    scanf("%s", str);
    
    int length = strlen(str);
    
    // Reverse the string
    for(int i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    
    return 0;
}