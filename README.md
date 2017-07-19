graph-GPA
===

graph-GPA is a graphical model for prioritizing GWAS results and investigating pleiotropic architecture. 'GGPA' package provides user-friendly interface to fit graph-GPA models, implement association mapping, and generate a phenotype graph. From its version 0.9.5, it also allows to utilize a prior phenotype graph.

Installation
===========

To install the development version of GGPA, it's easiest to use the 'devtools' package. Note that GGPA depends on the 'Rcpp' package, which also requires appropriate setting of Rtools and Xcode for Windows and Mac OS/X, respectively.

```
#install.packages("devtools")
library(devtools)
install_github("dongjunchung/GGPA")
```

Usage
===========

The R package vignette will provide a good start point for the genetic analysis using GGPA package, including the overview of GGPA package and the example command lines:

```
library(GGPA)
vignette("GGPA-example")
```
The following two help pages will also provide quick references for GGPA package and the example command lines:

```
package?GGPA
class?GGPA
```

References
==========

Chung D, Kim H, and Zhao H (2017), "graph-GPA: A graphical model for prioritizing GWAS results and investigating pleiotropic architecture," PLOS Computational Biology, 13(2): e1005388.

Kim H, Yu Z, Lawson A, Zhao H, and Chung D (2017), "Improving SNP prioritization and pleiotropic architecture estimation by incorporating prior knowledge using graph-GPA"
