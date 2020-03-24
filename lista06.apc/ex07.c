#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Contato{
    int id;
    char nome[50];
    int ano;
    int mes;
    int dia;
    char t_movel[12];
    char t_fixo[11];
    char email[100];
} CONTATO_T;


char readchar(){
    char c;
    do{
        c = getchar();
    }while (c == '\n');
    return(c);
}

void imprimir_agenda(FILE *pFile){
    CONTATO_T c;
    int conta_registro = 0;

    while (fscanf(pFile,"%d %s %d %d %d %s %s %s", &c.id,c.nome,&c.dia,&c.mes,&c.ano,c.email,c.t_movel,c.t_fixo)!= EOF){
        printf("\n\nContato [%d]\nNome: %s\nNascimento: %02d\\%02d\\%04d\nEmail: %s\nMovel: %s\t Fixo: %s", c.id,c.nome,c.dia,c.mes,c.ano,c.email,c.t_movel,c.t_fixo);
        conta_registro++;
    }

    if (conta_registro == 0)
        printf("\nAGENDA VAZIA\n");
}

void inserir_contato(FILE *pFile){
    CONTATO_T c;
    while (fscanf(pFile,"%d %s %d %d %d %s %s %s", &c.id,c.nome,&c.dia,&c.mes,&c.ano,c.email,c.t_movel,c.t_fixo)!= EOF){
    }
    //printf("%d\n", conta_registro);
    printf("Entre o contato [%d]\nNome:\n", c.id + 1);
    fprintf(pFile, "%d ", c.id + 1);
    scanf("%s", c.nome);
    fprintf(pFile, "%s ", c.nome);
    printf("Nascimento:\n");
    scanf("%d %d %d", &c.dia, &c.mes, &c.ano);
    fprintf(pFile, "%d %d %d ", c.dia, c.mes, c.ano);
    printf("email:\n");
    scanf("%s", c.email);
    fprintf(pFile, "%s ", c.email);
    printf("telefone movel:\n");
    scanf("%s", c.t_movel);
    fprintf(pFile, "%s ", c.t_movel);
    printf("telefone fixo:\n");
    scanf("%s", c.t_fixo);
    fprintf(pFile, "%s\n", c.t_fixo);
    
return;
}


void excluir_contato(FILE *pFile){
    CONTATO_T c[100];
    int ID, i = 0, f;
    printf("Informe o id do contato a ser excluiudo:\n");
    scanf("%d", &ID);
    while (fscanf(pFile,"%d %s %d %d %d %s %s %s", &c[i].id,c[i].nome,&c[i].dia,&c[i].mes,&c[i].ano,c[i].email,c[i].t_movel,c[i].t_fixo)!= EOF){
        i++;
    }
    FILE *fp;
    fp = fopen("tmp.dat", "w");
    if (ID > 0 && ID <= i){
       for (f = 0; f < i; f++){
           if (c[f].id != ID){
               fprintf(fp, "%d %s %d %d %d %s %s %s\n", c[f].id,c[f].nome,c[f].dia,c[f].mes,c[f].ano,c[f].email,c[f].t_movel,c[f].t_fixo);
           }
       }
       fclose(fp);
       fclose(pFile);
       remove("agenda.dat");
       rename("tmp.dat", "agenda.dat");
       printf("REGISTRO APAGADO COM SUCESSO!\n");
    return;
    }
        else{
            printf("REGISTRO NAO ENCONTRADO!\n");
            return;
        }
}

