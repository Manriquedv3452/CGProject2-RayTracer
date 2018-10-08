#define SWAP(x) ( ((x) << 24) | \
         (((x) << 8) & 0x00ff0000) | \
         (((x) >> 8) & 0x0000ff00) | \
         ((x) >> 24) )
#define FIX(x) (*(unsigned *)&(x) = \
         SWAP(*(unsigned *)&(x)))


void write_AVS(RGB** frameBuffer, char* file_name, int Vres, int Hres);

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

         for (int i = Hres - 1; i >= 0; i--) {
            for (int j = 0; j < Vres; j++) {
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