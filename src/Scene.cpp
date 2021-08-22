//
// Created by xRockmetalx
//

#include <cstdio>
#include <Scene.h>

Scene::Scene() { std::puts("OK Scene()."); }

bool Scene::is_paused() const { return pause; }
bool Scene::is_running() const { return running; }

Scene::~Scene() { std::puts("OK ~Scene()."); }
