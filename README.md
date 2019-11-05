# Battle of wits

## Description
This project is a round by round card game that runs in the console. It's a Computer vs Computer game. The user chooses the number of players and starts the game. Only one of the players will be victorious.

Several versions of the game exist:
1. Version 0 : it's the base version of the game. Each player have a hand of 5 cards and plays 1 card then draw a card from his deck. We suppose that the deck is limitless. Each card have a degree of power which is inversely proportional to the likelihood of drawing it from the deck. Each card have effects: it can remove life points from an opponent or increase the life points of the one who played it.

2. Version 1 : In this version, we enhance the Version 0 by using a doubly linked queue to manage the deck and the hand of the player.

3. Version 2 : In this version, We add an arena where the players will occupy a place throughout the game. After playing a card, each player will move by a defined number of steps. We also introduce new cards that can create impassable walls on the arena. If a player is trapped between four walls, he dies.

4. Version 3 : In this version, We add new cards that enable a player to create clones of himself and put them in the arena. Each round, these clones will attack their parent's opponents.

## Commands

to compile the game :
```bash
make
```
to execute the game:
```bash
./projectB   (version 0)
./projectA1  (version 1)
./projectA2  (version 2)
./projectA3  (version 3)
```

