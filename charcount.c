#include <stdio.h>
#include <string.h>

int main() {
    int num_frames;
    char frames[10][50]; 
    char transmitted_stream[500] = ""; 
    char temp[60];

    printf("Enter the number of frames to send: ");
    scanf("%d", &num_frames);

    for(int i = 0; i < num_frames; i++) {
        printf("Enter data for Frame %d: ", i + 1);
        scanf("%s", frames[i]);
    }

    for(int i = 0; i < num_frames; i++) {
        int data_len = strlen(frames[i]);
        int total_len = data_len + 1; 

        sprintf(temp, "%d%s", total_len, frames[i]);
        
        strcat(transmitted_stream, temp);
    }

    printf("\n--- Transmitted Stream ---\n");
    printf("Resulting Stream: %s\n", transmitted_stream);

    return 0;
}
