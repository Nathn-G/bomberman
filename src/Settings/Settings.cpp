/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** Settings
*/

#include "Settings.hpp"

Settings::Settings()
{
    _players_index = 1;
}

Settings::~Settings()
{

}

void Settings::undisplay()
{
    _sprites["_player1"]->_display = false;
    _sprites["_player2"]->_display = false;
    _sprites["_player3"]->_display = false;
    _sprites["_player4"]->_display = false;

    _sprites["_forward_clicked"]->_display = false;
    _sprites["_backward_clicked"]->_display = false;
    _sprites["_left_clicked"]->_display = false;
    _sprites["_right_clicked"]->_display = false;
    _sprites["_bomb_clicked"]->_display = false;
}

void Settings::init(std::shared_ptr<CoreInfo> core, std::shared_ptr<Cam> camera)
{
    this->_core = core;
    this->_camera = camera;

    _sprites["_background"] = this->_tools.newSprite("../assets/settings_background.png");
    _sprites["_player1"] = this->_tools.newSprite("../assets/settings_yellow.png");
    _sprites["_player2"] = this->_tools.newSprite("../assets/settings_red.png");
    _sprites["_player3"] = this->_tools.newSprite("../assets/settings_blue.png");
    _sprites["_player4"] = this->_tools.newSprite("../assets/settings_green.png");

    _sprites["_forward"] = this->_tools.newSprite("../assets/buttons/settings_forward.png");
    _sprites["_forward_clicked"] = this->_tools.newSprite("../assets/buttons/settings_forward_clicked.png");
    _sprites["_backward"] = this->_tools.newSprite("../assets/buttons/settings_backward.png");
    _sprites["_backward_clicked"] = this->_tools.newSprite("../assets/buttons/settings_backward_clicked.png");
    _sprites["_left"] = this->_tools.newSprite("../assets/buttons/settings_left.png");
    _sprites["_left_clicked"] = this->_tools.newSprite("../assets/buttons/settings_left_clicked.png");
    _sprites["_right"] = this->_tools.newSprite("../assets/buttons/settings_right.png");
    _sprites["_right_clicked"] = this->_tools.newSprite("../assets/buttons/settings_right_clicked.png");
    _sprites["_bomb"] = this->_tools.newSprite("../assets/buttons/settings_bomb.png");
    _sprites["_bomb_clicked"] = this->_tools.newSprite("../assets/buttons/settings_bomb_clicked.png");

    _texts["_forward"] = _tools.newText("", "nasa", 590, 267, 2, 60);
    _texts["_backward"] = _tools.newText("", "nasa", 590, 324, 2, 60);
    _texts["_left"] = _tools.newText("", "nasa", 590, 380, 2, 60);
    _texts["_right"] = _tools.newText("", "nasa", 590, 430, 2, 60);
    _texts["_bomb"] = _tools.newText("", "nasa", 590, 485, 2, 60);

    this->undisplay();
    _sprites["_player1"]->_display = true;

    _keys[KEY_APOSTROPHE] = "\"";
    _keys[KEY_COMMA] = "'";
    _keys[KEY_MINUS] = "<";
    _keys[KEY_PERIOD] = "";
    _keys[KEY_SLASH] = "/";
    _keys[KEY_ZERO] = "0";
    _keys[KEY_ONE] = "1";
    _keys[KEY_TWO] = "2";
    _keys[KEY_THREE] = "3";
    _keys[KEY_FOUR] = "4";
    _keys[KEY_FIVE] = "5";
    _keys[KEY_SIX] = "6";
    _keys[KEY_SEVEN] = "7";
    _keys[KEY_EIGHT] = "8";
    _keys[KEY_NINE] = "9";
    _keys[KEY_SEMICOLON] = ";";
    _keys[KEY_EQUAL] = "=";
    _keys[KEY_A] = "A"; 
    _keys[KEY_B] = "B";
    _keys[KEY_C] = "C";
    _keys[KEY_D] = "D";
    _keys[KEY_E] = "E";
    _keys[KEY_G] = "G";
    _keys[KEY_F] = "F";
    _keys[KEY_H] = "H";
    _keys[KEY_I] = "I";
    _keys[KEY_J] = "J";
    _keys[KEY_K] = "K";
    _keys[KEY_L] = "L";
    _keys[KEY_M] = "M";
    _keys[KEY_N] = "N";
    _keys[KEY_O] = "O";
    _keys[KEY_P] = "P";
    _keys[KEY_Q] = "Q";
    _keys[KEY_R] = "R";
    _keys[KEY_S] = "S";
    _keys[KEY_T] = "T";
    _keys[KEY_U] = "U";
    _keys[KEY_V] = "V";
    _keys[KEY_W] = "W";
    _keys[KEY_X] = "X";
    _keys[KEY_Y] = "Y";
    _keys[KEY_Z] = "Z";
    _keys[KEY_LEFT_BRACKET] = "L_BRACKET";
    _keys[KEY_BACKSLASH] = "\\";
    _keys[KEY_RIGHT_BRACKET] = "R_BRACKET";
    _keys[KEY_SPACE] = "SPACE";
    _keys[KEY_ESCAPE] = "ESC";
    _keys[KEY_ENTER] = "ENTER";
    _keys[KEY_TAB] = "TAB";
    _keys[KEY_BACKSPACE] = "B_SPACE";
    _keys[KEY_INSERT] = "INSERT";
    _keys[KEY_DELETE] = "DEL";
    _keys[KEY_RIGHT] = "RIGHT";
    _keys[KEY_LEFT] = "LEFT";
    _keys[KEY_DOWN] = "DOWN";
    _keys[KEY_UP] = "UP";
    _keys[KEY_PAGE_UP] = "PAGE_UP";
    _keys[KEY_PAGE_DOWN] = "PAGE_DOWN";
    _keys[KEY_HOME] = "HOME";
    _keys[KEY_END] = "END";
    _keys[KEY_CAPS_LOCK] = "CAPS_LOCK";
    _keys[KEY_SCROLL_LOCK] = "SCROLL_LOCK";
    _keys[KEY_NUM_LOCK] = "NUM_LOCK";
    _keys[KEY_PRINT_SCREEN] = "PRINT";
    _keys[KEY_PAUSE] = "PAUSE";
    _keys[KEY_F1] = "F1";
    _keys[KEY_F2] = "F2";
    _keys[KEY_F3] = "F3";
    _keys[KEY_F4] = "F4";
    _keys[KEY_F5] = "F5";
    _keys[KEY_F6] = "F6";
    _keys[KEY_F7] = "F7";
    _keys[KEY_F8] = "F8";
    _keys[KEY_F9] = "F9";
    _keys[KEY_F10] = "F10";      
    _keys[KEY_F11] = "F11";    
    _keys[KEY_F12] = "F12";    
    _keys[KEY_LEFT_SHIFT] = "L_SHIFT";
    _keys[KEY_LEFT_CONTROL] = "L_CTRL";
    _keys[KEY_LEFT_ALT] = "L_ALT";
    _keys[KEY_LEFT_SUPER] = "L_SUPER";
    _keys[KEY_RIGHT_SHIFT] = "R_SHIFT";
    _keys[KEY_RIGHT_CONTROL] = "R_CTRL";
    _keys[KEY_RIGHT_ALT] = "R_ALT";
    _keys[KEY_RIGHT_SUPER] = "R_SUPER";
    _keys[KEY_KB_MENU] = "KB_MENU";
    _keys[KEY_KP_0] = "KP_0";
    _keys[KEY_KP_1] = "KP_1";
    _keys[KEY_KP_2] = "KP_2";
    _keys[KEY_KP_3] = "KP_3";
    _keys[KEY_KP_4]  = "KP_4";
    _keys[KEY_KP_5] = "KP_5";
    _keys[KEY_KP_6] = "KP_6";
    _keys[KEY_KP_7] = "KP_7";
    _keys[KEY_KP_8] = "KP_8";
    _keys[KEY_KP_9] = "KP_9";
    _keys[KEY_KP_DECIMAL] = "KP_DECIMAL";
    _keys[KEY_KP_DIVIDE] = "KP_DIVIDE";
    _keys[KEY_KP_MULTIPLY] = "KP_MULTIPLY";
    _keys[KEY_KP_SUBTRACT] = "KP_SUBTRACT";
    _keys[KEY_KP_ADD] = "KP_ADD";
    _keys[KEY_KP_ENTER] = "KP_ENTER";
    _keys[KEY_KP_EQUAL] = "KP_EQUAL";
    _keys[GAMEPAD_BUTTON_LEFT_FACE_UP] = "MAN UP";
    _keys[GAMEPAD_BUTTON_LEFT_FACE_LEFT] = "MAN LEFT";
    _keys[GAMEPAD_BUTTON_LEFT_FACE_RIGHT] = "MAN RIGHT";
    _keys[GAMEPAD_BUTTON_LEFT_FACE_DOWN] = "MAN DOWN";
    _keys[GAMEPAD_BUTTON_RIGHT_FACE_RIGHT] = "SQUARE";
    this->update_texts();
}

