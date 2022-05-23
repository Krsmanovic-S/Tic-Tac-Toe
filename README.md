# Tic-Tac-Toe
 A simple game of Tic-Tac-Toe created with C++ and the SFML Library using VS Code.

![game_screenshot](https://user-images.githubusercontent.com/103185975/169864746-a6c1af1a-2130-412e-862c-2e9c7fa1e8bc.PNG)

--------------------------------
**Features:**

- Play as both X and O

- Play versus the computer or versus another player

- Reset/Change what symbol you are playing at any given time

- Unbeatable AI that plays using the Minimax Algorithm

--------------------------------
 The settings/workspace I used for compiling:
  
    Compiler     ---> GCC 7.3.0
    
    C++ Standard ---> C++17
    
    IDE          ---> Visual Studio Code
    
--------------------------------
You will need this **exact version of GCC** to compile the code if you are using VS Code like I am. For Visual Studio, you will need to download the SFML library and connect it to the project settings in the IDE (include path + link path). As for GCC, you will need to set it up as your compiler if you do not have it already. Note that you do not need to download SFML if you will be using this in VS Code, everything is set up in the project files already.

**Commands to clone, build and run the project:**

    mingw32-make.exe ---> Command to build the project
    
    ./main.exe       ---> Command to run the game
    
    git clone --recursive https://github.com/Krsmanovic-S/Tic-Tac-Toe

--------------------------------
Links to download required files:

    GCC  ---> https://gcc.gnu.org/install/download.html
    
    SFML ---> https://www.sfml-dev.org/download.php
