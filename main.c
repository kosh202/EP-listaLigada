#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#include <string.h>

/*nao sei como fazer a procura utilizando as palavras chaves,
tentar pesquisar depois*/

/*as musicas dentro da playlist nao estao ficando guardadas*/

int indice = 1;//vou usar como id
int shuffle = 0;

struct Node//seria nome do podcast
{
    int idPodcast;
    char nome[64];
  int quantidadeMusicas;
  struct Musica* musicas;
    struct Node* next;
};

struct Musica//musica para podcast
{
    int idMusica;
    
    char nome[64];
  char PalavraChave[64];
  int numero;//indice do podcast
    struct Musica* next;
};

void verificarShuffle(int shuffleVerificar);

//podcast
void deletar(struct Node* comeco);
void adicionar(struct Node* comeco);
void imprimir(struct Node* comeco);

//musicas
void adicionarMusicas(struct Musica* comeco);
void imprimirMusicas(struct Musica* iniMusica);
void entrarPodcast(struct Node* comeco);
void deletarMusica(struct Musica* comeco);//musica
 void tocarMusica(struct Musica* comeco, struct Node* inicioPod);
void percorrerMusicas(struct Musica* comeco, struct Node* inicioPod, int xx);


int main()
{
  
  
    struct Node* comeco = (struct Node*)malloc(sizeof(struct Node));
    comeco->next = NULL;//alocar o comeco
  //resposta do usuario
    int r;


    do {
      verificarShuffle(shuffle);
        printf("\nDigite 1 para adicionar\nDigite 2 para deletar\nDigite 3 para consultar os podcast\nDigite 4 para entrar em um podcast\nDigite 5 para ativar ou destivar o shuffle\nDigite 6 para sair do programa\n");
        scanf("%d", &r);
      indice = 1;
        switch (r) {

        case 1:
            adicionar(comeco);
            imprimir(comeco);
            break;
        case 2:
          imprimir(comeco);            
          deletar(comeco);
            break;
        case 3://consultar quais podacsat tem
          imprimir(comeco);
            break;
          case 4://entrar no podcasr
            entrarPodcast(comeco);
          break;
          case 5://ativar/destivar shuffle
            if(shuffle == 0)
            {
              shuffle = 1;
            }
            else
            {
              shuffle = 0;
            }
          break;
         
        }
    } while (r != 6);

}

void adicionar(struct Node* comeco)//podcast
{

    struct Node* next = (struct Node*)malloc(sizeof(struct Node));
    next->next = NULL;
  next->quantidadeMusicas = 0;

  struct Musica* inicio = (struct Musica*)malloc(sizeof(struct Musica));
    inicio->next = NULL;
next->musicas = inicio;
    printf("digite um valor: ");
    scanf("\n%s", &next->nome);

    next->next = comeco->next;
    comeco->next = next;
}

void imprimir(struct Node* comeco)//podcast
{
    struct Node* aux = (struct Node*)malloc(sizeof(struct Node));

    
    if (comeco->next != NULL)
    {
      imprimir(comeco->next);
      aux = comeco->next;
      comeco = aux;
      printf("\n%d- %s",indice, aux->nome);
      aux->idPodcast = indice;//guardar o indice no idpodcast
      indice++;
    }
}

void deletar(struct Node* comeco)//podcast
{
  
  
    struct Node* aux = (struct Node*)malloc(sizeof(struct Node));
    struct Node* anterior = (struct Node*)malloc(sizeof(struct Node));

    int indicepod = 1;
    int xx;

    //struct Node* inicio = (struct Node*)malloc(sizeof(struct Node));
    //inicio->next = NULL;

    printf("\n O que você quer apagar? ");
    scanf("%d", &xx);
    do {
        aux = comeco->next;
        anterior = comeco;
        comeco = aux;
        indicepod++;

    } while (comeco->idPodcast != xx);
    anterior->next = aux->next;
}

void adicionarMusicas(struct Musica* inicio)//musica
{
  struct Musica* next = (struct Musica*)malloc(sizeof(struct Musica));
    next->next = NULL;

    printf("digite o nome da musica: ");
    scanf("\n%s", &next->nome);

 printf("digite uma palavra chave para a musica: ");
    scanf("\n%s", &next->PalavraChave);

    next->next = inicio->next;
    inicio->next = next;
}

void entrarPodcast(struct Node* comeco)
{
  struct Node* aux = (struct Node*)malloc(sizeof(struct Node));
  

  
    indice = 1;
    int xx;

    struct Node* novInicio = (struct Node*)malloc(sizeof(struct Node));
    novInicio = comeco;

    printf("\nDigite o indice de qual podcast você quer entrar: ");
    scanf("%d", &xx);
    do {
        aux = comeco->next;
        
        comeco = aux;
        indice++;

    } while (comeco->idPodcast != xx);
    
//musicas
  int r;
  /*struct Musica* novo = (struct Musica*)malloc(sizeof(struct Musica));
  novo->next = NULL;
  comeco->musicas = novo;*/
  comeco->musicas->numero = xx;//indice do podcast dentro da musica
  
  //fazer um switch para a parte da musica

  printf("voce esta no podcast %s", comeco->nome);

    do {
      verificarShuffle(shuffle);
        printf("\nDigite 1 para adicionar\nDigite 2 para deletar\nDigite 3 para tocar musica\nDigite 4 para consultar os musica\nDigite 5 para ativar ou destivar o shuffle\nDigite 6 para voltar\n");
        scanf("%d", &r);
      indice = 1;
        switch (r) {

        case 1://adicionar
          adicionarMusicas(comeco->musicas);
          imprimirMusicas(comeco->musicas);
            comeco->quantidadeMusicas++;
            break;
        case 2://deletar
            imprimirMusicas(comeco->musicas);
          deletarMusica(comeco->musicas);
          imprimirMusicas(comeco->musicas);
            comeco->quantidadeMusicas--;
            break;
        case 3://tocar musica
           tocarMusica(comeco->musicas, comeco);
          //colocar a funcao de shuffle e o de proximo dentro de tocar usica
            break;
          case 4://consultar musica
            imprimirMusicas(comeco->musicas);
          break;
          case 5://ativar/desativar shuffle
            if(shuffle == 0)
            {
              shuffle = 1;
            }
            else
            {
              shuffle = 0;
            }
          break;
          
        }
    } while (r != 6);

}

