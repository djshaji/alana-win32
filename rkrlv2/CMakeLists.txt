#CMake file for LV2 Versions of Rakarrack Effects
# the name of the target operating system
SET(CMAKE_SYSTEM_NAME Windows)

# which compilers to use for C and C++
SET(CMAKE_C_COMPILER /usr/bin/x86_64-w64-mingw32-gcc)
SET(CMAKE_CXX_COMPILER /usr/bin/x86_64-w64-mingw32-g++)
SET(CMAKE_RC_COMPILER /usr/bin/x86_64-w64-mingw32-windres)
SET(CMAKE_AR /usr/bin/x86_64-w64-mingw32-ar)
SET(CMAKE_RANLIB /usr/bin/x86_64-w64-mingw32-ranlib)
set(PKG_CONFIG_EXECUTABLE x86_64-w64-mingw32-pkg-config)
# target environment location
SET(CMAKE_FIND_ROOT_PATH /usr/x86_64-w64-mingw32)

# adjust the default behaviour of the FIND_XXX() commands:
# search headers and libraries in the target environment, search 
# programs in the host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

cmake_minimum_required(VERSION 2.6)

#rename these files so they are easier to use for plugins
SET( RVB x;Chamber;Concrete_Stairwell;Hall;Med_Hall;Large_Room;Large_Hall;Guitar_Ambience;Studio;Twilight;Santa_Lucia )
SET( DLY x;SwingPong;Short_Delays;Flange_plus_Echo;Comb;EchoFlange;Filtered_Echo;Notch-Wah;Multi-Chorus;PingPong;90-Shifter;Basic_LR_Delay )

foreach(INDX RANGE 1 10)
    list(GET RVB ${INDX} NEWNAME)
    configure_file(data/${INDX}.rvb lv2data/${NEWNAME}.rvb COPYONLY)
    list(GET DLY ${INDX} NEWNAME)
    configure_file(data/${INDX}.dly lv2data/${NEWNAME}.dly COPYONLY)
endforeach(INDX)
# 1 more dly file 
list(GET DLY 11 NEWNAME)
configure_file(data/11.dly lv2data/${NEWNAME}.dly COPYONLY)


add_subdirectory(lv2)
