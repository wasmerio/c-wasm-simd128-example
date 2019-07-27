#include <cstdio>
#include <random>

typedef float float4 __attribute__((ext_vector_type(4)));

namespace {
constexpr int object_count = 10000;

float4 positions[object_count];
float4 velocities[object_count];

void init_positions() {
  std::mt19937_64 mt;
  std::uniform_real_distribution<float> dist(-127.0, 127.0);
  for (int i = 0; i < object_count; ++i) {
    positions[i] = (float4){dist(mt), dist(mt), dist(mt), dist(mt)};
  }
}

void init_velocities() {
  for (int i = 0; i < object_count; ++i) {
    velocities[i] = (float4){0, 0, 0, 0};
  }
}

float horizontal_add(float4 x) {
  auto partial_sum = x.xy + x.zw;
  return partial_sum.x + partial_sum.y;
}

float distance(float4 x, float4 y) {
  float4 d = y - x;
  float4 d2 = d * d;
  return horizontal_add(d2);
}

void update() {
  for (int i = 0; i < object_count; ++i) {
    for (int j = 0; j < object_count; ++j) {
      float dist = distance(positions[i], positions[j]);
      dist *= dist;
      if (dist == 0)
        continue;
      velocities[i] += (positions[j] - positions[i]) / dist;
    }
  }

  for (int i = 0; i < object_count; ++i) {
    positions[i] += velocities[i];
  }
}

float avg_motion() {
  float4 avg_motion = velocities[0] / (double)object_count;
  for (int i = 1; i < object_count; ++i) {
    avg_motion += velocities[i] / (double)object_count;
  }
  return distance((float4){0, 0, 0, 0}, avg_motion);
}
}

int main(void) {
  init_positions();
  init_velocities();
  std::printf("Beginning simulation.\n");
  fflush(stdout);
  for (int i = 0; i < 20; ++i) {
    update();
    std::printf("%g\n", avg_motion());
    fflush(stdout);
  }
}
