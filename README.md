EarthShakerDS
-------------

EarthShakerDS is a remake of a Sinclair ZX Spectrum game written in 1990 by
Michael Batty.  It is similar to Boulderdash.  The objective of the game is to
collect all of the diamonds in each level, avoiding falling boulders, fires,
etc.


Menu System
-----------

When the game starts, a menu system appears on the top screen.  You can choose
to start from the beginning of the game ("Start"), select a level from the
level select menu ("Level Select"), play with the game's sound effects
("Sound Test") or try out the level editor ("Level Editor").  Navigate to the
desired option using the up and down buttons or the Select button.  You can page
through the options more quickly by using the left and right buttons.  When the
correct option is highlighted, press A or Start to select it.  The B button
returns to the previous menu if a submenu is currently active.


Gameplay
--------

Collect all of the diamonds in each level.  When all of the diamonds are
collected, a notification sound will play and the door - located somewhere in
the level - will start flashing.  Enter the door to end the level.  You can be
killed by:

 - Blocks landing on your head;
 - Walking into fire;
 - Running out of time.


Controls
--------

The d-pad moves around the level.  The X, Y, B and A buttons will poke the block
that is above, to the left, below and to the right respectively, without moving
the player sprite.  This means you can push boulders, collect diamonds, and so
on, that are next to you without moving.  This is a useful technique in some of
the levels.

If you make a mistake and get stuck, you can press L and R simultaneously to
commit suicide and restart the level.

Press Select to bring up a map screen and press Select again to switch back to
the game.  Note that you can only bring up the map screen once per life per
level, so only look at it when you need to.

Press Start to pause the game.  Press it again to unpause.  While paused,
pressing X exits the game and returns to the title screen.


Blocks
------

The following blocks can be found at various points in the game:

 - Bubbles can be pushed around.  They can be pushed into fires to extinguish
   the fires.  They can also be used to prop up boulders.
 - Boulders fall if not supported.  They can be pushed around.
 - Diamonds can be collected.
 - Fires will destroy boulders that land on them.  They can be extinguished by
   bubbles.
 - Jumping jelly beans give a time bonus.
 - Teleporters transport the player from one location to another.
 - Elixirs give an extra life.
 - Soil is removed when the player walks over it.
 - Wet soil behaves like normal soil, except it falls like boulders.  Wet soil
   landing on the player will not harm the player.
 - Gravity inverters switch the direction of gravity.  Boulders and other blocks
   landing on the player when gravity is inverted will not kill the player.
   Gravity remains inverted until the gravity timer runs out.  The direction of
   gravity and the remaining time are both displayed at the bottom of the screen
   next to the green "g".
 - Barriers block your path.  They decrease the amount of remaining time if you
   walk into them.
 - Barrier controllers will destroy all barriers when they are themselves
   destroyed.  Drop a boulder onto them.


Level Editor
------------

The level editor is currently a work-in-progress feature.  In particular, the
load and save functions are not yet implemented.

The cursor in the top display can be controlled using the d-pad.  Press A to
place a block and B to erase a block.  By default, the map of the current level
is displayed in the bottom display.  Use the L and R buttons to change the block
that is added to the level when A is pressed.  The possible blocks are displayed
at the bottom of the upper screen, and the current block is highlighted.

The "Palette" button allows you to change the colour of the boulders and doors
and the type of soil and walls in the current level.

Lastly, the "File" button provides a menu with the ability to load and save
files (not implemented yet), erase the current level, and exit the editor.  It
also allows you to test the current level.  You can switch back to the level
editor from the test mode by either finishing the level, losing all of your
lives, or by switching to pause mode (press Start) and then pressing the X
button.

Level data is saved in "/data/EarthShakerDS/".  The "EarthShakerDS" directory is
created automatically if it does not exist.


Requirements
------------

To play the game you will need a flash cart and a DS or a DS emulator such as
DeSmuME.  To compile the sourcecode you will need to install devKitARM and the
WoopsiGfx library.


Credits and Acknowledgements
----------------------------

  - Coding                                          - Antony Dzeryn
  - Original graphics, sounds, levels and design    - Michael Batty
  - Beta testing                                    - Another World
  - M3i Zero compatibility testing                  - Polomint


Links
-----

  - http://simianzombie.com                         - Development blog
  - http://bitbucket.org/ant512/earthshakerds       - BitBucket page
  - http://bitbucket.org/ant512/woopsigfx           - WoopsiGfx library


Email
-----

  Contact me at ant@simianzombie.com.