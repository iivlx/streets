
# streets
#### GTA IV - Street Names Mod

**streets** is a mod for [**Grand Theft Auto IV**](https://en.wikipedia.org/wiki/Grand_Theft_Auto_IV).

It displays the name of the current street and cross street the player is on, as well as for any target blips on the map.

## Usage

While the mod is running it will display an overlay in the top right, showing your current location, as well as the location of any target blips.

## Build Instructions

To build this mod run [CMake](https://cmake.org/) from the root directory.

## Requirements & Installation

To install and run this mod copy the *.asi* file from the `bin/` directory to your **GTA IV** `plugin/` directory.

If you have an asi loader it will automatically load the mod when you launch the game.
>Version **1.0.4.0** of **Grand Theft Auto IV** is required.

## Development

This mod works by creating a *.dll* to be injected when **GTA IV** is launched. After the *.dll* is injected it creates a new thread that registers native script functions from **GTAIV.exe**, and then also hooks onto `DirectX 9` to draw an overlay before the scene is rendered.

Once this is completed, **streets** executes its mainloop and using the scripting interface finds the street names of the players location, and the location of any target blips and displays them on the overlay.

### TODO:

- [x] Get street name information from coordinates
- [ ] Get neighbourhood from coordinates
- [x] Display overlay
- [ ] Get information of first blip
- [ ] Iterate through blips
- [ ] Display blip info for each blip
- [ ] Cleanup overlay
- [x] Overlay opacity