/*
** EPITECH PROJECT, 2022
** Item
** File description:
** Item
*/

#ifndef __Item_HPP__
    #define __Item_HPP__

    #include "IItem.hpp"
    #include "../../Tools/Model3D.hpp"
    #include "../../Tools/Tools.hpp"
    #include <thread>

class Item : public IItem {
    public:
        Item();
        virtual ~Item();
        void setIndex(int idx) override;
        int getIndex() override;
        virtual void pure() = 0;
        std::shared_ptr<Model3D> model;

    protected:
    private:
        int _index;
};

#endif /* !__Item_HPP__ */
