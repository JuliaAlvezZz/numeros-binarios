#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>

void invert(char binario[]){
	
	char binario1[20];
	int i, j=0;
	
	for (i=7; i>=0; i--){
		binario1[j]=binario[i];
		j++;
	}
	
	binario1[8]='\0';
	strcpy(binario, binario1);
}

int decimal(char binario[]){
	int i, n=0, j;
	invert(binario);
	for (i=0; i<8; i++){;
		if (binario[i]=='1'){
			n+=1*pow(2,i);
		}		
	}
	return n;
}

void comp1(char binario[]){
	int i;
	for (i=0; i<8; i++){
		if (binario[i]=='0'){
			binario[i]='1';
		}else{
			binario[i]='0';
		}
	}
}

int comp2(char binario[]){
	int i;
	if (binario[7]=='0'){
		binario[7]='1';
		return 0;
	}else{
		binario[7]='0';
	}
	for (i=6; i>=0; i--){
		if (binario[i]=='0'){
			binario[i]='1';
			break;
		}else{
			binario[i]='0';
		}
	}
}


main(){
	setlocale(LC_ALL, "");
	char binario[10], orig[10];
	int n, neg=0;
	
	printf("Digite um número binário usando 8 bits (10000000 até 01111111): ");
	gets(binario);
	fflush(stdin);
	
	if (binario[0]=='1'){
		printf("\n%s é um número negativo.", binario);
		strcpy(orig, binario);
		comp1(binario);
		comp2(binario);
		neg=1;
	}else{
		printf("\n%s é um número positivo.", binario);
		strcpy(orig, binario);
	}
	
	n=decimal(binario);
	invert(binario);
	
	if (neg==1){
		n*=(-1);
	}
	
	printf("\n\n%s (base 2) = %d (base 10)\n\n", orig, n);
	
	system("pause");
	system("cls");
	main();
}
