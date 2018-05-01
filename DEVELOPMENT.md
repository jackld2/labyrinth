# Intended game structure: What I want to get done in week 1
## Player
A player will be an object that can move in two dimensions, and shoot bullets in two dimensions. They will have a health value with a UI indicator, perhaps a level, and I hope to load an image to represent the player. Idealy this image will transform as the player moves so they are not just a sliding image.

## Weapons
The player will be able to pick up weapons, one at a time, and these weapons will have unique damage, bullet image representations, and bullet speeds.

## Monsters
I will start with implementing a single monster type to get the game in a working condition. If I have time, I will add more. Ideally the monster will move toward the player and hurt them when they touch.

## Room
A room will be an object with a unique image that is linked to other rooms. For the sake of testing I will build the game and test with a single room, intending to add a randomly generated map of rooms in week 2.


# Week 1 Update Report:
It was much harder to get get the player controller working than I expected. There are a lot of nuances when it comes to movement in openFrameworks. Overall, I did not get the base game working as intended, but I have a good roadmap now. I completed the player controller and succesfully implemented images that rotate based on player movement. I had trouble creating a barrier for the player because with my implementation the player would get stuck once they reached the edge of the screen. This is because the player would cease to update once they went out of bounds. The way around this was to split update for Player to update left, right, up, and down. This way I could only prevent an update in a single direction.

# Week 2: Roadmap
## Collisions
Plan on implementing collision for bullets, monsters, and the player. The bullets will need to be deleted once they leave the screen to prevent memory leaks.

## Screen Resizing and UI
I plan on keeping the game in a 1024x1024 window to keep the square shape of the room. This will mean I will need to recenter the entire game when you fullscreen. This will probabably be challenging and require a lot of calculation. The UI with player health and items will go on the left.

## Labyrinth with rooms and random generation
The last thing I want to start this week is to create a labyrinth object that generates new rooms every time you go in a specific direction. There will be randomized weapons, monsters, and hopefully random backgrounds. 

# Week 2 Update Report:



