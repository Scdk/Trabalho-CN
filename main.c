#include <stdio.h>

int aRb(int i, int j, int n){
	int d = 0;
	d = 1 << (((i-1) * 4) + (j-1));
	if((n & d) == d)
		return 1;
	else
		return 0;
}

void escrever(int bin, FILE *arq){
	int i = 1, j = 1;
    fprintf(arq, "%s", "{");
    if((aRb(i, j, bin)) == 1)
        fprintf(arq, "%s", "(1,1)");
    i = 1;
    j = 2;
    if((aRb(i, j, bin)) == 1)
        fprintf(arq, "%s", "(1,2)");
    i = 1;
    j = 3;
    if((aRb(i, j, bin)) == 1)
        fprintf(arq, "%s", "(1,3)");
    i = 1;
    j = 4;
    if((aRb(i, j, bin)) == 1)
        fprintf(arq, "%s", "(1,4)");
    i = 2;
    j = 1;
    if((aRb(i, j, bin)) == 1)
        fprintf(arq, "%s", "(2,1)");
    i = 2;
    j = 2;
    if((aRb(i, j, bin)) == 1)
        fprintf(arq, "%s", "(2,2)");
    i = 2;
    j = 3;
    if((aRb(i, j, bin)) == 1)
        fprintf(arq, "%s", "(2,3)");
    i = 2;
	j = 4;
    if((aRb(i, j, bin)) == 1)
        fprintf(arq, "%s", "(2,4)");
    i = 3;
	j = 1;
    if((aRb(i, j, bin)) == 1)
        fprintf(arq, "%s", "(3,1)");
    i = 3;
    j = 2;
    if((aRb(i, j, bin)) == 1)
        fprintf(arq, "%s", "(3,2)");
    i = 3;
    j = 3;
    if((aRb(i, j, bin)) == 1)
        fprintf(arq, "%s", "(3,3)");
    i = 3;
    j = 4;
    if((aRb(i, j, bin)) == 1)
        fprintf(arq, "%s", "(3,4)");
    i = 4;
    j = 1;
    if((aRb(i, j, bin)) == 1)
        fprintf(arq, "%s", "(4,1)");
    i = 4;
    j = 2;
    if((aRb(i, j, bin)) == 1)
        fprintf(arq, "%s", "(4,2)");
    i = 4;
    j = 3;
    if((aRb(i, j, bin)) == 1)
        fprintf(arq, "%s", "(4,3)");
    i = 4;
    j = 4;
    if((aRb(i, j, bin)) == 1)
        fprintf(arq, "%s", "(4,4)");

    fprintf(arq, "%s", "}");

}

void simetrica(int bin, FILE *arq){
    int i, j, flag = 0;
    for(i = 1; i < 5; i++)
        for(j = 1; j < 5; j++){
            if((aRb(i, j, bin) == 1) && (aRb(j, i, bin) == 0)){
                flag = 1;
                break;
            }
            if((aRb(i, j, bin) == 1) && i == j){
                flag = 1;
                break;
            }
        }
    if(flag == 0)
      fprintf(arq, "%s", " S ");
}

void reflexiva(int bin, FILE *arq){
    if((bin & 33825) == 33825)
      fprintf(arq, "%s", " R ");
}

void ireflexiva(int bin, FILE *arq){
    int flag = 0;
    if((bin & 1) == 1)
        flag = 1;
    if((bin & 32) == 32)
        flag = 1;
    if((bin & 1024) == 1024)
        flag = 1;
    if((bin & 32768) == 32768)
        flag = 1;
    if(flag == 0)
      fprintf(arq, "%s", " I ");
}

int main(){
	int bin = 0, x = 0;
	FILE *arq;
	arq = fopen("gravar.txt", "w");
    while(x != 65535){
        escrever(bin, arq);
        simetrica(bin, arq);
        reflexiva(bin, arq);
        ireflexiva(bin, arq);
        fprintf(arq, "%s", "\n");
        x = bin & 65535;
        bin++;
    }
    fclose(arq);
	return 0;
}

