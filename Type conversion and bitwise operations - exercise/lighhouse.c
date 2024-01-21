#include <stdio.h>

unsigned char light1 = 1 << 0; //0000 0001
unsigned char light2 = 1 << 1; //0000 0010
unsigned char light3 = 1 << 2; //0000 0100
unsigned char light4 = 1 << 3; //0000 1000
unsigned char light5 = 1 << 4; //0001 0000
unsigned char light6 = 1 << 5; //0010 0000
unsigned char light7 = 1 << 6; //0100 0000
unsigned char light8 = 1 << 7; //1000 0000

unsigned char house = 0;

void switch_lights(int room) {
    unsigned char *lights[] = {&light1, &light2, &light3, &light4, &light5, &light6, &light7, &light8};
    house ^= *lights[room - 1]; 
}

void print_state() {
    printf("The light is on in rooms: ");
    for (int i = 0; i < 8; i++) {
        if (house & (1 << i)) { 
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}

int main() {
    int choice, room;
    while (1) {
        printf("1. Switch lights\n2. Print state\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter room number (1-8): ");
                scanf("%d", &room);
                switch_lights(room);
                break;
            case 2:
                print_state();
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
