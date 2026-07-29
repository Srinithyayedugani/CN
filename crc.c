#include<stdio.h>
int main() {
	int data[100], div[20], temp[100];
	int datalen = 0, divlen = 0, i, j;
	char ch;
// Input data
	printf("Enter the data (binary): ");
	while ((ch = getchar()) != '\n') {
		if (ch == '1' || ch == '0') {
			data[datalen++] = ch - '0';
		}
	}
// Input divisor
	printf("Enter the divisor (generator polynomial): ");
	while ((ch = getchar()) != '\n') {
		if (ch == '1' || ch == '0') {
			div[divlen++] = ch - '0';
		}
	}
// Copy data to temp and append zeros for CRC calculation
	for (i = 0; i < datalen; i++) {
		temp[i] = data[i];
	}
	for (i = 0; i < divlen - 1; i++) {
		temp[datalen + i] = 0;
	}
	int totalLen = datalen + divlen - 1;
// CRC Division
	for (i = 0; i <= totalLen - divlen; i++) {
		if (temp[i] == 1) {
			for (j = 0; j < divlen; j++) {
				temp[i + j] = temp[i + j] ^ div[j];
			}
		}
	}
// Append CRC (remainder) to data
	for (i = 0; i < datalen; i++) {
		printf("%d", data[i]);
	}
	printf(" (Data) + ");
	for (i = datalen; i < totalLen; i++) {
		printf("%d", temp[i]);
		data[i] = temp[i]; // Appending CRC bits
	}
	printf(" (CRC)\n");
// Final transmitted data
	printf("Transmitted Data (Data + CRC): ");
	for (i = 0; i < totalLen; i++) {
		printf("%d", data[i]);
	}
	printf("\n");
	return 0;
}	
