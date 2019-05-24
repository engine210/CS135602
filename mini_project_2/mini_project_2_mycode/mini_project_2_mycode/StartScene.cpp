//
//  StartScene.cpp
//  mini_project_2_mycode
//
//  Created by engine210 on 2019/5/24.
//  Copyright © 2019 engine210. All rights reserved.
//

#include "StartScene.hpp"
#include "PlayScene.hpp"
#include "AudioHelper.hpp"
#include "Slider.hpp"
#include "LOG.hpp"

void StartScene::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::ImageButton* btn;
    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW - 200, halfH - 50, 400, 100);
    btn->SetOnClickCallback(std::bind(&StartScene::PlayOnClick, this, 1));
    AddNewObject(new Engine::Image("start/start_background.jpg", 0, 0, w, h, 0, 0));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Start", "pirulen.ttf", 48, halfW, halfH, 0, 0, 0, 255, 0.5, 0.5));
    // Not a safe way, however we only free while change scene, so it's fine.
    bgmInstance = al_create_sample_instance(Engine::Resources::GetInstance().GetSample("happy.ogg").get());
    al_set_sample_instance_playmode(bgmInstance, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(bgmInstance, al_get_default_mixer());
    al_play_sample_instance(bgmInstance);
}
void StartScene::PlayOnClick(int stage) {
    Engine::GameEngine::GetInstance().ChangeScene("stage-select");
}
