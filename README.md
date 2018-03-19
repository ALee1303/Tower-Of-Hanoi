# Tower-Of-Hanoi
----------------
Repositories for UE4 projects

## Project Description

This Unreal project is a visual data structure that simulates [Table of Hanoi](https://en.wikipedia.org/wiki/Tower_of_Hanoi) puzzle solution. It uses stack, queue, and recursion to create data structure from Unreal Actors that allows different disk types and tower height.

[gifv](https://i.imgur.com/rRYvIP1.gifv)

## Table of Content

<!--ts-->
* [How to Setup](#how-to-setup)
  * [Requirements](#requirements)
  * [Deployment](#deployment)
* [Project Overview](#project-overview)
  * [Default Level settings](#default-level-settings)
  * [Adjusting Game Mode](#adjusting-game-mode)
  * [Tower Data Structures](#tower-data-structures)
* [License](#license)
<!--te-->

## How to Setup

These explanations will get you through setting up Unreal Project for Tower of Hanoi on your machine.

### Requirements

* UE4 v4.15.3
* Visual Studio 2015 or 2017 **with** Microsoft SDK v8.1

### Deployment

1. Clone repository into your hard drive.
2. Right-click on **UnrealHanoiSim.uproject** and click **Generate Visual Studio Project Files**.
3. Start **UnrealHanoiSim.uproject**. When prompted to generate _.dll_ files, click yes to generate necessary files and start the project.

## Project Overview

These explanation will get you through trying different settings provided in the Tower of Hanoi simulation.

### Default Level Settings

* The Project loads up with default level **Basic Simulation**.
* It is set up for visualizing 5 level tower solution using the simplest mesh and material provided by _standard content_.
* Player is set to start directly in front of tower staring at the tower. The disks are not generated until level is actually played.
* Once played, disk will start moving from right-most-tower onto the left-most-tower, obeying the [rules](https://en.wikipedia.org/wiki/Tower_of_Hanoi) of the puzzle.

![png](https://i.imgur.com/eAORKos.png)

### Adjusting Game Mode

* Default level runs on a custom game mode __UnrealHanoiSimGameModeBase_BP__. This is derived from C++ __AGameModeBase__ class, __AUnrealHanoiSimGameModeBase__.
* Tower level can be adjusted by modifying fields in __UnrealHanoiSimGameModeBase_BP__.(Double-click __UnrealHanoiSimGameModeBase_BP__ to edit Blue Print).
* _Move Delay_ decides the time between each disks moved.
* _Hanoi Count_ decides the height of the tower.

![png](https://i.imgur.com/RVCL3tZ.png)

### Tower Data Structures

Tower is simulated using three separate data structure, created by Unreal Engine's _C++_ __AActor__ classes. These three classes are derived into Blue Print classes which can be easily adjusted in editor's **Content Browser** by double-clicking each of them.

* [Tower Manager](https://github.com/ALee1303/Tower-Of-Hanoi/blob/master/Source/UnrealHanoiSim/TowerManager.cpp)
  * _Tower to Spawn_: Type of tower composing the puzzle. Set to default __Tower_BP__.
  * _Towers Start Position_: Position where the first tower will spawn. Set to the Scene Component.
  ![png](https://i.imgur.com/rM8YDz7.png)
  * _Tower Offset_: Distance between each tower.
* [Tower](https://github.com/ALee1303/Tower-Of-Hanoi/blob/master/Source/UnrealHanoiSim/Tower.cpp)
  * _Disk to Spawn_: Type of disk tower is composed of. Set to default __Disk_BP__.
  * _Stack Offset_: Distance between two disks.
  ![png](https://i.imgur.com/YXbBOFZ.png)
* [Disk](https://github.com/ALee1303/Tower-Of-Hanoi/blob/master/Source/UnrealHanoiSim/Disk.cpp)
  * _Static Mesh_: Adjust the shape of each disk. Can be any of the provided _Standard Content_ or custom one.
  * _Materials_: Decides the rendered material of the disk. Can be any of the provided _Standard Content_ or custom one.

## License

This project is licensed under the MIT License - see the [LICENSE](License.md) file for details
