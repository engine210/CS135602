//
//  StickyTurret.hpp
//  mini_project_2_v3_mycode
//
//  Created by engine210 on 2019/6/1.
//  Copyright © 2019 engine210. All rights reserved.
//

#ifndef StickyTurret_hpp
#define StickyTurret_hpp

#include "Turret.hpp"

class StickyTurret: public Turret {
public:
    static const int Price;
    StickyTurret(float x, float y);
    void CreateBullet() override;
};

#endif /* StickyTurret_hpp */
