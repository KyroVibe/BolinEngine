@echo off
erase bin\Debug-x64\Sandbox\BolinEngine.dll
erase bin\Debug-x64\Sandbox\BolinEngine.lib
copy bin\Debug-x64\BolinEngine\BolinEngine.dll bin\Debug-x64\Sandbox\BolinEngine.dll
copy bin\Debug-x64\BolinEngine\BolinEngine.lib bin\Debug-x64\Sandbox\BolinEngine.lib