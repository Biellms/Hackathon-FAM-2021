#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#define TAM 50

HANDLE saida;
COORD posicao;

/* ESTRUTURA E VALOR PARTICIPANTE */
typedef struct{
    int edicao;
    char nome[100];
    int estrela;
}Participante;

Participante participante[TAM];

// MÉTODOS
void menuPrincipal(Participante *participante);
void cadastrarParticipante(Participante *participante);
void exibirParticipantes(Participante *participante);
void saidas(Participante *participante);
void relatorio(Participante *participante);

// VARIÁVEIS GLOBAIS CONTAVEIS
int contTotal=0;
int contEdicao1=0, contEdicao2=0, contEdicao3=0;
int contEstrela1=0, contEstrela2=0, contEstrela3=0;
// VARIAVEIS GLOBAIS
int op;

int main() { 

    system("cls");Sleep(500);
	printf("\n\n\t\t===========================================================");Sleep(500);
	printf("\n\t\t====================== HACKATHON-C ========================");Sleep(500);
	printf("\n\t\t===========================================================\n");Sleep(500);
	printf("\n\t\t===========================================================");Sleep(500);
	printf("\n\t\t>>>>>>>>>>>>>>>>>>>>> SEJA BEM-VINDO <<<<<<<<<<<<<<<<<<<<<<");Sleep(500);
	printf("\n\t\t>> CADASTRE PARTICIPANTES E EMITA RELATORIOS COM DADOS!! <<");Sleep(500);
	printf("\n\t\t===========================================================\n\n\n\n\t\t");Sleep(1000);
	system("pause");

    menuPrincipal(participante); 
}

void menuPrincipal(Participante *participante){ // MENU PRINCIPAL

    saida = GetStdHandle(STD_OUTPUT_HANDLE);
    posicao = {30,1};
    system("cls");
    printf("\n QUAL OPCAO DESEJA ACESSAR: [   ]\n\n");
    printf(" 1) CADASTRAR PARTICIPANTE\n");
    printf(" 2) EXIBIR PARTICIPANTES\n");
    printf(" 3) SAIDAS \n");
    printf(" 4) RELATORIO \n");
    printf(" 5) INFORMACOES DO SISTEMA\n");
    printf(" 6) SAIR ");
    SetConsoleCursorPosition(saida,posicao);
    scanf("%d", &op);

    switch (op) {
    case 1: cadastrarParticipante(participante); break;
    case 2: exibirParticipantes(participante); break;
    case 3: saidas(participante); break;
    case 4: relatorio(participante); break;
    case 5: system("cls");
			printf("=====================================");
			printf("\n\n HACKATHON-C");
			printf("\n\n CRIADOR: Gabriel Mendes");
			printf("\n CONTATO: biell.mendes8@gmail.com");
			printf("\n\n COPYRIGHT@2021\n\n");
			printf("=====================================\n\n ");
			system("pause"); menuPrincipal(participante); break;
    case 6: system("exit"); break;
    default: menuPrincipal(participante); break;
    }

}

void cadastrarParticipante(Participante *participante) { //CADASTRO DE PARTICIPANTES

int i=contTotal;
    
    saida = GetStdHandle(STD_OUTPUT_HANDLE);
    posicao = {28,9};

    system("cls");
    printf("\n CADASTRAR PARTICIPANTE\n\n");

    for ( i=contTotal; i>=contTotal && i<TAM; i++) {
        fflush(stdin);
        printf(" NOME: ");
        gets(participante[i].nome);
        fflush(stdin);
        printf("\n EDICAO QUE O PARTICIPANTE ESTEVE/ESTA: ");
        scanf("%d", &participante[i].edicao);
        if (participante[i].edicao == 1) { contEdicao1++; } if (participante[i].edicao == 2) { contEdicao2++; } if (participante[i].edicao == 3) { contEdicao3++; }
        printf("\n ESTRELA: ");
        scanf("%d", &participante[i].estrela);
        if (participante[i].estrela == 1) { contEstrela1++; } if (participante[i].estrela == 2) { contEstrela2++; } if (participante[i].estrela == 3) { contEstrela3++; }
        contTotal++;
        printf("\n PARTICIPANTE CADASTRADO! [   ]");
        printf("\n\n 1) CADASTRAR NOVAMENTE\n 2) SAIR");
        SetConsoleCursorPosition(saida,posicao);
        scanf("%d", &op);

        if(op == 1) { cadastrarParticipante(participante); } else { menuPrincipal(participante); }
    break; }

}

