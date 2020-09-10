#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#define TAM 1000
void menu();//MENU PARA SABER A BASE DO NUMERO
void menu2();//MENU PARA SABER QUAL BASE O NUMERO VAI SER CONVERTIDO
void deci_to_bin(int num);//DECIMAL PARA BINARIO
void bin_oct(int num);//binario octal
int dec_oct(int num);//decimal octal
void dec_hexa(int num);//decimal hexa
int oct_dec(int num);//octal decimal
int bin_dec(int num);//binario decimal
int verifica_bin(int num);//verificador de bases
int funcao(int num, int pot);//auxiliar binario decimal
int hex_dec(char hex[]);
int auxint(char c);

////////////////////////////////////////////////////////
int main()
{
    int num;
    int tipobase, converter;
    char resp, valor[TAM];
    char hex[17];
	menu();
	scanf("%d", &tipobase);
	switch(tipobase)
	{
		case 1://base binaria
		fflush(stdin);
			printf("Digite um numero binario\n");
			scanf("%d", &num);
			break;
		case 2://base Octal
		fflush(stdin);
			printf("Digite um numero octal\n");
			scanf("%d", &num);
			break;
		case 3://base decimal
		fflush(stdin);
			printf("Digite um numero decimal\n");
			scanf("%d", &num);
			break;
		case 4://base hexadecimal
                    fflush(stdin);
			    printf("Entre com o numero Hexadecimal\nUtilize LETRAS MAIUSCULAS\n");
    			gets(hex);
    			fflush(stdin);
    			//strcpy(*hex, hexa);
                //printf("%s\n", hex);



			break;

	}
    //printf("numero\n");
    //scanf("%d", &num);


do{
    menu2();
    scanf("%d", &converter);
    system("cls");
    ///////////////////////////////////////BINARIO
    if(tipobase == 1)//BASE BINARIA
    {
        //VERIFICANDO SE È BINARIO
        int retorno = verifica_bin(num);
        if( retorno > 1)
        {
            printf("O numero digitado nao e binario\n");
            break;
        }
                switch(converter)
                {
                    case 1://binario para binario
                        {
                            printf("\n%d\n", num);
                            break;
                        }
                    case 2://binario octal
                        {
                            system("cls");
                            int retfun = bin_dec(num);
                        //printf("\n\t%d", retfun);
                            int retfun2 =  dec_oct(retfun);
                            printf("\n%d\n", retfun2);
                            break;
                        }
                    case 3://binario decimal
                        {
                            printf("%d", bin_dec(num));//funcao binario para decimal
                            break;
                        }
                    case 4://binario HEXADECIMAL
                        {
                            int retfun = bin_dec(num);
                            dec_hexa(retfun);

                            break;
                        }
                    default:
                        printf("BASE INVALIDA\n");
                        break;
        }
    }
//////////////////////////////////////////////////////////OCTAL
        else
            if(tipobase == 2)//BASE OCTAL
            {
                //VERIFICA OCTAL
                int retorno = verifica_bin(num);
                if( retorno > 7)
                {
                    printf("O numero digitado nao e octal\n");
                    break;
                }

                switch(converter)
                {
                    case 1://OCTAL para binario
                        {
                            int ret = oct_dec(num);
                            deci_to_bin(ret);
                             break;
                        }
                    case 2://OCTAL octal
                        {
                            printf("\n%d\n", num);
                            break;
                        }

                    case 3://OCTAL decimal
                        {
                            printf("%d", oct_dec(num));
                            break;
                        }
                    case 4://OCTAL HEXADECIMAL
                        {
                            int ret = oct_dec(num);
                            dec_hexa(ret);
                            break;
                        }
                    default:
                    printf("BASE INVALIDA\n");
                    break;
            }

        }
///////////////////////////////////////////////////////////DECIMAL
            else
                if(tipobase == 3)//BASE DECIMAL
            {

                switch(converter)
                {
                case 1://DECIMAL para binario
                    deci_to_bin(num);//conversor

                    break;
                case 2://DECIMAL octal
                    printf("%d\n", dec_oct(num));

                    break;
                case 3://DECIMAL decimal
                    printf("\n%d\n", num);
                    break;
                case 4://DECIMAL HEXADECIMAL
                    dec_hexa(num);
                    break;
                default:
                    printf("BASE INVALIDA\n");
                    break;
                }
            }
////////////////////////////////////////////////////////////HEXADECIMAL
                else//BASE HEXADIMAL
                {
                    switch(converter)
                    {
                    case 1://HEXADECIMAL para binario
                        {
                            int ret = hex_dec(hex);
                            deci_to_bin(ret);

                            break;
                        }


                    case 2://HEXADECIMAL octal
                        {
                            int ret = hex_dec(hex);
                            printf("%d\n", dec_oct(ret));
                           break;
                        }


                    case 3://HEXADECIMAL decimal
                        {
							int ret = hex_dec(hex);
                            printf("%d\n", ret);

                            break;
                        }


                case 4://HEXADECIMAL HEXADECIMAL
                    {
                        printf("\n%s\n", hex);

                        break;
                    }


                default:
                    printf("BASE INVALIDA\n");
                    break;
                }
            }
            fflush(stdin);
            printf("\nDeseja converter novamente? S / N\n");
            scanf("%c", &resp);
            resp = toupper(resp);
            fflush(stdin);
            system("cls");
}while(resp == 'S');

    //tam_vet =
    //printf("\n\n%d", tam_vet);

    return 0;
}
////////////////////////////////
void menu2()
{
    printf("Qual base deseja converter seu numero: \n1 - Binario\n2 - Octal\n3 - Decimal\n4 - Hexadecimal\n");
}
void menu()
{
    printf("Digite a base do seu numero: \n1 - Binario\n2 - Octal\n3 - Decimal\n4 - Hexadecimal\n");
}

