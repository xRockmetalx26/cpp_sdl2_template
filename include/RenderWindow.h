//
// Created by xRockmetalx on 22/5/2021.
//

#ifndef RENDER_WINDOW_H
#define RENDER_WINDOW_H

#include <memory>
#include <string>
#include <Size.h>

struct SDL_Renderer;
struct SDL_Window;
struct SDL_Surface;

class RenderWindow {
public:

    RenderWindow(const RenderWindow &other) = delete;
    RenderWindow(const RenderWindow &&other) = delete;
    RenderWindow& operator = (const RenderWindow &other) = delete;
    RenderWindow& operator = (const RenderWindow &&other) = delete;
    virtual ~RenderWindow();

    static RenderWindow& new_render_window(const std::string &title, const Size &size,
                                        const std::string &icon);

    static RenderWindow& get_instance();
    SDL_Renderer* get_renderer() const;
    SDL_Window* get_window() const;

private:

    RenderWindow(const std::string &title, const Size &size, const std::string &icon);

    static std::unique_ptr<RenderWindow> instance;

    SDL_Renderer *renderer{};
    SDL_Window *window{};
    SDL_Surface *window_icon{};
};

#endif // RENDER_WINDOW_H
