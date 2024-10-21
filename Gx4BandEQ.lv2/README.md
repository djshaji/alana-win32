# Gx4BandEQ.lv2
Equalizer with 4 variable bands

![Gx4BandEQ](https://raw.githubusercontent.com/brummer10/Gx4BandEQ.lv2/master/Gx4BandEQ.png)

## Keyboard shortcuts

|   Command       |     |   Action                      |
|-----------------|:---:|-------------------------------|
|TAB              |==   |make next controller active    |
|SHIFT+TAB        |==   |make previus controller active |
|UP or RIGHT      |==   |increase controller value      |
|DOWN or LEFT     |==   |decrease controller value      |
|HOME (pos1)      |==   |set min controller value       |
|END              |==   |set max controller value       |
|INSERT           |==   |set standard value             |

## Numpad shortcuts

|   Command       |     |   Action                      |
|-----------------|:---:|-------------------------------|
|+                |==   |make next controller active    |
|-                |==   |make previus controller active |
|UP or RIGHT      |==   |increase controller value      |
|DOWN or LEFT     |==   |decrease controller value      |
|HOME (pos1)      |==   |set min controller value       |
|END              |==   |set max controller value       |
|INSERT           |==   |set standard value             |


###### BUILD DEPENDENCY’S 

the following packages are needed to build Gx4BandEQ:

- libc6-dev
- libcairo2-dev
- libx11-dev
- x11proto-dev
- lv2-dev

note that those packages could have different, but similar names 
on different distributions. There is no configure script, 
make will simply fail when one of those packages isn't found.

## BUILD 

$ make install

will install into ~/.lv2

$ sudo make install

will install into /usr/lib/lv2

