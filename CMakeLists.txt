cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 17)
project(bomberman)

set (raylib_DIR cmake)
FIND_PACKAGE(raylib REQUIRED)

set(
    SOURCE_FILES
    src/main.cpp

    src/Raylib/Raylib.cpp
    src/Raylib/RImage.cpp
    src/Raylib/RTexture.cpp
    src/Raylib/RMusic.cpp
    src/Raylib/RModel.cpp
    src/Raylib/RSound.cpp

    src/Utils.cpp
    src/AError.cpp

    src/Core/CoreLoop.cpp
    src/Core/Core.cpp
    src/Core/CoreInfo.cpp
    
    src/Menu/Particles/Particles.cpp
    src/Menu/Menu.cpp

    src/Tools/AnimatedSprite.cpp
    src/Tools/KeyEvent.cpp
    src/Tools/Model3D.cpp
    src/Tools/Sprite.cpp
    src/Tools/Text.cpp
    src/Tools/MusicP.cpp
    src/Tools/Pclock.cpp
    src/Tools/Tools.cpp
    src/Tools/Cam.cpp

    src/Game/Items/Item.cpp
    src/Game/Game.cpp
    src/Game/Items/Bomb.cpp
    src/Game/Items/Fire.cpp
    src/Game/Items/SpeedUp.cpp
    src/Game/Items/Detonator.cpp
    src/Game/Items/RecovBomb.cpp
    src/Game/Items/RecovLife.cpp
    src/Game/Characters/Characters.cpp
    src/Game/Characters/Player.cpp
    src/Game/Characters/OpAIFive.cpp
    src/Game/Characters/OpAIFive2.cpp

    src/MapSelection/MapSelection.cpp

    src/LoadSave/LoadSave.cpp

    src/Pause/Pause.cpp

    src/Settings/Settings.cpp

    src/Ending/Ending.cpp

    src/HowToPlay/HowToPlay.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ./src)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} PUBLIC raylib)