void Settings::destroy()
{

}

void Settings::update_texts()
{
    if (_players_index == 1) {
        this->_texts["_forward"]->setText(this->_keys[this->_core->_players_binds[0][0]].c_str()); 
        this->_texts["_backward"]->setText(this->_keys[this->_core->_players_binds[0][1]].c_str()); 
        this->_texts["_left"]->setText(this->_keys[this->_core->_players_binds[0][2]].c_str()); 
        this->_texts["_right"]->setText(this->_keys[this->_core->_players_binds[0][3]].c_str()); 
        this->_texts["_bomb"]->setText(this->_keys[this->_core->_players_binds[0][4]].c_str());    
    }
    if (_players_index == 2) {
        this->_texts["_forward"]->setText(this->_keys[this->_core->_players_binds[1][0]].c_str()); 
        this->_texts["_backward"]->setText(this->_keys[this->_core->_players_binds[1][1]].c_str()); 
        this->_texts["_left"]->setText(this->_keys[this->_core->_players_binds[1][2]].c_str()); 
        this->_texts["_right"]->setText(this->_keys[this->_core->_players_binds[1][3]].c_str()); 
        this->_texts["_bomb"]->setText(this->_keys[this->_core->_players_binds[1][4]].c_str()); 
    }
    if (_players_index == 3) {
        this->_texts["_forward"]->setText(this->_keys[this->_core->_players_binds[2][0]].c_str()); 
        this->_texts["_backward"]->setText(this->_keys[this->_core->_players_binds[2][1]].c_str()); 
        this->_texts["_left"]->setText(this->_keys[this->_core->_players_binds[2][2]].c_str()); 
        this->_texts["_right"]->setText(this->_keys[this->_core->_players_binds[2][3]].c_str()); 
        this->_texts["_bomb"]->setText(this->_keys[this->_core->_players_binds[2][4]].c_str()); 
    }
    if (_players_index == 4) {
        this->_texts["_forward"]->setText(this->_keys[this->_core->_players_binds[3][0]].c_str()); 
        this->_texts["_backward"]->setText(this->_keys[this->_core->_players_binds[3][1]].c_str()); 
        this->_texts["_left"]->setText(this->_keys[this->_core->_players_binds[3][2]].c_str()); 
        this->_texts["_right"]->setText(this->_keys[this->_core->_players_binds[3][3]].c_str()); 
        this->_texts["_bomb"]->setText(this->_keys[this->_core->_players_binds[3][4]].c_str()); 
    }   
}

