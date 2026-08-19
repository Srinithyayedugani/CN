#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int total_frames;
    int window_size;
    int lost_frame;
    
    printf("--- Data Link Layer GBN Simulator ---\n");
    printf("Enter total number of frames to transmit: ");
    if (scanf("%d", &total_frames) != 1) return 1;
    
    printf("Enter Sender Window Size (N): ");
    if (scanf("%d", &window_size) != 1) return 1;
    
    printf("Enter a frame number to simulate as LOST/CORRUPTED (1 to %d): ", total_frames);
    if (scanf("%d", &lost_frame) != 1) return 1;

    int current_ack = 1;      // Next expected ACK by sender / expected frame by receiver
    int next_frame_to_send = 1; 
    int total_transmissions = 0;
    bool loss_simulated = false;

    printf("\n--- Starting Pipelined Transmission ---\n");

    while (current_ack <= total_frames) {
        // 1. Send all frames possible within the current sliding window
        while (next_frame_to_send < current_ack + window_size && next_frame_to_send <= total_frames) {
            printf("[Sender] Transmitting Frame %d\n", next_frame_to_send);
            total_transmissions++;
            next_frame_to_send++;
        }

        // 2. Process the oldest outstanding frame in the window
        printf("\n[Processing] Checking status for Frame %d...\n", current_ack);
        
        // Simulate network loss condition
        if (current_ack == lost_frame && !loss_simulated) {
            printf("[Network] !! ERROR !! Frame %d was LOST or CORRUPTED.\n", current_ack);
            printf("[Receiver] Out of order/Missing frame! Dropping everything else.\n");
            printf("[Sender] !! TIMEOUT !! No ACK received for Frame %d.\n", current_ack);
            printf("[Sender] Going Back N -> Resetting window to Frame %d\n\n", current_ack);
            
            // Go-Back-N Loss Recovery Adjustment
            next_frame_to_send = current_ack; 
            loss_simulated = true; // Clear error flag so retransmission succeeds
        } else {
            // Successful transmission and window slide
            printf("[Receiver] Frame %d received successfully. Sending ACK %d\n", current_ack, current_ack + 1);
            printf("[Sender] ACK %d received. Sliding window forward.\n\n", current_ack + 1);
            current_ack++;
        }
    }

    printf("--- Transmission Completed Successfully ---\n");
    printf("Total successful frames: %d\n", total_frames);
    printf("Total frame transmission attempts (including retransmissions): %d\n", total_transmissions);

    return 0;
}

