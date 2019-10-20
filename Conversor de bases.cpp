#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int b1, b2;

void menu(){
	system("cls");
	printf("**********CONVERSOR DE BASES**********\n\n\n");
	printf("2. Binario\n");
	printf("8. Octal\n");
	printf("10. Decimal\n");
	printf("16. Hexadecimal\n\n");
	printf("Digite a base do numero que sera convertido: ");
	scanf("%d", &b1);
	printf("\nDigite a base para a qual o numero sera convertido: ");
	scanf("%d", &b2);
}

void invert(char nC[]){
	
	char nCI[20];
	int i, j=0, tam;
	
	tam=strlen(nC);
	
	for (i=tam-1; i>=0; i--){
		nCI[j]=nC[i];
		j++;
	}
	
	nCI[tam]='\0';
	strcpy(nC, nCI);
}

int toDecimal(char nC[]){
	int tam=strlen(nC), i, n;
	
	invert(nC);
	
	switch (b1){
		case 2:
			for (i=0; i<tam; i++){
				if (nC[i]=='1'){
					n+=1*pow(2,i);
				}		
			}
			break;
		case 8:
			for (i=0; i<tam; i++){
				switch (nC[i]){
					case '0':
						n+=0*pow(8,i);
						break;
					case '1':
						n+=1*pow(8,i);
						break;
					case '2':
						n+=2*pow(8,i);
						break;
					case '3':
						n+=3*pow(8,i);
						break;
					case '4':
						n+=4*pow(8,i);
						break;
					case '5':
						n+=5*pow(8,i);
						break;
					case '6':
						n+=6*pow(8,i);
						break;
					case '7':
						n+=7*pow(8,i);
						break;
				}
			}
			break;
		case 10:
			break;
		case 16:
			for (i=0; i<tam; i++){
				switch (nC[i]){
					case 'A':
						n+=10*pow(16,i);
						break;
					case 'B':
						n+=11*pow(16,i);
						break;
					case 'C':
						n+=12*pow(16,i);
						break;
					case 'D':
						n+=13*pow(16,i);
						break;
					case 'E':
						n+=14*pow(16,i);
						break;
					case 'F':
						n+=15*pow(16,i);
						break;
					case '0':
						n+=0*pow(16,i);
						break;
					case '1':
						n+=1*pow(16,i);
						break;
					case '2':
						n+=2*pow(16,i);
						break;
					case '3':
						n+=3*pow(16,i);
						break;
					case '4':
						n+=4*pow(16,i);
						break;
					case '5':
						n+=5*pow(16,i);
						break;
					case '6':
						n+=6*pow(16,i);
						break;
					case '7':
						n+=7*pow(16,i);
						break;
					case '8':
						n+=8*pow(16,i);
						break;
					case '9':
						n+=9*pow(16,i);
						break;
				}
			}
			break;
	}
	
	return n;
}

void decimalTo(int n, char nC[]){
	int i=0, k;
	char aux[1];
	
	if (n==0){
		nC[0]='0';
		nC[1]='\0';
	}
	
	switch (b2){
		case 2:
			while (n!=0){
				k=n%2;
				sprintf(aux, "%d", k);
				n/=2;
				nC[i]=aux[0];
				i++;
			}
			if (n!=0){
				nC[i]='\0';
				invert(nC);
			}
			break;
		case 8:
			while (n>=8){
				k=n%8;
				switch (k){
					case 0:
						aux[0]='0';
						break;
					case 1:
						aux[0]='1';
						break;
					case 2:
						aux[0]='2';
						break;
					case 3:
						aux[0]='3';
						break;
					case 4:
						aux[0]='4';
						break;
					case 5:
						aux[0]='5';
						break;
					case 6:
						aux[0]='6';
						break;
					case 7:
						aux[0]='7';
						break;
				}	
				n/=8;
				nC[i]=aux[0];
				i++;
			}
			switch (n){
				case 1:
					aux[0]='1';
					break;
				case 2:
					aux[0]='2';
					break;
				case 3:
					aux[0]='3';
					break;
				case 4:
					aux[0]='4';
					break;
				case 5:
					aux[0]='5';
					break;
				case 6:
					aux[0]='6';
					break;
				case 7:
					aux[0]='7';
					break;
			}
			if (n!=0){
				nC[i]=aux[0];
				nC[i+1]='\0';
				invert(nC);
			}
			break;
		case 10:
			sprintf(nC, "%d", n);
			break;
		case 16:
			while (n!=0){
				k=n%16;
				if (k==10){
					sprintf(aux, "A");
				}else{
					if (k==11){
						sprintf(aux, "B");
					}else{
						if (k==12){
							sprintf(aux, "C");
						}else{
							if (k==13){
								sprintf(aux, "D");
							}else{
								if (k==14){
									sprintf(aux, "E");
								}else{
									if (k==15){
										sprintf(aux, "F");
									}else{
										sprintf(aux, "%d", k);
									}
								}	
							}
						}
					}
				}
				n/=16;
				nC[i]=aux[0];
				i++;
			}
			if (n!=0){
				nC[i]='\0';
				invert(nC);
			}
			break;
	}
	
		
}

main(){
	int n;
	char nC[20], nA[20];
	
	menu();
	
	system("cls");
	printf("**********CONVERSOR DE BASES**********\n\n\n");
	printf("\n\nBase %d para base %d.\n\n", b1, b2);
	printf("Digite o numero a ser convertido: ");

	switch (b1){
		case 2:
			fflush(stdin);
			gets(nC);
			strcpy(nA, nC);
			if (b1!=b2){
				n=toDecimal(nC);
				decimalTo(n, nC);
			}
			break;
		case 8:
			fflush(stdin);
			gets(nC);
			strcpy(nA, nC);
			if (b1!=b2){
				n=toDecimal(nC);
				decimalTo(n, nC);
			}
			break;
		case 10:
			int n;
			scanf("%d", &n);
			sprintf(nA, "%d", n);
			decimalTo(n, nC);
			break;
		case 16:
			fflush(stdin);
			gets(nC);
			strcpy(nA, nC);
			if (b1!=b2){
				n=toDecimal(nC);
				decimalTo(n, nC);
			}
			break;
	}
	
	system("cls");
	printf("**********CONVERSOR DE BASES**********\n\n\n");
	printf("\n\n%s (base %d) = %s (base %d)\n\n", nA, b1, nC, b2);
	
	system("pause");
	
	main();
}
