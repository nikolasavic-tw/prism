#include <stdio.h>
#include <math.h>

#define WIDTH 1024
#define HEIGHT 1024

int main() {
  FILE *f;
  f = fopen("rainbow.ppm", "wb");

  char* h = "P6\n";
  char* info = "16 16 255\n";
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
      val =  i * j;
      x = ( 1.0 * i)/ HEIGHT;
      y = ( 1.0 * j)/ WIDTH;

      r = (int)((1-x) * 255.0);
      b = (int)(x * 255.0);
      g = (int)(y * 255.0);

      if (0 && i % 500 == 0 && j % 500 ==0) {
        printf("x: %f, y: %f--  r: %d b: %d g: %d", x, y, r, b, g);
      }

      fwrite(&r, sizeof(r), 1, f);
      fwrite(&g, sizeof(g), 1, f);
      fwrite(&b, sizeof(b), 1, f);
    }
  }


  fclose(f);

  return 0;
}
