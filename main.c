#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "myjogo.h"


void floodFill(int tabuleiro[14][14], int linha, int coluna, int velha_cor, int nova_cor)
{
    if(linha < 0 || coluna < 0 || linha > 13 || coluna > 13)
    {
        return;
    }
    else
    {
        if(tabuleiro[linha][coluna] == velha_cor)
        {
            tabuleiro[linha][coluna] = nova_cor;
            floodFill(tabuleiro, linha + 1, coluna, velha_cor, nova_cor);
            floodFill(tabuleiro, linha - 1, coluna, velha_cor, nova_cor);
            floodFill(tabuleiro, linha, coluna + 1, velha_cor, nova_cor);
            floodFill(tabuleiro, linha, coluna - 1, velha_cor, nova_cor);
            
        }
    }
}



int main()
{
    //Declarando as variáveis
    int i,j, velha_cor, desfazer = 0;
    int x;
    char nova_cor[0], salvar;
    int jogadas = 0, terminou = 0;
    int tabuleiro[14][14], undo[14][14];
    FILE *pf;
    
    //Mensagem Inicial
    system ("cls");
    printf("Bem vindo ao FLOOD IT!\nPara jogar, basta digitar um número de 0 à 5.\nE imundar todo tabuleiro com apenas um número em até 25 jogadas.\nBoa sorte!!!\n\n");
    printf("Você ainda tem 25 jogadas\n\n");
    
    //Carrega o inicio do jogo, buscando lá do myjogo.h
    comeco();
    
    //Abre o arquivo que o jogo tava salvo e preenche o tabuleiro
    if((pf = fopen("arquivo.bin", "rb")) == NULL) 
    {
        printf("Erro na abertura do arquivo");
        exit(1);
    }
    
    for( i = 0; i < 14; ++i )
    {
        for( j = 0; j < 14; ++j )
        {
            if(fread(&tabuleiro[i][j], sizeof(int), 1,pf) != 1)
            {
                printf("Erro na escrita do arquivo");
                
                 undo[i][j] = tabuleiro[i][j];
            }
        }
    }
    fclose(pf);

    //Aqui começa o jogo, no enquanto ele testa se não passou das 25 jogadas, se não completou o jogo, ou se o usuario quis interromper 
    while(jogadas <25 && nova_cor[0]!= 'q' && terminou != 196) 
    {  
        terminou = 0;
        
        fgets (nova_cor, 256, stdin);
        
        //Testa se o usuario quis desfazer o seu movimento
        if(nova_cor[0] == 'z')
        {
            if(jogadas > 0 && desfazer == 0)
            {
                system ("cls");
                jogadas = jogadas-1;
                printf("Você ainda tem %i jogadas\n\n", 25-jogadas);
                for(i=0; i<14; ++i)
                {
                    for(j=0; j<14; ++j)
                    {
                        printf("%i", undo[i][j]);
                        if(j < 13 )
                            printf( " " );
                        else
                            printf( "\n" );
                    }
                }
               desfazer ++; 

            }else
            {
                printf("Não pode desfazer mais!\n");
            }
        }
        
        velha_cor = tabuleiro[0][0];
        
        //Testa se o jogador digitou uma cor válida, senão dá outra chance
        if(nova_cor[0] == '0' || nova_cor[0] == '1' || nova_cor[0] == '2' || nova_cor[0] == '3' || nova_cor[0] == '4' || nova_cor[0] == '5')
        {
            
            //Habilita apção de desfazer e grava o tabuleiro antigo;
            desfazer =0;
            for(i = 0; i < 14; ++i)
            {
                for(j = 0; j < 14; ++j)
                {
                     undo[i][j] = tabuleiro[i][j];
                }
            }
            
            //Transforma em inteiro o que o jogador digitou
            x = atoi (nova_cor);
            
            //Chama a recusividade;
            floodFill(tabuleiro, 0, 0, velha_cor, x);
            
            // Limpa a tela e mostra quantas jogas ainda restam e o novo tabuleiro
            system ("cls");
            printf("Você ainda tem %i jogadas\n\n", 24-jogadas);
            for(i=0; i<14; ++i)
            {
                for(j=0; j<14; ++j)
                {
                    printf("%i", tabuleiro[i][j]);
                    if(j < 13 )
                        printf( " " );
                    else
                        printf( "\n" );

                    if(tabuleiro[0][0] == tabuleiro[i][j])
                    {
                        terminou = terminou + 1;
                    }
                }
            }
            jogadas++;
        }
    }
    
    //Ver como o jogo terminou;
    if(terminou == 196)
    {
        printf("Parabéns!!! Vc é o novo ganhador\n");
    }
    if(terminou != 196 && jogadas >=25)
    {
        printf("Quem sabe na próxima?\n");
    }
    
    // se o jogador interroper, pergunta se deseja salvar
    if(nova_cor[0]== 'q')
    {
        printf("Deseja salvar o jogo?\n");
        scanf("%c",&salvar);
        
        //se quer salvar, o programa grava um arquivo com o tabuleiro e a qtd de jogadas;
        if(salvar == 's')
        {
            FILE *pf;
            int i, j;
    
            if((pf = fopen("jogo_salvo.bin", "wb")) == NULL) 
            {
                printf("Erro na abertura do arquivo");
                exit(1);    
            }
    
            for( i = 0; i < 14; ++i)
            {
                for( j = 0; j < 14; ++j)
                {
                    if(fwrite(&tabuleiro[i][j], sizeof(int), 1,pf) != 1)
                    printf("Erro na escrita do arquivo");
                }
            }
            if(fwrite(&jogadas, sizeof(int), 1,pf) != 1)
                    printf("Erro na escrita do arquivo");
            fclose(pf);
            
            printf("Salvo com sucesso\n");
        }
    }
	system ("pause");
    return 0;
}