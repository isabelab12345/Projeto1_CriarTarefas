#include "projeto.h"
#include <stdio.h>     //para incluir bibliotecas, ultiliza-se <> e não aspas ("")

int main(){
ListaDeTarefas lt;

char arquivo[] = "tarefas";
int codigo, opcao;

codigo=carregarTarefas(&lt, arquivo);  //faltou o '&' antes de 'lt'

if (codigo !=0){
printf("Lista de tarefas nao carregada");
lt.qtd=0;    //o valor certo é '0' e não '2'
}

do{
exibeMenu();
scanf("%d", &opcao);

if(opcao == 0){}
else if(opcao == 1){
    codigo=criarTarefa(&lt);
    if (codigo ==1 )
    printf("erro ao criar tarefa: Sem espacao disponivel\n");
    }
else if(opcao == 2){
    codigo=deletarTarefa(&lt);
    if (codigo ==1 )
    printf("erro ao deletar tarefa: nao existem tarefas para deletar\n");
else if(codigo ==2)
    printf("erro ao deletar tarefa: posicao invalida\n");
}
else if(opcao == 3){
    codigo=listarTarefas(&lt);
   if (codigo == 1)     //o código de erro na função 'listarTarefas' é 1 e não 2
   printf("Erro ao listar tarefas: nao existem tarefas para serem listadas");
}
else {
	printf("opcao invalida\n");
}
}while (opcao != 0);

codigo=salvarTarefas(&lt,arquivo);
if(codigo !=0)    //o certo é '!=' e não '=='
printf("Erro ao salvar tarefas em arquivo");


system ("pause");

}
