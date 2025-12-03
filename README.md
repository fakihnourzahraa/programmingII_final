# programmingII_final

# Project Description

The project is a 2D video game made using a library (minilibx) for graphics. 
The program has three components: makefile, header file, source code.
After creating the executable, the user may run the program with a map of their choice (.ber file), there's a folder with available maps.

# Data structures and important variables
Theres a struct for each piece of the game.The textures structure contains void pointers to all textures or visual components of the game. The player structure contains the index, number of collected items, frame, moves, and animatation tick. Lastly, the map structure contains grid, row, col, and total collectibles needed. These are all contained in the game structcure itself. It includes the mlx and win pointer, the textures, map, and player variables. These are all used to appriopriately divide the variables, and make it much easier to acces the data from wherever needed, and pass them easily to other functions.