#define SWAP(x) ( ((x) << 24) | \
         (((x) << 8) & 0x00ff0000) | \
         (((x) >> 8) & 0x0000ff00) | \
         ((x) >> 24) )
#define FIX(x) (*(unsigned *)&(x) = \
         SWAP(*(unsigned *)&(x)))


void write_AVS(RGB** frameBuffer, char* file_name, int Vres, int Hres);
Texture * load_texture_from_AVS(char *file_name);


void write_AVS(RGB** frameBuffer, char* file_name, int Vres, int Hres){
   int row, column;
   int *width, *height;

   FILE *filePtr = fopen(file_name, "w");

   if(filePtr != NULL) {

      /*    Hace el swap a big endian     */
      int fileWidth = SWAP(Hres);
      int fileHeight = SWAP(Vres);

      /*    Crea el header de la imagen      */
      fwrite(&fileWidth, sizeof(unsigned int),1,filePtr);
      fwrite(&fileHeight, sizeof(unsigned int),1,filePtr);

      /*    Escribe los colores     */

         for (int i = Vres - 1; i >= 0; i--) {
            for (int j = 0; j < Hres; j++) {
               fputc(255, filePtr);
               fputc(framebuffer[i][j].r * 255, filePtr);
               fputc(framebuffer[i][j].g * 255, filePtr);
               fputc(framebuffer[i][j].b * 255, filePtr);
            }
         }

   }else
      printf(" Fallo al abrir el archivo %s\n", file_name);


   fclose(filePtr);
}

Texture * load_texture_from_AVS(char *file_name)
{
      int a,r,g,b;
      FILE *fptr;
      int width,height; /* Assumes 4 byte ints */
      Texture * texture;

      texture = NULL;
      /* Attempt to open the file */
      if ((fptr = fopen(file_name,"r")) == NULL) {
            fprintf(stderr,"Failed to open input file \"%s\"\n", file_name);
            return texture;
      }

      /* Read the header */
      fread(&width,sizeof(int),1,fptr);
      width = FIX(width);
      fread(&height,sizeof(int),1,fptr);
      height = FIX(height);

      texture = new_texture(width, height);

      for (int i = height -1; i >= 0; i--) {
            for (int j = 0; j < width; j++) {

            /* Read the current pixel */
            a = fgetc(fptr);
            r = fgetc(fptr);
            g = fgetc(fptr);
            b = fgetc(fptr);

            if (a == EOF || g == EOF || r == EOF || b == EOF) {
                  fprintf(stderr,"Unexpected end of file\n");
                  return texture;
            }

            texture -> texels[i][j].r = (double) r / 256;
            texture -> texels[i][j].g = (double) g / 256;
            texture -> texels[i][j].b = (double) b / 256;

            }
      }
      return texture;
}