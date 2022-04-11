# EP-listaLigada
 
1) Fiz 2 tipos de struct, um para a musica(Musica) e outro para o podcast(Node) para fazer as listas ligadas

2) 2 variaveis globais 1 para verificar se o shuffle está ativo ou não e o outro para o indice e id das listas

Quando inicializado o programa vai mostrar:

shuffle: OFF

Digite 1 para adicionar

Digite 2 para deletar

Digite 3 para consultar os podcast

Digite 4 para entrar em um podcast

Digite 5 para ativar ou destivar o shuffle

Digite 6 para sair do programa

1) Primeiro chama uma funcao para adicionar um podcast na lista[(adicionar(comeco)) sendo o comeco a cabeca da lista dos podcast] e depois mostra o que tem dentro da lista de podcast, sendo ecessario adiconar o nome do podcast.

2) Deleta um podcast especifico onde precisa colocar o id dele (deletar(comeco)) e depois mostra a lista de podcast.

3) Imprime a lista de podcast(imprimir(comeco)).

4) Entra dentro de um podcast usando a função (entrarPodcast(comeco)), mas precisa indicar o indice do podcast desejado. 

-----
4,1) Entrando no podcast vai aparecer:
Digite o indice de qual podcast você quer entrar: 1

voce esta no podcast "nome do podcast que voce selecionou"

shuffle: OFF

Digite 1 para adicionar

Digite 2 para deletar

Digite 3 para tocar musica

Digite 4 para consultar os musica

Digite 5 para ativar ou destivar o shuffle

1) Adiciona um musica dentro do podcast selecionado usando a função ''adicionarMusicas(comeco->musicas)'', vai precisar inserir nome e uma palavra chave para a musica adicionada 
e depois mostra as lista de musicas dentro desse podcast com a função "imprimirMusicas(comeco->musicas)".

2) Deleta uma musica dentro da lista de musicas do podcast selecionado usando a função "deletarMusica(comeco->musicas)", vai precisar inserir somente o indice da musica que deseja deletar.

3) Precisa do indice da musica que voce quer que ela toca usando a função "tocarMusica(comeco->musicas)", e depois vai aparecer: 

---
3,1)  
Estou no indice de musicas "indice da musica que está sendo tocada" do Podcast "nome do podcast" tocando a musica "nome da musica sendo tocada"

shuffle: OFF
Digite 1 para ir para o proximo
Digite 2 para ativa e destivar o shuffle

1) Verificaria se o shuffle esta ativo ou não, se estiver ele gera um numero aleatorio diferente do que está.
---

4) Imprime a lista de musicas dentro do podcast usando a função "imprimirMusicas(comeco->musicas)".

5) Ativa e desativa o shuffle, se ele estiver ON e for selecionado essa função vai ficar OFF.

----------------------

5) Ativa e desativa o shuffle, se ele estive ligado e for selecionado essa função ele vai desativar.

6)Simplesmente sai do programa.