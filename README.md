# C Practicum — 15 Tasks
### Учебно-ознакомительная практика — БГТУ им. В.Г. Шухова
### التدريب التعليمي التمهيدي (Practicum) — الجامعة التقنية الحكومية في بيلغورود (БГТУ)

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Language: C](https://img.shields.io/badge/Language-C11-blue.svg)](https://en.wikipedia.org/wiki/C11_(C_standard_revision))
[![Docs: Doxygen](https://img.shields.io/badge/docs-Doxygen-2C4AA8.svg)](Doxyfile)

## 🎓 About this project / عن المشروع

This repository is the deliverable for the **учебно-ознакомительная практика**
("introductory/orientation academic practicum") — a mandatory practicum
assigned as part of the coursework, combining material from the courses
**Основы программирования** (Fundamentals of Programming) and
**Дискретная математика** (Discrete Mathematics).

هذا المستودع هو الناتج النهائي لمادة **"التدريب التعليمي التمهيدي"**
(практика) المقررة ضمن المنهج الدراسي، وتجمع بين مواد
**أساسيات البرمجة** و **الرياضيات المتقطعة (المنفصلة)**.

| | |
|---|---|
| **University / الجامعة** | Belgorod State Technological University named after V.G. Shukhov (БГТУ им. В.Г. Шухова) — Белгородский государственный технологический университет им. В.Г. Шухова |
| **Faculty / group** | Group **ВТ-252** |
| **Student / الطالب** | ГУЙЛАЙ Мохаммед Эйса Мохаммед (Quillai Mohammed Eisa) |
| **Supervisors / المشرفون** | доц. Островский Алексей Мичеславович; асс. Стеценко Оксана Николаевна |
| **Courses covered** | Основы программирования (Fundamentals of Programming); Дискретная математика (Discrete Mathematics) |

Each of the 15 tasks corresponds to **"Theme N, Task 4"** of the practicum
assignment sheet, spanning topics from linear/branching/iterative algorithms
through arrays, vectors and matrices, string processing, analytic geometry,
and quadric surfaces. The full write-up — problem statement, mathematical
justification, TikZ flowchart, source listing, and test results for every
task — is compiled separately as a ~49-page LaTeX/PDF report (source
included under `report/`).

## 📁 Project structure / هيكل المشروع

```
.
├── src/                  # 15 C source files (t01.c – t15.c), Doxygen-documented
├── report/               # LaTeX report source (problem statements, flowcharts, results)
│   ├── main.tex          # Report entry point
│   ├── sections/         # One .tex file per task + intro/conclusion/references/cover
│   └── media/            # Images (university logo, etc.)
├── Doxyfile              # Doxygen configuration (generates docs/ — API-style reference)
├── Makefile              # Build system: programs, report, and documentation
├── LICENSE               # MIT License
└── README.md
```

## 🧩 Tasks overview / نظرة عامة على المهام

| # | File | Theme | Topic |
|---|------|-------|-------|
| 1  | `t01.c` | Theme 1  | Linear algorithms — time interval duration |
| 2  | `t02.c` | Theme 2  | Branching algorithms — quadrilateral type classification |
| 3  | `t03.c` | Theme 3  | Iterative algorithms — intersection area of rectangles |
| 4  | `t04.c` | Theme 4  | Array operations — mean and variance |
| 5  | `t05.c` | Theme 5  | Vectors and matrices — cube visibility projection |
| 6  | `t06.c` | Theme 6  | Linear search — minimum of an upper envelope of lines |
| 7  | `t07.c` | Theme 7  | Arithmetic — rounding to significant digits |
| 8  | `t08.c` | Theme 8  | Sets — subsets with sum in a given range |
| 9  | `t09.c` | Theme 9  | Linear algebra — recursive minor expansion |
| 10 | `t10.c` | Theme 10 | String processing — longest word / longest phrase |
| 11 | `t11.c` | Theme 11 | Analytic geometry — angle between two lines |
| 12 | `t12.c` | Theme 12 | Analytic geometry — rotated rectangle vertices |
| 13 | `t13.c` | Theme 13 | Linear systems — Cramer's rule (2×2) |
| 14 | `t14.c` | Theme 14 | Planes in 3D — point-to-plane distance and projection |
| 15 | `t15.c` | Theme 15 | Quadric surfaces — point vs. ellipsoid position |

## ⚙️ Requirements / المتطلبات

- GCC (or any C11-compatible compiler) and `make`
- Optional, to build the report: a LaTeX distribution (e.g. TeX Live) with
  `latexmk` and the packages `polyglossia`/`babel`, `tikz`, `listings`,
  `tocloft` (see `report/main.tex` for the full preamble)
- Optional, to build the source documentation: [Doxygen](https://www.doxygen.nl/)

## 🚀 Build & run / البناء والتشغيل

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

### Building the report / بناء التقرير

```bash
make report          # produces report/main.pdf
make report-clean    # removes LaTeX build artifacts
```

## 📖 Source documentation (Doxygen) / توثيق الكود

Every source file carries a `@file` / `@brief` Doxygen header describing the
task it implements. HTML reference documentation can be generated locally:

```bash
make docs          # generates docs/index.html via Doxygen
make docs-clean    # removes the generated docs/ directory
```

Then open `docs/html/index.html` in a browser. The `docs/` directory is
generated (not tracked in git — see `.gitignore`); running `make docs`
regenerates it from `Doxyfile` and the comments in `src/`.

## 👤 Author / المؤلف

**Quillai Mohammed Eisa (ГУЙЛАЙ Мохаммед Эйса Мохаммед / قويلاي محمد عيسى)**
Group ВТ-252, БГТУ им. В.Г. Шухова (Belgorod State Technological University
named after V.G. Shukhov)
Supervisors: доц. Островский А.М., асс. Стеценко О.Н.

## 📄 License / الترخيص

This project is licensed under the **MIT License** — see [LICENSE](LICENSE)
for details. The code is shared for educational and portfolio purposes; the
practicum assignment itself belongs to БГТУ им. В.Г. Шухова's curriculum.
