<h1 align="center">
 Cub3D
</h1>

<h2 align="center">
 Introduction
</h2>
<p>This project is part of the 42 school curriculum, aimed at creating a basic raycasting engine reminiscent of the classic game Wolfenstein 3D.
  
  In this project, you will find the source code for a simple raycasting engine implemented in C. The engine uses raycasting principles to render a 3D perspective from a 2D map. This project was developed as a learning exercise to understand the fundamentals of raycasting, graphics programming, and optimization techniques.</p>

  <h2 align="center">
 Features
</h2>

> Raycasting engine rendering a 3D perspective

> Texture mapping

> Player movement and collision detection

> Configurable map layout using a simple file format


  <h2 align="center">
 To Run
</h2>

At the root of the project
<pre>
$> make 
./cub3D maps/[map_name].ber
</pre> 

The game ends when the player gets all the collectibles and goes to the exit.

 <h1 align="center">
 How to make your own map
</h1>

> Create a map with any form with 0s and 1s, where 0 is floor and 1 is wall, in a .cub file.

> The map must be closed by walls.

> Place just 1 character N, S, W, or E, depending on which orientation you want the player to start, somewhere on the map for the player's starting position.

> NO [path_to_north_texture]

> SO [path_to_south_texture]

> WE [path_to_west_texture]

> EA [path_to_east_texture]

> F [color_code_for_floor]

> C [color_code_for_celling]

