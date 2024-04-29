#include <stdio.h>
#include <stdlib.h>
#define NOT 100

int main() {
    float notas[NOT], notaNova, maiorNota = 0, menorNota = 10.1, media = 0.0, numEstudantes = 0, numDefinido;
    int alunoAlt, opcao, numNot, i = 0;

    memset(notas, 0, sizeof(notas));

    do {
        printf("\nMenu de opções:\n");
        printf("(1) Cadastrar as notas dos alunos\n");
        printf("(2) Imprimir todas as notas\n");
        printf("(3) Alterar uma nota\n");
        printf("(4) Calcular e imprimir a média da turma\n");
        printf("(5) Imprimir as notas maiores que uma nota informada\n");
        printf("(6) Imprimir as notas menores que uma nota informada\n");
        printf("(7) Imprimir a maior nota\n");
        printf("(8) Imprimir a menor nota\n");
        printf("(9) Excluir todas as notas cadastradas\n");
        printf("(0) Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:

                if (i == NOT) {
                    printf("Número máximo de notas atingido");
                    return;
                }

                printf("\nDigite o número de notas que serão cadastradas: ");
                scanf("%d", &numNot);

                for (i = 0; i < numNot; i++) {
                    printf("Entre com a nota do aluno: ");
                    scanf("%f", &notas[i]);

                    while (notas[i] < 0.0 || notas[i] > 10.0) {
                            printf("Nota inválida, digite novamente: ");
                            scanf("%f", &notas[i]);
                    }
                }
            break;

            case 2:

                if (notas[i] == i) {
                    printf("\nNão há notas cadastradas. Execute novamente!\n");
                    return;
                }

                printf("\nNotas cadastradas:\n");
                for (int i = 0; i < numNot; i++) {
                    printf("Nota: %.1f\n", notas[i]);
                }
            break;

            case 3:

                if (notas[i] == i) {
                    printf("\nNão há notas cadastradas. Execute novamente!\n");
                    return;
                }

                printf("\nDigite a posição da nota à ser alterada: ");
                scanf("%d", &alunoAlt);

                while (alunoAlt < 1 || alunoAlt > numNot) {
                    printf("Número de aluno inválido! Digite novamente: ");
                    scanf("%d", &alunoAlt);
                }

                printf("Digite a nova nota (entre 0.0 e 10.0): ");
                scanf("%f", &notaNova);

                while (notaNova < 0.0 || notaNova > 10.0) {
                    printf("Nota inválida! Digite novamente: ");
                    scanf("%f", &notaNova);
                }

                notas[alunoAlt - 1] = notaNova;
                printf("Nota na posição %d alterada com sucesso!\n", alunoAlt);

            break;

             case 4:

                if (notas[i] == i) {
                    printf("\nNão há notas cadastradas. Execute novamente!\n");
                    return;
                }

                for (int i = 0; i < numNot; i++) {
                    media += notas[i];
                }
                media /= numNot;
                printf("A média das notas é: %.1f\n", media);

            break;

            case 5:

                if (notas[i] == i) {
                    printf("\nNão há notas cadastradas. Execute novamente!\n");
                    return;
                }

                printf("Digite o valor definido: ");
                scanf("%f", &numDefinido);

                printf("\nNotas acima de %.1f:\n", numDefinido);
                for (i = 0; i < numNot; i++) {
                    if (notas[i] > numDefinido) {
                        printf("%.1f\n", notas[i]);
                    }
                }

            break;

             case 6:

                if (notas[i] == i) {
                    printf("\nNão há notas cadastradas. Execute novamente!\n");
                    return;
                }

                printf("Digite o valor definido: ");
                scanf("%f", &numDefinido);

                printf("\nNotas menor de %.1f:\n", numDefinido);
                for (i = 0; i < numNot; i++) {
                    if (notas[i] < numDefinido) {
                        printf("%.1f\n", notas[i]);
                    }
                }

            break;

            case 7:

                if (notas[i] == i) {
                    printf("\nNão há notas cadastradas. Execute novamente!\n");
                    return;
                }

                for(int i = 0; i < numNot; i++) {
                    if(notas[i] > maiorNota) {
                        maiorNota = notas[i];
                    }
                }

                printf("\nA maior nota é: %.1f\n", maiorNota);

            break;

            case 8:

                if (notas[i] == i) {
                    printf("\nNão há notas cadastradas. Execute novamente!\n");
                    return;
                }

                for(int i = 0; i < numNot; i++) {
                    if(notas[i] < menorNota) {
                        menorNota = notas[i];
                    }
                }

                printf("\nA menor nota é: %.1f\n", menorNota);

            break;

            case 9:

                memset(notas, 0, sizeof(notas));
                printf("Notas apagadas com sucesso!\n");

            break;

            case 0:

                printf("\nPrograma finalizado!\n");
            break;

        }
    } while (opcao != 0);

    return 0;
}

