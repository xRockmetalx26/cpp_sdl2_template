//
// Created by xRockmetalx on 22/5/2021.
//

#include <cstdio>
#include <RenderWindow.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>

std::unique_ptr<RenderWindow> RenderWindow::instance{};

RenderWindow::RenderWindow(const std::string &window_title, const Size &size_window, const std::string &window_icon_path) {
    window = SDL_CreateWindow(window_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size_window.get_width(), size_window.get_height(), SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if(not window) {
        std::puts("ERROR SDL_CreateWindow().");
        exit(EXIT_FAILURE);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED /*| SDL_RENDERER_PRESENTVSYNC*/);
    if(not renderer) {
        std::puts("ERROR SDL_CreateRenderer().");
        exit(EXIT_FAILURE);
    }

    window_icon = IMG_Load(window_icon_path.c_str());
    SDL_SetWindowIcon(window, window_icon);

    std::puts("OK RenderWindow().");
}

RenderWindow& RenderWindow::new_render_window(const std::string &window_title, const Size &size_window, const std::string &window_icon_path) {
    if(not instance)
        instance.reset(new RenderWindow{window_title, size_window, window_icon_path});

    if(not instance) {
        std::puts("ERROR RenderWindow().");
        exit(EXIT_FAILURE);
    }

    return *instance;
}

RenderWindow& RenderWindow::get_instance() { return *instance; }
SDL_Renderer* RenderWindow::get_renderer() const { return renderer; }
SDL_Window* RenderWindow::get_window() const { return window; }

RenderWindow::~RenderWindow() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_FreeSurface(window_icon);

    std::puts("OK ~RenderWindow().");
}
