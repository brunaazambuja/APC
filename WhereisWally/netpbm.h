#ifndef NETPBM_H
#define NETPBM_H

typedef struct{
  unsigned char chns; //canais ((3 canais - colorida))
  unsigned int rows;
  unsigned int cols;
  unsigned char max; //valor max - 255
  unsigned char ***data; //cor, linha, coluna
  char filename[256];
}Image;

int load_img(Image *img); // pega uma imagem e transforma ela
int save_img(Image img); // carregada anteriormente e escreve no disco
int allocate_img(Image *img, unsigned int channels, unsigned int rows, unsigned int cols, unsigned char max);

#endif