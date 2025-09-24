#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SHAPE_COUNT 5
#define LINE_SIZE 40
#define TRUE 1
#define FALSE 0

const char *KNOWN_SHAPES[SHAPE_COUNT] = {"🪨  ", "🗒️ ", "✂️  ", "🖖 ", "🦎 "};

const char WELCOME_MESSAGE[] = "Welcome to 🪨  🗒️  ✂️  🖖 🦎!\n";
const char WIN[] = "Congratz! You won the round!\n";
const char LOSE[] = "WahWah, you lose the round!\n";
const char DRAW[] = "This a draw!\n";

int beats(int player, int computer) { // making a variable for what beats what
  if (player == computer)
    return 0;

  if ((player == 0 && (computer == 2 || computer == 4)) || // 🪨 beats ✂️ and 🦎
      (player == 1 && (computer == 0 || computer == 3)) || // 🗒️ beats 🪨 and 🖖
      (player == 2 && (computer == 1 || computer == 4)) || // ✂️ beats 🗒️ and 🦎
      (player == 3 && (computer == 0 || computer == 2)) || // 🖖 beats 🪨 and ✂️
      (player == 4 && (computer == 1 || computer == 3))) { // 🦎 beats 🗒️ and 🖖
    return 1;
  }
  return -1;
}

void game() { // making the game itself
  int choice;
  int playerscore = 0;
  int computerscore = 0;
  printf("Starting Best of 3!\n");
  while (playerscore < 2 &&
         computerscore < 2) { // keeps looping until there is a victor.
    printf("\nPick a shape!:\n");
    for (int i = 0; i < SHAPE_COUNT; i++) {
      printf("\n%d: %s\n", i,
             KNOWN_SHAPES[i]); // shows all the different options to chose from.
    }
    printf("5: Return to Main Menu\n");
    scanf("%d", &choice);
    if (choice == 5) {
      printf("Returning to Main Menu:\n");
      break;
    }
    if (choice < 0 ||
        choice >=
            SHAPE_COUNT) { // if you choose a shape that isn't part of the game.
      printf("You can't choose that!\n");
      continue;
    }

    int computer =
        rand() % SHAPE_COUNT; // makes the computer use random numbers.
    printf(
        "You %s | Computer:%s\n",
        KNOWN_SHAPES[choice], // shows what the player and the computer picked.
        KNOWN_SHAPES[computer]);
    int result = beats(choice, computer);
    if (result == 1) {
      printf("%s", WIN);
      playerscore++; // gives the player 1 point if they won
    } else if (result == -1) {
      printf("%s", LOSE);
      computerscore++; // gives the computer 1 point if they won
    } else {
      printf("%s", DRAW); // prints draw if its a draw, no points giving.
    }
    printf("Score: You %d - %d Computer\n", playerscore,
           computerscore); // prints the score after the duel.
  }
  if (playerscore == 2) {
    printf("Eyooo!!! You just won the game CHAMP!\n"); // player won
  } else if (computerscore == 2) {
    printf("WAAAH!!! Goddamn, I can't believe you just lost to a computer "
           "xd\n"); // computer won
  }
}
int main() {
  srand(time(
      NULL)); // makes sure the numbers are random everytime the program starts.
  int MENU_CHOICE;
  printf("%s", WELCOME_MESSAGE);
  while (TRUE) { // prints the main menu.
    printf("\n=== MAIN MENU ===\n");
    printf("1: Start Game (Best of 3)\n");
    printf("2: Exit\n");
    printf("Choose an option: ");

    scanf("%d", &MENU_CHOICE); // respond what you want.

    ;
    if (MENU_CHOICE == 1) { // start game if player types 1
      game();
    } else if (MENU_CHOICE == 2) { // ends game and program if player types 2
      printf("Another day i guess...");
      break;
    } else {
      printf("Invalid option...");
    }
  }
  return 0;
}