# 2048 SDL2 Game

## Description
This is a 2048 puzzle game project developed in C using SDL2. It was created as part of a university project at the University of Science and Technology Houari Boumediene (USTHB), Algiers, Algeria. The game is fully graphical and includes different modes such as Player mode, Machine mode, and Machine vs Player mode.

## Game Description
The classic 2048 game is a sliding puzzle where you combine tiles with the same numbers to reach the 2048 tile. This project expands the concept by offering a complete graphical interface, save/load functionality, machine-based simulation, competitive play, and sound effects.

When the player reaches the 2048 tile, a message is displayed and they can choose to either **continue playing** or **start a new game**.

## How to Play
The game can be played using the **keyboard or the mouse**.

You slide the tiles in four directions (up, down, left, right). When two tiles with the same number collide, they merge into one, and your score increases. The objective is to reach the 2048 tile.

After reaching 2048, the player can choose to continue playing for a higher score or start over.

The game also allows loading a saved game (matrix, score, player name, and time are preserved). When no more moves are possible, a “Game Over” message is displayed, and input is disabled.

## Game Modes
- **Player Mode**: The standard game mode. The player plays manually and can either start a new game or continue a previous one.
- **Machine Auto Mode**: The machine plays automatically using a built-in strategy.
- **Machine vs Player Mode**: Both the machine and the player play simultaneously on two separate matrices.
  - The first to reach **2048 wins**.
  - If neither reaches 2048 and no moves are left, the player with the **higher score wins**.

> Note: The machine does not cheat — it has no access to the internal logic or matrix. It simulates the game by reading the screen pixels to build its own version of the matrix.

## Controls

### Player Mode:
- **Keyboard**:
  - Arrow Keys: Move tiles
- **Mouse**:
  - Click on the four **on-screen arrow buttons** (↑, ↓, ←, →) to move the tiles in the respective directions

### Machine Mode:
- Fully automated — no controls required

### Machine vs Player Mode:
- Same controls as Player Mode for the human player
- Machine plays automatically

## Folder Structure
project-root/

│

├── # SDL DLLs (SDL2, SDL_ttf, SDL_image, SDL_mixer)

├── assets/ # Images, fonts, sounds 

├── src/

│ ├── include/ # Header files

│ │ └── SDL2/ # SDL2 headers

│ ├── lib/ # Source files (main.c, logic.c, draw.c, etc.)

│ ├── cmake/ # CMake config

│ └── pkgconfig/ # Package config files

├── Makefile # Makefile for build commands

└── README.md # Project documentation

## Files Description

- **main.c**: Entry point of the application, handles game flow and loop.
- **init.c / init.h**: SDL initialization and cleanup.
- **draw.c / draw.h**: Functions for drawing the game UI and menu.
- **logic.c / logic.h**: Core game logic (matrix manipulation, merging logic, etc.).
- **mods.c / mods.h**: Mode-specific logic (machine vs player, etc.).
- **global.c / global.h**: Global variables, constants, and shared data.

All `.c` files have corresponding `.h` headers located in `include/`, documenting constants, structs, and function prototypes.

## Dependencies List

- **SDL2** : Main graphics and input library — [install](https://www.libsdl.org/)
- **SDL2_image** : For loading image assets — [install](https://www.libsdl.org/projects/SDL_image/)
- **SDL2_ttf** : For rendering text — [install](https://www.libsdl.org/projects/SDL_ttf/)
- **SDL2_mixer** : For playing background music and sound effects — [install](https://www.libsdl.org/projects/SDL_mixer/)
- **mingw32 / gcc** : C compiler for building the project

## How to Build
Open a terminal or command prompt in the project root and run: **make**. If using Windows and make doesn't work, try: **mingw32-make**

## Authors
- Akniou Moahamed Achraf [GitHub](https://github.com/Zweihander-25)

## License
This project is licensed under the [MIT License](LICENSE).
