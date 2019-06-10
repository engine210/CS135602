//
//  NextStageScene.cpp
//  mini_project_2_v3_mycode
//
//  Created by engine210 on 2019/6/11.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <functional>
#include <string>

#include "AudioHelper.hpp"
#include "GameEngine.hpp"
#include "ImageButton.hpp"
#include "Label.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "NextStageScene.hpp"

void NextStageScene::Initialize() {
    ticks = 0;
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    AddNewObject(new Engine::Label("You Win!", "pirulen.ttf", 48, halfW, halfH / 2, 255, 255, 255, 255, 0.5, 0.5));
    Engine::ImageButton* btn;
    btn = new Engine::ImageButton("win/dirt.png", "win/floor.png", halfW - 200, halfH * 3 / 2 - 50, 400, 100);
    btn->SetOnClickCallback(std::bind(&NextStageScene::NextOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Next Stage", "pirulen.ttf", 40, halfW, halfH * 3 / 2, 0, 0, 0, 255, 0.5, 0.5));
    
    btn = new Engine::ImageButton("win/dirt.png", "win/floor.png", halfW - 200, halfH - 50, 400, 100);
    btn->SetOnClickCallback(std::bind(&NextStageScene::BackOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Back", "pirulen.ttf", 40, halfW, halfH, 0, 0, 0, 255, 0.5, 0.5));
    
    AudioHelper::PlayAudio("win.wav");
}
void NextStageScene::Update(float deltaTime) {
    ticks += deltaTime;
    if (ticks > 4 && ticks < 100 &&
        dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetScene("play"))->MapId == 2) {
        ticks = 100;
        AudioHelper::PlayBGM("happy.ogg");
    }
}
void NextStageScene::NextOnClick() {
    // Change to select scene.
    Engine::GameEngine::GetInstance().ChangeScene("play");
}
void NextStageScene::BackOnClick() {
    Engine::GameEngine::GetInstance().ChangeScene("stage-select");
}
