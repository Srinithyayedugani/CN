#include <stdio.h>
int main() {
    int data[20] ;
    for(int i=0;i<20;i++){
    	scanf("%d",&data[i]);
    }
    printf("Without Stuffing:");
    for(int i=0;i<20;i++){
    	printf("%d",data[i]);
    }
    int n = sizeof(data) / sizeof(data[0]);
    int stuffed_data[50]; 
    int j = 0; 
    int count = 0; 
    for (int i = 0; i < n; i++) {
        stuffed_data[j] = data[i];
        j++;
	    if (data[i] == 1) {
            count++;
        } else {
            count = 0; // Reset counter if bit is 0
        }
        if (count == 5) {
            stuffed_data[j] = 0; 
            j++;
            count = 0; 
        }
    }
    

    printf("\nStuffed Data:  ");
    for (int i = 0; i < j; i++) {
        printf("%d ", stuffed_data[i]);
    }
    printf("\n");

    return 0;
}

