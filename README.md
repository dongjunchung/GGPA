graph-GPA
===

graph-GPA is a graphical model for prioritizing GWAS results and investigating pleiotropic architecture. 'GGPA' package provides user friendly interface to fit graph-GPA models, implement association mapping, and generate a phenotype graph.

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

The following two help pages provide a good start point for the genetic analysis using GGPA package, including the overview of GGPA package and the example command lines:

```
library(GGPA)
package?GGPA
class?GGPA
```

References
==========

Chung D, Kim H, and Zhao H (2016), "graph-GPA: A graphical model for prioritizing GWAS results and investigating pleiotropic architecture."
