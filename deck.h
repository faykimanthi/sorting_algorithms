#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * enum kind_e - This is the enumeration of card suits.
 * @SPADE: This represents spades suit.
 * @HEART: This represents hearts suit.
 * @CLUB: This represents clubs suit.
 * @DIAMOND: This represents diamonds suit.
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - This represents the playing card
 *
 * @value: This represents the value of the card
 * From "Ace" to "King"
 * @kind: This represents the kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - This represents the deck of card
 *
 * @card: This represents the pointer to the card of the node
 * @prev: This represents the pointer to the previous node of the list
 * @next: This represents the pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
