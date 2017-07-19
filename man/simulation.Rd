\name{simulation}
\docType{data}
\alias{simulation}
\title{Simulation dataa for graph-GPA}
\description{
  This is an simulation dataset.
}
\usage{ data(simulation) }
\format{
  \code{simulation} list object containing simulation data (element Y) and its simulation setting (the remaining elements).
}
\references{
Chung D, Kim H, and Zhao H (2016), 
"graph-GPA: A graphical model for prioritizing GWAS results and investigating pleiotropic architecture."

Kim H, Yu Z, Lawson A, Zhao H, and Chung D (2017),
"Improving SNP prioritization and pleiotropic architecture estimation by incorporating prior knowledge using graph-GPA."
}
\author{ Hang J. Kim, Dongjun Chung }
\examples{
\dontrun{
data(simulation)
head(t(simulation$pmat))
}
}
\keyword{datasets}
