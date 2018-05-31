typedef struct linear_eq_{

// var:= number of variables ; eq:= number of restrictions
unsigned var;
unsigned req;

// a:= pointer to matrix; b:= pointer to restriction vector
double **a;
double *b;

} linear_eq, *Plinear_eq;



typedef struct linear_ineq_{


  // var:= number of variables ; eq:= number of restrictions
  unsigned var;
  unsigned rineq;

  // a:= pointer to matrix; b:= pointer to restriction vector
  double **a;
  double *b;


} linear_ineq, *Plinear_ineq;
