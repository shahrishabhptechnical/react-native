/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <memory>

#include <react/components/root/RootProps.h>
#include <react/components/view/ConcreteViewShadowNode.h>
#include <react/core/LayoutContext.h>

namespace facebook {
namespace react {

class RootShadowNode;

using SharedRootShadowNode = std::shared_ptr<const RootShadowNode>;
using UnsharedRootShadowNode = std::shared_ptr<RootShadowNode>;

extern const char RootComponentName[];

/*
 * `ShadowNode` for the root component.
 * Besides all functionality of the `View` component, `RootShadowNode` contains
 * props which represent external layout constraints and context of the
 * shadow tree.
 */
class RootShadowNode final
    : public ConcreteViewShadowNode<RootComponentName, RootProps> {
 public:
  using ConcreteViewShadowNode::ConcreteViewShadowNode;

  /*
   * Layouts the shadow tree.
   */
  void layout();

 private:
  using YogaLayoutableShadowNode::layout;
};

} // namespace react
} // namespace facebook
