/* Compile with:
   gcc solution.c -lm -pedantic -Wall
*/

#include<stdio.h>
#include<stdlib.h> /* calloc */ 
#include<string.h> /* strcmp */
#include<math.h>   /* sqrt */

#define VERBOSE 0
#define D_TITANIC_HIST 128
#define COLS 6

#define USE_BIAS 0

typedef struct{
  unsigned int rows;
  unsigned int cols;
  double **data;
}Data2D;

typedef struct{
  unsigned int length;
  double *data;
}Data1D;

typedef struct{
  double data;
  unsigned int idx;
}DistanceType;


void free_Data1D(Data1D *labels){
  free(labels->data);
}

void free_Data2D(Data2D *titanic){
  unsigned int r;
  for(r=0; r < titanic->rows; r++)
    free(titanic->data[r]);
  free(titanic->data);
}


unsigned int bind(float x, int boundary){
  return (unsigned int) (x>boundary ? boundary : x); 
}

void print_1D(Data1D *labels){
  unsigned int r;
  if(VERBOSE) printf("%u elements\n", labels->length);
  for(r=0; r < labels->length; r++)
    printf("%.0lf\n", labels->data[r]);
}


void print_2D(Data2D *titanic){
  unsigned int r,c;
  if(VERBOSE) printf("%u rows and %u columns\n", titanic->rows, titanic->cols);
  for(r=0; r < titanic->rows; r++){
    for(c=0; c < titanic->cols; c++)
      printf(" %.3lf", titanic->data[r][c]);
    printf("\n");
  }
}


int read_data(Data2D *titanic){
  /* Lendo tabela e convertendo para numeros */
  unsigned int r;
  char sex, embarked;
  titanic->cols = COLS;

  titanic->data = (double **) malloc(titanic->rows * sizeof(double *));
  if(titanic->data == NULL) return(0);
	 
  for(r=0; r < titanic->rows; r++){
    titanic->data[r] = (double *) calloc(titanic->cols, sizeof(double));
    if(titanic->data[r] == NULL) return(0);
  }

  /* Lendo tabela e convertendo para numeros */
  for(r=0; r < titanic->rows; r++) {
    scanf("%lf %c %lf %lf %lf %c", &titanic->data[r][0], &sex, &titanic->data[r][2], &titanic->data[r][3], &titanic->data[r][4], &embarked);
    if(VERBOSE) printf("%lf %c %lf %lf %lf %c\n", titanic->data[r][0], sex, titanic->data[r][2], titanic->data[r][3], titanic->data[r][4], embarked); 
    titanic->data[r][1] = sex=='f';
    titanic->data[r][5] = (embarked=='Q' ? 2 : embarked=='C');
  }
  return(1);
}

int read_labels(Data1D *labels){
  unsigned int r;
  
  labels->data = (double *) malloc(labels->length * sizeof(double));
  if(labels->data == NULL) return(0);
	 
  for(r=0; r < labels->length; r++){
    scanf("%lf", &labels->data[r]);
    if(VERBOSE) printf("%lf\n", labels->data[r]);
  }
  return(1);
}

int classify_rules(Data2D *titanic, Data1D *Y){

  /* 
     Implemente um classificador baseado no gabarito da
     primeira prova teorica, i.e., um passageiro morre 
     se sua idade for maior que 15 e menor ou igual a 45
     ou se o sexo for 1 e a classe for maior que 1. 
     Coloque o resultado em Y->data[]
     Retorne 1 quando o classificador funcionar.
  */ 
}

int titanic_hvec(Data2D *titanic, Data2D *h){
  unsigned int classe, sexo, idade, parceiros, filhos, embarque, counter, r;
  
  h->rows = titanic->rows;
  h->cols = D_TITANIC_HIST;

  h->data = (double **) calloc(h->rows, sizeof(double *));
  if(h->data == NULL) return(0);

  for(r=0; r < h->rows; r++){
    h->data[r] = (double *) calloc(h->cols, sizeof(double));
    if(h->data[r] == NULL) return(0);
  }

  for(r=0; r < h->rows; r++){
    counter = 0;
    classe =         titanic->data[r][0];
    sexo =           titanic->data[r][1];
    idade =     bind(titanic->data[r][2], 99);
    parceiros = bind(titanic->data[r][3], 9);
    filhos =    bind(titanic->data[r][4], 9);
    embarque =       titanic->data[r][5];

    h->data[r][classe-1]++;
    counter += 3;
    h->data[r][sexo+counter]++;
    counter += 2;
    h->data[r][idade+counter]++;
    counter += 100;
    h->data[r][parceiros+counter]++;
    counter += 10;
    h->data[r][filhos+counter]++;
    counter += 10;
    h->data[r][embarque+counter]++;
  }
  return(1);
}

int train_hist_classifier(Data2D *train_h, Data1D *train_labels, Data1D *hist_classifier){
  unsigned int r, c;
  double bias=0.0; /* Compensates for class unbalance. */
  hist_classifier->length = train_h->cols;
  hist_classifier->data = (double *) calloc(hist_classifier->length, sizeof(double));
  if(hist_classifier->data == NULL) return(0);

  if(USE_BIAS){
    for(r=0; r < train_labels->length; r++){
      bias += train_labels->data[r];
    }
    bias /= (double)train_labels->length;
    bias = (bias - .5)*2;
    if(VERBOSE) printf("bias = %lf\n", bias);
  }
  
  for(c=0; c < train_h->cols; c++){
    /* Count survivals (positive) or deahs (negative): */
    for(r=0; r < train_h->rows; r++){
      hist_classifier->data[c] += train_h->data[r][c] * (2*train_labels->data[r]-1);
    }
    hist_classifier->data[c] /= train_h->rows;
    /* Convert it to -1, 0 or +1: */
    /* if the dataset is ballanced, bias ==  0, 
       if all samples are negative, bias == -1,
       if all samples are positive, bias ==  1
    */
    hist_classifier->data[c] = (hist_classifier->data[c] < bias ? -1 : hist_classifier->data[c] > bias); 
    
  }
  return(1);
}

