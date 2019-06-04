#include <allegro5/allegro_audio.h>
#include <functional>
#include <memory>
#include <string>

#include "AudioHelper.hpp"
#include "GameEngine.hpp"
#include "ImageButton.hpp"
#include "Label.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Resources.hpp"
#include "Slider.hpp"
#include "StageSelectScene.hpp"

void StageSelectScene::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    
    Slider *sliderBGM, *sliderSFX;
    sliderBGM = new Slider(40 + halfW - 95, halfH - 300 - 2, 190, 4);
    sliderBGM->SetOnValueChangedCallback(std::bind(&StageSelectScene::BGMSlideOnValueChanged, this, std::placeholders::_1));
    AddNewControlObject(sliderBGM);
    AddNewObject(new Engine::Label("BGM: ", "pirulen.ttf", 28, 40 + halfW - 60 - 95, halfH - 300, 255, 255, 255, 255, 0.5, 0.5));
    sliderSFX = new Slider(40 + halfW - 95, halfH - 200 - 2, 190, 4);
    sliderSFX->SetOnValueChangedCallback(std::bind(&StageSelectScene::SFXSlideOnValueChanged, this, std::placeholders::_1));
    AddNewControlObject(sliderSFX);
    AddNewObject(new Engine::Label("SFX: ", "pirulen.ttf", 28, 40 + halfW - 60 - 95, halfH - 200, 255, 255, 255, 255, 0.5, 0.5));
    
    Engine::ImageButton* btn;
    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW - 350, halfH - 50, 100, 100);
    btn->SetOnClickCallback(std::bind(&StageSelectScene::PlayOnClick, this, 1));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("1", "pirulen.ttf", 48, halfW - 300, halfH, 0, 0, 0, 255, 0.5, 0.5));
    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW - 200, halfH - 50, 100, 100);
    btn->SetOnClickCallback(std::bind(&StageSelectScene::PlayOnClick, this, 2));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("2", "pirulen.ttf", 48, halfW - 150, halfH, 0, 0, 0, 255, 0.5, 0.5));
    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW - 50, halfH - 50, 100, 100);
    btn->SetOnClickCallback(std::bind(&StageSelectScene::PlayOnClick, this, 3));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("3", "pirulen.ttf", 48, halfW, halfH, 0, 0, 0, 255, 0.5, 0.5));
    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW + 100, halfH - 50, 100, 100);
    btn->SetOnClickCallback(std::bind(&StageSelectScene::PlayOnClick, this, 4));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("4", "pirulen.ttf", 48, halfW + 150, halfH, 0, 0, 0, 255, 0.5, 0.5));
    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW + 250, halfH - 50, 100, 100);
    btn->SetOnClickCallback(std::bind(&StageSelectScene::PlayOnClick, this, 5));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("5", "pirulen.ttf", 48, halfW + 300, halfH, 0, 0, 0, 255, 0.5, 0.5));
    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW - 350, halfH + 100, 100, 100);
    btn->SetOnClickCallback(std::bind(&StageSelectScene::PlayOnClick, this, 6));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("6", "pirulen.ttf", 48, halfW - 300, halfH + 150, 0, 0, 0, 255, 0.5, 0.5));
    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW - 200, halfH + 100, 100, 100);
    btn->SetOnClickCallback(std::bind(&StageSelectScene::PlayOnClick, this, 7));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("7", "pirulen.ttf", 48, halfW - 150, halfH + 150, 0, 0, 0, 255, 0.5, 0.5));
    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW - 50, halfH + 100, 100, 100);
    btn->SetOnClickCallback(std::bind(&StageSelectScene::PlayOnClick, this, 8));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("8", "pirulen.ttf", 48, halfW, halfH + 150, 0, 0, 0, 255, 0.5, 0.5));
    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW + 100, halfH + 100, 100, 100);
    btn->SetOnClickCallback(std::bind(&StageSelectScene::PlayOnClick, this, 9));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("9", "pirulen.ttf", 48, halfW + 150, halfH + 150, 0, 0, 0, 255, 0.5, 0.5));
    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW + 250, halfH + 100, 100, 100);
    btn->SetOnClickCallback(std::bind(&StageSelectScene::PlayOnClick, this, 10));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("10", "pirulen.ttf", 48, halfW + 300, halfH + 150, 0, 0, 0, 255, 0.5, 0.5));
    
    // Not a safe way, however we only free while change scene, so it's fine.
    bgmInstance = al_create_sample_instance(Engine::Resources::GetInstance().GetSample("select.ogg").get());
    al_set_sample_instance_playmode(bgmInstance, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(bgmInstance, al_get_default_mixer());
    al_play_sample_instance(bgmInstance);
    sliderBGM->SetValue(AudioHelper::BGMVolume);
    sliderSFX->SetValue(AudioHelper::SFXVolume);
}
void StageSelectScene::PlayOnClick(int stage) {
    PlayScene* scene = dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetScene("play"));
    scene->MapId = stage;
    Engine::GameEngine::GetInstance().ChangeScene("play");
}
void StageSelectScene::BGMSlideOnValueChanged(float value) {
    al_set_sample_instance_gain(bgmInstance, value);
    AudioHelper::BGMVolume = value;
}
void StageSelectScene::SFXSlideOnValueChanged(float value) {
    AudioHelper::SFXVolume = value;
}
