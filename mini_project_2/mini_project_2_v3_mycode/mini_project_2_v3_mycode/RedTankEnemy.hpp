//
//  RedTankEnemy.hpp
//  mini_project_2_v3_mycode
//
//  Created by engine210 on 2019/6/2.
//  Copyright © 2019 engine210. All rights reserved.
//

#ifndef RedTankEnemy_hpp
#define RedTankEnemy_hpp

#include "Enemy.hpp"
#include "Sprite.hpp"

class RedTankEnemy : public Enemy {
private:
    Sprite head;
    float targetRotation;
public:
    RedTankEnemy(int x, int y);
    void Draw() const override;
    void Update(float deltaTime) override;
    
    //new added
    void CreateBullet();
    float coolDown;
    float reload = 0;
    float rotateRadian = 2 * ALLEGRO_PI;
    std::list<RedTankEnemy*>::iterator lockedEnemyIterator;
    // Reference: Design Patterns - Factory Method.
    bool Enabled = true;
    bool Preview = false;
    Turret* Target = nullptr;
    //Turret(std::string imgBase, std::string imgTurret, float x, float y, float radius, int price, float coolDown);
};

#endif /* RedTankEnemy_hpp */
