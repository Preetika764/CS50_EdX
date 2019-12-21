#include <stdio.h>
#include <stdlib.h>
typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
      fprintf(stderr, "Usage: ./recover image");
      return 1;
  }
  int ctr = 0;
  char filename[8];
  FILE *file = fopen(argv[1], "r");
  FILE *img = NULL;
  if(file == NULL)
  {
      fprintf(stderr,"Could not open file");
      return 1;
  }

    BYTE * buffer = malloc(512);

    while (fread(buffer, 512, 1, file))
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            if (ctr > 0)
            {
                fclose(img);
            }

            sprintf(filename, "%03i.jpg", ctr);

           img = fopen(filename, "w");

            if (img == NULL)
            {
                fclose(file);
                free(buffer);
                fprintf(stderr, "Could not create output JPG %s", filename);
                return 1;
            }

            ctr++;
        }

        if (!ctr)
        {
            continue;
        }


        fwrite(buffer, 512, 1, img);
    }


  fclose(file);
  free(buffer);
  return 0;


}