bool Settings::settings_key_free(int key)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (this->_core->_players_binds[i][j] == key) {
                return false;
            }
        }
    }
    return true;
}

void Settings::update()
{
    if (this->lib.IsGestureDetectedE(GESTURE_TAP) && this->_core->_players_binds[this->_players_index - 1][5] == 0) {
        // forward
        if (this->lib.GetMousePosition().first >= 400 && this->lib.GetMousePosition().first <= 576 &&
            this->lib.GetMousePosition().second >= 257 && this->lib.GetMousePosition().second <= 257 + 35) {
            _sprites["_forward_clicked"]->_display = true;
        } else {
            _sprites["_forward_clicked"]->_display = false;
        }

        // backward
        if (this->lib.GetMousePosition().first >= 400 && this->lib.GetMousePosition().first <= 576 &&
            this->lib.GetMousePosition().second >= 310 && this->lib.GetMousePosition().second <= 310 + 35) {
            _sprites["_backward_clicked"]->_display = true;
        } else {
            _sprites["_backward_clicked"]->_display = false;
        }

        // left
        if (this->lib.GetMousePosition().first >= 400 && this->lib.GetMousePosition().first <= 576 &&
            this->lib.GetMousePosition().second >= 368 && this->lib.GetMousePosition().second <= 368 + 35) {
            _sprites["_left_clicked"]->_display = true;
        } else {
            _sprites["_left_clicked"]->_display = false;
        }

        // right
        if (this->lib.GetMousePosition().first >=  400 && this->lib.GetMousePosition().first <= 576 &&
            this->lib.GetMousePosition().second >= 420 && this->lib.GetMousePosition().second <= 420 + 35) {
            _sprites["_right_clicked"]->_display = true;
        } else {
            _sprites["_right_clicked"]->_display = false;
        }

        // bomb
        if (this->lib.GetMousePosition().first >=  400 && this->lib.GetMousePosition().first <= 576 &&
            this->lib.GetMousePosition().second >= 472 && this->lib.GetMousePosition().second <= 472 + 35) {
            _sprites["_bomb_clicked"]->_display = true;
        } else {
            _sprites["_bomb_clicked"]->_display = false;
        }
    }
    if (this->is_key_clicked() == true) {
        int key = this->lib.GetKeyPressedE();
        if (key == 0 || settings_key_free(key) == false)
            return;
        if (_sprites["_forward_clicked"]->_display == true) {
            this->_core->_players_binds[_players_index - 1][0] = key;
        }
        if (_sprites["_backward_clicked"]->_display == true) {
            this->_core->_players_binds[_players_index - 1][1] = key;
        }
        if (_sprites["_left_clicked"]->_display == true) {
            this->_core->_players_binds[_players_index - 1][2] = key;
        }
        if (_sprites["_right_clicked"]->_display == true) {
            this->_core->_players_binds[_players_index - 1][3] = key;
        }
        if (_sprites["_bomb_clicked"]->_display == true) {
            this->_core->_players_binds[_players_index - 1][4] = key;
        }
    }
    this->update_texts();
    this->update_screen();
}

