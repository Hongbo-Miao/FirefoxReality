/* -*- Mode: C++; tab-width: 20; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VRBROWSER_WIDGET_DOT_H
#define VRBROWSER_WIDGET_DOT_H

#include "vrb/Forward.h"
#include "vrb/MacroUtils.h"

#include <memory>
#include <string>

namespace crow {

class Widget;
typedef std::shared_ptr<Widget> WidgetPtr;

class Widget {
public:
  static WidgetPtr Create(vrb::ContextWeak aContext, const int aType);
  static WidgetPtr Create(vrb::ContextWeak aContext, const int aType, const int32_t aWidth, const int32_t aHeight, float aWorldWidth);
  static WidgetPtr Create(vrb::ContextWeak aContext, const int aType, const int32_t aWidth, const int32_t aHeight, const vrb::Vector& aMin, const vrb::Vector& aMax);
  int32_t GetType() const;
  uint32_t GetHandle() const;
  const std::string& GetSurfaceTextureName() const;
  void GetSurfaceTextureSize(int32_t& aWidth, int32_t& aHeight) const;
  void GetWidgetMinAndMax(vrb::Vector& aMin, vrb::Vector& aMax) const;
  bool TestControllerIntersection(const vrb::Vector& aStartPoint, const vrb::Vector& aDirection, vrb::Vector& aResult, bool& aIsInWidget, float& aDistance) const;
  void ConvertToWidgetCoordinates(const vrb::Vector& aPoint, float& aX, float& aY) const;
  void ConvertToWorldCoordinates(const vrb::Vector& aPoint, vrb::Vector& aResult) const;
  const vrb::Matrix GetTransform() const;
  void SetTransform(const vrb::Matrix& aTransform);
  void ToggleWidget(const bool aEnabled);
  void TogglePointer(const bool aEnabled);
  vrb::NodePtr GetRoot();
  vrb::NodePtr GetPointerGeometry();
  void SetPointerGeometry(vrb::NodePtr& aNode);
protected:
  struct State;
  Widget(State& aState, vrb::ContextWeak& aContext);
  ~Widget();
private:
  State& m;
  Widget() = delete;
  VRB_NO_DEFAULTS(Widget)
};

} // namespace crow

#endif // VRBROWSER_WIDGET_DOT_H
