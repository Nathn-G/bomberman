/*
** EPITECH PROJECT, 2022
** raylib
** File description:
** raylib
*/

#ifndef __RAYLIB_HPP__
    #define __RAYLIB_HPP__

    #include <iostream>
    #include "raylib.h"
    #include "RImage.hpp"
    #include "RTexture.hpp"

class Raylib {
    public:
        Raylib();
        ~Raylib();
        void InitWindowE(int width, int height, std::string title);
        void CloseWindowE();
        bool WindowShouldCloseE(void);
        void InitAudioDeviceE();
        bool IsWindowReadyE(void);
        void SetTargetFPSE(int fps);
        bool IsKeyPressedE(int key);
        bool IsKeyDownE(int key);
        void BeginDrawingE(void);
        void EndDrawingE(void);
        void ClearBackgroundE(Color color);
        void DrawTextE(std::string text, int posX, int posY, int fontSize, Color color);
        void DrawRectangleE(int posX, int posY, int width, int height, Color color);
        void DrawCircleE(int centerX, int centerY, float radius, Color color);
        void DrawTextureE(RTexture texture, int posX, int posY, Color tint);
        void DrawTextureRecE(RTexture texture, Rectangle source, Vector2 position, Color tint);
        bool IsGestureDetectedE(int gesture);
        int GetScreenWidthE(void);
        int GetScreenHeightE(void);
        void MaximizeWindowE(void);
        int GetPlacementWidthE(int width);
        int GetPlacementHeightE(int height);
        void SetWindowIconE(RImage image);
        void SetConfigFlagsE(unsigned int flags);
        void SetCameraModeE(Camera camera, int mode);
        void UpdateCameraE(Camera *camera);
        bool IsWindowResizedE();
        void BeginMode3DE(Camera3D camera);
        void EndMode3DE();
        int GetRandomValueE(int min, int max);
        int MeasureTextExE(Font font, std::string text, int fontSize, float spacing);
        Font LoadFontE(std::string fileName);
        void DrawTextExE(Font font, std::string text, int x, int y, int fontSize, float spacing, Color color);
        std::pair<float, float> GetMousePosition(void);
        int GetKeyPressedE();
        int AmountGamePadE(void);
        bool isGamepadButtonPressedE(int gamepad, int button);
    private:
};

#endif /* !__RAYLIB_HPP__ */
