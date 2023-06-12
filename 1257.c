#include <stdio.h>

int main(){

    int n, i, j, k, l;
    int sum;
    char string[51];

    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d%*c",&l);
        sum = 0;
        for(j = 0; j < l; j++){
            scanf("%[^\n]%*c", &string);
            for(k = 0; string[k] != '\0'; k++){
                sum += string[k] - 65 + j + k;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