int verifica_bin(int num)//verifica se é binario
{
    int i=0;
    int vet[TAM];
    while(num>0)
    {
        vet[i] = num%10;
        num = num/10;
        i++;

    }

return vet[0];
}

void deci_to_bin(int num)//DECIMAL PARA BINARIO
{
    int i=0;
    int vet[TAM];
    int tamvet = 0;
    while(num>0)
    {
        vet[i] = num%2;
        num = num/2;
        i++;
        tamvet++;

    }

    for(i = tamvet -1 ; i>=0; i--)
    {
        printf("%d", vet[i]);
    }
}

int bin_dec(int num)//BINARIO PARA DECIMAL
{
    int valorconv = 0;
    int pot = 0;

    valorconv = funcao(num, pot);
   // printf("\n%d", valorconv);
    return valorconv;
}
//funcao auxiliar binario decimal
int funcao (int num, int pot)
{
	if(num == 0)
	{
		return 0;
	}
	int x = num%10; // Quebra o número
	return x*pow(2,pot) + funcao(num/10,pot+1);
}

//DECIMAL PARA OCTAL
int dec_oct(int num)
{
    int oct = 0, i = 1;

    while (num != 0)
    {
        oct += (num % 8) * i;
        num /= 8;
        i *= 10;
    }

    return oct;
}
//DECIMAL HEXA
void dec_hexa(int num)
{
    	int resto, q, i;
	char hexa[10] = {'\0'}, getInt[10] = {'\0'};

	do{
		q = num / 16;
		resto = num % 16;
		num = num/16;

		switch(resto){
			case 10:
				strcat(hexa, "A");
			break;
			case 11:
				strcat(hexa, "B");
			break;
			case 12:
				strcat(hexa, "C");
			break;
			case 13:
				strcat(hexa, "D");
			break;
			case 14:
				strcat(hexa, "E");
			break;
			case 15:
				strcat(hexa, "F");
			break;
			default:
				sprintf(getInt, "%i", resto);
				strcat(hexa, getInt);
		}
	}while(q != 0);

	for(i=strlen(hexa); i >= 0; i--)
    {
		printf("%c", hexa[i]);
	}
}

//OCTAL DECIMAL
int oct_dec(int num)
{
    int decimal = 0, i = 0;

    while(num != 0)
    {
        decimal += (num%10) * pow(8,i);
        ++i;
        num/=10;
    }

    i = 1;

    return decimal;
}
//HEXADECIMAL DECIMAL
int hex_dec(char hex[])
{

    long long decimal, place;
    int i = 0, val, len;

    decimal = 0;
    place = 1;


    //tamanho do numero
    len = strlen(hex);
    len--;


    for(i=0; hex[i]!='\0'; i++)
    {
        if(hex[i]>='0' && hex[i]<='9')
        {
            val = hex[i] - 48;
        }
        else if(hex[i]>='a' && hex[i]<='f')
        {
            val = hex[i] - 97 + 10;
        }
        else if(hex[i]>='A' && hex[i]<='F')
        {
            val = hex[i] - 65 + 10;
        }

        decimal += val * pow(16, len);
        len--;
    }
    return decimal;
}


