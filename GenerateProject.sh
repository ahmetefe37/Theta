#!/bin/bash
echo "---------------------------------"
echo "PROJECT FILES GENERATING..."
echo "PROJECT IS COMPILING..."
echo "---------------------------------"
./vendor/bin/premake/premake5 gmake2
echo "---------------------------------"
echo "PROJECT WAS COMPILED SUCCESSFULLY!"
echo "--------------------------------"
echo "PROJECT IS BUILDING..."
echo "---------------------------------"
make config=debug
echo "---------------------------------"
echo "PROJECT WAS BUILDED SUCCESSFULLY!"
echo "---------------------------------"