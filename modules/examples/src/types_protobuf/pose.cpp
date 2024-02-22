//=================================================================================================
// Copyright (C) 2023-2024 EOLO Contributors
//=================================================================================================

#include "eolo/examples/types_protobuf/pose.h"

#include "eolo/examples/types_protobuf/geometry.h"

namespace eolo::examples::types {
void toProto(proto::Pose& proto_pose, const Pose& pose) {
  toProto(*proto_pose.mutable_position(), pose.position);
  toProto(*proto_pose.mutable_orientation(), pose.orientation);
}

void fromProto(const proto::Pose& proto_pose, Pose& pose) {
  fromProto(proto_pose.position(), pose.position);
  fromProto(proto_pose.orientation(), pose.orientation);
}

}  // namespace eolo::examples::types
