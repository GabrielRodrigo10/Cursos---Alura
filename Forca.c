#include <stdio.h>
#include <string.h>
#include "forca.h"
#include <time.h>
#include <stdlib.h>

//variaveis globais
char palavrasecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesdados = 0;
	
void abertura () {
	printf ("******************************\n");
	printf ("*        Jogo de Forca       *\n");
	printf ("******************************\n\n");
	}
	
void chuta () {
	char chute;
	printf ("Qual e a letra? \n");
	scanf (" %c", &chute);
	
	if (letraexiste(chute)) {
		printf ("Voce acertou: a palavra tem a letra %c\n\n", chute);
	} else {
		printf ("\nVoce errou: a palavra NAO tem a letra %c\n\n", chute);
	}
		
	chutes[chutesdados]= chute;
	
	chutesdados++;
			
}	

void desenhaforca () {
	
	int erros = chuteserrados();
	
	
printf("    	 _______       \n");
printf("    	|/      |      \n");
printf("    	|      %c%c%c  \n", (erros>=1 ? '(' : ' '),
(erros >=1 ? '_' : ' '), (erros >=1 ? ')' : ' '));
printf("    	|      %c%c%c  \n", (erros>=3 ? '\\' : ' '),
(erros >=2 ? '|' : ' '), (erros >=3 ? '/' : ' '));
printf("    	|       %c     \n", (erros>=2 ? '|' : ' '));
printf("    	|      %c %c   \n", (erros>=4 ? '/' : ' '),
(erros >=4 ? '\\' : ' '));
printf("    	|              \n");
printf("       _|___           \n");
printf("\n\n");

	int i;
	
	for(i = 0; i < strlen(palavrasecreta); i++) {

    	int achou = jachutou (palavrasecreta[i]);

        if(achou) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }

	}
		printf ("\n");
}

void escolhepalavra () {
	
	FILE* f;
	
	f = fopen("´palavras.txt", "r");
	
	if (f == 0) {
		printf ("Desculpe, banco de dados não disponível. \n\n");
		exit (1);
	}
	
	int qtddepalavras;
	fscanf (f, "%d", &qtddepalavras);
	
	srand (time(0));
	int randomico = rand() % qtddepalavras;
	
	int i;
	
	for (i=0; i<= randomico; i++) {
		
		fscanf (f, "%s", palavrasecreta);
	}
	
	fclose(f);
}

int letraexiste (char letra) {

	int j;
	
		for (j=0; j<strlen(palavrasecreta); j++) {
			if (letra == palavrasecreta[j]) {
				
				return 1;
			}
		}
		
		return 0;
}

int chuteserrados () {
	
	int erros =0;
	
	int i;
	
	for (i=0; i<chutesdados; i++) {
		
	if (!letraexiste(chutes[i])) {
			erros ++;	
		}
	} 
	
	return erros;		
	
}

int enforcou () {

	return chuteserrados() >= 5;	
}
int acertou () {
	
	int i; 

	
	for (i=0;i<strlen(palavrasecreta); i++) {
		
		if (!jachutou (palavrasecreta[i])) {
			
			return 0;
		}
	} return 1;
}

int jachutou (char letra) {
	
	    int achou = 0;
	    int j=0;
        

        for( j = 0; j < chutesdados; j++) {
    
            if(chutes[j] == letra) {
    
                achou = 1;
                break;
            }
        }
        
        return achou;
}

void adicionapalavra() {
	
	char quer;
	
	printf ("Voce deseja adicionar uma nova palavra ao jogo? (S/N) \n");
	scanf (" %c", &quer);
	
	if (quer == 'S') {
		
		char novapalavra[TAMANHO_PALAVRA];
		
		printf ("Digite a nova palavra:");
		scanf ("%s", &novapalavra);
		
		FILE *f;
		
		f = fopen ("´palavras.txt", "r+");
		
		if (f == 0) {
			printf ("Desculpe, banco de dados não disponível. \n\n");
			exit (1);
		}
		
		int qtd;
		fscanf (f, "%d", &qtd);
		qtd++;
		
		fseek (f, 0, SEEK_SET);
		fprintf (f, "%d", qtd);
		
		fseek (f, 0, SEEK_END);
		
		fprintf (f, "\n %s", novapalavra);
		
		fclose (f);
	}
}

int main () {
	abertura ();
	escolhepalavra ();
	
	do {
    
    	desenhaforca ();
		
		chuta();
		
		
	}while (!acertou() && !enforcou());
	
	if (acertou()) {
		
		printf ("\n Parabens! Voce ganhou! \n\n");
		
		printf ("          .-=========-.  \n");
        printf ("          \\'-=======-'/  \n");
    	printf ("          _|   .=.   |_  \n");
    	printf ("         ((|  {{1}}  |)) \n");
    	printf ("          \\|   /|\\   |/  \n");
    	printf ("           \\__ '`' __/   \n");
    	printf ("             _`) (`_     \n");
    	printf ("      jgs  _/_______\\_   \n");
    	printf ("          /___________\\  \n\n");
	}
	
	else {
		
		printf ("\nPoxa, voce foi enforcado!\n");
		printf ("A palavra secreta era **%s** \n", palavrasecreta);
		
		printf ("      ________       \n");
    	printf ("    .-""        ""-.     \n");  
    	printf ("   /            \\    \n");
    	printf ("  |              |   \n");
    	printf ("  |,  .-.  .-.  ,|   \n");
    	printf ("  | )(__/  \\__)( |   \n");
    	printf ("  |/     /\\     \\|   \n");
    	printf ("  (_     ^^     _)   \n");
    	printf ("   \\__|IIIIII|__/    \n");
    	printf ("    | \\IIIIII/ |     \n");
    	printf ("    \\          /     \n");
  	    printf ("jgs  `--------`      \n\n");
	
		
	}
	
	adicionapalavra();
}
