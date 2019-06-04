//
//  RedTankEnemy.cpp
//  mini_project_2_v3_mycode
//
//  Created by engine210 on 2019/6/2.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <allegro5/base.h>
#include <random>
#include <string>

#include "Point.hpp"
#include "RedTankEnemy.hpp"
#include "AudioHelper.hpp"
#include "PlayScene.hpp"
#include "RedTankBullet.hpp"
#include "Turret.hpp"
#include "list"

RedTankEnemy::RedTankEnemy(int x, int y) : Enemy("play/enemy-5-2.png", x, y, 20, 20, 50, 200), head("play/enemy-5-head.png", x, y), targetRotation(0) {
    CollisionRadius = 200;
    coolDown = 0.5;
    smallRadius = 20;
}

void RedTankEnemy::Draw() const {
    Enemy::Draw();
    head.Draw();
}
void RedTankEnemy::Update(float deltaTime) {
    Enemy::Update(deltaTime);
    head.Position = Position;
    
    //new added
    Sprite::Update(deltaTime);
    PlayScene* scene = getPlayScene();
    //imgBase.Position = Position;
    //imgBase.Tint = Tint;
    if (!Enabled)
        return;
    if (Target) {
        Engine::Point diff = Target->Position - Position;
        if (diff.Magnitude() > CollisionRadius) {
            Target->lockedEnemys.erase(lockedEnemyIterator);
            Target = nullptr;
            lockedEnemyIterator = std::list<RedTankEnemy*>::iterator();
        }
    }
    if (!Target) {
        // Lock first seen target.
        // Can be improved by Spatial Hash, Quad Tree, ...
        // However simply loop through all enemies is enough for this program.
        for (auto& it : scene->TowerGroup->GetObjects()) {
            Engine::Point diff = it->Position - Position;
            if (diff.Magnitude() <= CollisionRadius) {
                Target = dynamic_cast<Turret*>(it);
                Target->lockedEnemys.push_back(this);
                lockedEnemyIterator = std::prev(Target->lockedEnemys.end());
                break;
            }
        }
    }
    if (Target) {
        Engine::Point originRotation = Engine::Point(cos(head.Rotation - ALLEGRO_PI / 2), sin(head.Rotation - ALLEGRO_PI / 2));
        Engine::Point targetRotation = (Target->Position - Position).Normalize();
        float maxRotateRadian = rotateRadian * deltaTime;
        float cosTheta = originRotation.Dot(targetRotation);
        // Might have floating-point precision error.
        if (cosTheta > 1) cosTheta = 1;
        else if (cosTheta < -1) cosTheta = -1;
        float radian = acos(cosTheta);
        Engine::Point rotation;
        if (abs(radian) <= maxRotateRadian)
            rotation = targetRotation;
        else
            rotation = ((abs(radian) - maxRotateRadian) * originRotation + maxRotateRadian * targetRotation) / radian;
        // Add 90 degrees (PI/2 radian), since we assume the image is oriented upward.
        head.Rotation = atan2(rotation.y, rotation.x) + ALLEGRO_PI / 2;
        // Shoot reload.
        reload -= deltaTime;
        if (reload <= 0) {
            // shoot.
            reload = coolDown;
            CreateBullet();
        }
    }
}

//new added
void RedTankEnemy::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(head.Rotation - ALLEGRO_PI / 2), sin(head.Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    Engine::Point normal = Engine::Point(-normalized.y, normalized.x);
    // Change bullet position to the front of the gun barrel.
    getPlayScene()->BulletGroup->AddNewObject(new RedTankBullet(Position + normalized * 10 - normal * 6, diff, rotation, this));
    getPlayScene()->BulletGroup->AddNewObject(new RedTankBullet(Position + normalized * 10 + normal * 6, diff, rotation, this));
    AudioHelper::PlayAudio("missile.wav");
}
