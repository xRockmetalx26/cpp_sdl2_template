//
// Created by xRockmetalx
//

#include <cstdio>
#include <SceneManager.h>
#include <SceneMain.h>

std::unique_ptr<SceneManager> SceneManager::instance{};

SceneManager::SceneManager() {
    current_scene = std::make_unique<SceneMain>();

    std::puts("OK SceneManager().");
}

SceneManager& SceneManager::new_scene_manager() {
    if(not instance)
        instance.reset(new SceneManager{});

    if(not instance) {
        std::puts("ERROR SceneManager().");
        exit(EXIT_FAILURE);
    }

    return *instance;
}

void SceneManager::set_next_scene(std::unique_ptr<Scene> scene) { next_scene = std::move(scene); }

void SceneManager::switch_scene() { current_scene = std::move(next_scene); }

SceneManager& SceneManager::get_instance() { return *instance; }

bool SceneManager::contains_scene() const { return current_scene.get(); }

Scene& SceneManager::get_current_scene() const { return *current_scene; }

SceneManager::~SceneManager() { std::puts("OK ~SceneManager()."); }