void exibirParticipantes(Participante *participante) { //DADOS DOS PARTICIPANTES

int i;

    system("cls");
    printf("\n =========================");
    printf("\n DADOS DOS PARTICIPANTES");
    printf("\n QUANTIDADE: %d ", contTotal);
    printf("\n =========================\n\n");

    for ( i=0; i<contTotal && i<TAM; i++) {
        printf(" EDICAO: %d \n", participante[i].edicao);
        printf(" NOME: %s \n", participante[i].nome);
        printf(" ESTRELA: %d \n", participante[i].estrela);
        printf("--------------------------------------\n ");
    }
    system("pause");
    menuPrincipal(participante);

}

void saidas(Participante *participante) { //SAIDAS DE DADOS DO EVENTO

float porcNovato=0, porcReinc=0;
int totalReinc=0;

//PORCENTAGEM DE PARTICIPANTES
totalReinc = contEstrela2+contEstrela3;
porcNovato = contEstrela1*100/contTotal;
porcReinc = totalReinc*100/contTotal;

    system("cls");
    printf("\n >>> SAIDA DE DADOS <<<\n\n");
    printf(" ===========================================================================");
    printf("\n O EVENTO CORRENTE TEM UM TOTAL DE %d PARTICIPANTES ONDE: ", contTotal);
    printf("\n %d PARTICIPANTES ESTIVERAM NA 2 EDICAO ", contEdicao2);
    printf("\n %d PARTICIPANTES ESTIVERAM NA 1 EDICAO ", contEdicao1);
    printf("\n ===========================================================================");
    printf("\n SENDO QUE: ");
    printf("\n %d PARTICIPANTES SAO 1 ESTRELA ", contEstrela1);
    printf("\n %d PARTICIPANTES SAO 2 ESTRELAS ", contEstrela2);
    printf("\n %d PARTICIPANTES SAO 3 ESTRELAS ", contEstrela3);
    printf("\n ===========================================================================");
    printf("\n O NUMERO TOTAL DE NOVATOS E IGUAL A %d, E SUA REPRESENTACAO PERCENTUAL ", contEstrela1);
    printf("\n EQUIVALE A %.1f%% DO EVENTO ", porcNovato);
    printf("\n O NUMERO TOTAL DE REINCIDENTES E IGUAL A %d, E SUA REPRESENTACAO PERCENTUAL ", totalReinc);
    printf("\n EQUIVALE A %.1f%% DO EVENTO ", porcReinc);
    printf("\n ===========================================================================\n\n ");
    system("pause");
    menuPrincipal(participante);

}

void relatorio(Participante *participante) { //RELATORIO GERAL DO EVENTO

float porcNovato=0, porcReinc=0, cresED12=0, difED12=0, cresED23=0, difED23=0, cresED13=0, difED13=0;
int totalReinc=0;

//PORCENTAGEM DE PARTICIPANTES
totalReinc = contEstrela2+contEstrela3;
porcNovato = contEstrela1*100/contTotal;
porcReinc = totalReinc*100/contTotal;

//PORCENTAGEM DE CRESCIMENTOS
difED12 = contEdicao2 - contEdicao1;
cresED12 = (difED12/contEdicao2)*100;
difED23 = contTotal - contEdicao2;
cresED23 = (difED23/contTotal)*100;
difED13 = contTotal - contEdicao1;
cresED13 = (difED13/contTotal)*100;

    system("cls");
    printf("\n\n\t\t\t  ===============\n");
    printf("\t\t\t  == RELATORIO ==");
    printf("\n\t\t\t  ===============");
    printf("\n\n O numero de participantes do evento Hachathon e de %d no total. Deste ", contTotal);
    printf("\n numero, %d sao participantes novos, o que representa %.1f%% do total. ", contEstrela1 ,porcNovato);
    printf("\n Na edicao atual do evento Hachathon, %d participantes estiveram em ", totalReinc);
    printf("\n edicoes anteriores, o que representa %.1f%% de reincidentes no evento ", porcReinc);
    printf("\n atual. A primeira edicao do evento Hackathon teve %d participantes. A ", contEdicao1);
    printf("\n segunda edicao do evento Hackathon teve %d participantes. Na edicao ", contEdicao2);
    printf("\n atual do  evento Hackathon, temos: %d participantes 3 estrelas(pessoas", contEstrela3);
    printf("\n que participaram das tres edicoes do evento), %d participantes 2 estrelas", contEstrela2);
    printf("\n (pessoas que participaram de duas edicoes do evento), %d participantes", contEstrela1);
    printf("\n 1 estrela (pessoas que participaram pela primeira vez no evento). O ");
    printf("\n crescimento do evento Hackathon entre a primeira e a segunda edicao foi");
    printf("\n de %.1f%%. O crescimento do evento entre a segunda e a terceira edicao ", cresED12); 
    printf("\n foi de %.1f%%. O crescimento total do evento Hackathon entre a primeira", cresED23);
    printf("\n e a terceira edicao foi de %.1f%%.\n\n ", cresED13);
    system("pause");
    menuPrincipal(participante);

}