//
// Created by xRockmetalx
//

#ifndef SCENE_H
#define SCENE_H

class Scene {
public:

    Scene();
    Scene(const Scene &other) = delete;
    Scene(const Scene &&other) = delete;
    Scene& operator = (const Scene &other) = delete;
    virtual ~Scene();

    virtual void init() = 0;
    virtual void handle_events() = 0;
    virtual void update() = 0;
    virtual void render() const = 0;

    bool is_paused() const;
    bool is_running() const;

protected:

    bool running = true;
    bool pause = false;
};

#endif // SCENE_H
