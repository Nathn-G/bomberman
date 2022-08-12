/*
** EPITECH PROJECT, 2022
** raylib
** File description:
** raylib
*/

#include "Raylib.hpp"

Raylib::Raylib()
{
}

Raylib::~Raylib()
{
}

void Raylib::InitWindowE(int width, int height, std::string title)
{
    InitWindow(width, height, title.c_str());
}

void Raylib::CloseWindowE()
{
    CloseWindow();
}

bool Raylib::WindowShouldCloseE(void)
{
    return WindowShouldClose();
}

void Raylib::InitAudioDeviceE()
{
    InitAudioDevice();
}

bool Raylib::IsWindowReadyE(void)
{
    return IsWindowReady();
}

void Raylib::SetTargetFPSE(int fps)
{
    SetTargetFPS(fps);
}

bool Raylib::IsKeyPressedE(int key)
{
    return IsKeyPressed(key);
}

int Raylib::GetKeyPressedE()
{
    return GetKeyPressed();
}

bool Raylib::IsKeyDownE(int key)
{
    return IsKeyDown(key);
}

bool Raylib::isGamepadButtonPressedE(int gamepad, int button)
{
    return IsGamepadButtonDown(gamepad, button);
}

void Raylib::BeginDrawingE(void)
{
    BeginDrawing();
}

void Raylib::EndDrawingE(void)
{
    EndDrawing();
}

int Raylib::AmountGamePadE(void)
{
    int amount = 0;
    for (int index = 0; index < 4; index += 1) {
        if (IsGamepadAvailable(index))
            amount += 1;
    }
    return amount;
}

void Raylib::ClearBackgroundE(Color color)
{
    ClearBackground(color);
}

void Raylib::DrawTextE(std::string text, int posX, int posY, int fontSize, Color color)
{
    DrawText(text.c_str(), posX, posY, fontSize, color);
}

void Raylib::DrawTextExE(Font font, std::string text, int x, int y, int fontSize, float spacing, Color color)
{
    Vector2 position = {static_cast<float>(x), static_cast<float>(y)};
    DrawTextEx(font, text.c_str(), position, fontSize, spacing, color);
}

void Raylib::DrawRectangleE(int posX, int posY, int width, int height, Color color)
{
    DrawRectangle(posX, posY, width, height, color);
}

Font Raylib::LoadFontE(std::string fileName)
{
    return (LoadFont(fileName.c_str()));
}

int Raylib::MeasureTextExE(Font font, std::string text, int fontSize, float spacing)
{
    return (static_cast<int>(MeasureTextEx(font, text.c_str(), static_cast<float>(fontSize), spacing).x));
}

void Raylib::DrawCircleE(int centerX, int centerY, float radius, Color color)
{
    DrawCircle(centerX, centerY, radius, color);
}

void Raylib::DrawTextureE(RTexture texture, int posX, int posY, Color tint)
{
    DrawTexture(texture.getTexture(), posX, posY, tint);
}

void Raylib::DrawTextureRecE(RTexture texture, Rectangle source, Vector2 position, Color tint)
{
    DrawTextureRec(texture.getTexture(), source, position, tint);
}

bool Raylib::IsGestureDetectedE(int gesture)
{
    return IsGestureDetected(gesture);
}

int Raylib::GetScreenWidthE(void)
{
    return GetScreenWidth();
}

int Raylib::GetScreenHeightE(void)
{
    return GetScreenHeight();
}

void Raylib::MaximizeWindowE(void)
{
    MaximizeWindow();
}

int Raylib::GetPlacementWidthE(int width)
{
    double ratio = (double)this->GetScreenWidthE() / (double)800 * width;
    return ratio;
}

int Raylib::GetPlacementHeightE(int height)
{
    double ratio = (double)this->GetScreenHeightE() / (double)600 * height;
    return ratio;
}

void Raylib::SetWindowIconE(RImage image)
{
    SetWindowIcon(image.getImage());
}

void Raylib::SetConfigFlagsE(unsigned int flags)
{
    SetConfigFlags(flags);
}

void Raylib::SetCameraModeE(Camera camera, int mode)
{
    SetCameraMode(camera, mode);
}

void Raylib::UpdateCameraE(Camera *camera)
{
    UpdateCamera(camera);
}

bool Raylib::IsWindowResizedE()
{
    return IsWindowResized();
}

void Raylib::BeginMode3DE(Camera3D camera)
{
    BeginMode3D(camera);
}

void Raylib::EndMode3DE()
{
    EndMode3D();
}

int Raylib::GetRandomValueE(int min, int max)
{
    return GetRandomValue(min, max);
}

std::pair<float, float> Raylib::GetMousePosition(void)
{
    std::pair<float, float> Mpos = {(float)GetMouseX(), (float)GetMouseY()};

    return Mpos;
}