void editar_contato(FILE * pFile){
    CONTATO_T c[100];
    int id;
    char nome[50];
    int ano;
    int mes;
    int dia;
    char t_movel[12];
    char t_fixo[11];
    char email[100];
    int i, l = 0;
    printf("Informe o id do contato a ser editado:\n");
    scanf("%d", &id);
    printf("Forneca o novo nome:\n");
    scanf("%s", nome);
    printf("Nascimento: dia mes ano\n");
    scanf("%d %d %d", &dia, &mes, &ano);
    printf("Forneca email:\n");
    scanf("%s", email);
    printf("Movel:\n");
    scanf("%s", t_movel);
    printf("Fixo:\n");
    scanf("%s", t_fixo);

    while (fscanf(pFile,"%d %s %d %d %d %s %s %s", &c[i].id,c[i].nome,&c[i].dia,&c[i].mes,&c[i].ano,c[i].email,c[i].t_movel,c[i].t_fixo)!= EOF){
        i++;
    }

    FILE *fp;
    fp = fopen("tmp.dat", "w");

    for (l = 0; l < i; l++){
        if (c[l].id != id){
            fprintf(fp, "%d %s %d %d %d %s %s %s\n", c[l].id,c[l].nome,c[l].dia,c[l].mes,c[l].ano,c[l].email,c[l].t_movel,c[l].t_fixo);
        }
        if (c[l].id == id){
            fprintf(fp, "%d %s %d %d %d %s %s %s\n", id, nome, dia, mes, ano, email, t_movel,t_fixo);
        }
    }
    fclose(fp);
    fclose(pFile);
    remove("agenda.dat");
    rename("tmp.dat", "agenda.dat");
    printf("REGISTRO ALTERADO COM SUCESSO!\n");
    return;
}

void buscar_contato(FILE * pFile){
    CONTATO_T c[100];
    int i = 0, l, f = 0;
    char cont[50];
    while (fscanf(pFile,"%d %s %d %d %d %s %s %s", &c[i].id,c[i].nome,&c[i].dia,&c[i].mes,&c[i].ano,c[i].email,c[i].t_movel,c[i].t_fixo)!= EOF){
        i++;
    }
    printf("Informe o nome do contato a ser encontrado:\n");
    scanf("%s", cont);
    for (l = 0; l < i; l++){
        if (strcmp(cont, c[l].nome) == 0){
            printf("Nome: %s\nNascimento: %02d/%02d/%02d\nEmail: %s\nMovel: %s fixo: %s\n", c[l].nome, c[l].dia,c[l].mes,c[l].ano,c[l].email,c[l].t_movel,c[l].t_fixo);
        }
            else f++;
    }
    if (f == i){
        printf("CONTATO NAO ENCONTRADO\n");
    }
    return;
}

int main(){
    int opcao = 0;
    FILE * pFileAgenda;

    while (1){
        printf("\n\n");
        printf("\n\nMENU DE OPERACOES NA AGENDA\n\n");
        printf("(1) Imprimir agenda\t\t(2) Inserir contato\n\n");
        printf("(3) Excluir contato\t\t(4) Editar contato\n\n");
        printf("(5) Buscar contato\t\t(6) Sair do programa\n\n\n");

        pFileAgenda = fopen("agenda.dat", "r+");
        if (pFileAgenda == NULL){
            pFileAgenda = fopen("agenda.dat", "w+");
            if (pFileAgenda == NULL){
                printf("Problemas com a abertura do arquivo de dados da agenda");
                exit(0);
            }
        }

        do{
            printf("Digite a opcao desejada: ");
            opcao = readchar();
            if (feof(stdin)) break;
        }
        while (opcao < '1'  ||  opcao > '6');

        if (feof(stdin)){
            printf("EOF encontrado. Saindo ...\n\n\n");
            break;
        }

        switch (opcao){
        case '1':
            imprimir_agenda(pFileAgenda);
            break;
        case '2':
            inserir_contato(pFileAgenda);
            break;
        case '3':
            excluir_contato(pFileAgenda);
            break;
        case '4':
            editar_contato(pFileAgenda);
            break;
        case '5':
            buscar_contato(pFileAgenda);
            break;
        case '6':
            break;
        default:
            break;
        }

        if (opcao == '6'){
            printf("O usuario pediu para sair do programa. Saindo ...\n\n\n");
            break;
        }
        fclose(pFileAgenda);
    }

    exit(0);
}
