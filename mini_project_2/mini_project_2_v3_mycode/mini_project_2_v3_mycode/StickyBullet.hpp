//
//  StickyBullet.hpp
//  mini_project_2_v3_mycode
//
//  Created by engine210 on 2019/6/1.
//  Copyright © 2019 engine210. All rights reserved.
//

#ifndef StickyBullet_hpp
#define StickyBullet_hpp

#include "Bullet.hpp"

class Enemy;
class Turret;
namespace Engine {
    struct Point;
}  // namespace Engine

class StickyBullet : public Bullet {
public:
    explicit StickyBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
    void OnExplode(Enemy* enemy) override;
};

#endif /* StickyBullet_hpp */
