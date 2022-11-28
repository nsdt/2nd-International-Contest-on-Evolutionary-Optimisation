**THIS PAGE IS UNDER REVISIONS -- still not complete** 

A complete information of the test function suite for 
1st and 2nd International Contest on Evolutionary Optimization (ICEO) is reproduced here.

* Here all 7 functions of 2nd ICEO and original source codes are excavated from web archive.
* The original source we used was here (link not found) : http://iridia.ulbac.be/~aroli/ICEO/Functions/Functions.html.
* It has been searched at the wayback machine : https://web.archive.org/
* A screenshot of the web page is also included in this git repository : 1996_2nd_ICEO_Test_Problems_by_Seront.pdf

* Among 5 test functions of 1st ICEO, 2 of them seems the same with those used in 2nd ICEO.
* Thus, 2 test functions (Sphere and Griewank) is also reproduced here.
* All of them are rewritten in C++ for convenience with a test code to check consistency.

### 1. The Sphere Model (1st ICEO)
$$f({\bf x}) = \sum_{i=1}^{N} (x_{i} - 1)^{2}, $$<br />
with search range $-5 \le x_{i} \le 5$.

It is evident that the function becomes the minimum 
$f({\bf x}^{\*}) = 0$ at ${\bf x}^{\*} = (1, 1, \cdots, 1)$

### 2. The Griewank's function (1st ICEO)
$$f({\bf x}) = 1 + \frac{1}{d} \sum_{i=1}^{N} (x_{i} - 100)^{2} - \prod_{i=1}^{N} \cos\left( \frac{x_{i} - 100}{\sqrt{i}} \right), $$<br />
where $d = 4000$. 
The search range is $-600 \le x_{i} \le 600$.

### 3. The Michalewicz' function (1st ICEO)
$$f({\bf x}) = -\sum_{i=1}^{N} \sin(x_{i}) \sin^{2m}\left( \frac{ix_{i}^{2}}{\pi} \right), $$<br />
where the parameter $m = 10$ 
with search range $0 \le x_{i} \le \pi$.
I couldn't find what are $N$ experimented in 1st ICEO, but $N = 5$ and $10$ may be used.

### 4. The Epistatic Michalewicz' function (2nd ICEO)
$$f({\bf x}) = -\sum_{i=1}^{N} \sin(y_{i}) \sin^{2m}\left( \frac{iy_{i}^{2}}{\pi} \right), $$<br />
where 

