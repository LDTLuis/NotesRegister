#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define LIN 8
#define COL 10
#define CHUTE 500

void preencherArray(int m[][COL]) {
    int lin, col;

    for (lin = 0; lin < LIN; lin++) {
        for (col = 0; col < COL; col++) {
            m[lin][col] = (rand() % CHUTE) + 1;
        }
    }
}

void mostrarMenu(void) {
    printf("\n\n(1) Cadastrar novos numeros no array\n");
    printf("(2) Limpar o array\n");
    printf("(3) Imprimir o conteudo do array\n");
    printf("(4) Alterar um numero no array\n");
    printf("(5) Imprimir uma determinada linha do array\n");
    printf("(6) Imprimir uma determinada coluna do array\n");
    printf("(7) Imprimir o somatorio dos numeros do array\n");
    printf("(8) Imprimir o maior numero contido no array\n");
    printf("(9) Imprimir o menor numero contido no array\n");
    printf("(0) Sair\n");
    printf("Opcao: ");
}

void zerarArray(int m[][COL], int tamanho) {
    memset(m, 0, tamanho);
}

int main(void) {
    int m[LIN][COL];
    int lin, col, opcaoMenu, linhaDesejada, colunaDesejada, novoNumero;
    bool entradaInvalida;
    int somatorio = 0, maiorNumero, menorNumero;

    srand(time(NULL));

    preencherArray(m);

    do {
        mostrarMenu();
        scanf("%d", &opcaoMenu);

        switch (opcaoMenu) {
            case 0: printf("Programa encerrado pelo usuario.");
                    break;

            case 1: printf("\n");
                    preencherArray(m);
                    printf("Array preenchido com sucesso.");
                    break;

            case 2: zerarArray(m, sizeof(m));
                    printf("\nArray vazio.");
                    break;

            case 3: printf("\n");

                    for (lin = 0; lin < LIN; lin++) {
                        for (col = 0; col < COL; col++) {
                             printf("%5d", m[lin][col]);
                        }
                        printf("\n\n");
                    }
                    printf("Array impresso com sucesso.");
                    break;

            case 4: printf("\n");

                    do {
                        entradaInvalida = false;
                        printf("Entre com a linha desejada: ");
                        scanf("%d", &linhaDesejada);

                        if (linhaDesejada < 1 || linhaDesejada > LIN) {
                            printf("Linha invalida (1 a %d)", LIN);
                            entradaInvalida = true;
                        }
                    } while (entradaInvalida);

                    do {
                        entradaInvalida = false;
                        printf("Entre com a coluna desejada: ");
                        scanf("%d", &colunaDesejada);

                        if (colunaDesejada < 1 || colunaDesejada > COL) {
                            printf("Coluna invalida (1 a %d)", COL);
                            entradaInvalida = true;
                        }
                    } while (entradaInvalida);

                    printf("\nNumero contido na matriz em [%d][%d] = %d\n", linhaDesejada, colunaDesejada, m[linhaDesejada - 1][colunaDesejada - 1]);

                    do {
                        entradaInvalida = false;
                        printf("Entre com novo numero para o array: ");
                        scanf("%d", &novoNumero);

                        if (novoNumero < 1 || novoNumero > CHUTE) {
                            printf("Numero invalido (1 a %d)", CHUTE);
                            entradaInvalida = true;
                        }
                    } while (entradaInvalida);

                    m[linhaDesejada - 1][colunaDesejada - 1] = novoNumero;
                    printf("\nNumero atribuido a matriz com sucesso.");
                    break;

            case 5: printf("\n");

                    do {
                        entradaInvalida = false;
                        printf("Entre com a linha desejada: ");
                        scanf("%d", &linhaDesejada);

                        if (linhaDesejada < 1 || linhaDesejada > LIN) {
                            printf("Linha invalida (1 a %d)", LIN);
                            entradaInvalida = true;
                        }
                    } while (entradaInvalida);

                    for (col = 0; col < COL; col++) {
                        printf("%5d", m[linhaDesejada - 1][col]);
                    }

                    break;

            case 6: printf("\n");

                    do {
                        entradaInvalida = false;
                        printf("Entre com a coluna desejada: ");
                        scanf("%d", &colunaDesejada);

                        if (colunaDesejada < 1 || colunaDesejada > COL) {
                            printf("Coluna invalida (1 a %d)", COL);
                            entradaInvalida = true;
                        }
                    } while (entradaInvalida);

                    for (lin = 0; lin < LIN; lin++) {
                        printf("%5d\n\n", m[lin][colunaDesejada - 1]);
                    }

                    break;

            case 7: somatorio = 0;

                    for (lin = 0; lin < LIN; lin++) {
                        for (col = 0; col < COL; col++) {
                            somatorio += m[lin][col];
                        }
                    }

                    printf("\nSomatorio = %d", somatorio);
                    break;

            case 8: maiorNumero = 0;

                    for (lin = 0; lin < LIN; lin++) {
                        for (col = 0; col < COL; col++) {
                             if (m[lin][col] > maiorNumero) {
                                maiorNumero = m[lin][col];
                             }
                        }
                    }

                    printf("\nO maior numero contido na matriz e' = %d", maiorNumero);
                    break;

            case 9: menorNumero = CHUTE;

                    for (lin = 0; lin < LIN; lin++) {
                        for (col = 0; col < COL; col++) {
                             if (m[lin][col] < menorNumero){
                                menorNumero = m[lin][col];
                             }
                        }
                    }

                    printf("\nO menor numero contido na matriz e' = %d", menorNumero);
                    break;

            default: printf("\nOpcao invalida!");
        }
    } while (opcaoMenu != 0);

    return 0;
}