void imprimirMusicas(struct Musica* iniMusica)//podcast
{
    struct Musica* aux = (struct Musica*)malloc(sizeof(struct Musica));
    indice = 1;
    
    if (iniMusica->next != NULL)
    {
      imprimirMusicas(iniMusica->next);
      aux = iniMusica->next;
      iniMusica = aux;
      printf("\n%d- %s",indice, aux->nome);
      printf("\nPalavra-chave: %s",aux->PalavraChave);
      aux->idMusica = indice;//guardar o indice no idMusica
      indice++;
    }
}

void deletarMusica(struct Musica* comeco)//musica
{
    struct Musica* aux = (struct Musica*)malloc(sizeof(struct Musica));
    struct Musica* anterior = (struct Musica*)malloc(sizeof(struct Musica));

    int indicemusica = 1;
    int xx;

    //struct Node* inicio = (struct Node*)malloc(sizeof(struct Node));
    //inicio->next = NULL;

    printf("\n O que você quer apagar? ");
    scanf("%d", &xx);
    do {
        aux = comeco->next;
        anterior = comeco;
        comeco = aux;
        indicemusica++;

    } while (comeco->idMusica != xx);
    anterior->next = aux->next;
}

void tocarMusica(struct Musica* comeco, struct Node* inicioPod)//musica
//inicioPod = o pod cast que esta dentro
{
  struct Musica* aux = (struct Musica*)malloc(sizeof(struct Musica));
    struct Musica* anterior = (struct Musica*)malloc(sizeof(struct Musica));

  struct Musica* comecoreferencia = (struct Musica*)malloc(sizeof(struct Musica));
  comecoreferencia = comeco;

    int xx;

    printf("\n Digite o indice da musica que você quer tocar:");
    scanf("%d", &xx);
    do {
        aux = comeco->next;
        anterior = comeco;
        comeco = aux;
        

    } while (comeco->idMusica != xx);
    printf("\nEstou no indice de musicas %d do Podcast %s tocando a musica %s\n", comeco->idMusica, inicioPod->nome, comeco->nome);

    //colocar a parte de ir para a proxima musica e a do shuffle
    int op;//posso tranformar isso em uma funcao
  
  do{
    verificarShuffle(shuffle);
  printf("\nDigite 1 para ir para o proximo\nDigite 2 para ativa e destivar o shuffle\nDigite 3 para voltar\n");
  scanf("%d",&op);
    switch (op)
      {
        case 1://ir para a proxima musica
         comeco = comecoreferencia;
          if(shuffle == 1)
          {
            srand(time(NULL));//numero aleatorio
            int num = (rand() % (inicioPod->quantidadeMusicas)-1)+1;//variar entre 1 ate o a ultima musica
            
            if(num == xx)
            {
              if(num == inicioPod->quantidadeMusicas)
              {
                num = (rand() % (inicioPod->quantidadeMusicas)-1)+1;
                
                xx = num;
                percorrerMusicas(comeco,inicioPod, xx);
                break;
              }
            num = (rand() % (inicioPod->quantidadeMusicas)-1)+1;
              
              xx = num;
              percorrerMusicas(comeco,inicioPod, xx);
              break;
            }
          }
          xx++;
          percorrerMusicas(comeco,inicioPod, xx);
        break;
        case 2://ativar sshuffle
          if(shuffle == 0)
            {
              shuffle = 1;
            }
            else
            {
              shuffle = 0;
            }
        break;
      }
  }while(op != 3);
  //preciso guardar o id do pod e musica para usar o shuffle
}

void verificarShuffle(int shuffleVerificar)
{
  if(shuffleVerificar == 1)
    printf("\nshuffle: ON");
  else
    printf("\nshuffle: OFF");
}

void percorrerMusicas(struct Musica* comeco, struct Node* inicioPod, int xx)
{
  struct Musica* aux = (struct Musica*)malloc(sizeof(struct Musica));
    struct Musica* anterior = (struct Musica*)malloc(sizeof(struct Musica));
  int verificarSeIgual;//verificar se vai ser o mesmo numero
  do {
        aux = comeco->next;
        anterior = comeco;
        comeco = aux;
        if(comeco->next==NULL)
        {
          printf("Você chegou na ultima musica da playlist: %s",inicioPod->nome);
          return;
        }

    } while (comeco->idMusica != xx);
    printf("\nEstou no indice de musicas %d do Podcast %s tocando a musica %s\n", comeco->idMusica, inicioPod->nome, comeco->nome);
       
}
