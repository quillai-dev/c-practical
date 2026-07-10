# C Practicum — 15 Tasks
### Учебно-ознакомительная практика — 15 задач на языке C

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Language: C](https://img.shields.io/badge/Language-C11-blue.svg)](https://en.wikipedia.org/wiki/C11_(C_standard_revision))
[![Docs: Doxygen](https://img.shields.io/badge/docs-Doxygen-2C4AA8.svg)](Doxyfile)

> This repository is a university coursework deliverable (учебно-ознакомительная
> практика) and is shared here for portfolio and reference purposes.
>
> Данный репозиторий является учебной работой (учебно-ознакомительная
> практика) и публикуется здесь в портфолио-целях.

## Overview / Обзор

15 standalone C programs, each solving one algorithmic or mathematical task
("Theme N, Task 4" in the assignment sheet) — covering linear, branching and
iterative algorithms, arrays, vectors and matrices, string processing,
analytic geometry, linear systems, and quadric surfaces. The full write-up
(problem statements, mathematical justification, flowcharts, code listings,
and test results) is included as LaTeX source under `report/`.

15 самостоятельных программ на C, каждая решает отдельную алгоритмическую
или математическую задачу («Тема N, Задание 4») — линейные, разветвляющиеся
и циклические алгоритмы, массивы, векторы и матрицы, обработка строк,
аналитическая геометрия, линейные системы и поверхности второго порядка.
Полный отчёт (постановки задач, математическое обоснование, блок-схемы,
листинги и результаты тестирования) — в виде исходников LaTeX в `report/`.

## Project structure / Структура проекта

```
.
├── src/                  # 15 C source files (t01.c – t15.c), Doxygen-documented
├── report/               # LaTeX report source (problem statements, flowcharts, results)
│   ├── main.tex          # Report entry point
│   ├── sections/         # One .tex file per task + intro/conclusion/references/cover
│   └── media/            # Images (logo, etc.)
├── Doxyfile              # Doxygen configuration (generates docs/ — source reference)
├── Makefile              # Build system: programs, report, and documentation
├── LICENSE               # MIT License
└── README.md
```

## Tasks overview / Обзор задач

| # | File | Theme | Topic / Тема |
|---|------|-------|---------------|
| 1  | `t01.c` | Theme 1  | Linear algorithms — time interval duration / линейные алгоритмы |
| 2  | `t02.c` | Theme 2  | Branching algorithms — quadrilateral type / разветвляющиеся алгоритмы |
| 3  | `t03.c` | Theme 3  | Iterative algorithms — rectangle intersection area / циклические алгоритмы |
| 4  | `t04.c` | Theme 4  | Array operations — mean and variance / операции над массивами |
| 5  | `t05.c` | Theme 5  | Vectors and matrices — cube visibility projection / векторы и матрицы |
| 6  | `t06.c` | Theme 6  | Linear search — minimum of an upper envelope / линейный поиск |
| 7  | `t07.c` | Theme 7  | Arithmetic — rounding to significant digits / арифметика |
| 8  | `t08.c` | Theme 8  | Sets — subsets with sum in a given range / теория множеств |
| 9  | `t09.c` | Theme 9  | Linear algebra — recursive minor expansion / линейная алгебра |
| 10 | `t10.c` | Theme 10 | String processing — longest word / phrase / обработка строк |
| 11 | `t11.c` | Theme 11 | Analytic geometry — angle between two lines / аналитическая геометрия |
| 12 | `t12.c` | Theme 12 | Analytic geometry — rotated rectangle vertices |
| 13 | `t13.c` | Theme 13 | Linear systems — Cramer's rule (2×2) / линейные системы |
| 14 | `t14.c` | Theme 14 | Planes in 3D — point-to-plane distance / плоскости в пространстве |
| 15 | `t15.c` | Theme 15 | Quadric surfaces — point vs. ellipsoid position / поверхности 2-го порядка |

## Requirements / Требования

- GCC (or any C11-compatible compiler) and `make`
- Optional, to build the report: a LaTeX distribution (e.g. TeX Live) with
  `latexmk` and the packages `polyglossia`/`babel`, `tikz`, `listings`,
  `tocloft` (see `report/main.tex` for the full preamble)
- Optional, to build source documentation: [Doxygen](https://www.doxygen.nl/)

## Build & run / Сборка и запуск

```bash
# Build all 15 programs into bin/
make

# Build and run a single task, e.g. t05
make run T=t05

# List all available task names
make list

# Remove compiled binaries
make clean
```

Each program can also be compiled and run individually:

```bash
gcc -std=gnu11 -Wall -Wextra -O2 -o bin/t05 src/t05.c -lm
./bin/t05
```

### Building the report / Сборка отчёта

```bash
make report          # produces report/main.pdf
make report-clean    # removes LaTeX build artifacts
```

## Source documentation (Doxygen) / Документация исходного кода

Every source file carries a `@file` / `@brief` Doxygen header describing the
task it implements. HTML reference documentation can be generated locally:

```bash
make docs          # generates docs/index.html via Doxygen
make docs-clean    # removes the generated docs/ directory
```

Then open `docs/html/index.html` in a browser. The `docs/` directory is
generated (not tracked in git — see `.gitignore`); running `make docs`
regenerates it from `Doxyfile` and the comments in `src/`.

## License / Лицензия

This project is licensed under the **MIT License** — see [LICENSE](LICENSE)
for details.