void Settings::display()
{

    this->lib.BeginDrawingE();
    this->lib.ClearBackgroundE(GRAY);

    this->lib.DrawRectangleE(0, 0, this->lib.GetScreenWidthE(), this->lib.GetScreenHeightE(), BLUE);
    this->_tools.display(CoreScreen::PAUSE, this->_camera->getCam());
    this->lib.EndDrawingE();
}

void Settings::update_screen()
{
    if (_players_index == 1) {
        this->undisplay();
        _sprites["_player1"]->_display = true;
    }
    if (_players_index == 2) {
        this->undisplay();
        _sprites["_player2"]->_display = true;
    }
    if (_players_index == 3) {
        this->undisplay();
        _sprites["_player3"]->_display = true;
    }
    if (_players_index == 4) {
        this->undisplay();
        _sprites["_player4"]->_display = true;
    }
}

bool Settings::is_key_clicked()
{
    if (_sprites["_forward_clicked"]->_display == true)
        return true;
    if (_sprites["_backward_clicked"]->_display == true)
        return true;
    if (_sprites["_left_clicked"]->_display == true)
        return true;
    if (_sprites["_right_clicked"]->_display == true)
        return true;
    if (_sprites["_bomb_clicked"]->_display == true)
        return true;
    return false;
}

void Settings::handleEvent()
{
    if (this->lib.IsKeyPressedE(KEY_BACKSPACE)) {
        if (_core->getOldScreen() == CoreScreen::MENU)
            this->_core->changeScreen(CoreScreen::MENU);
    }
    if (this->lib.IsKeyPressedE(KEY_RIGHT) && _players_index < 4 && this->is_key_clicked() == false) {
        _players_index += 1;
        this->update_screen();
        this->update_texts();
    }
    if (this->lib.IsKeyPressedE(KEY_LEFT) && _players_index > 1 && this->is_key_clicked() == false) {
        _players_index -= 1;
        this->update_screen();
        this->update_texts();
    }
}
