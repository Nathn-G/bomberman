/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Core
*/

#include "Tools.hpp"

Tools::Tools()
{
    this->_raylib = std::make_shared<Raylib>();
    this->_keyEvent.setRaylib(this->_raylib);
}

Tools::~Tools()
{
}

std::shared_ptr<RImage> Tools::getImagePath(std::string path) 
{
    for (auto image : this->_imageMap) {
        if (path == image.first)
            return (image.second);
    }
    this->_imageMap[path] = std::make_shared<RImage>(path);
    return (this->_imageMap[path]);
}

std::shared_ptr<Sprite> Tools::newSprite(std::string path, int layer, int x, int y)
{
    std::shared_ptr<RImage> image = this->getImagePath(path);
    std::shared_ptr<Sprite> newSprite = std::make_shared<Sprite>(this->_raylib, image, layer, x, y);
    this->_sprites.push_back(newSprite);
    return (newSprite);
}

std::shared_ptr<AnimatedSprite> Tools::newAnimatedSprite(std::string path, int layer, int x, int y)
{
    std::shared_ptr<RImage> image = this->getImagePath(path);
    std::shared_ptr<AnimatedSprite> newAnimatedSprite = std::make_shared<AnimatedSprite>(this->_raylib, image, layer, x, y);
    this->_animatedSprites.push_back(newAnimatedSprite);
    return (newAnimatedSprite);
}

std::shared_ptr<Text> Tools::newText(std::string text, std::string font, int x, int y, int layer, int size)
{
    std::shared_ptr<Text> newText = std::make_shared<Text>(this->_raylib, text, this->_font[font], layer, size, x, y);
    this->_texts.push_back(newText);
    return (newText);
}

std::shared_ptr<MusicP> Tools::newMusic(std::string path, bool loop)
{
    std::shared_ptr<MusicP> newMusic = std::make_shared<MusicP>(path, loop);
    this->_musics.push_back(newMusic);
    return (newMusic);
}

std::shared_ptr<Model3D> Tools::newModel(CoreScreen screen, std::string pathModel, std::string pathTexture, Vector3 position, Vector3 scale, Vector3 rotationAxis, float rotationAngle, int layer)
{
    std::shared_ptr<RModel> model;
    std::string id = pathModel + pathTexture;

    if (this->_listModels.find(id) == this->_listModels.end()) {
        model = std::make_shared<RModel>(pathModel, pathTexture);
        this->_listModels[id] = model;
    } else {
        model = this->_listModels[id];
    }
    std::shared_ptr<Model3D> newModel = std::make_shared<Model3D>(this->_raylib, screen, model, position, scale, rotationAxis, rotationAngle, layer);
    newModel.get()->setIndex(this->_models.size());
    this->_models.push_back(newModel);
    return (newModel);
}

std::shared_ptr<Model3D> Tools::newModelWithAnimation(CoreScreen screen, std::string pathModel, std::string pathTexture, std::string pathAnimation, Vector3 position, Vector3 scale, Vector3 rotationAxis, float rotationAngle, int layer)
{
    std::shared_ptr<Model3D> newModel = std::make_shared<Model3D>(this->_raylib, screen, pathModel, pathTexture, pathAnimation, position, scale, rotationAxis, rotationAngle, layer);
    newModel.get()->setIndex(this->_models.size());
    this->_models.push_back(newModel);
    return (newModel);
}

void Tools::loadFont(std::string fontPath, std::string name)
{
    this->_font[name] = std::make_shared<MyFont>(this->_raylib, fontPath);
}

void Tools::display(CoreScreen screen, Camera3D camera)
{
    this->setLayer();
    for (auto layeur : this->_layeurList) {
        for (auto sprite : this->_sprites) {
            if (sprite.get()->_layer == layeur) {
                sprite.get()->draw();
            }
        }
        for (auto animatedSprite : this->_animatedSprites) {
            if (animatedSprite.get()->_layer == layeur) {
                animatedSprite.get()->draw();
            }
        }
        for (auto text : this->_texts) {
            if (text.get()->_layer == layeur) {
                text.get()->draw();
            }
        }
        if (screen == CoreScreen::GAMEPLAY) {
            BeginMode3D(camera);
            for (auto model : this->_models) {
                if (model->_display == true && model->_layer == layeur) {
                    model.get()->draw();
                }
            }
            EndMode3D();
        }
    }
    updateMusic();
}

void Tools::updateMusic()
{
    for (auto music : this->_musics) {
        music.get()->update();
    }
}

void Tools::setLayer()
{
    this->_layeurList.clear();
    for (auto sprite : this->_sprites) {
        this->_layeurList.push_back(sprite.get()->_layer);
    }
    for (auto animatedSprite : this->_animatedSprites) {
        this->_layeurList.push_back(animatedSprite.get()->_layer);
    }
    for (auto text : this->_texts) {
        this->_layeurList.push_back(text.get()->_layer);
    }
    for (auto model : this->_models) {
        this->_layeurList.push_back(model->_layer);
    }
    std::sort(this->_layeurList.begin(), this->_layeurList.end());
    this->_layeurList.erase(std::unique(this->_layeurList.begin(), this->_layeurList.end()), this->_layeurList.end());
}

void Tools::deleteModel(int idx)
{
    std::vector<std::shared_ptr<Model3D>>::iterator it = this->_models.begin();

    for (int i = 0; i < idx; i++, it++);
    this->_models.erase(it);
    for (int i = idx; i < this->_models.size(); i++)
        this->_models[i].get()->setIndex(this->_models[i].get()->getIndex() - 1);
}