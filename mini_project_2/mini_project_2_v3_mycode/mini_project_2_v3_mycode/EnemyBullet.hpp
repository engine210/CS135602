//
//  EnemyBullet.hpp
//  mini_project_2_v3_mycode
//
//  Created by engine210 on 2019/6/3.
//  Copyright © 2019 engine210. All rights reserved.
//

#ifndef EnemyBullet_hpp
#define EnemyBullet_hpp

#include <string>

#include "Sprite.hpp"
#include "Enemy.hpp"

class Enemy;
class PlayScene;
class Turret;
namespace Engine {
    struct Point;
}  // namespace Engine

class EnemyBullet : public Engine::Sprite {
protected:
    float speed;
    float damage;
    Enemy* parent;
    PlayScene* getPlayScene();
    virtual void OnExplode(Turret* enemy);
public:
    Enemy* Target = nullptr;
    explicit EnemyBullet(std::string img, float speed, float damage, Engine::Point position, Engine::Point forwardDirection, float rotation, Enemy* parent);
    void Update(float deltaTime) override;
};

#endif /* EnemyBullet_hpp */
