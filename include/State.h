#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "GameObject.h"
#include "Music.h"

class State {
  public:
    State();
    ~State() { objectArray.clear(); }
    bool QuitRequested();
    void LoadAssets();
    void Update(float dt);
    void Render();

  private:
    void Input();
    void AddObject(int mouseX, int mouseY);

    //Sprite* bg;
    Music* music;
    bool quitRequested;
    std::vector<std::unique_ptr<GameObject>> objectArray;
};
