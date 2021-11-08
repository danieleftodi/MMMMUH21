#include <stdio.h>

#define SUIT 0;

enum suit
{
    hearts=10,
    spades,
    clubs,
    diamonds,
}cards;

// Returns "Hearts", "Spades" etc
const char* get_suit(enum suit a_suit);

//const char* get_suit2(enum suit a_suit);  // dåligt exempel

int main(){
    
    enum suit cards = diamonds;

    //printf("Cards: %d\n", cards);
    //printf("Kortet är av typen: %s\n", get_suit(cards));

    for(int kort = hearts; kort <= diamonds; kort++){
        printf("Kortet är av typen: %s\n", get_suit(kort));
    }

    return 0;
}

const char* get_suit(enum suit a_suit){
    char* suit_name ="";

    switch (a_suit)
    {
    case hearts:
        suit_name = "Hearts";
        break;
    case spades:
        suit_name = "Spades";
        break;
    case diamonds:
        suit_name = "Diamonds";
        break;
    case clubs:
        suit_name = "Clubs";
        break;
    default:
        suit_name ="unkown";
        break;
    }

    return suit_name;
}

/* // Exempel på hur man inte ska använda enum då detta inte kommer att 
    // fungera om man ger enumerationerna andra värden än default.
const char* get_suit2(enum suit a_suit){
    char* suit_strs[] = {"Hearts", "Spades", "Clubs", "Diamonds", "unknown"};
    return suit_strs[a_suit];
} */
