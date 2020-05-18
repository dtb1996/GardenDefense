# GardenDefense
A defense game that requires taking care of your garden and protecting it from bug invasions.

****************************************************************************************

Attributions

Bug model:
Ant by ZERG_LURKER
https://www.turbosquid.com/3d-models/ant-animation-running-3ds-free/856094

Leaf texture:
Leaf texture png taken from YAWD
https://ya-webdesign.com/imgdownload.html

Dirt texture:
Dirt by LuminousDragonGames
https://opengameart.org/content/simple-seamless-tiles-of-dirt-and-sand-dirt-1-0png

Well 3-D model:
3D Old Well by nestofgames
https://www.turbosquid.com/3d-models/3d-old-1519355

Seed 3-D model:
Almond Kernel by triduza
https://www.turbosquid.com/FullPreview/Index.cfm/ID/626073

****************************************************************************************

Description

This game is a forest world originally created as part of the Game Programming and Development coursework at Southern New Hampshire University. The refined version includes new gameplay mechanics based on the tower defense genre. In Garden defense, the player must plant seeds, water the individual plants, and defend against insect attacks.

Tools Used

- Unreal Engine 4
- Autodesk Maya
-Autodesk 3ds Max
- Adobe Photoshop
- GIMP

Reflection

How would you describe the process of creating and polishing the artifact?

The original version of this game began as a simple forest landscape with a cabin made in Unreal Engine 4, with textures created in Photoshop and a tree model imported from 3ds Max. Various game elements, such as pickup items and HUD status bars, were built in Visual Studio using C++. Refining the game involved creating new functionality for the defense mechanics. First the basic game components were added, including seed pickups, plant spots, AI spawn areas and attacks, a player attack, and a place to refill water. With everything functioning correctly, custom models were added to the plants and dirt mounds and additional models were imported to be used for the remaining actors. Finally, progress bars were added to the HUD to show the water and bug spray levels and a counter for the number of seeds the player has.

What did you learn as you were creating it and improving it?

Creating the first version of the game was my first experience with using C++ alongside Unreal Engine 4. I learned how to create base game components and functionality through C++ coding. While improving this game, I learned how to handle complex logic, having to make sure various scripts communicated with each other correctly.

What challenges did you face?

While making the initial version of Garden Defense, I had to learn how to replace visual scripting with equivalent C++ code. I was already comfortable with C++ but was not used to using it for game development, so most of the features I had planned had to be left out. Returning to this project allowed me to come up with a fresh idea and turn it into an actual game over the base components I previous created. Additional models were planned for the water bucket, bug spray, and player but had to be dropped due to time constraints. The animation for the bug was also not working correctly, so that was removed as well.

How did you incorporate feedback as you made changes to the artifact?

I used the feedback I received on the first version of the game as a base for the new functionality introduced in this refined version. The mechanics present in the original project worked as intended, but there was no clear objective for the player. Before I began making changes, I came up with a new idea to address this issue and implemented it in this final game.

How was the artifact improved?

- Added a garden with individual plants that must be defended from enemy attacks
- Added abilities and pickup items that make the game interesting and provide the player with strategy options
- Created custom models for the garden
- Imported models for the bug enemies, seeds, and well
- Added a particle system to visually represent the bug spray
- Update the existing HUD graphics to match the new game changes
