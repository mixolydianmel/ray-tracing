#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <ostream>

class vec3 {
public:
  float e[3];

  // Constructors w/ member initializers
  vec3() : e{0, 0, 0} {}
  vec3(float x, float y, float z) : e{x, y, z} {}

  // Getters
  inline float x() const { return e[0]; }
  inline float y() const { return e[1]; }
  inline float z() const { return e[2]; }

  // Negation
  vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }

  // Array accessors
  float operator[](unsigned int idx) const { return e[idx]; }
  float &operator[](unsigned int idx) { return e[idx]; }

  // Add
  vec3 &operator+=(const vec3 &o) {
    e[0] += o.e[0];
    e[1] += o.e[1];
    e[2] += o.e[2];
    return *this;
  }

  // Sub
  vec3 &operator-=(const vec3 &o) { return *this += -o; }

  // Mul
  vec3 &operator*=(float t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
  }

  // Div
  vec3 &operator/=(float t) { return *this *= 1 / t; }

  float length() const { return std::sqrt(length_squared()); }

  float length_squared() const {
    return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
  }
};

// alias
using point3 = vec3;

// printing
inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
  return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

// utils
inline vec3 operator+(const vec3 &u, const vec3 &v) {
  return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3 &u, const vec3 &v) {
  return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3 &u, const vec3 &v) {
  return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator/(const vec3 &u, const vec3 &v) {
  return vec3(u.e[0] / v.e[0], u.e[1] / v.e[1], u.e[2] / v.e[2]);
}

inline vec3 operator*(float t, const vec3 &v) {
  return vec3(v.e[0]*t, v.e[1]*t, v.e[2]*t);
}

inline vec3 operator*(const vec3 &v, float t) {
  return t * v;
}

inline vec3 operator/(const vec3 &v, float t) {
  return (1/t) * v;
}

inline float dot(const vec3 &u, const vec3 &v) {
  return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2];
}

inline vec3 cross(const vec3 &u, const vec3 &v) {
  return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
              u.e[2] * v.e[0] - u.e[0] * v.e[2],
              u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(const vec3& v) {
  return v / v.length();
}

#endif
