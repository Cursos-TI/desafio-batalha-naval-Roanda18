#include <stdio.h>
#include <stdlib.h>

int main()
{

    
    int tabuleiro[10][10] = {0};
    #define alturaMatriz 3
    #define larguraMatriz 5
    int coneHabilidade[alturaMatriz][larguraMatriz];
    int cruzHabilidade[alturaMatriz][larguraMatriz];
    int octaedroHabilidade[alturaMatriz][larguraMatriz];

    // Posicionamento dos navios
    int navioVertical[3] = {3, 3, 3};   // Navio 1 (vertical)
    int navioHorizontal[3] = {3, 3, 3}; // Navio 2 (horizontal)
    int navioDiagonal01[3] = {3, 3, 3}; // Navio 3 (diagonal)
    int navioDiagonal02[3] = {3, 3, 3}; // Navio 4 (diagonal)

    // Habilidade cone
    for (int i = 0; i < alturaMatriz; i++)
    {
        for (int j = 0; j < larguraMatriz; j++)
        {
            int centro = alturaMatriz - 1;
            if (j >= centro - i && j <= centro + i)
            {
                coneHabilidade[i][j] = 1; // Marca a área de habilidade do cone
            }
            else
            {
                coneHabilidade[i][j] = 0; // Marca a área fora da habilidade do cone
            }
            printf("%d ", coneHabilidade[i][j]);
            
        }
        printf("\n");
    }
    printf("\n");

    // Habilidade cruz
    for (int i = 0; i < alturaMatriz; i++)
    {
        for (int j = 0; j < larguraMatriz; j++)
        {
            if (i == alturaMatriz / 2 || j == larguraMatriz / 2)
            {
                cruzHabilidade[i][j] = 1; // Marca a área de habilidade da cruz
            }
            else
            {
                cruzHabilidade[i][j] = 0; // Marca a área fora da habilidade da cruz
            }
            printf("%d ", cruzHabilidade[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Habilidade octaedro
    for (int i = 0; i < alturaMatriz; i++)
    {
        for (int j = 0; j < larguraMatriz; j++)
        {
            int centroAltura = alturaMatriz/2;
            int centroLargura = larguraMatriz/2;
            int distanciaAltura = (i > centroAltura) ? i - centroAltura : centroAltura - i;
            int distanciaLargura = (j > centroLargura) ? j - centroLargura : centroLargura - j;

            if (distanciaAltura + distanciaLargura <= centroAltura)
            {
                octaedroHabilidade[i][j] = 1; // Marca a área de habilidade do octaedro
            }
            else
            {
                octaedroHabilidade[i][j] = 0; // Marca a área fora da habilidade do octaedro
            }
            printf("%d ", octaedroHabilidade[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    // Adicionando navios no tabuleiro

    for (int i = 0; i < 3; i++)
    {
        if (0 < 10 && i < 10)
        {
            tabuleiro[i][0] = navioVertical[i]; // Navio 1 (vertical)
        }
        else
        {
            printf("Posição inválida para o navio vertical.\n");
            return 1;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (6 < 10 && (7 + i) < 10)
        {
            if (tabuleiro[6][7 + i] == 3)
            {
                printf("Conflito de posição para o navio horizontal.\n");
                return 1;
            }
            tabuleiro[6][7 + i] = navioHorizontal[i]; // Navio 2 (horizontal)
        }
        else
        {
            printf("Posição inválida para o navio horizontal.\n");
            return 1;
        }
    }

    for (int i = 0, j = 0; i < 3; i++)
    {
        if ((3 + j) < 10 && (0 + i) < 10)
        {
            j++;
            if (tabuleiro[3 + j][2 + i] == 3)
            {
                printf("Conflito de posição para o navio diagonal 1.\n");
                return 1;
            }
            tabuleiro[3 + j][2 + i] = navioDiagonal01[i]; // Navio 3 (diagonal)
        }
        else
        {
            printf("Posição inválida para o navio diagonal 1.\n");
            return 1;
        }
    }

    for (int i = 0, j = 0; i < 3; i++)
    {
        if ((4 + j) < 10 && (5 + i) < 10)
        {
            j++;
            if (tabuleiro[4 + j][5 + i] == 3)
            {
                printf("Conflito de posição para o navio diagonal 2.\n");
                return 1;
            }
            tabuleiro[4 - j][5 + i] = navioDiagonal02[i]; // Navio 4 (diagonal)
        }
        else
        {
            printf("Posição inválida para o navio diagonal 2.\n");
            return 1;
        }
    }

    //Adicionando habilidade cone no tabuleiro
    for (int i = 0; i < alturaMatriz; i++)
    {
        for (int j = 0; j < larguraMatriz; j++)
        {
            if (coneHabilidade[i][j] == 1)
            {
                tabuleiro[i][j] = coneHabilidade[i][j];
            }
        }
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
