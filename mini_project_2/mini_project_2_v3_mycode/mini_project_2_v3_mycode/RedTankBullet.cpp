//
//  RedTankBullet.cpp
//  mini_project_2_v3_mycode
//
//  Created by engine210 on 2019/6/3.
//  Copyright © 2019 engine210. All rights reserved.
//


#include <allegro5/base.h>
#include <random>
#include <string>

#include "DirtyEffect.hpp"
#include "Enemy.hpp"
#include "RedTankBullet.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Turret.hpp"

class Turret;

RedTankBullet::RedTankBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Enemy* parent) :
    EnemyBullet("play/bullet-1.png", 500, 10, position, forwardDirection, rotation - ALLEGRO_PI / 2, parent) {
    // TODO 2 (1/8): You can imitate the 2 files: 'FireBullet.hpp', 'FireBullet.cpp' to create a new bullet.
}
void RedTankBullet::OnExplode(Turret* tower) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(2, 5);
    getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-1.png", dist(rng), tower->Position.x, tower->Position.y));
}
