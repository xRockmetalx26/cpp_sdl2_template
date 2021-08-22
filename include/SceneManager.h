//
// Created by xRockmetalx
//

#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <memory>

class Scene;

class SceneManager {
public:

    SceneManager(const SceneManager &other) = delete;
    SceneManager(const SceneManager &&other) = delete;
    SceneManager& operator = (const SceneManager &other) = delete;
    SceneManager& operator = (const SceneManager &&other) = delete;
    virtual ~SceneManager();

    void switch_scene();
    bool contains_scene() const;

    static SceneManager& new_scene_manager();
    void set_next_scene(std::unique_ptr<Scene> scene);

    static SceneManager& get_instance();
    Scene& get_current_scene() const;

private:

    SceneManager();

    static std::unique_ptr<SceneManager> instance;

    std::unique_ptr<Scene> current_scene{};
    std::unique_ptr<Scene> next_scene{};
};

#endif // SCENE_MANAGER_H