int classify_hist(Data2D *hists, Data1D *hist_classifier, Data1D *Y){
  /* 
     Implemente um classificador baseado nos histogramas da
     primeira prova pratica em que:
     * hists armazena a matriz de dados em que cada amostra foi convertida
       para um vetor binario usado para calcular histograms.
     * hist_classifier armazena o vetor de classificacao, criado para a
       ultima tarefa da prova pratica 1.
     * Para cada vetor de elemento de teste (em hists), calcule o produto 
       interno entre ele e o vetor hist_classifier.
       Se o resultado for > 0, classifique-o (no vetor Y) como 1 (sobreviveu). 
       Caso contrario, classifique-o como 0 (morreu).     
     Retorne 1 para indicar sucesso.
  */  
}

int compute_means(Data2D *titanic, Data1D *means){
  unsigned int r, c;
  
  means->length = titanic->cols;
  means->data = (double *) calloc(means->length, sizeof(double));
  if(means->data == NULL) return(0);
  
  /* Soma */
  for(r=0;r < titanic->rows;r++)
    for(c=0; c < titanic->cols; c++)
      means->data[c] += titanic->data[r][c];
   
  /* Divisao */
  for(c=0; c < titanic->cols; c++){
    means->data[c] /= titanic->rows;
  }
  return(1);
}

int compute_stds(Data2D *titanic, Data1D *means, Data1D *stds){
  unsigned int r, c;

  stds->length = titanic->cols;
  stds->data = (double *) calloc(stds->length, sizeof(double));
  if(stds->data == NULL) return(0);

  /* Soma */  
  for(r=0;r<titanic->rows;r++)
    for(c=0; c < titanic->cols; c++)
      stds->data[c] += (titanic->data[r][c] - means->data[c]) * (titanic->data[r][c] - means->data[c]);
   
  /* Divisao e raiz*/
  for(c=0; c < titanic->cols; c++){
    stds->data[c] /= titanic->rows;
    stds->data[c] = sqrt(stds->data[c]);
  }
  return(1);
}

void normalise_data(Data2D *titanic, Data1D *means, Data1D *stds){
  unsigned int r, c;
  for(r=0; r < titanic->rows; r++) {
    for(c=0; c < titanic->cols; c++) {
      titanic->data[r][c] -= means->data[c];
      titanic->data[r][c] /= stds->data[c];
    }
  }  
}

double distance(double *x1, double *x2, unsigned int cols){
  unsigned int c=0;
  double d=0;
  for(; c<cols; c++) d += (x1[c]-x2[c]) * (x1[c]-x2[c]);
  return sqrt(d);
}

unsigned int SortK(DistanceType *vector, int N, int K){
  unsigned int i, k;
  unsigned int operations=0;
  DistanceType aux;
  /* aux.data = 3.402823e+38;  FLT_MAX */

  for(k=0; k<K; k++){
    for(i=k+1; i<N; i++){
      operations++;
      if(vector[i].data < vector[k].data){
	aux = vector[i];
	vector[i] = vector[k];
	vector[k] = aux;
      }
    }
  }
  return(operations);
}

int classify_KNN(Data2D *train, Data1D *labels, Data2D *test, Data1D *Y, unsigned int K){
  unsigned int r, c, k, morreu, sobreviveu;
  DistanceType *dists = (DistanceType *) calloc(train->rows, sizeof(DistanceType));  
  if(dists==NULL) return(0);

  /* Implemente o classificador de K-vizinhos mais proximos. */
  
  return(1);
}

int main(void){
  Data2D train, test, train_h, test_h;
  Data1D train_labels, hist_classifier, Y, means, stds;
  unsigned int T;

  scanf("%u", &T);
  scanf("%u", &train.rows);
  scanf("%u", &test.rows);
  train_labels.length = train.rows;
  
  read_data(&train);
  read_labels(&train_labels);
  read_data(&test);

  Y.length = test.rows;
  Y.data = (double *) calloc(Y.length, sizeof(double));

  if(VERBOSE){
    print_2D(&train);
    print_2D(&test);    
    print_1D(&train_labels);
  }
  
  switch(T){
  case 0:  
    classify_rules(&test, &Y);
    break;

  case 1:
    titanic_hvec(&train, &train_h);
    titanic_hvec(&test, &test_h);
    train_hist_classifier(&train_h, &train_labels, &hist_classifier);

    if(VERBOSE){
      print_2D(&train_h);
      print_2D(&test_h);
      print_1D(&hist_classifier);
    }

    classify_hist(&test_h, &hist_classifier, &Y);
    free_Data2D(&train_h);
    free_Data2D(&test_h);
    free_Data1D(&hist_classifier);
    break;

  case 2:
    classify_KNN(&train, &train_labels, &test, &Y, 1);
    break;

  case 3:
    /* 
       Classifique os dados usando KNN para K=11
    */
    break;

  default:
    /* 
       Normalize os dados antes de classifica-los.
       ...
    */

    free_Data1D(&means);
    free_Data1D(&stds);  

    if(T==4){
      /* 
	 Classifique os dados normalizados usando KNN para K=1
      */
    }
    if(T==5){
      /* 
	 Classifique os dados normalizados usando KNN para K=11
      */
    }
  }
  print_1D(&Y);
  
  free_Data2D(&train);
  free_Data2D(&test);
  free_Data1D(&train_labels);
  free_Data1D(&Y);
  return 0;
}
