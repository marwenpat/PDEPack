# CMake-File f�r die Hauptprogramme

# Name des Projekts: "PDEPack". 
cmake_minimum_required (VERSION 3.4)
#project (PDEPack_Apps)

include (../CMakeOptions.txt)

# Jedes Beispiel liegt in einem Unterverzeichnis!
# Ein neues Beispiel muss mit add_subdirectory hinzugef�gt werden!
add_subdirectory(Drahtgleichung)
