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
    fprintf(arq, "%s", "\n");

}

int main(){
	int bin = 0, x = 0;
	FILE *arq;
	arq = fopen("gravar.txt", "w");
    while(x != 65535){
       escrever(bin, arq);
        x = bin & 65535;
        bin++;
    }
    fclose(arq);
	return 0;
}

