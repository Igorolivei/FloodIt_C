- Arquivo .H "myjogo.h"
	Nele � criado um arquivo para gravar um tabuleiro de tamanho 14 por 14 preenchido por n�meros aleat�rios que varia de 0 a 5. E mostra o tabuleiro na tela;

- Arquivo .C
	Nele mostra na tela as instru��es do jogo e chama a fun��o do arquivo .H para mostrar o tabuleiro criado na tela;
	Pega o tabuleiro guardado em um arquivo e passa para uma matriz do tipo inteira e para a vari�vel do desfazer e fecha o arquivo;
	Depois disso que o jogo realmente come�a, entra em um la�o para executar no m�ximo 25 rodas, caso ele n�o tenha preenchido o tabuleiro antes, e testa se o jogador quis interromper o jogo;
	Ao entrar no loop, o jogo recebe uma entrada do usu�rio, verifica se essa entrada foi igual � letra 'z', se sim ele testa se � a primeira vez que o jogador fez esse comando e se n�o � o inicio do jogo: se sim ele diminui uma jogada e mostra o tabuleiro salvo; sen�o mostra uma mensagem que n�o pode realizar o desfazer e d� outra chance ao usu�rio;
	Se a entrada for igual � letra 's', ele pergunta se o usu�rio quer salvar a configura��o atual do jogo. Se sim, ele salva e � poss�vel continuar o jogo.
	Se a entrada for igual � letra 'o', ele pergunta se o usu�rio deseja ler a �ltima configura��o de jogo salva. Se sim, ele l� o tabuleiro salvo e a quantidade de jogadas restantes. Se n�o, continua o jogo atual.
	Se a entrado do jogador for igual ao n�mero de 0 a 5, o jogo libera que a pr�xima jogada seja o desfazer; grava o tabuleiro em uma matriz; converte a entrada em inteiro; chama a sub-rotina floodFill onde � realizada a emunda��o do tabuleiro pelo n�mero da entrada; Limpa a tela; mostra o  tabuleiro modificado; Ver se todas as c�lulas do tabuleiro tem a mesma cor; e incrementa mais uma jogada;
	Se a entrada n�o for igual a algum n�mero de 0 a 5, nem igual a 'z' e nem a 'q', o jogo d� outra jogada ao usu�rio sem contar como uma rodada;
	Apos sair do la�o, ver as condi��es do jogo, se o tabuleiro estiver todo com a mesma cor, mostra uma mensagem o parabenizando, se o tabuleiro n�o estiver completo e chegou nas 25 rodadas mostra a mensagem que o jogador perdeu o jogo;
	Se o jogo foi interrompido, � perguntado se o jogador deseja salvar o jogo, se sim, ele salva o estado do jogo e a quantidade de jogadas em um arquivo.

- Funcionalidade extra
	Possibilidade de realizar o desfazer no m�ximo 1 vez; 

Dupla:
	D�bora Emili Costa Oliveira � 2014026450 
	Igor Bezerra de Oliveira - 2014038246
