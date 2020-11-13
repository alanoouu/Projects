#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Triangle.h"

using namespace shapes;
using namespace testing;

// Failing Tests

TEST(TriangleTests, getPerimeterIncorrect) {
  Triangle isoTri {5, 5, 3};

  int actualIsoPermim = 13;

  ASSERT_EQ(actualIsoPermim, isoTri.getPerimeter());
}

TEST(TriangleTests, getAreaIncorrect) {
  Triangle scaTri {5, 4, 3};

  int actualScaArea = 6;

  ASSERT_EQ(actualScaArea, scaTri.getArea());
}

TEST(TriangleTests, getKindIncorrect) {
  Triangle equTri {3, 3, 3};
  ASSERT_EQ(Triangle::Kind::EQUILATERAL, equTri.getKind());

  Triangle isoTri {80, 41, 41};
  ASSERT_EQ(Triangle::Kind::ISOSCELES, isoTri.getKind());
}

// Passing Tests

TEST(TriangleTests, getPerimeter) {
  Triangle equTri {3, 3, 3};

  int equPermim = 9;

  ASSERT_EQ(equPermim, equTri.getPerimeter());
}

TEST(TriangleTests, getArea) {
  Triangle isoTri {80, 41, 41};

  int actualIsoArea = 360;

  ASSERT_EQ(actualIsoArea, isoTri.getArea());
}

TEST(TriangleTests, getKind) {
  Triangle scaTri {5,4,3};
  ASSERT_EQ(Triangle::Kind::SCALENE, scaTri.getKind());

  ASSERT_FALSE(scaTri.isIsosceles());
  ASSERT_FALSE(scaTri.isEquilateral());
}
