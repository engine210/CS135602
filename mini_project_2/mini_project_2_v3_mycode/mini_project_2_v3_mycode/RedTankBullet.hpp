//
//  RedTankBullet.hpp
//  mini_project_2_v3_mycode
//
//  Created by engine210 on 2019/6/3.
//  Copyright © 2019 engine210. All rights reserved.
//

#ifndef RedTankBullet_hpp
#define RedTankBullet_hpp

#include "EnemyBullet.hpp"

class Enemy;
class Turret;
namespace Engine {
    struct Point;
}  // namespace Engine

class RedTankBullet : public EnemyBullet {
public:
    explicit RedTankBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Enemy* parent);
    void OnExplode(Turret* tower) override;
};

#endif /* RedTankBullet_hpp */
