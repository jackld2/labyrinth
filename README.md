# LABYRINTH
![alt text](https://github.com/uiuc-sp18-cs126/final-project-jackld2/blob/master/bin/data/31a702439966e98edb7984a9db7d00ff.png "Labyrinth")

Labyrinth is a randomly generated, skill based, dungeon crawling, shooting game. You are placed in a random room in a 'Labyrinth'. There are doors on all four sides of these square rooms. Be sure to pick up the weapon provided in the first room. Every weapon is randomly generated with different bullet speeds, damages, bullet sizes/hitbox sizes, and bullet limits. Bullets can be shot in all four directions and your momentum as the player is added to the bullet's trajectory. Explore the labyrinth and kill the monsters, each room may or may not spawn a weapon, and there is a small chance of a boss room spawning which is high difficulty but high reward. Press M to see where you are and how many rooms you have traveled. You will see the map can extend for hundreds of rooms (over 800) and the final room can be any one of these rooms. Actually, you can go beyond 800 rooms, you just wont apear on the map anymore (this can be fixed in the future).

# How to play the game
It is simple, just pick up weapons and shoot monsters, your goal is to search for the end room of the labyrinth. When you reach it, you win. All rooms are continuous so leaving objects behind and coming back for them later is fine. This game will generate an infinite amount of rooms, so you can walk in one direction for a very long time. I have not tested how far you can go before the game breaks down, but it is probably a large amount of rooms. Everything is generated in real time as well, the only thing determined beforehand is the coordinate of the final room. Each room is generated as you walk into it. Press 'P' to enter a type of cheat mode where you cannot die and can travel rooms freely without having to kill monsters. Press 'O' to go back to normal mode.



# How to build:

The game runs in open frameworks using ofXGUI, and some other standard openframeworks libraries like ofImage and ofVec2f. There is really not a lot to the game besides that. Just a lot of vector calculations, hitbox checking, and image/text loading. Be sure to include the images in 'bin/data' file to work the game. This game is modular, meaning you can add as many images for weapons, bullets, rooms, and monsters. Put them all in the bin. I reccommend using the following image dimensions.
## Monster Images: 100x100
## Weapon Images: 100x100
## Bullet Images: 100x100
## Player Images: 100x100
## Room Images: 1200x1200 (the traversable room is 1024x1024 with a border for walls, so keep that in mind)
The whole has to run in 1920x1080 resolution, so also keep that in mind.

Every file in 'src' is needed in order for this game to run properly. A few files worth noting are 'Generation', 'Randomize', and 'Imageload'.

## Randomize:
Contains modifiable functions that tune the probabilites of the game and the stats weapons and monsters. Tune the range parameters after reading the commments explaining each function.

## ImageLoad:
This contains functions for getting the images that are loaded into the game. Note the vectors of image file name strings at the top feel free to add as many as you like, for they will all be loaded into the game then, however, be sure to tune the paramenters of the possible vector indexes in 'Randomize' accordingly

## Generation:
This contains functions that randomly generate every object in the game. New types of rooms can be created with different probabilities, different monsters, or whatever. The point is the game is very modular and it should not be hard to add new things.






