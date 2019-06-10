//
//  NextStageScene.hpp
//  mini_project_2_v3_mycode
//
//  Created by engine210 on 2019/6/11.
//  Copyright © 2019 engine210. All rights reserved.
//

#ifndef NextStageScene_hpp
#define NextStageScene_hpp

#include "IScene.hpp"

class NextStageScene final : public Engine::IScene {
private:
    float ticks;
public:
    explicit NextStageScene() = default;
    void Initialize() override;
    void Update(float deltaTime) override;
    void BackOnClick();
    void NextOnClick();
};

#endif /* NextStageScene_hpp */
