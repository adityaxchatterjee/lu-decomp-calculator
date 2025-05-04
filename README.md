# LU Decomposition Calculator

A web-based calculator that performs LU decomposition on any square matrix using **Gaussian elimination**. Built with vanilla HTML, CSS, and JavaScript, it dynamically computes and displays the **L** and **U** matrices with LaTeX-style formatting using MathJax.

## AUTHOR 
Aditya Chatterjee
LinkedIn: https://www.linkedin.com/in/adityaxchatterjee/
Email: chat.aditya03@gmail.com

## FEATURES

- Interactive n × n matrix input grid
- Dynamic LU decomposition computation using Gaussian elimination
- Clean LaTeX typeset output for:
  - Original matrix (A)
  - Upper triangular matrix (U)
  - Lower triangular matrix (L)
- Responsive and minimalist UI
- Built entirely with frontend technologies (no backend required)

---

## LIVE DEMO

🔗 [View the site on GitHub Pages](https://adityaxchatterjee.github.io/lu-decomp-calculator)

---

## OVERVIEW

**LU decomposition** factors a square matrix **A** into two triangular matrices:

\[
A = LU
\]

- **L** is a lower triangular matrix (with 1s on the diagonal)
- **U** is an upper triangular matrix (in row echelon form)

This decomposition simplifies solving systems of linear equations, computing determinants, and inverting matrices.

---

## HOW TO RUN LOCALLY

git clone https://github.com/adityaxchatterjee/lu-decomp-calculator.git
cd lu-decomp-calculator
open index.html  # or just drag into your browser
No additional dependencies required.

## PROJECT STRUCTURE
graphql
Copy code
.
├── index.html        # Main HTML file
├── style.css         # Styling for UI
├── lu.js             # JavaScript logic for LU decomposition
├── README.md         # Project documentation

## LICENSE
This project is open source and available under the MIT License.
