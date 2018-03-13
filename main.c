#include <stdio.h>

void printEthernet(FILE *arq, unsigned char data[]);

int main()
{
	int op;
	printf("1: UDP\n2: TCP\n");
	scanf("%d", &op);

	FILE *arq;
	unsigned char ethernetData[60];

	if (op == 1)
	{
		arq = fopen("packet_udp.bin", "rb");
		if (arq == NULL)
		{
			printf("Problemas na abertura do arquivo\n");
			return -1;
		}
		printEthernet(arq, ethernetData);
	}
	else if (op == 2)
	{
		arq = fopen("packet_tcp.bin", "rb");
		if (arq == NULL)
		{
			printf("Problemas na abertura do arquivo\n");
			return -1;
		}
	}
	else
	{
		printf("Opcao invalida\n");
		return -1;
	}

	return 0;
}

void printEthernet(FILE *arq, unsigned char data[])
{
	unsigned char dstAdress[6];
	unsigned char srcAdress[6];
	unsigned char e_type[2];

	fread(dstAdress, sizeof(unsigned char) * 6, 1, arq); // ler dst adress
	fread(srcAdress, sizeof(unsigned char) * 6, 1, arq); // ler src adress
	fread(e_type, sizeof(unsigned char) * 2, 1, arq); // ler type
	fread(data, sizeof(unsigned char) * 60, 1, arq); // ler data

	printf("Destination Adress: ");
	for (int i = 0; i < 6; i++)
		printf("%x ", dstAdress[i]);

	printf("\n\nSource Adress: ");
	for (int i = 0; i < 6; i++)
		printf("%x ", srcAdress[i]);

	printf("\n\ntype: ");
	for (int i = 0; i < 2; i++)
		printf("%x ", e_type[i]);

	printf("\n\nDados: ");
	for (int i = 0; i < 60; i++)
		printf("%x ", data[i]);
}