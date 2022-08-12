/*
** EPITECH PROJECT, 2022
** Model3D
** File description:
** Model3D
*/

#ifndef __MODEL3D_HPP__
    #define __MODEL3D_HPP__

    #include <memory>

    #include "../Raylib/Raylib.hpp"
    #include "../Utils.hpp"
    #include "../Raylib/RModel.hpp"

class Model3D {
    public:
        Model3D(std::shared_ptr<Raylib> raylib, CoreScreen screen, std::shared_ptr<RModel> model, Vector3 position = {0}, Vector3 scale = {0}, Vector3 rotationAxis = {0}, float rotationAngle = 0, int layer = 1);
        Model3D(std::shared_ptr<Raylib> raylib, CoreScreen screen, std::string pathModel, std::string pathTexture, std::string pathAnimation, Vector3 position = {0}, Vector3 scale = {0}, Vector3 rotationAxis = {0}, float rotationAngle = 0, int layer = 1);

        void draw();
        bool hasAnimation();
        void updateAnimation();
        void changeAnimation(int indexAnimation);
        void resetAnimation();
        bool isLastAnimation();

        void setX(float x);
        void setY(float y);
        void setZ(float z);
        void setPosition(float x, float y, float z);
        void setScaleX(float x);
        void setScaleY(float y);
        void setScaleZ(float z);
        void setScale(float x, float y, float z);
        void setRotationAxisX(float x);
        void setRotationAxisY(float y);
        void setRotationAxisZ(float z);
        void setRotationAxis(float x, float y, float z);
        void setRotationAngle(float angle);
        void setIndex(int idx);

        Vector3 getPosition();
        float getRotationAngle();
        int getIndex();

        // var
        bool _display;
        int _layer;
        bool _loopAnimation;
        Color _color;
        std::string _colorStr;
        CoreScreen _screen;

    private:
        std::shared_ptr<Raylib> _raylib;
        std::shared_ptr<RModel> _model;
        
        Vector3 _position;
        Vector3 _scale;
        Vector3 _rotationAxis;
        float _rotationAngle;
        bool _hasAnimation;
        unsigned int _animationsCount;
        ModelAnimation *_animations;
        int _animFrameCounter;
        int _indexAnimation;
        int _index;
};

#endif /* !__MODEL3D_HPP__ */
