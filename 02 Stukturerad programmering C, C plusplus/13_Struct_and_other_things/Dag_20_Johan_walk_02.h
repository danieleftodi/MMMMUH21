//
//  Dag_20_Johan_The_300_lines_of_code_samle_to_digest__walk_02.h
//  Dag_20_Johan_The_300_lines_of_code_samle_to_digest__walk_02
//
//  Created by Daniel Eftodi on 2021-11-01.
//

#ifndef Dag_20_Johan_walk_02_h
#define Dag_20_Johan_walk_02_h

/* INCLUDES */

#include <climits>
#include <ctime>
#include <iostream>
#include <random>
#include <string>

#ifdef __WIN32__
#include <Windows.h>
#else
#include <unistd.h>   // system(clear);
                      // sleep($SECS);
#endif

/* DEFINITIONS */

// ENABLE-DISABLE debug logging
#define DEBUG_LOGGING false

int DBG_Counter = 0;

/* DECLARATIONS */

/**
 * DUNGEON: a simple game for the terminal. The objective of the
 * game is that the player ("P") reaches the treasure ("X")
 * avoiding the traps ("T") and the bandits ("B").
 * Bandits move randomly each turn.
 * */
int  NUMBEROFTRAPS   = 3;
int  NUMBEROFBANDITS = 2;

/*
 * Array to buffer our output
 */
char currentToRender[10][10];

/*
 Struct info: https://stackoverflow.com/questions/11516657/c-structure-initialization
*/
// Represents a place in the board.
// xPosition is the x-axis index and yPosition is the y-axis index
struct Location {
    int xPosition;
    int yPosition;
};

// Represents the player.
// It is guaranteed Player position is in the board.
// Position is altered through function movePlayer.
struct Player {
    Location position;
    char symbol = 'P';
    std::string name = "player";
};

// Represents traps on the board
// It is guarateed Trap position is in the board.
struct Trap {
    Location position;
    char symbol = 'T';
};

// Represents Bandits moving around the map.
// Position is altered through funtion moveBandit.
struct Bandit {
    Location position;
    char symbol = 'B';
};

// Represents the treasure.
// The game ends as soon Player.position == Treasure.position
struct Treasure {
    Location position;
    char symbol = 'X';
};

// Represents the board.
struct {
    int xDimension;
    int yDimension;
} board = {.xDimension = 10, .yDimension = 9};

// Represents the world.
struct World {
    
    // Represents Bandits moving around the map.
    // Position is altered through funtion moveBandit.
    struct Bandit {
        struct Location position;
        char symbol = 'B';
    } Bandit;
    
    // Represents the board.
    struct Board {
        int xDimension;
        int yDimension;
    } Board = {.xDimension = 10, .yDimension = 9};
    
    // Represents a place in the board.
    // xPosition is the x-axis index and yPosition is the y-axis index
    struct Location {
        int xPosition;
        int yPosition;
    } Location;
    
    // Represents the player.
    // It is guaranteed Player position is in the board.
    // Position is altered through function movePlayer.
    struct Player {
        struct Location position;
        char symbol = 'P';
        std::string name = "player";
    } Player;
    
    // Represents traps on the board
    // It is guarateed Trap position is in the board.
    struct Trap {
        struct Location position;
        char symbol = 'T';
    } Trap;

    // Represents the treasure.
    // The game ends as soon Player.position == Treasure.position
    struct Treasure {
        struct Location position;
        char symbol = 'X';
    };
} worldDungeon;


// Possible directions. WRONG_DIRECTION is used to report incorrect input
enum Direction { RIGHT, LEFT, TOP, BOTTOM, WRONG_DIRECTION };
enum Result { VICTORY, DEFEAT };


/* FUNCTIONS */

/* FUNC :: Walk_Main
 
 This is the main function where the game starts from.
 
*/
void Walk_Main(void);


