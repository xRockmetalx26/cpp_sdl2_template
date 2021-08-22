//
// Created by xRockmetalx
//

#include <cstdio>
#include <SceneMain.h>
#include <SceneManager.h>
#include <RenderWindow.h>
#include <Rectangle.h>
#include <Sprite.h>
#include <Label.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>

SceneMain::SceneMain() { std::puts("OK SceneMain()."); }

void SceneMain::init() {
    Sprite *sprite{new Sprite{"assets/images/icon.png", Position{0, 0}, Size{128, 128}}};

    map_drawables.insert({"sprite", sprite});
    drawables.emplace_back(sprite);
}

void SceneMain::handle_events() {
    SDL_Event event{};

    while(SDL_PollEvent(&event))
        switch(event.type) {
            case SDL_QUIT:
                running = false;
                SceneManager::get_instance().set_next_scene(std::unique_ptr<Scene>() /*EXIT*/);
                break;

            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_SPACE)
                    pause = !pause;
                break;

            default: break;
        }
}

void SceneMain::update() {
    const uint8_t* keys{SDL_GetKeyboardState(nullptr)};
    auto sprite{dynamic_cast<Sprite*>(map_drawables["sprite"])};

    if(keys[SDL_SCANCODE_A])
        sprite->move(-4.0, 0.0);

    if(keys[SDL_SCANCODE_D])
        sprite->move(4.0, 0.0);

    if(keys[SDL_SCANCODE_S])
        sprite->move(0.0, 4.0);

    if(keys[SDL_SCANCODE_W])
        sprite->move(0.0, -4.0);
}

void SceneMain::render() const {
    SDL_SetRenderDrawColor(RenderWindow::get_instance().get_renderer(), 0, 0, 0, 255);
    SDL_RenderClear(RenderWindow::get_instance().get_renderer());

    //BEGIN RENDER

    for(const auto &drawable: drawables)
        drawable->draw();

    //END RENDER

    SDL_RenderPresent(RenderWindow::get_instance().get_renderer());
}

SceneMain::~SceneMain() { std::puts("OK ~SceneMain()."); }
