#pragma once

struct Coordinates {
  double x;
  double y;
  double z;
};

// struct Rotation
// struct Scale

enum GameDimensionType {
  2D,
  3D
};
class Object {
 private:
  Coordinates position;
}
