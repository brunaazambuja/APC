/* Compile with:
   gcc solution.c -lm -pedantic -Wall
 */

#include
#include

#define COLS 6
#define VERBOSE 0

/* Function prototypes */	
void read_data(double data[][COLS], int rows);
void read_labels(int labels[], int rows);
void compute_means(double data[][COLS], double means[COLS], int rows);
void compute_stds(double data[][COLS], double means[COLS], double stds[COLS], int rows);
void normalise_data(double data[][COLS], double means[COLS], double stds[COLS], int rows);
double distance(double x1[COLS], double x2[COLS]);  
int insertion_sort(double vetor[], int idx[], int N);
  

int main()
{  
  int n_train, n_test, r, c, K, n_survived, n_died;

  scanf("%d", &K);
  scanf("%d", &n_train);
  scanf("%d", &n_test);

  double Xtrain[n_train][COLS], Xtest[n_test][COLS],
    dists[n_test][n_train],
    means[COLS],
    stds[COLS];
  int labels[n_train], idxs[n_test][n_train];

  /* Load train and test data */
  read_data(Xtrain, n_train);
  read_labels(labels, n_train);
  read_data(Xtest, n_test);

  /* Compute mean, stantard deviation */ 
  compute_means(Xtrain, means, n_train);
  compute_stds(Xtrain, means, stds, n_train);  

  /* Normalising the data: */
  normalise_data(Xtrain, means, stds, n_train);
  normalise_data(Xtest, means, stds, n_test);
  
  /*************** 
   * Classifying */
  for(r=0; r < n_test; r++){
    /* Compute distance matrix. */

    /* Sort the results. */

    /* Classify the sample and print output. */
  }  

  return 0;
}

/*************** 
 * Function definitions */	

void compute_stds(double data[][COLS], double means[COLS], double stds[COLS], int rows){
  /* Inicializacao */
  int r, c;
  for(c=0; c < COLS; c++) stds[c] = 0.0; 

  /* Soma */  
  for(r=0; r < rows; r++)
    for(c=0; c < COLS; c++)
      stds[c] += (data[r][c] - means[c]) * (data[r][c] - means[c]);
   
  /* Divisao e raiz*/
  if(VERBOSE) printf("STDs = ");
  for(c=0; c < COLS; c++){
    stds[c] /= rows;
    stds[c] = sqrt(stds[c]);
    if(VERBOSE) printf("%lf ", stds[c]);    
  }
  if(VERBOSE) printf("\n");
}
		   
double distance(double x1[COLS], double x2[COLS]){
  int c=0;
  double d=0;
  for(; c < COLS; c++) d += (x1[c]-x2[c]) * (x1[c]-x2[c]);
  return sqrt(d);
}