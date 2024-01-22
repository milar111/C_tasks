#include <stdio.h>

unsigned char house = 0;

void switch_lights(int room) {
    house |= (1 << (room - 1));
// unsigned char light1 = 1 << 0; //0000 0001
// unsigned char light2 = 1 << 1; //0000 0010
// unsigned char light3 = 1 << 2; //0000 0100
// unsigned char light4 = 1 << 3; //0000 1000
// unsigned char light5 = 1 << 4; //0001 0000
// unsigned char light6 = 1 << 5; //0010 0000
// unsigned char light7 = 1 << 6; //0100 0000
// unsigned char light8 = 1 << 7; //1000 0000
}

void print_room() {
    printf("Rooms: ");
    for (int i = 0; i < 8; i++) {
        if (house & (1 << i)) {
            printf("%d ", i + 1);
        }
    }
}

#include <stdio.h>

int main(void) {
    int choice; 
    int room;

    while (1) {
        printf("1. Switch lights\n2. Print room number\n1/2: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Room: ");
            scanf("%d", &room);
            switch_lights(room);    
        } else {
            print_room();
    }

    }
}

