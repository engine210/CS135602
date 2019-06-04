//
//  StickyTurret.cpp
//  mini_project_2_v3_mycode
//
//  Created by engine210 on 2019/6/1.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "FireBullet.hpp"
#include "Group.hpp"
#include "StickyTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"

const int StickyTurret::Price = 400;
StickyTurret::StickyTurret(float x, float y) :
// TODO 2 (2/8): You can imitate the 2 files: 'MachineGunTurret.hpp', 'MachineGunTurret.cpp' to create a new turret.
Turret("play/tower-base.png", "play/turret-6.png", x, y, 400, Price, 0.1) {
    // Move center downward, since we the turret head is slightly biased upward.
    Anchor.y += 8.0f / GetBitmapHeight();
}
void StickyTurret::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    // Change bullet position to the front of the gun barrel.
    getPlayScene()->BulletGroup->AddNewObject(new FireBullet(Position + normalized * 36, diff, rotation, this));
    AudioHelper::PlayAudio("gun.wav");
}
