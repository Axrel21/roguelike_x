#ifndef ROGUE_H
#define ROGUE_H

#include<ncurses.h>
#include<stdlib.h>
#include<time.h>

typedef struct Level
{
    char ** tiles;
    int level;
    int numberOfRooms;
    struct Room **rooms;
    struct Monster **monsters;
    int numberOfMonsters;
}Level;

typedef struct Position{
    int x;
    int y;
    // TILE_TYPE tile;
}Position;

typedef struct Room{
    Position position;
    int height;
    int width;
    
    Position **doors;
    //Monster ** monsters;
    //Items ** items;
}Room;

typedef struct Player{
    Position position;
    int health;
    //Room *room;
}Player;

typedef struct Monster
{
    char symbol;
    int health;
    int attack;
    int speed;
    int defence;
    int pathfinding;
    Position position;
}Monster;


int screenSetUp();

/* level/map functions */
Room ** roomsSetUp();
Level * createLevel();
char ** saveLevelPositions();

/* player functions */
Player * playerSetUp();
Position * handleInput(int input, Player * user);
int checkPosition(Position * newPosition, Player * user, char ** level);
int playerMove(Position * newPosition, Player * user, char ** level);

/* room functions */
Room * createRoom(int x, int y, int height, int width);
int drawRoom(Room * room);
int connectDoors(Position * doorOne, Position * doorTwo);

/* monster functions */
int  addMonsters(Level *level);
Monster * selectMonster(int level);
Monster * createMonster(char symbol, int health, int attack, int speed, int defence, int pathfinding);
int setStartingPosition(Monster * monster, Room * room);

#endif