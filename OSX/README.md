EarthShakerOSX
-------------

EarthShakerOSX is a remake of a Sinclair ZX Spectrum game written in 1990 by
Michael Batty.  The objective of the game is to collect all of the diamonds in
each level, avoiding falling boulders, fires, etc.


Menu System
-----------

When the game starts, a menu system appears on the top screen.  You can choose:

 - Start: start from the beginning of the game
 - Level Select: select a level from the level select menu
 - Custom Level: play a level created with the level editor
 - Sound Test: play with the game's sound effects
 - Level Editor: create or edit custom levels in the level editor

Navigate to the desired option using the up and down cursors or the F key.  You
can page through the options more quickly by using the left and right cursors.
When the correct option is highlighted, press D or Z to select it.  The X key
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

The cursor keys move around the level.  The C, Z, X and V keys will poke the
block that is above, to the left, below and to the right respectively, without
moving the player sprite.  This means you can push boulders, collect diamonds,
and so on, that are next to you without moving.  This is a useful technique in
some of the levels.

If you make a mistake and get stuck, you can press A and S simultaneously to
commit suicide and restart the level.

Press F to bring up a map screen and press F again to switch back to the game.
Note that you can only bring up the map screen once per life per level, so only
look at it when you need to.

Press D to pause the game.  Press it again to unpause.  While paused, pressing C
exits the game and returns to the title screen.


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

The level editor allows you to create custom levels using any of the blocks from
the game.  You can test your levels in the editor and save them to disk.  You
can even share them with other people by sending them the level files.  Levels
created in the editor will work in both the Nintendo DS and Mac OSX versions of
EarthShaker.

The cursor in the top display can be controlled using the cursors.  Press Z to
place a block and X to erase a block.  By default, the map of the current level
is displayed in the bottom display.  Use the A and S keys to change the block
that is added to the level when Z is pressed.  The possible blocks are displayed
at the bottom of the upper screen, and the current block is highlighted.

The "Options" button allows you to change the colour of the boulders and doors
and the type of soil and walls in the current level.  It also allows you to
clear the current level ("New"), try out the level ("Test") or quit the editor
("Exit").  You can switch back to the level editor from the test mode by either
finishing the level, losing all of your lives, or by switching to pause mode
(press D) and then pressing the C key.

Lastly, the "File" button provides a file requester with the ability to load,
save and delete files.  You can load a file by entering its name using the
keyboard or by choosing it in the file list and then pressing "Load".  You can
save a file by entering a filename and pressing "Save".  The filename is used as
the name of the level and can be up to 28 characters long.  To delete files,
choose the file in the file list and press "Del".  Scroll the file list up and
down using the buttons on the right of the list.

Note that you will receive no warnings when saving or deleting that you are
about to delete or overwrite a file.

Level data is saved in "~/EarthShakerDS/".  The "EarthShakerDS" directory is
created automatically if it does not exist.  Levels can be played via the
"Custom Level" option on the main menu.  They can also be shared by copying the
level file from one flash cart to another.


Requirements
------------

To play the game you will need a Mac running OSX 10.9.  To compile the
sourcecode you will need:

 - Xcode 5
 - SDL2
 - SDL2_mixer


Credits and Acknowledgements
----------------------------

  - Coding                                          - Antony Dzeryn
  - Original graphics, sounds, levels and design    - Michael Batty
  - Beta testing                                    - Another World
  - M3i Zero compatibility testing                  - Polomint


Links
-----

  - http://simianzombie.com                         - Development blog
  - http://bitbucket.org/ant512/earthshakerosx      - BitBucket page
  - http://bitbucket.org/ant512/earthshakerds       - Nintendo DS port
  - http://bitbucket.org/ant512/woopsigfx           - WoopsiGfx library


Email
-----

  Contact me at ant@simianzombie.com.
