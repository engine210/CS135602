//
//  StaticImageButton.cpp
//  mini_project_2_v3_mycode
//
//  Created by engine210 on 2019/6/2.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <functional>
#include <memory>

#include "Collider.hpp"
#include "GameEngine.hpp"
#include "Image.hpp"
#include "StaticImageButton.hpp"
#include "Point.hpp"
#include "Resources.hpp"

namespace Engine {
    StaticImageButton::StaticImageButton(std::string img, std::string imgIn, float x, float y, float w, float h, float anchorX, float anchorY) :
    Image(img, x, y, w, h, anchorX, anchorY), imgOut(Resources::GetInstance().GetBitmap(img)), imgIn(Resources::GetInstance().GetBitmap(imgIn)) {
        Point mouse = GameEngine::GetInstance().GetMousePosition();
        mouseIn = Collider::IsPointInBitmap(Point((mouse.x - Position.x) * GetBitmapWidth() / Size.x + Anchor.x * GetBitmapWidth(), (mouse.y - Position.y) * GetBitmapHeight() / Size.y + Anchor.y * GetBitmapHeight()), bmp);
        if (!mouseIn || !Enabled) bmp = imgOut;
        else bmp = this->imgIn;
    }
    void StaticImageButton::SetOnClickCallback(std::function<void(void)> onClickCallback) {
        OnClickCallback = onClickCallback;
    }
    void StaticImageButton::OnMouseDown(int button, int mx, int my) {
        if ((button & 1) && mouseIn && Enabled) {
            if (OnClickCallback)
                OnClickCallback();
        }
    }
    void StaticImageButton::OnMouseMove(int mx, int my) {
        //mouseIn = Collider::IsPointInBitmap(Point((mx - Position.x) * GetBitmapWidth() / Size.x + Anchor.x * GetBitmapWidth(), (my - Position.y) * GetBitmapHeight() / Size.y + Anchor.y * GetBitmapHeight()), bmp);
        if (mx > Position.x && mx < Position.x + GetBitmapWidth() && my > Position.y && my < Position.y + GetBitmapHeight()) {
            mouseIn = true;
        }
        else {
            mouseIn = false;
        }
    }
}
