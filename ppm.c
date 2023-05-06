#include <stdio.h>
#include <math.h>

#define WIDTH 1024
#define HEIGHT 1024

int main() {
  FILE *f;
  f = fopen("rainbow.ppm", "wb");

  fprintf(f, "P6\n");
  fprintf(f, "%d %d 255\n", WIDTH, HEIGHT);

  char r, g, b;
  float x, y;

  for(int i = 0; i < HEIGHT; i++) {
    for(int j = 0; j < WIDTH; j++) {
      y = ( 1.0 * i)/ HEIGHT;
      x = ( 1.0 * j)/ WIDTH;

      r = (int)((1-y) * 255);
      b = (int)(y * 255);
      g = (int)(x * 255);

      fwrite(&r, sizeof(r), 1, f);
      fwrite(&g, sizeof(g), 1, f);
      fwrite(&b, sizeof(b), 1, f);
    }
  }

  fclose(f);

  return 0;
}
