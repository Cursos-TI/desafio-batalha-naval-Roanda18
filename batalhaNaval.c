#include <stdio.h>

int main()
{

    int tabuleiro[10][10] = {0};

    // Posicionamento dos navios
    int navioVertical[3] = {3, 3, 3};   // Navio 1 (vertical)
    int navioHorizontal[3] = {3, 3, 3}; // Navio 2 (horizontal)

    for (int i = 0; i < 3; i++)
    {
        tabuleiro[i][0] = navioVertical[i]; // Navio 1 (vertical)
    }

    for (int i = 0; i < 3; i++)
    {
        tabuleiro[6][3 + i] = navioHorizontal[i]; // Navio 2 (horizontal)
    }

    // Exibição do tabuleiro
    printf("Tabuleiro de Batalha Naval:\n");
    printf("  A B C D E F G H I J\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", i + 1);
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
