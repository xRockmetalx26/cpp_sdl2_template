//
// Created by xRockmetalx
//

#include <cstdio>
#include <Game.h>
#include <SceneManager.h>
#include <RenderWindow.h>
#include <LoopTimer.h>
#include <Scene.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

std::unique_ptr<Game> Game::instance{};

Game::Game(const std::string &title, const Size &size, const std::string &icon, const int fps) {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::puts("ERROR SDL_Init().");
        exit(EXIT_FAILURE);
    }

    if(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_WEBP | IMG_INIT_TIF) < 0) {
        std::puts("ERROR SDL_Init().");
        exit(EXIT_FAILURE);
    }

    if(TTF_Init() < 0) {
        std::puts("ERROR TTF_Init().");
        exit(EXIT_FAILURE);
    }

    SceneManager::new_scene_manager();
    RenderWindow::new_render_window(title, size, icon);
    LoopTimer::new_loop_timer(fps);

    std::puts("OK Game().");
}

void Game::run() const {
    while(SceneManager::get_instance().contains_scene()) {
        Scene &current_scene{SceneManager::get_instance().get_current_scene()};
        current_scene.init();

        while(current_scene.is_running()) {
            LoopTimer::get_instance().update();
            current_scene.handle_events();

            while(LoopTimer::get_instance().is_ready()) {
                if(not current_scene.is_paused())
                    current_scene.update();

                LoopTimer::get_instance().reset();
                current_scene.render();
           }
        }

        SceneManager::get_instance().switch_scene();
    }
}

Game& Game::new_game(const std::string &title, const Size &size, const std::string &icon, const int fps) {
    if(not instance)
        instance.reset(new Game{title, size, icon, fps});

    if(not instance) {
        std::puts("ERROR Game().");
        exit(EXIT_FAILURE);
    }

    return *instance;
}

Game& Game::get_instance() { return *instance; }

Game::~Game() {
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();

    std::puts("OK ~Game().");
}
