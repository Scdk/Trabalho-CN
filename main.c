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

int simetrica(int bin, FILE *arq){
    int i, j, flag = 0;
    for(i = 1; i < 5; i++)
        for(j = 1; j < 5; j++){
            if((aRb(i, j, bin) == 1) && (aRb(j, i, bin) == 0)){
                flag = 1;
                break;
            }
        }
    if(flag == 0){
      fprintf(arq, "%s", " S ");
      return 0;
    }
    else
        return 1;
}

int transitiva(int bin, FILE *arq){
    int i, j, z, flag = 0;
    for(i = 1; i < 5; i++)
        for(j = 1; j < 5; j++)
            for(z = 1; z < 5; z++){
                if(j!= z)
                    if((aRb(i, j, bin) == 1) && (aRb(j, z, bin) == 1))
                        if(aRb(i, z, bin) == 0){
                            flag = 1;
                            break;
                        }

            }
    if(flag == 0){
        fprintf(arq, "%s", " T ");
        return 0;
    }
    else
        return 1;
}

int reflexiva(int bin, FILE *arq){
    if((bin & 33825) == 33825){
      fprintf(arq, "%s", " R ");
      return 0;
    }
    else
        return 1;
}

void equivalencia(int s, int t, int r, FILE *arq){
    if(s == 0 && t == 0 && r == 0)
        fprintf(arq, "%s", " E ");
}

void irreflexiva(int bin, FILE *arq){
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

void sobrejetora(int bin, FILE *arq){
    int i, j, x, flag = 0, flag2 = 0;
    for(i = 1; j < 5; i++){
        for(j = 1; i < 5; j++){
            if(aRb(i, j, bin) == 1){
               flag = 1;
               if(x == 1){
                    flag = 0;
                    break;
               }
                x = 1;

            }
        }
        x = 0;
        if(flag == 1){
            flag2++;
            flag = 0;
        }
    }
    if(flag2 == 4){
        fprintf(arq, "%s", " Fs ");
    }

}

void funcao(int bin, FILE *arq){
    int i, j, x, flag = 0, flag2 = 0;
    for(i = 1; i < 5; i++){
        for(j = 1; j < 5; j++){
            if(aRb(i, j, bin) == 1){
               flag = 1;
               if(x == 1){
                    flag = 0;
                    break;
               }
                x = 1;
            }
        }
        x = 0;
        if(flag == 1){
            flag2++;
            flag = 0;
        }
    }
    if(flag2 == 4){
        fprintf(arq, "%s", " F ");
        sobrejetora(bin, arq);
    }
}

int main(){
	int bin = 0, x = 0, s = 0, t = 0, r = 0;
	FILE *arq;
	arq = fopen("gravar.txt", "w");
    while(x != 65535){
        escrever(bin, arq);
        s = simetrica(bin, arq);
        t = transitiva(bin, arq);
        r = reflexiva(bin, arq);
        equivalencia(s, t, r, arq);
        irreflexiva(bin, arq);
        funcao(bin, arq);
        fprintf(arq, "%s", "\n");
        x = bin & 65535;
        bin++;
    }
    fclose(arq);
	return 0;
}

