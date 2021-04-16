#include <stdio.h>
#include <time.h> // Time function.
#include <stdlib.h> // Random number generator functions.
#include <string.h>

/**
 * Simulates shuffling a deck of playing 52 cards each time the user
 * hits Enter. Creates a deck of playing cards by defining a "card" structure
 * and storing "card" structures in an array. Shuffles and displays the deck.
 * NO jokers.
 *
 * Uses strings as a char array and a char* array.
 *
 * To compile this file alone:
 *   % gcc cards.c
 * To run:
 *   % ./a.out
 *
 * @modified_author Robert Sterenchak
 * @author Ed Meyer
 * @original_author William Albritton
 */

#define MAX 9 // The max length of a suit: Diamonds + '\0'
#define MAX_CARDS 52
#define MAX_RANKS 13
#define MAX_SUITS 4
#define COLS 1 // Number of columns to display in output.

/**
 * A playing "card" structure.
 * Stores the following attributes of a single playing card:
 *   1) rank: The number or face (Ace, King, Queen, Jack)
 *   2) suit: Clubs, Diamonds, Hearts, Spades.
 */
struct card {
  char *rank;
  char suit[MAX];
  char *color;//Added to allow color be a part of the card struct - modified author
};
// Declares Card as an alias/synonym for struct card.
typedef struct card Card;

// All possible ranks a playing card can have.
char *ranks[MAX_RANKS] = {"Ace", "Two", "Three", "Four", "Five",
                          "Six", "Seven", "Eight", "Nine", "Ten",
                          "Jack", "Queen", "King"};

// Two-dimensional array of strings for suits.
// All possible suits a playing card can have.
char suits[MAX_SUITS][MAX] = {"Clubs", "Diamonds", "Hearts", "Spades"};

char *colors[2] = {"(Black)","(Red)"};//All Possible colors for each suit and rank - modified author


/** Function prototypes */
void initialize(Card []);
void shuffle(Card []);
void display(const Card[]);

int main() {

  char newline = '\n'; //to repeat while loop
  
  // Declare an array of 52 cards.
  Card deck[MAX_CARDS] = {"", ""};
  
  // Populate the deck.
  initialize(deck);
  printf("Display an ordered deck of cards:\n");
  display(deck);
  
  // Keep shuffling and displaying the deck each time the user hits Enter.
  // End the program when the user enters anything else.
  while ('\n' == newline) {
    printf("\nshuffling deck ... \n");
    shuffle(deck);
    display(deck);
    printf("\nWould you like to shuffle again?\nIf so, press \"Enter\" key. ");
    printf("If not, press any other key. ");
    newline = getchar();
  }
  
  return 0;
}

/**
 * Initializes a playing card deck of 52 cards.
 * Sets the rank and suit of each card in deck[].
 * Creates all the Clubs, then Diamonds, then Hearts and finally Spades cards.
 * (Essentially in the order of suits[].)
 *
 * @param deck[] An array of cards to initialize.
 */
void initialize(Card deck[]) {
  int i = 0;
  
  // Loop through the deck.
  for (i = 0; i < MAX_CARDS; i++) {
    // i % MAX_RANKS to cycle through each possible rank.
    deck[i].rank = ranks[i % MAX_RANKS];
    // i / MAX_RANKS to keep the same suit for each card in a suit.
    strncpy(deck[i].suit, suits[i / MAX_RANKS], MAX);

    if((strcmp(deck[i].suit, suits[0]) == 0)){//Performs comparison of suits for Clubs 
      deck[i].color = colors[0];//Assigns Black 
    }
    if((strcmp(deck[i].suit, suits[1]) == 0)){//Performs comparison of suits for Diamonds
      deck[i].color = colors[1];//Assigns Red
    }
    if((strcmp(deck[i].suit, suits[2]) == 0)){//Performs comparison of suits for Hearts
      deck[i].color = colors[1];//Assigns Red
    }
    if((strcmp(deck[i].suit, suits[3]) == 0)){//Performs comparison of suits for Spades
      deck[i].color = colors[0];//Assigns Black
    }
  }
}

/**
 * Shuffles the deck (an array of cards).
 * Uses the pseudo-random number generator to shuffle the cards.
 * Loops through the entire deck and makes random swaps.
 *
 * @param deck[] An array of cards to shuffle.
 */
void shuffle(Card deck[]) {

  // Index of the card to be swapped.
  int swapper = 0;
  // Loop increment variable.
  int i = 0;
  // Temp holding place for the swap.
  Card temp = {"", ""};
  
  srand(time(NULL)); // Seed the random generator.
  
  // Loop through the deck and make random swaps.
  for (i = 0; i < MAX_CARDS; i++) {
  
    // Generate a pseudo-random number from 0 to 51 for the index.
    swapper = rand() % MAX_CARDS;
    
    // Make the swap.
    temp = deck[i];
    deck[i] = deck[swapper];
    deck[swapper] = temp;
  }
}

/**
 * Prints the contents of the deck (an array of cards) in columns.
 * Default: 3 columns (Change COLS to change the number of columns)
 *
 * @param deck[] An array of cards to be printed.
 */
void display(const Card deck[]) {
  int i = 0;
  for (i = 0; i < MAX_CARDS; i++) {
    printf("%5s of %-s %s", deck[i].rank, deck[i].suit, deck[i].color);
    // Every COLS (3) cards print a newline to separate.
    if (0 == ((i + 1) % COLS)) {
      printf("\n");
    }
  }
}
