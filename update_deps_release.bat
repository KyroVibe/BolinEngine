@echo off
erase bin\Release-x64\Sandbox\BolinEngine.dll
erase bin\Release-x64\Sandbox\BolinEngine.lib
copy bin\Release-x64\BolinEngine\BolinEngine.dll bin\Release-x64\Sandbox\BolinEngine.dll
copy bin\Release-x64\BolinEngine\BolinEngine.lib bin\Release-x64\Sandbox\BolinEngine.lib