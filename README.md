# cube3d

About the Project

Cub3D is a beginner-level 3D raycasting project designed to enhance skills in C programming, algorithm development, and graphical design. Using the MinilibX, it introduces the basics of rendering 3D scenes, exploring practical applications of mathematical concepts without delving deeply into their complexities.

Key Objectives

	•	Develop rigorous programming habits and adhere to the Norm coding standard.
	•	Manage memory efficiently and avoid leaks.
	•	Implement a basic 3D rendering engine using raycasting techniques.
	•	Parse and validate a .cub configuration file to define the 3D scene.
	•	Ensure robust error handling and program stability.

Core Features

	1.	3D Rendering: Create a first-person view of a maze-like structure using raycasting.
	2.	Texturing:
	•	Different textures for walls based on orientation (north, south, east, west).
	•	Floor and ceiling colors defined in RGB format.
	3.	User Interactions:
	•	Camera rotation using arrow keys.
	•	Movement using W, A, S, D.
	•	Graceful program exit with ESC or window close button.
	4.	Configuration File:
	•	Define textures, colors, and map layout.
	•	Ensure maps are enclosed by walls and follow strict parsing rules.

Bonus Features

Available only if the mandatory part is fully functional:
	•	Wall collision detection.
	•	Mini-map display.
	•	Interactive doors (open/close functionality).
	•	Animated sprites.
	•	Mouse-controlled camera rotation.

Technical Details

	•	Language: C
	•	External Libraries: MinilibX, Math library (-lm)
	•	Build: Includes a Makefile with standard targets (all, clean, fclean, re, bonus).
	•	Error Handling: Explicit error messages for configuration issues.

Getting Started

	1.	Test the original inspiration: Wolfenstein 3D.
	2.	Clone the repository and build the project using the provided Makefile.
	3.	Launch the program with a .cub configuration file as the argument.

 ## Contributors

Thanks my amazing contributor for his help!

- [@maxmart26](https://github.com/maxmart26)
