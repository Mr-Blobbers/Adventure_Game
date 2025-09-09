@echo off
echo Building Adventure Game...

:: Clean old build
if exist adventure.exe del adventure.exe
if exist *.o del *.o

:: Compile each source file
gcc -std=c11 -Wall -Wextra -O2 ^
  main.c engine.c scene.c data.c player.c class.c combat.c save.c common.c ^
  -o adventure.exe

if exist adventure.exe (
    echo Build successful! Run adventure.exe to play.
) else (
    echo Build failed!
)
adventure.exe
pause