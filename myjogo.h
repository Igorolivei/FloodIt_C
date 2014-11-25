#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int comeco()
{
    FILE *pf;
    int matriz[14][14];
    int i, j;
    
    if((pf = fopen("arquivo.bin", "wb")) == NULL) 
    {
        printf("Erro na abertura do arquivo");
        exit(1);    
    }
    
    srand( (unsigned)time(NULL) );
    
    for( i = 0; i < 14; ++i )
    {
        for( j = 0; j < 14; ++j )
        {
            matriz[i][j] = rand()%6;
            if(fwrite(&matriz[i][j], sizeof(int), 1,pf) != 1)
               printf("Erro na escrita do arquivo");
        }
    }
    fclose(pf);
	
	if((pf = fopen("arquivo.bin", "rb")) == NULL) 
    {
        printf("Erro na abertura do arquivo");
        exit(1);
    }
	
    for( i = 0; i < 14; ++i )
    {
        for( j = 0; j < 14; ++j )
        {
            if(fread(&matriz[i][j], sizeof(int), 1,pf) != 1)
            {
                printf("Erro na escrita do arquivo");
            }
            else
            {
                printf("%i", matriz[i][j]);
                if(j < 13 )
                    printf( " " );
                else
                    printf( "\n" );
            }
        }
    }
    
    fclose(pf);
    
}