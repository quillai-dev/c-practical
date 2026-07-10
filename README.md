# C Practicum — 15 Tasks

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Language: C](https://img.shields.io/badge/Language-C11%20(gnu11)-blue.svg)](https://en.wikipedia.org/wiki/C11_(C_standard_revision))
[![Docs: Doxygen](https://img.shields.io/badge/docs-Doxygen-2C4AA8.svg)](Doxyfile)
[![Build: Make](https://img.shields.io/badge/build-Make-brightgreen.svg)](Makefile)

> **University coursework.**  
> This repository is the deliverable for the *учебно-ознакомительная практика*
> (introductory orientation practicum) at **Belgorod State Technological
> University named after V.G. Shukhov (БГТУ им. В.Г. Шухова)**, and is
> published here for portfolio and reference purposes.

---

## Table of Contents

1. [Overview](#overview)
2. [Project Structure](#project-structure)
3. [Requirements](#requirements)
4. [Build & Run](#build--run)
5. [Tasks — Detailed Reference](#tasks--detailed-reference)
   - [Task 01 — Time Interval Duration](#task-01--time-interval-duration)
   - [Task 02 — Quadrilateral Classification](#task-02--quadrilateral-classification)
   - [Task 03 — Rectangle Intersection Area](#task-03--rectangle-intersection-area)
   - [Task 04 — Mean and Variance](#task-04--mean-and-variance)
   - [Task 05 — 3D Cube Visibility Projection](#task-05--3d-cube-visibility-projection)
   - [Task 06 — Upper Envelope of Linear Functions](#task-06--upper-envelope-of-linear-functions)
   - [Task 07 — Rounding to Significant Digits](#task-07--rounding-to-significant-digits)
   - [Task 08 — Subsets by Sum Range](#task-08--subsets-by-sum-range)
   - [Task 09 — Minor of a Matrix](#task-09--minor-of-a-matrix)
   - [Task 10 — Longest Word and Phrase](#task-10--longest-word-and-phrase)
   - [Task 11 — Angle Between Two Lines](#task-11--angle-between-two-lines)
   - [Task 12 — Rotated Rectangle Vertices](#task-12--rotated-rectangle-vertices)
   - [Task 13 — 2×2 Linear System (Cramer's Rule)](#task-13--22-linear-system-cramers-rule)
   - [Task 14 — Point-to-Plane Distance and Projection](#task-14--point-to-plane-distance-and-projection)
   - [Task 15 — Point vs. Ellipsoid Position](#task-15--point-vs-ellipsoid-position)
6. [Doxygen Documentation](#doxygen-documentation)
7. [LaTeX Report](#latex-report)
8. [Author](#author)
9. [License](#license)

---

## Overview

This practicum covers 15 independent C programs, each solving one
algorithmically or mathematically distinct problem corresponding to
**"Theme N, Task 4"** of the assignment sheet. The themes progress from
fundamental programming constructs (linear and branching algorithms, loops,
arrays) through mathematical computing (linear algebra, set enumeration,
analytic geometry) up to three-dimensional geometry (planes, quadric surfaces).

Every source file is documented with Doxygen-style `@file`/`@brief` headers.
All 15 programs compile cleanly with:

```
gcc -std=gnu11 -Wall -Wextra -O2 -o <output> <file>.c -lm
```

The complete formal report — problem statements, mathematical justification,
TikZ flowcharts, source listings, and test results — is included as LaTeX
source under `report/`.

---

## Project Structure

```
.
├── src/
│   ├── t01.c   Theme 1  — Linear algorithms
│   ├── t02.c   Theme 2  — Branching algorithms
│   ├── t03.c   Theme 3  — Iterative algorithms
│   ├── t04.c   Theme 4  — Basic array operations
│   ├── t05.c   Theme 5  — Vectors and matrices
│   ├── t06.c   Theme 6  — Linear search
│   ├── t07.c   Theme 7  — Arithmetic
│   ├── t08.c   Theme 8  — Set theory
│   ├── t09.c   Theme 9  — Linear algebra
│   ├── t10.c   Theme 10 — String processing
│   ├── t11.c   Theme 11 — Analytic geometry (2D)
│   ├── t12.c   Theme 12 — Analytic geometry (rotation)
│   ├── t13.c   Theme 13 — Linear systems
│   ├── t14.c   Theme 14 — Plane in 3D space
│   └── t15.c   Theme 15 — Quadric surfaces
│
├── report/
│   ├── main.tex          Entry point — includes all sections
│   ├── sections/         One .tex per task + intro/conclusion/references/cover
│   └── media/            Images (university logo, etc.)
│
├── Doxyfile              Doxygen configuration (output → docs/)
├── Makefile              Build system
├── LICENSE               MIT License
└── README.md
```

---

## Requirements

| Tool | Purpose | Required |
|------|---------|----------|
| GCC (C11 / gnu11) | Compile C sources | Yes |
| `make` | Run build targets | Yes |
| TeX Live + `latexmk` | Build the LaTeX report | Optional |
| Doxygen | Generate HTML source docs | Optional |

---

## Build & Run

```bash
# Build all 15 programs into bin/
make

# Build and run a single task
make run T=t07

# List all available task names
make list

# Remove compiled binaries
make clean
```

Alternatively, compile any single file manually:

```bash
gcc -std=gnu11 -Wall -Wextra -O2 -o bin/t07 src/t07.c -lm
./bin/t07
```

---

## Tasks — Detailed Reference

---

### Task 01 — Time Interval Duration

**File:** `src/t01.c` | **Theme:** 1 — Linear algorithms

**Problem:** Given the start and end moments of a time interval expressed in
hours, minutes, and seconds (both within a single day), compute the duration
of the interval in the same units.

**Approach:** Convert both timestamps to total seconds since midnight:

```
t = h × 3600 + m × 60 + s
```

Compute the difference `dt = t2 - t1`; if the result is negative (end is
before start, i.e. the interval crosses midnight), add 86400 seconds. Decompose
the result back into hours, minutes, and seconds using integer division and
modulo.

**Input:**
```
Start (hh mm ss): 8 0 0
End   (hh mm ss): 10 30 15
```
**Output:**
```
Duration: 02 h 30 min 15 s
```

---

### Task 02 — Quadrilateral Classification

**File:** `src/t02.c` | **Theme:** 2 — Branching algorithms

**Problem:** Given the four vertex coordinates of a quadrilateral ABCD in the
plane, classify it as one of: Rectangle, Parallelogram, Trapezoid, or
Arbitrary quadrilateral.

**Approach:** Use the cross-product test to check whether pairs of opposite
sides are parallel. If both pairs (AB ∥ CD and BC ∥ AD) are parallel, the
figure is a parallelogram; if additionally the dot product of two adjacent
sides is zero, it is a rectangle. If exactly one pair is parallel, it is a
trapezoid; otherwise arbitrary.

**Key functions:** `cross(a, b, c)` computes the signed area of triangle
formed by three points; `parallel(a, b, c, d)` checks whether line AB is
parallel to CD by comparing cross products.

**Input:**
```
Enter coordinates A B C D (x y for each):
0 0   2 0   2 1   0 1
```
**Output:**
```
Rectangle
```

---

### Task 03 — Rectangle Intersection Area

**File:** `src/t03.c` | **Theme:** 3 — Iterative algorithms

**Problem:** A sequence of n axis-aligned rectangles is entered one by one.
After reading each new rectangle, intersect it with the running cumulative
intersection, and report the area of the final intersection.

**Approach:** Keep the current intersection as `[cx1, cx2] × [cy1, cy2]`.
For each new rectangle `[x1, x2] × [y1, y2]`, update:

```
lx = max(cx1, x1),  rx = min(cx2, x2)
ly = max(cy1, y1),  ry = min(cy2, y2)
```

If `rx > lx` and `ry > ly`, the intersection is non-empty and is updated;
otherwise it collapses to the zero rectangle.

**Input:**
```
Enter number of rectangles: 3
First rectangle: 0 0 4 4
Rectangle 2: 1 1 5 5
Rectangle 3: 2 0 6 3
```
**Output:**
```
Total intersection area: 2.0000
```

---

### Task 04 — Mean and Variance

**File:** `src/t04.c` | **Theme:** 4 — Basic array operations

**Problem:** Given an array X of n real observations, compute the arithmetic
mean m and the (population) variance d.

**Formulae:**

```
m = (1/n) × Σ xᵢ
d = (1/n) × Σ (xᵢ - m)²
```

**Approach:** Two sequential passes over the array — first to sum the
elements and compute m, then to sum the squared deviations and compute d.
Array size is bounded by `MAXN = 100`.

**Input:**
```
Enter number of elements n: 4
Enter array elements: 2.0 4.0 4.0 6.0
```
**Output:**
```
Mean m     = 4.0000
Variance d = 2.0000
```

---

### Task 05 — 3D Cube Visibility Projection

**File:** `src/t05.c` | **Theme:** 5 — Vectors and matrices

**Problem:** A 3D cube of size N×N×N is composed of elementary unit cubes,
each either transparent (0) or opaque (1). Compute the **visibility
projection** along the Z axis: a 2D cell (i, j) in the projection is marked
opaque if at least one cube in the column (i, j, k) for any k is opaque.

**Approach:** Iterate over all positions (i, j, k); for each (i, j) column,
set the projection cell to 1 if any layer k contains an opaque cube. The
result is an N×N binary matrix.

**Input (N=3, flattened):**
```
0 0 0  0 1 0  0 0 0
0 0 0  0 0 0  0 0 0
0 0 1  0 0 0  0 0 0
```
**Output:**
```
Projection along Z axis:
0 1 0
0 0 0
0 0 1
Total opaque cubes: 2 of 27
```

---

### Task 06 — Upper Envelope of Linear Functions

**File:** `src/t06.c` | **Theme:** 6 — Linear search

**Problem:** Given n linear functions `yᵢ(x) = kᵢ × x + bᵢ`, evaluate the
**upper envelope** at a given point x₀:

```
f(x₀) = max{ kᵢ × x₀ + bᵢ  :  i = 1 … n }
```

and report which function achieves the maximum.

**Approach:** A single linear scan over the n functions, tracking the current
maximum value and the index of the function that achieves it.

**Input:**
```
Enter number of functions n: 3
Coefficients (k b): 1 0   -1 4   0 2
Enter value of x: 1
```
**Output:**
```
Upper envelope at x=1.00: f(x)=3.0000 (function 2)
```

---

### Task 07 — Rounding to Significant Digits

**File:** `src/t07.c` | **Theme:** 7 — Arithmetic

**Problem:** Given an array of n distinct real numbers, round each value to
exactly **3 significant digits**.

**Approach:** The custom function `round3sig(x)` determines the order of
magnitude of |x| via `floor(log10(|x|))`, computes the scaling factor
`10^(2 - exponent)`, multiplies, rounds with the standard `round()`,
and divides back. Sign is handled separately.

```
Example: 1234.567  →  1230
         0.004567  →  0.00457
        -98.76     →  -98.8
```

**Input:**
```
n: 3
Elements: 1234.567  0.004567  -98.76
```
**Output:**
```
  1234.567 -> 1230
 0.004567  -> 0.00457
 -98.76    -> -98.8
```

---

### Task 08 — Subsets by Sum Range

**File:** `src/t08.c` | **Theme:** 8 — Set theory

**Problem:** Given a set S of n integers and an interval [a, b], enumerate
all subsets of S whose element sum lies within [a, b].

**Approach:** Iterate over all 2ⁿ possible subsets using a bitmask
`mask ∈ {0, …, 2ⁿ − 1}`. For each mask, check bit i to determine whether
element i is included, accumulate the sum, and print the subset if the sum
falls in [a, b]. Time complexity: O(n × 2ⁿ); suitable for n ≤ 20.

**Input:**
```
n: 4
Elements: 1 2 3 4
Bounds a b: 4 6
```
**Output:**
```
{1,3}   sum=4
{2,4}   sum=6
{1,2,3} sum=6
{1,4}   sum=5
{2,3}   sum=5
Subsets found: 5
```

---

### Task 09 — Minor of a Matrix

**File:** `src/t09.c` | **Theme:** 9 — Linear algebra

**Problem:** Given an m×n matrix A and a selection of k row indices and k
column indices (k ≤ 4), compute the value of the corresponding minor
(the determinant of the k×k submatrix).

**Approach:** Extract the k×k submatrix from the chosen rows and columns,
then evaluate its determinant with recursive cofactor expansion along the
first row. Base cases handle k = 1 (trivial) and k = 2 (2×2 formula).

```
det(M, k) = Σⱼ (−1)ʲ × M[0][j] × det(M without row 0 and col j, k−1)
```

**Input:**
```
M N: 3 3
Matrix:  1 2 3
         4 5 6
         7 8 9
k: 2
Rows: 0 1
Cols: 0 1
```
**Output:**
```
Minor value: -3.0000
```

---

### Task 10 — Longest Word and Phrase

**File:** `src/t10.c` | **Theme:** 10 — String processing

**Problem:** Given a single line of text, find (a) the longest word (sequence
of alphabetic characters) and (b) the longest phrase (sequence of characters
between sentence-terminating punctuation: `.`, `!`, `?`).

**Approach:** A single left-to-right scan with two simultaneously maintained
running buffers — `curWord` and `curPhrase`. A word boundary is triggered by
any non-alphabetic character; a phrase boundary is triggered by `.`, `!`, `?`,
or end of string. Both the word and phrase champions are updated on the fly.

**Input:**
```
Hello world. This is a wonderful demonstration!
```
**Output:**
```
Longest word:   "demonstration" (13 letters)
Longest phrase: " This is a wonderful demonstration"
```

---

### Task 11 — Angle Between Two Lines

**File:** `src/t11.c` | **Theme:** 11 — Analytic geometry

**Problem:** Two lines in the plane are given by their general equations:

```
a₁x + b₁y + c₁ = 0
a₂x + b₂y + c₂ = 0
```

Find the acute angle between them.

**Approach:** The normal vectors of the lines are **n₁** = (a₁, b₁) and
**n₂** = (a₂, b₂). The angle between the normals satisfies:

```
cos α = |n₁ · n₂| / (|n₁| × |n₂|)
```

Taking the absolute value ensures the acute angle is returned even when the
lines form an obtuse angle. The result is converted to degrees and
degrees+minutes.

**Input:**
```
Line 1 (a1 b1 c1): 1 -1 0
Line 2 (a2 b2 c2): 1  1 0
```
**Output:**
```
Angle between lines: 1.570796 rad = 90 deg 0 min
```

---

### Task 12 — Rotated Rectangle Vertices

**File:** `src/t12.c` | **Theme:** 12 — Analytic geometry (rotation)

**Problem:** A rectangle is specified by its center (cx, cy), its width w and
height h, and a rotation angle θ in degrees. Compute the Cartesian coordinates
of its four vertices.

**Approach:** The four corner offsets in the rectangle's local frame are
`(±w/2, ±h/2)`. Each is rotated by θ using the standard 2D rotation matrix:

```
x' = dx × cos θ − dy × sin θ
y' = dx × sin θ + dy × cos θ
```

and then translated by the center.

**Input:**
```
Center (cx cy): 0 0
Width and height: 4 2
Rotation angle (degrees): 45
```
**Output:**
```
Rectangle vertices:
  (-2.1213,  1.4142)
  ( 1.4142, -2.1213)
  ( 2.1213, -1.4142)
  (-1.4142,  2.1213)
```

---

### Task 13 — 2×2 Linear System (Cramer's Rule)

**File:** `src/t13.c` | **Theme:** 13 — Linear systems

**Problem:** Solve the 2×2 linear system:

```
a₁x + b₁y = c₁
a₂x + b₂y = c₂
```

using Cramer's rule, handling all three possible cases (unique solution,
infinitely many solutions, no solution).

**Approach:**

```
D  = a₁b₂ − a₂b₁
Dₓ = c₁b₂ − c₂b₁
Dᵧ = a₁c₂ − a₂c₁

x = Dₓ / D,  y = Dᵧ / D  (when D ≠ 0)
```

If D = 0 and Dₓ = Dᵧ = 0, the lines coincide (infinitely many solutions);
if D = 0 but Dₓ ≠ 0 or Dᵧ ≠ 0, the lines are parallel (no solution).

**Input:**
```
Equation 1 (a1 b1 c1): 2 1 5
Equation 2 (a2 b2 c2): 1 -1 1
```
**Output:**
```
Unique solution: x=2.0000, y=1.0000
```

---

### Task 14 — Point-to-Plane Distance and Projection

**File:** `src/t14.c` | **Theme:** 14 — Plane in 3D space

**Problem:** Given a plane Ax + By + Cz + D = 0 and a point P₀ = (x₀, y₀, z₀),
compute (a) the perpendicular distance from P₀ to the plane and (b) the
orthogonal projection of P₀ onto the plane.

**Formulae:**

```
distance = |A·x₀ + B·y₀ + C·z₀ + D| / √(A² + B² + C²)
```

The projection P' is found by moving P₀ along the normal by the signed
distance:

```
t  = −(A·x₀ + B·y₀ + C·z₀ + D) / (A² + B² + C²)
P' = (x₀ + A·t,  y₀ + B·t,  z₀ + C·t)
```

**Input:**
```
Plane (A B C D): 1 0 0 -3
Point (x0 y0 z0): 7 2 5
```
**Output:**
```
Distance from point to plane: 4.0000
Projection onto plane: (3.0000, 2.0000, 5.0000)
```

---

### Task 15 — Point vs. Ellipsoid Position

**File:** `src/t15.c` | **Theme:** 15 — Quadric surfaces

**Problem:** Given an ellipsoid defined by

```
x²/a² + y²/b² + z²/c² = 1
```

and a point (x, y, z), determine whether the point lies **inside**, **on
the surface of**, or **outside** the ellipsoid.

**Approach:** Evaluate the ellipsoid's implicit function:

```
f(x, y, z) = x²/a² + y²/b² + z²/c²
```

- `|f − 1| < ε`  →  on the surface
- `f < 1`        →  inside
- `f > 1`        →  outside

The tolerance ε = 1e-6 guards against floating-point rounding errors at the
boundary.

**Input:**
```
Semi-axes (a b c): 3 2 1
Point (x y z): 1 1 0
```
**Output:**
```
Point is inside the ellipsoid (f=0.361111)
```

---

## Doxygen Documentation

Every source file carries a Doxygen `@file`/`@brief` header. HTML
documentation can be generated locally with:

```bash
make docs        # outputs to docs/html/index.html
make docs-clean  # removes the generated docs/ directory
```

The `docs/` directory is not tracked in git (see `.gitignore`); run
`make docs` to regenerate it at any time.

---

## LaTeX Report

The `report/` directory contains the full LaTeX source of the practicum
write-up (~49 pages): cover page, introduction, one section per task
(problem statement, mathematical justification, TikZ flowchart, code listing,
test results), conclusion, and references.

```bash
make report        # compiles report/main.pdf (requires TeX Live + latexmk)
make report-clean  # removes LaTeX auxiliary files
```

---

## Author

**Quillai Mohammed Eisa** (ГУЙЛАЙ Мохаммед Эйса Мохаммед)  
Group ВТ-252  
Supervisors: доц. Островский А.М. · асс. Стеценко О.Н.

---

## License

This project is licensed under the **MIT License** — see [LICENSE](LICENSE)
for details.
