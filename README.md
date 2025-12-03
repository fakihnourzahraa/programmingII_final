# Documentation

# Project Description

    The project is a 2D video game made using a library (minilibx) for graphics. 
    The program has three components: makefile, header file, source code.
    After creating the executable, the user may run the program with a map of their choice (.ber file), there's a folder with available maps.

# Data structures and important variables
    Theres a struct for each piece of the game.The textures structure contains void pointers to all textures or visual components of the game. The player structure contains the index, number of collected items, frame, moves, and animatation tick. Lastly, the map structure contains grid, row, col, and total collectibles needed. These are all contained in the game structcure itself. It includes the mlx and win (window) pointer, the textures, map, and player variables. These are all used to appropriately divide the variables, and make it much easier to acces the data from wherever needed, and pass them easily to other functions.

# Main functions
    The program is divided into 3 parts. Parsing, which includes error handling and filling structs, the mlx loop, which includes handling input during game, and memory managment.
   # Main 
    This function handles invalid input, and then calls all the other main functions we wrote, then it plays the mlx loop. 
   # ft_all_map_valid
    This functions handles parsing of the actual file and filling it in the map and game structure
   # ft_draw_map
    Fills background with the tiles texture, then draws player and counter
   # ft_handle_keypress
    Handles input (letters and arrows) and if valid, moves the player accordingly

# Compiling
    To simplify compiling, a makefile is added. There are 2 main options on the makefike.
        1. all: creates all objects and executable
        2. clean: deletes objects and executable
    The executable is called final
    To run: ./final maps/map.ber
    Pick map level, else create your own map.
    The map needs to be a rectangle, surrounded by walls (1) with at least 1 reachable collectible (C), exactly 1 player (P) and the rest of the spaces are character 0. However, due to the minilibx library, this program can only be compiled on linux devices.