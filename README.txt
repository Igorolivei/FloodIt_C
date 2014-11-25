- Arquivo .H "myjogo.h"
	Nele é criado um arquivo para gravar um tabuleiro de tamanho 14 por 14 preenchido por números aleatórios que varia de 0 a 5. E mostra o tabuleiro na tela;

- Arquivo .C
	Nele mostra na tela as instruções do jogo e chama a função do arquivo .H para mostrar o tabuleiro criado na tela;
	Pega o tabuleiro guardado em um arquivo e passa para uma matriz do tipo inteira e para a variável do desfazer e fecha o arquivo;
	Depois disso que o jogo realmente começa, entra em um laço para executar no máximo 25 rodas, caso ele não tenha preenchido o tabuleiro antes, e testa se o jogador quis interromper o jogo;
	Ao entrar no loop, o jogo recebe uma entrada do usuário, verifica se essa entrada foi igual à letra 'z', se sim ele testa se é a primeira vez que o jogador fez esse comando e se não é o inicio do jogo: se sim ele diminui uma jogada e mostra o tabuleiro salvo; senão mostra uma mensagem que não pode realizar o desfazer e dá outra chance ao usuário;
	Se a entrada for igual à letra 's', ele pergunta se o usuário quer salvar a configuração atual do jogo. Se sim, ele salva e é possível continuar o jogo.
	Se a entrada for igual à letra 'o', ele pergunta se o usuário deseja ler a última configuração de jogo salva. Se sim, ele lê o tabuleiro salvo e a quantidade de jogadas restantes. Se não, continua o jogo atual.
	Se a entrado do jogador for igual ao número de 0 a 5, o jogo libera que a próxima jogada seja o desfazer; grava o tabuleiro em uma matriz; converte a entrada em inteiro; chama a sub-rotina floodFill onde é realizada a emundação do tabuleiro pelo número da entrada; Limpa a tela; mostra o  tabuleiro modificado; Ver se todas as células do tabuleiro tem a mesma cor; e incrementa mais uma jogada;
	Se a entrada não for igual a algum número de 0 a 5, nem igual a 'z' e nem a 'q', o jogo dá outra jogada ao usuário sem contar como uma rodada;
	Apos sair do laço, ver as condições do jogo, se o tabuleiro estiver todo com a mesma cor, mostra uma mensagem o parabenizando, se o tabuleiro não estiver completo e chegou nas 25 rodadas mostra a mensagem que o jogador perdeu o jogo;
	Se o jogo foi interrompido, é perguntado se o jogador deseja salvar o jogo, se sim, ele salva o estado do jogo e a quantidade de jogadas em um arquivo.

- Funcionalidade extra
	Possibilidade de realizar o desfazer no máximo 1 vez; 

Dupla:
	Débora Emili Costa Oliveira – 2014026450 
	Igor Bezerra de Oliveira - 2014038246
