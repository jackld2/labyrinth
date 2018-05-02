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

# Week 2 Update Report: 4/29
I have learned that making a game without a game engine takes a large amount of work. From making hitboxes/barriers to simple physics, it is a lot of work. I have forced the game to run in a 1920x1080 window at 60fps for my own sanity. Of course it would be ideal for the game to resize to the window, but the HUD and UI would take even more work to implement.

After much thought on how to create enemies with some type of intelligence, I created a simple solution. Monsters move in the same way that the player moves. It is based on 4 boolean direction values. UP, DOWN, LEFT, RIGHT. As the player presses WASD these bools adjust accordingly. The monster operates with these same bools but I found that randomly generating a sequence of 4 bools creates enough random movement to give the monsters a bit of life. They change direction every time they shoot, and the monster shoots every time they move a given distance.

There are two major flaws in this AI without a bit of fixing however. First, a randomly generated string of 4 bools has a 1/16 chance of producing 4 falses, which means the monster is stuck. Since direction change depends on the monster shooting and shooting depends on moving, you can see that this causes a problem. Monsters would also become stuck if they run into a wall. Fortunatley, fixing this was simple by adding a distance_moved variable to each monster, and implementing an isFroze() boolean function that is called during every monster update. The monster fires at the player with pretty decent accuracy by some simple vector subtraction. Normalize(PlayersCurrentPosition - MonsterPosition) yeilds a direction vector straight from the monster to the player, which is then scaled and modified for speed.

Another thing that I added was momentum to the bullets from both the player and the monsters. The players current direction and speed will be added to the bullets direction and speed during firing. It works incredibly well and adds a level of polish to the player control. I decided to remove backwards momentum subtraction from bullets due to bullets traveling and super slow speeds and sometimes even getting stuck in mid-air. However, if you run forward and shoot, your bullet travels faster, and if you run sideways and shoot, your bullets also have your sideways momentum.

Now for the main point of this game: the random generation. I implemented an array of rooms. Each room has a coordinate based on a simple x,y plane. For example, the starting room is (0,0). Now, the player can move in any direction, up,down,left,right. If they choose to go up frome the starting room, the array is searched for (0,1). If it exists, it is loaded. If not, the rooms is entirely randomly generated and added to the array of rooms. This means that there is a potentially infinite amount of rooms in the game (before you run out of memory), and no two rooms will be alike.

Each room generates monster, each with random speeds, bullet speeds, bullet fire rates, damages, monster sizes, and bullet sizes. Each room also may spawn a weapon with the same random attributes (speed, bullet size, damage). The player weapons also have a firing ammo system that limits the amount of bullets that can be in the room which is also randomly generated. This is displayed by the HUD on the right that shows the amount of bullets you can fire which dynamically changes with how many bullets are in the room. 

I also implemented a map for the player to see what room they are in, and how many rooms they have explored. There is total continutity between rooms, meaning that if you drop a weapon or shoot a bullet in room (0,0) or example, and come back to in 10 rooms later, that bullet or weapon will still be there waiting for you.

My goal with this game was to create something that felt kind of large and infinite with simple tricks like random generation and rooms. I think I succeeded to some degree. However, another goal was to make the code extremely modular. My randomization functions can be tuned at any time to play with literally every aspect of the game. Even the images of the rooms, bullets, monsters, and weapons can be randomly generated if you wanted to add many different pictures.

# Finishing Up: 05/02/18
Even making a simple HUD is pretty tedious, at least in openframeworks, but I am happy with the way it turned out. I know we are not supposed to use  'Magic Numbers' but when it comes to placing text and pictures in very specific places, I cannot see it being worth my time to create an int constant for every single coordinate. In any case, the HUD turned out well.

The final features I added was a boss system and a win room. The win room is simple. The map display roughly 800 rooms, so within these 800ish rooms one of them will be set as the 'win' room. If you find this room, you win. However, you must search for it, and you cannot leave a room unless you defeat every monster inside. As for the boss room, there is about a 5% chance of a boss room spawning. Inside this room is a single strong boss, and a weapon that has higher stats than normal. Also, I reduced the probability of weapons spawning in normal rooms to around 30%. 

# Final Words

I think I succeeded with my goal of making the game feel large for what it is, and I believe that I made it extremely modulur, meaning that new systems can be implemented easily, and adding new art assets is literally as easy as adding a text file name to an array, and adjusting an index parameter. You could in theory add hundreds of different weapon images, room images, bullet images, and monster images. No two rooms will ever be the same difficulty or spawn the same weapons (or rather the chances are extremely small). I am happy with what I created and this is probably the most complex program I have ever made. It has been great experience. 