/* FUNC :: drawBoard
 
 in Player     player
 in Trap       totalTraps[]
 in Bandit     totalBandits[]
 in Treasure   treasure
 
 Draws a (board.xDimension * board.yDimension) grid.
 Elements are drawn using .location.?Dimensions.

 Precondition: 0 <= Player.xPosition <= board.xDimension &&
      0 <= player.position.yPosition <= board.yDimension  &&
      board.xDimension > 0  && board.yDimension > 0 &&
 Postcondition: The grid has been drawn.
      All elements have been drawn.
      If the player is in the same square than the treasure,
      the game ends with victory.
      If the player is in the same square than a bandit or
      a trap, the game ends with defeat.
 */
void drawBoard(Player     player,
               Trap       totalTraps[],
               Bandit     totalBandits[],
               Treasure   treasure);

/*
 * As drawBoard(), but draw to a buffer,
 * currentToRender[10][10], instead.
 */
void drawBoard2(Player     player,
                Trap       totalTraps[],
                Bandit     totalBandits[],
                Treasure   treasure);

/* FUNC :: askDirection
  
 Asks the user to input a direction and returns it.
 
 Precondition: -
 Poscondition:
 Return: a Direction value containing the direction chosen or
 WRONG_DIRECTION.
*/
Direction askDirection();


/* FUNC :: movePlayer
 
  inout Player      &player     // Player of the game
 
  in    Direction   direction   // Direction previously chosen.
                                // It is represented by a Direction object,
                                // different from WRONG_DIRECTION.
 
 Moves player in the chosen direction, by altering its coordinates.
 If the player would finish out of the board, no movement is made.

 Precondition: 0 <= Player.xPosension <= board.xDimension &&
        0 <= player.position.yPosition <= board.yDimension  &&
        board.xDimension > 0  && board.yDimension > 0 &&
        direction in {LEFT; RIGHT; TOP; BOTTOM} &&
 Postcondition: player coordinates have been altered &&
        player remains inside the board.
*/
void movePlayer(Player &player,
                Direction direction);


/* FUNC :: moveBandit
 
  inout   Bandit &bandit    // Player of the game
                            // It is represented by a Direction object,
                            // different from WRONG_DIRECTION.

 Moves player in the chosen direction, by altering its coordinates.
 If the player would finish out of the board, no movement is made.

 Precondition: 0 <= Player.xPosension <= board.xDimension &&
        0 <= player.position.yPosition <= board.yDimension  &&
        board.xDimension > 0  && board.yDimension > 0 &&
        direction in {LEFT; RIGHT; TOP; BOTTOM} &&
 Postcondition: player coordinates have been altered &&
        player remains inside the board.
*/
void moveBandit(Bandit &bandit);


/* FUNC :: moveCharacter
 
 in     char        cCharacter  // (P)layer || (B)andit
                                
 inout  World       &world      // Player of the game
 
 in     Direction   direction   // Direction previously chosen.
                                // It is represented by a Direction object,
                                // different from WRONG_DIRECTION.
 
 Moves any character (Player or Bandit) in the chosen direction,
 by altering its coordinates.
 If the player would finish out of the board, no movement is made.
 
 Precondition:
 */
void moveCharacter(char cCharacter,
                   World &world = worldDungeon,
                   Direction direction = WRONG_DIRECTION);


/* FUNC :: endGame

  in    Result  result  // Result of the game.
                        // It is either VICTORY or DEFEAT
 
 Cleans screen, prints a good bye message and ends the game.
 
 Precondition: a condition for ending the game has been found.
              Either player.position == bandit.position ||
              player.position == trap.position [DEFEAT]
              or player.position == treasure.position [VICTORY]
 Poscondition: game is ended. Greeting message is printed.
*/
void endGame(Result result);


/* FUNC :: clearScreen
 
 POSIX compilant way of clearing the screen on any OS
 
*/
void clearScreen(void);


/* FUNC :: delay
 
 POSIX compilant way of clearing the screen on any OS
 
 */
void delay(int iDelayTime);

#endif /* Dag_20_Johan_walk_02 */
