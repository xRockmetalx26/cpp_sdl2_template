//
// Created by xRockmetalx
//

#ifndef GAME_H
#define GAME_H

#include <memory>
#include <string>
#include <Size.h>

class Game {
public:

    Game(const Game &other) = delete;
    Game(const Game &&other) = delete;
    Game& operator = (const Game &other) = delete;
    Game& operator = (const Game &&other) = delete;
    virtual ~Game();

    void run() const;

    static Game& new_game(const std::string &title = "SDL Template", const Size &size = Size{800, 600},
                        const std::string &icon = "assets/images/icon.png", int fps = 60);
    static Game& get_instance();

private:

    Game(const std::string &title, const Size &size, const std::string &icon, int fps);

    static std::unique_ptr<Game> instance;
};

#endif // GAME_H
