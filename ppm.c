#include <stdio.h>
#include <math.h>

#define WIDTH 1024
#define HEIGHT 1024

int main() {
  FILE *f;
  f = fopen("rainbow.ppm", "wb");

  fprintf(f, "P6\n");
  fprintf(f, "%d %d 255\n", WIDTH, HEIGHT);

  char r = 0;
  char g = 0;
  char b = 0;
  int val;
  float x = 0.0;
  float y = 0.0;

  for(int i = 0; i < HEIGHT; i++) {
    for(int j = 0; j < WIDTH; j++) {
      x = ( 1.0 * i)/ HEIGHT;
      y = ( 1.0 * j)/ WIDTH;

      r = (int)((1-x) * 255.0);
      b = (int)(x * 255.0);
      g = (int)(y * 255.0);

      fwrite(&r, sizeof(r), 1, f);
      fwrite(&g, sizeof(g), 1, f);
      fwrite(&b, sizeof(b), 1, f);
    }
  }

  fclose(f);

  return 0;
}
