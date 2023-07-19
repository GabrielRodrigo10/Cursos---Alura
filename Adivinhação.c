#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
	
	int chute, i, tentativas = 1;
	double pontos = 1000;
    printf ("\n\n");
	printf ("                    |>>>                        |>>>                                       \n");
	printf ("                    |                           |                                          \n");
	printf ("                _  _|_  _                   _  _|_  _                                      \n");
	printf ("               | |_| |_| |                 | |_| |_| |                                     \n");
	printf ("               \\  .      /                 \\ .    .  /                                     \n");
	printf ("                \\    ,  /                   \\    .  /        Bem vindo ao                  \n");
	printf ("                 | .   |_   _   _   _   _   _| ,   |      Jogo de Adivinhacao!             \n");
	printf ("                 |    .| |_| |_| |_| |_| |_| |  .  |                                       \n");
	printf ("                 | ,   | .    .     .      . |    .|                                       \n");
	printf ("                 |   . |  .     . .   .  ,   |.    |                                       \n");
	printf ("     ___----_____| .   |.   ,  _______   .   |   , |---~_____                              \n");
	printf ("_---~            |     |  .   /+++++++\\    . | .   |         ~---_                         \n");
	printf ("                 |.    | .    |+++++++| .    |   . |              ~-_                      \n");
	printf ("              __ |   . |   ,  |+++++++|.  . _|__   |                 ~-_                   \n");
	printf ("     ____--`~    '--~~__ .    |++++ __|----~    ~`---,              ___^~-__               \n");
	printf ("-~--~                   ~---__|,--~'                  ~~----_____-~'   `~----~             \n");
	printf ("                                                                              \n");
	printf ("\n\n");
	
	int acertou = 0;
	
	int segundos = time (0);
	
	srand (segundos);
	
	int numerogrande = rand ();
	int NumeroSecreto = numerogrande % 100;
	
	int nivel;
	printf ("Qual o nivel de dificuldade?\n");
	printf (" (1) Facil\n (2) Medio\n (3) Dificil\n\n");
	printf ("Escolha: ");
	scanf ("%d", &nivel);
	
	int numerodetentativas;
	switch (nivel) {
		case 1 :
			numerodetentativas = 20;
			break;
		case 2 :
			numerodetentativas = 15;
			break;
		default :
			numerodetentativas = 6;
			break;
	}
	
	
	for (i=1; i <= numerodetentativas; i++) {
		
		printf ("Tentativa %d\n", tentativas);
		printf ("Qual e o seu chute? ");
		scanf ("%d", &chute);
		printf ("Seu chute foi %d\n", chute);
		
		if (chute <0) {
		printf ("Voce nao pode chutar numeros negativos!\n");
		
		continue; 
	}
		int maior = chute > NumeroSecreto;
		
		acertou = (chute == NumeroSecreto); 
			
		if (acertou){
			
printf ("		        *****************                      \n");
printf ("               ******               ******                \n");
printf ("           ****                           ****            \n");
printf ("        ****                                 ***          \n");
printf ("      ***                                       ***       \n");
printf ("     **           ***               ***           **      \n");
printf ("   **           *******           *******          ***    \n");
printf ("  **            *******           *******            **   \n");
printf (" **             *******           *******             **  \n");
printf (" **               ***               ***               **  \n");
printf ("**                                                     ** \n");
printf ("**       *                                     *       ** \n");
printf ("**      **                                     **      ** \n");
printf (" **   ****                                     ****   **  \n");
printf (" **      **                                   **      **  \n");
printf ("  **       ***                             ***       **   \n");
printf ("   ***       ****                       ****       ***    \n");
printf ("     **         ******             ******         **      \n");
printf ("      ***            ***************            ***       \n");
printf ("        ****                                 ****         \n");
printf ("           ****                           ****            \n");
printf ("               ******               ******                \n");
printf ("                    *****************                     \n");	
			break;
		}
			
		else if (maior){
			printf ("Seu chute foi maior que o numero secreto! \n");
		}
		else {
			printf ("Seu chute foi menor que o numero secreto! \n");
		}
		
			tentativas ++;
		
		double pontosperdidos = abs(chute - NumeroSecreto) / (double)2;
		pontos = pontos - pontosperdidos;
	}
	printf ("Fim de jogo! \n");
	
	if (acertou) {
		printf ("Voce ganhou!\n");
		printf ("Voce acertou em %d tentativas!", tentativas);
		printf ("Total de pontos: %.1f\n", pontos);	
	}
	else {
		printf ("Voce perdeu. Tente de novo! \n");

printf (" , ; ,   .-''''''''''-. , ;   \n");
printf ("  \\\\|/  .'         '.  \\|//         \n");
printf ("   \\-;-/   ()   ()   \\-;-/          \n");
printf ("   // ;               ; \\\\          \n");
printf ("  //__; :.         .; ;__\\\\         \n");
printf (" `-----\'.'-.....-'.'/-----'        \n");
printf ("        '.'.-.-,_.'.'               \n");
printf ("          '(  (..-'                 \n");
printf ("            '-'                     \n");
}
}
