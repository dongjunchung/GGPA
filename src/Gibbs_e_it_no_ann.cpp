// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-

#include "RcppArmadillo.h"
#include <Rmath.h>

// [[Rcpp::export]]
arma::mat Gibbs_e_it_no_ann(arma::mat beta_mat, arma::mat G_mat, int n_SNP, int n_GibbsStep){
  
  int n_pheno = beta_mat.n_rows ; // i=1,...,n_pheno,  t=1,...,n_SNP
  
  arma::mat e_it(n_pheno,n_SNP) ; // filled with 0
  
  for (int i_iter=1; i_iter<=n_GibbsStep; i_iter++){
    int no_eit_1 = 0 ; 
    for (int t=0; t<n_SNP; t++){
      // Rprintf("%d ",t) ; 
      for (int i=0; i<n_pheno; i++){
        // double nu_i = 1.0 / ( 1.0 + 1.0/exp(beta_mat(i,i)) ) ;
        double unnorm_logprob1 = beta_mat(i,i) ;
        double unnorm_logprob0 = 0.0 ; 
        for (int j=0; j<n_pheno; j++){
          if (G_mat(i,j)==1){
            // double nu_j = 1.0 / ( 1.0 + 1.0/exp(beta_mat(j,j)) ) ;
            unnorm_logprob1 = unnorm_logprob1 + beta_mat(i,j) * 1.0 * e_it(j,t) ; 
            // unnorm_logprob0 = unnorm_logprob0 + beta_mat(i,j) * (-nu_i) * (e_it(j,t)-nu_j) ; 
          }
        }
        double prob_e_it = 1.0 / ( 1.0 + exp(unnorm_logprob0-unnorm_logprob1) ) ; 
        if ( prob_e_it >= R::runif(0,1) ){
          e_it(i,t) = 1 ; no_eit_1 ++ ; 
        } else {
          e_it(i,t) = 0 ; 
        }
      } // i=0~(n_pheno-1)
    } // t=0~(n_SNP-1)
    if (i_iter%100==0){
      Rprintf("iter: %d", i_iter);
      Rprintf(", total no. of e_it=1: %d \n", no_eit_1); 
    }
  } // i_iter 
  
//   for (int t=0; t<n_SNP; t++){
//     for (int i=0; i<n_pheno; i++){
//       Rprintf("%.1f ", e_it(i,t));
//     }
//     Rprintf("\n");
//   }
  
  return e_it ; 
  
}


// http://gallery.rcpp.org/articles/random-number-generation/
//
// Section 6.3 of Writing R Extensions describes an additional requirement for 
// calling the R random number generation functions: you must call GetRNGState 
// prior to using them and then PutRNGState afterwards. These functions (respectively) 
// read .Random.seed and then write it out after use.
// When using Rcpp attributes (as we do via the // [[Rcpp::export]] annotation 
// on the functions above) it is not necessary to call GetRNGState and PutRNGState 
// because this is done automatically within the wrapper code generated for exported functions. 
// In fact, since these calls don’t nest it is actually an error to call them when within a function exported via Rcpp attributes.
// In the case where you are writing an Rcpp function that doesn’t use Rcpp attributes 
// (e.g. a function using a raw SEXP interface that is exported via extern C) Rcpp 
// exposes a convenience class you can use to get and put the RNG state.

  
  


// [1] "iter=1, Total no. of e_it=139015"
// [1] "iter=2, Total no. of e_it=140472"
// [1] "iter=3, Total no. of e_it=140590"
// [1] "iter=4, Total no. of e_it=140420"
// [1] "iter=5, Total no. of e_it=140465"
// [1] "iter=6, Total no. of e_it=140715"
// [1] "iter=7, Total no. of e_it=140289"
// [1] "iter=8, Total no. of e_it=140298"
// [1] "iter=9, Total no. of e_it=140599"
// [1] "iter=10, Total no. of e_it=140870"
// [1] "iter=11, Total no. of e_it=140569"
// [1] "iter=12, Total no. of e_it=140658"
// [1] "iter=13, Total no. of e_it=140642"
// [1] "iter=14, Total no. of e_it=140625"
// [1] "iter=15, Total no. of e_it=140401"
// [1] "iter=16, Total no. of e_it=140632"
// [1] "iter=17, Total no. of e_it=140891"
// [1] "iter=18, Total no. of e_it=140371"
// [1] "iter=19, Total no. of e_it=140815"
// [1] "iter=20, Total no. of e_it=140644"
// [1] "iter=21, Total no. of e_it=140691"
// [1] "iter=22, Total no. of e_it=140505"
// [1] "iter=23, Total no. of e_it=140653"
// [1] "iter=24, Total no. of e_it=140534"
// [1] "iter=25, Total no. of e_it=140634"
// [1] "iter=26, Total no. of e_it=140603"
// [1] "iter=27, Total no. of e_it=140702"
// [1] "iter=28, Total no. of e_it=140601"
// [1] "iter=29, Total no. of e_it=140496"
// [1] "iter=30, Total no. of e_it=140591"
// [1] "iter=31, Total no. of e_it=140722"
// [1] "iter=32, Total no. of e_it=140781"
// [1] "iter=33, Total no. of e_it=140586"
// [1] "iter=34, Total no. of e_it=140471"
// [1] "iter=35, Total no. of e_it=140535"
// [1] "iter=36, Total no. of e_it=140467"
// [1] "iter=37, Total no. of e_it=140530"
// [1] "iter=38, Total no. of e_it=140747"
// [1] "iter=39, Total no. of e_it=140856"
// [1] "iter=40, Total no. of e_it=140681"
// [1] "iter=41, Total no. of e_it=140458"
// [1] "iter=42, Total no. of e_it=140510"
// [1] "iter=43, Total no. of e_it=140489"
// [1] "iter=44, Total no. of e_it=140594"
// [1] "iter=45, Total no. of e_it=140470"
// [1] "iter=46, Total no. of e_it=140518"
