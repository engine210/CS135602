//
//  EnemyBullet.cpp
//  mini_project_2_v3_mycode
//
//  Created by engine210 on 2019/6/3.
//  Copyright © 2019 engine210. All rights reserved.
//

#include "EnemyBullet.hpp"
#include "Collider.hpp"
#include "Turret.hpp"
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IObject.hpp"
#include "IScene.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Sprite.hpp"

PlayScene* EnemyBullet::getPlayScene() {
    return dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetActiveScene());
}

void EnemyBullet::OnExplode(Turret* enemy) {}

EnemyBullet::EnemyBullet(std::string img, float speed, float damage, Engine::Point position, Engine::Point forwardDirection, float rotation, Enemy* parent) :
Sprite(img, position.x, position.y), speed(speed), damage(damage), parent(parent) {
    Velocity = forwardDirection.Normalize() * speed;
    Rotation = rotation;
    CollisionRadius = 4;
}

void EnemyBullet::Update(float deltaTime) {
    Sprite::Update(deltaTime);
    PlayScene* scene = getPlayScene();
    // Can be improved by Spatial Hash, Quad Tree, ...
    // However simply loop through all enemies is enough for this program.
    for (auto& it : scene->TowerGroup->GetObjects()) {
        Turret* tower = dynamic_cast<Turret*>(it);
        //Enemy* enemy = dynamic_cast<Enemy*>(it);
        if (!tower->Visible)
            continue;
        if (Engine::Collider::IsCircleOverlap(Position, CollisionRadius, tower->Position, tower->smallRadius)) {
            OnExplode(tower);
            tower->Hit(damage);
            getPlayScene()->BulletGroup->RemoveObject(objectIterator);
            return;
        }
    }
    // Check if out of boundary.4
    if (!Engine::Collider::IsRectOverlap(Position - Size / 2, Position + Size / 2, Engine::Point(0, 0), PlayScene::GetClientSize()))
        getPlayScene()->BulletGroup->RemoveObject(objectIterator);
}