$$y_{i} = 
\left(
\begin{array}{ll}
x_{i} \cos\left( \frac{\pi}{6} \right) - x_{i+1} \sin\left( \frac{\pi}{6} \right), & i = 1, 3, 5, \cdots, {\rm odd}, \\ 
x_{i-1} \sin\left( \frac{\pi}{6} \right) + x_{i} \cos\left( \frac{\pi}{6} \right), & i = 2, 4, 6, \cdots, {\rm even}, \\ 
x_{N}, & i = N, \\
\end{array} 
\right. ,$$
<br />

and the parameter $m = 10$ 
with search range $0 \le x_{i} \le \pi$.
In 2nd ICEO, $N = 5$ and $10$ are used.

### 5. The (modified?) Langerman function (1st and 2nd ICEO)
Although, the name is the Langarman's function in 1st ICEO, and there is the "modified" Langarman function in 2nd ICEO, I cannot find any difference.
$$f({\bf x}) = -\sum_{i=1}^{m} c_{i} \left[ \exp\left( -\frac{L_{2}^{2}(i)}{\pi} \cos\left( \pi L_{2}^{2}(i) \right) \right) \right], $$<br />
where $$L_{2}(i) = \sqrt{ \sum_{j=1}^{N} (x_{j} - A_{ij})^{2} },$$<br />
and the parameters $m = 5$ (in the source web page of 2nd ICEO, m = 15 in the equation, but m = 5 in the source code), 

$${\bf A} =
\begin{bmatrix}
9.681 & 0.667 & 4.783 & 9.095 & 3.517 & 9.325 & 6.544 & 0.211 & 5.122 & 2.020 \\ 
9.400 & 2.041 & 3.788 & 7.931 & 2.882 & 2.672 & 3.568 & 1.284 & 7.033 & 7.374 \\
8.025 & 9.152 & 5.114 & 7.621 & 4.564 & 4.711 & 2.996 & 6.126 & 0.734 & 4.982 \\ 
2.196 & 0.415 & 5.649 & 6.979 & 9.510 & 9.166 & 6.304 & 6.054 & 9.377 & 1.426 \\ 
8.074 & 8.777 & 3.467 & 1.863 & 6.708 & 6.349 & 4.534 & 0.276 & 7.633 & 1.567
\end{bmatrix},$$

${\bf c} = \left( 0.806, 0.517, 0.1, 0.908, 0.965 \right)$
with search range $0 \le x_{i} \le 10$.
In 2nd ICEO, $N = 5$ and $10$ are used.

### 6. The (modified?) Shekel's foxhole (1st and 2nd ICEO)
The name is the Shekel's foxholes function in 1st ICEO, and there is the "modified" Shekel's foxhole function in 2nd ICEO.
According to the screen shot of web archive, there is no constant term $c_{i}$ added in the denominator in the 2nd ICEO version. It might be the difference, however, it is strange because the function becomes $-\infty$ without this term at ${\bf x} = ({\bf A}(i))$ which can be found within the search range. 
Therefore, I believe there is no difference between the 1st and 2nd ICEO versions.
$$f({\bf x}) = -\sum_{i=1}^{m} \frac{1}{L_{2}^{2}(i) + c_{i}},$$
where $$L_{2}(i) = \sqrt{ \sum_{j=1}^{N} (x_{j} - A_{ij})^{2} },$$
which is the same with the modified Langerman function.
The parameter $m = 30$.
The first 5 rows of ${\bf A}$ and the first 5 elements of ${\bf c}$ are the same with 
the modified Langerman function.

$${\bf A} =
\begin{bmatrix}
9.681 & 0.667 & 4.783 & 9.095 & 3.517 & 9.325 & 6.544 & 0.211 & 5.122 & 2.020 \\
9.400 & 2.041 & 3.788 & 7.931 & 2.882 & 2.672 & 3.568 & 1.284 & 7.033 & 7.374 \\
8.025 & 9.152 & 5.114 & 7.621 & 4.564 & 4.711 & 2.996 & 6.126 & 0.734 & 4.982 \\
2.196 & 0.415 & 5.649 & 6.979 & 9.510 & 9.166 & 6.304 & 6.054 & 9.377 & 1.426 \\
8.074 & 8.777 & 3.467 & 1.863 & 6.708 & 6.349 & 4.534 & 0.276 & 7.633 & 1.567 \\
7.650 & 5.658 & 0.720 & 2.764 & 3.278 & 5.283 & 7.474 & 6.274 & 1.409 & 8.208 \\
1.256 & 3.605 & 8.623 & 6.905 & 0.584 & 8.133 & 6.071 & 6.888 & 4.187 & 5.448 \\
8.314 & 2.261 & 4.224 & 1.781 & 4.124 & 0.932 & 8.129 & 8.658 & 1.208 & 5.762 \\
0.226 & 8.858 & 1.420 & 0.945 & 1.622 & 4.698 & 6.228 & 9.096 & 0.972 & 7.637 \\
7.305 & 2.228 & 1.242 & 5.928 & 9.133 & 1.826 & 4.060 & 5.204 & 8.713 & 8.247 \\
0.652 & 7.027 & 0.508 & 4.876 & 8.807 & 4.632 & 5.808 & 6.937 & 3.291 & 7.016 \\
2.699 & 3.516 & 5.874 & 4.119 & 4.461 & 7.496 & 8.817 & 0.690 & 6.593 & 9.789 \\
8.327 & 3.897 & 2.017 & 9.570 & 9.825 & 1.150 & 1.395 & 3.885 & 6.354 & 0.109 \\
2.132 & 7.006 & 7.136 & 2.641 & 1.882 & 5.943 & 7.273 & 7.691 & 2.880 & 0.564 \\
4.707 & 5.579 & 4.080 & 0.581 & 9.698 & 8.542 & 8.077 & 8.515 & 9.231 & 4.670 \\
8.304 & 7.559 & 8.567 & 0.322 & 7.128 & 8.392 & 1.472 & 8.524 & 2.277 & 7.826 \\
8.632 & 4.409 & 4.832 & 5.768 & 7.050 & 6.715 & 1.711 & 4.323 & 4.405 & 4.591 \\
4.887 & 9.112 & 0.170 & 8.967 & 9.693 & 9.867 & 7.508 & 7.770 & 8.382 & 6.740 \\
2.440 & 6.686 & 4.299 & 1.007 & 7.008 & 1.427 & 9.398 & 8.480 & 9.950 & 1.675 \\
6.306 & 8.583 & 6.084 & 1.138 & 4.350 & 3.134 & 7.853 & 6.061 & 7.457 & 2.258 \\
0.652 & 2.343 & 1.370 & 0.821 & 1.310 & 1.063 & 0.689 & 8.819 & 8.833 & 9.070 \\
5.558 & 1.272 & 5.756 & 9.857 & 2.279 & 2.764 & 1.284 & 1.677 & 1.244 & 1.234 \\
3.352 & 7.549 & 9.817 & 9.437 & 8.687 & 4.167 & 2.570 & 6.540 & 0.228 & 0.027 \\
8.798 & 0.880 & 2.370 & 0.168 & 1.701 & 3.680 & 1.231 & 2.390 & 2.499 & 0.064 \\
1.460 & 8.057 & 1.336 & 7.217 & 7.914 & 3.615 & 9.981 & 9.198 & 5.292 & 1.224 \\
0.432 & 8.645 & 8.774 & 0.249 & 8.081 & 7.461 & 4.416 & 0.652 & 4.002 & 4.644 \\
0.679 & 2.800 & 5.523 & 3.049 & 2.968 & 7.225 & 6.730 & 4.199 & 9.614 & 9.229 \\
4.263 & 1.074 & 7.286 & 5.599 & 8.291 & 5.200 & 9.214 & 8.272 & 4.398 & 4.506 \\
9.496 & 4.830 & 3.150 & 8.270 & 5.079 & 1.231 & 5.731 & 9.494 & 1.883 & 9.732 \\
4.138 & 2.562 & 2.532 & 9.661 & 5.611 & 5.500 & 6.886 & 2.341 & 9.699 & 6.500
\end{bmatrix},$$

and ${\bf c} = \left( 0.806, 0.517, 0.100, 0.908, 0.965, 0.669, 0.524, 0.902, 0.531, 0.876, 0.462, 0.491, 0.463, 0.714, 0.352, 0.869, 0.813, 0.811, 0.828, 0.964, 0.789, 0.360, 0.369, 0.992, 0.332, 0.817, 0.632, 0.883, 0.608, 0.3260.806, 0.517, 0.1, 0.908, 0.965 \right)$
with search range $0 \le x_{i} \le 10$.
In 2nd ICEO, $N = 5$ and $10$ are used.

### 7. The Generalized Rosenbrock function (2nd ICEO)
$$f({\bf x}) = \sum_{i=1}^{N-1} (1 - x_{i})^{2} + 100 (x_{i+1} - x_{i}^{2})^{2}, $$<br />
with search range $-5.12 \le x_{i} \le 5.12$.
In 2nd ICEO, $N = 5$ and $10$ are used.

### 8. The Odd Square (2nd ICEO)
$$f({\bf x}) = \exp\left(-\frac{L_{\infty}^{2}}{2\pi}\right) \cos(\pi L_{\infty}^{2} ) \left(1 + c_{1} \frac{ L_{2}^{2} }{ L_{\infty}^{2} + 0.01 } \right),$$ 
where $$L_{\infty} = \max_{i=1}^{N} | x_{i} - A_{i} |, ~~~ L_{2} = \sqrt{ \sum_{i=1}^{N} (x_{i} - A_{i})^{2} },$$<br />
and the parameter $c_{1} = 0.2$, ${\bf A} = \left( 1, 1.3, 0.8, -0.4, -1.3, 1.6, -0.2, -0.6, 0.5, 1.4, 1, 1.3, 0.8, -0.4, -1.3, 1.6, -0.2, -0.6, 0.5, 1.4 \right)$ cyclic at the interval of 10,
with search range $-5\pi \le x_{i} \le 5\pi$.
In 2nd ICEO, $N = 5$ and $10$ are used.





### 9. Tchebychev polynomials (2nd ICEO)
According to the web archive and the function name in the source code, the name is "Chebychev" and no formula is given.
However, the name of original source code file is "Tchebichev.c".
Furthermore, in a literature [2], the name of function is "Tchebychev".
We follow the name used in the literature.

$$f({\bf x}) = f_{1}({\bf x}) + f_{2}({\bf x}) + f_{3}({\bf x}), $$<br />

where

$$f_{1}({\bf x}) =\left(
\begin{array}{ll}
  [ 1 - p_{1}({\bf x}) ]^{2}, & |p_{1}({\bf x})| > 1,\\
  0, & {\rm otherwise},
\end{array}\right.
$$

$$f_{2}({\bf x}) =\left(
      \begin{array}{ll}
        p_{2}^{2}({\bf x}), & p_{2}({\bf x}) < 0,\\
        0, & {\rm otherwise},
      \end{array}\right.
$$

$$
f_{3}({\bf x}) =\left(
      \begin{array}{ll}
        p_{3}^{2}({\bf x}), & p_{3}({\bf x}) < 0,\\
        0, & {\rm otherwise},
      \end{array}\right.
$$

$$p_{1}({\bf x}) = \sum_{t=0}^{100} \sum_{i=1}^{N} (0.02t - 1)^{N-i} x_{i},$$

$$p_{2}({\bf x}) = \sum_{i=1}^{N} \left[ x_{i} \left( \frac{6}{5} \right)^{N-i} \right] - D,$$

$$p_{3}({\bf x}) = \sum_{i=1}^{N} \left[ x_{i} \left( -\frac{6}{5} \right)^{N-i} \right] - D.$$
  
This function can be used for $N = 9$ and $17$ only.

The parameter $D = 72.66066$ and $10558.145$ for $N = 9$ and $17$, respectively.

For $N = 9$, the global minimum is $f({\bf x}^{\*}) = $ at  ${\bf x}^{\*} = \{\}$
with the search range is $-512 \le {\bf x} \le 512$.

For $N = 17$, the global minimum is $f({\bf x}^{\*}) = $ at  ${\bf x}^{\*} = \{\}$
with the search range is $-32768 \le {\bf x} \le 32768$.

### 10. The Bump function
$$f({\bf x}) = \left| \frac{ \displaystyle\sum_{i=1}^{N} \cos^{4}(x_{i}) - 2 \prod_{i=1}^{N} \cos^{2}(x_{i}) }{ \displaystyle\sqrt{ \sum_{i=1}^{N} ix_{i}^{2} } } \right|, $$<br />
where 

## References
1. H. Bersini, M. Dorigo, S. Langerman, G. Seront and L. Gambardella, "Results of the first international contest on evolutionary optimisation (1st ICEO)," Proceedings of IEEE International Conference on Evolutionary Computation, 1996, pp. 611-615. https://ieeexplore.ieee.org/document/542670
2. K. V. Price, "Differential evolution vs. the functions of the 2/sup nd/ ICEO," Proceedings of 1997 IEEE International Conference on Evolutionary Computation (ICEC '97), 1997, pp. 153-157. https://ieeexplore.ieee.org/document/592287

