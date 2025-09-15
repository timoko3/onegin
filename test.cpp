#include <stdio.h>

int main() {
    // Эта строка будет сохранена в кодировке вашего исходного файла
    printf("Пример: ё Ё ж Ж\n");
    
    // Вывод байтов, из которых состоит строка
    char str[] = "ё";
    for (int i = 0; str[i] != 0; i++) {
        printf("Байт %d: %d (0x%02X)\n", i, (unsigned char)str[i], (unsigned char)str[i]);
    }
    return 0;
}