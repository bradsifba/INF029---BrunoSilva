// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de AnÃ¡lise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - LaboratÃ³rio de ProgramaÃ§Ã£o
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- OrientaÃ§Ãµes gerais -----
//  DescriÃ§Ã£o: esse arquivo deve conter as questÃµes do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questÃµes do trabalho

//  ----- Dados do Aluno -----
//  Nome: Bruno Silva
//  email: brmatico@gmail.com
//  MatrÃ­cula: 20212160014
//  Semestre: 2Â°

//  Copyright Â© 2016 Renato Novais. All rights reserved.
// Ãšltima atualizaÃ§Ã£o: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "BrunoSilva-20212160014-T1.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
#include <string.h>
#include <math.h>



/*
 Questão 01
 */

DataQuebrada quebradata(char data[]);
int dgtoval (char dgt);
DiasMesesAnos q2(char dtini[], char dtfn[]);

DataQuebrada q1(char data[]){

    DataQuebrada dataint;
    int vali=0;

    
    dataint = quebradata(data);

    dataint.valido=0;

    if(dataint.iAno>-1)
        vali++;
    switch(dataint.iMes){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
        {
                if(dataint.iDia<=31 && dataint.iDia>0)
                    vali++;
                break;
        }
        case 4:
        case 6:
        case 9:
        case 11:
        {
            if(dataint.iDia<=30 && dataint.iDia>0)
                vali++;
            break;
        }
        case 2:
            if(dataint.iAno%4==0){
                if(dataint.iDia<=29 && dataint.iDia>0){
                    vali++;
                    if(dataint.iAno%100==0 && dataint.iAno%400!=0)
                        if(dataint.iDia>28)
                            vali--;
                }
            }
            else{
                if(dataint.iDia<=28)
                    vali++;
            }
            break;
        default:
            dataint.valido=0;
            break;
    }

    if(vali == 2)
        dataint.valido=1;


    return dataint;

}

DataQuebrada quebradata(char data[]){

    DataQuebrada dq;
    char dia[3];
    char mes[3];
    char ano[5];
    int i, j;
    int vali = 0;

    for(i=0; data[i]!='/'; i++)
        {
        dia[i] = data[i];
        }
    if(i == 1 || i==2){
        dia[i]= '\0';
        if(i==1 && validadigito(dia[0])==1)
            vali++;
        else
            dq.valido=0;
        if(i==2 && (validadigito(dia[0])== validadigito(dia[1])==1))
            vali++;
        else
            dq.valido=0;
        i++;
    }
    else
        dq.valido = 0;


    for(j=0; data[i]!= '/'; i++,j++){
        mes[j]=data[i];
    }
    if (j==1 || j==2){
        mes[j] = '\0';
        if(j==1 && validadigito(mes[0])==1)
            vali++;
        else
            dq.valido=0;
        if(j==2 &&  validadigito(mes[0])==validadigito(mes[1])==1)
            vali++;
        else
            dq.valido=0;
        i++;
    }
    else
        dq.valido = 0;

    for(j=0; data[i] != '\0';i++, j++){
        ano[j]= data[i];
    }
    if(j==2 || j==4)
    {
        ano[j] = '\0';
        if(j==2 && validadigito(ano[0])==validadigito(ano[1])==1)
        {
            ano[2] = ano[0];
            ano[3] = ano[1];
            ano[0] = '2';
            ano[1] = '0';
            ano[4] = '\0';
            vali++;
        }
        else
            dq.valido=0;
        if(j==4 && validadigito(ano[0])==validadigito(ano[1])==validadigito(ano[2])==validadigito(ano[3])==1)
            vali++;
        else
            dq.valido=0;
    }
    else
        dq.valido = 0;

    if(vali==3)
    {
        dq.iDia = atoi(dia);
        dq.iMes = atoi(mes);
        dq.iAno = atoi(ano);
        dq.valido = 1;
    }

    return dq;
}

int validadigito (char digito){

    switch(digito)
    {
        case '0':
            return 1;
            break;
        case '1':
           return 1;
            break;
        case '2':
           return 1;
            break;
        case '3':
            return 1;
            break;
        case '4':
            return 1;
            break;
        case '5':
            return 1;
            break;
        case '6':
            return 1;
            break;
        case '7':
           return 1;
            break;
        case '8':
            return 1;
            break;
        case '9':
            return 1;
            break;
        default:
            return 0;
    }
}

/*
 Questão 02
*/

DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    
    DiasMesesAnos dma;
    DataQuebrada dataIntInicial, dataIntFinal;
    int diferenca_ano, diferenca_mes, diferenca_dia;
    int num_d_m;

    dataIntInicial = q1(datainicial);
    dataIntFinal = q1(datafinal);

    if (dataIntInicial.valido == 0){
      dma.retorno = 2;
      return dma;
    }else if (dataIntFinal.valido == 0){
      dma.retorno = 3;
      return dma;
    }

    diferenca_ano = dataIntFinal.iAno - dataIntInicial.iAno;
    diferenca_mes = dataIntFinal.iMes - dataIntInicial.iMes;
    diferenca_dia = dataIntFinal.iDia - dataIntInicial.iDia;

    if( (diferenca_ano > 0) || ((diferenca_ano == 0) && (diferenca_mes > 0)) || ((diferenca_ano == 0) && (diferenca_mes == 0) && (diferenca_dia>=0))){
        dma.retorno = 1;
        if(diferenca_mes>=0){
            if(diferenca_dia>=0){
                dma.qtdAnos = diferenca_ano;
                dma.qtdMeses = diferenca_mes;
                dma.qtdDias = diferenca_dia;
               
            }
            else{
                dma.qtdAnos = diferenca_ano;
                dma.qtdMeses = diferenca_mes-1;
                num_d_m = (n_dia_mes(dataIntInicial.iMes, dataIntInicial.iAno));
                dma.qtdDias = (num_d_m - dataIntInicial.iDia) + dataIntFinal.iDia;
                if (num_d_m == dataIntInicial.iDia){
                    dma.qtdDias = 0;
                    dma.qtdMeses++;
                }
               
            }
        }
        if(diferenca_mes<0){
            if(diferenca_dia>=0){
                dma.qtdAnos = diferenca_ano-1;
                dma.qtdMeses = 12+diferenca_mes;
                dma.qtdDias = diferenca_dia;
               
            }
            else{
                dma.qtdAnos = diferenca_ano-1;
                dma.qtdMeses = 11+diferenca_mes;
                num_d_m = (n_dia_mes(dataIntInicial.iMes, dataIntInicial.iAno));
                dma.qtdDias = (num_d_m - dataIntInicial.iDia) + dataIntFinal.iDia;
                if (num_d_m == dataIntInicial.iDia){
                    dma.qtdDias = 0;
                    dma.qtdMeses++;
                }
               
            }
        }
    }
    else{
        dma.retorno = 4;
        return dma;
    }

    return dma;
}

int n_dia_mes( int mes, int ano){



    int num_dia_do_mes;

    switch(mes){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
        {
            num_dia_do_mes = 31;
            return num_dia_do_mes;
            break;
        }
        case 4:
        case 6:
        case 9:
        case 11:
        {
            num_dia_do_mes = 30;
            return num_dia_do_mes;
            break;
        }
        case 2:
            if(ano%4==0){
                if(ano%4==0 && ano%100!=0){
                    num_dia_do_mes = 29;
                    return num_dia_do_mes;
                }
                if((ano%4==0) && (ano%100==0) && (ano%400==0)){
                    num_dia_do_mes = 29;
                    return num_dia_do_mes;
                }
            }
            else{
                num_dia_do_mes = 28;
                return num_dia_do_mes;
                break;
            }

        default:
            break;
    }


}

/*
 Questão 03
 */
   int q3(char *texto, char c, int isCaseSensitive)
{
    int ocorr = 0;
    int icont ;
    int asc2;
    char c_C;

    if(c >=65 && c<=90)
        asc2 = (c+32);
    else if(c>=97 && c<=122)
                asc2 = (c-32);
    c_C = asc2;

    if(isCaseSensitive==1){
        for(icont=0 ; icont<=250 ; icont++){
            if (texto[icont] != '\0'){
                
                if (texto[icont] == c)
                    ocorr=ocorr+1;
            }
            else
                icont=250;
        }
    }
    else{
        for(icont=0 ; icont<=250 ; icont++){
            if (texto[icont] != '\0'){
                
                if (texto[icont] == c || texto[icont] == c_C)
                    ocorr= ocorr+1;
            }
            else
                icont=250;
        }
    }
    return ocorr;
}


/*
 Questão 04
 */
int q4(char *strTexto, char *strBusca, int *posicoes)
{
    int ocorr = 0;
    int icont, icont2, jcont, contador=0, k=0;
    int tam_strBusca;

    tam_strBusca = strlen(strBusca);
    
    for(icont=0; icont<=250; icont++){
        if(strTexto[icont] != '\0'){
            if(strTexto[icont] == strBusca[0]){
                icont2 = icont;
                contador = 0;
                for(jcont=0; jcont<tam_strBusca;jcont++){
                    if(strTexto[icont2] == strBusca[jcont]){
                        contador= contador+1;
                        if(contador == tam_strBusca){
                            ocorr=ocorr+1;
                            posicoes[k] = (icont+1);
                            k++;
                            posicoes[k] = (icont+tam_strBusca);
                            k=k+1;
                        }
                        icont2=icont2+1;
                    }
                }
            }
        }
        else
            icont=250;
    }

    return ocorr;
}

/*
 Questão 05 
 */

int q5(int num){

  
    int r, final, div = 10;
    int icont , icontdec = 0;
    int aux;
    int expo;
    int ninverse;

    aux = num;

    do {
        final = aux/div;
        aux = final;
        icontdec=icontdec+1;
    }while (final>=10);

    if(final==0 && icontdec==1)
        expo = 0;
    else
        expo = icontdec;

    ninverse = 0;
    for(icont=0; icont<icontdec; icont++){
        final = num/div;
        r = num%div;
        ninverse += r*(pow(10,expo));
        expo--;
        num = final;
    }

    ninverse += final;

    return ninverse;

}



