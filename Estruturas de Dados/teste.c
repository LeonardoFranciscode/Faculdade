#include <stdio.h>

int main() {
    int numeros [5];
    for (int i = 0; i < 5; i++) {
        printf("Type the %d º number: ", i + 1);
        scanf("%d", &numeros[i]);
    }
    printf("Lista invertida!\n\n");
    for (int i = 4; i >= 0; i--){
        if (i == 0){
            printf("%d \n", numeros[i]);
        } else {
            printf("%d | ", numeros[i]);
        }
    }
}
