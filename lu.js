console.log("[DEBUG] lu.js loaded");

window.onload = () => {
    document.querySelectorAll(".matrix-section").forEach(el => {
        el.style.display = "none";
    });
};

function generateMatrix() {
    const n = parseInt(document.getElementById("matrixSize").value);
    const container = document.getElementById("matrixInputGrid");

    container.innerHTML = ""; 
    container.style.gridTemplateColumns = `repeat(${n}, 50px)`;

    for (let i = 0; i < n * n; i++) {
        const input = document.createElement("input");
        input.type = "number";
        input.step = "any";
        input.id = `cell-${i}`;
        container.appendChild(input);
    }

    // Stores globally for LU decomp
    window.matrixSize = n; 
}

function clearMatrix() {
    const inputs = document.querySelectorAll("#matrixInputGrid input");
    inputs.forEach(input => input.value = "");
 }


function computeLU() {
    // Debug test
    console.log("[DEBUG] Testing button clicked");
    
    // Set dim(n) from generateMatrix()
    const n = window.matrixSize; 
    const A = [];
    
    // Read values from grid to matrix A

    for (let i = 0; i < n; i++) {
        const row = [];
        for (let j = 0; j < n; j++) {
            const cellId = `cell-${i * n + j}`;
            const val = parseFloat(document.getElementById(cellId).value);
            if (isNaN(val)) {
                alert(`Invalid input at row ${i + 1}, column ${j + 1}`);
                return;
            }
            row.push(val);
        }
        A.push(row);
    
    }

    // Deep copy for matrix U
    const U = A.map(row => [...row]);

    // Matrix L
    const L = Array.from({ length: n}, (_, i) =>
        Array.from({ length: n}, (_, j) => (i === j ? 1 : 0))
    );

    // Perform LU decomposition on matrix A
    for (let pivot = 0; pivot < n; pivot++) {
        for (let row = pivot + 1; row < n; row++) {
            const factor = U[row][pivot] / U[pivot][pivot];
            L[row][pivot] = factor;
            for (let col = pivot; col < n; col++) {
                U[row][col] -= factor * U[pivot][col];
            }
        }
    }

    // Format matrix display
    //const format = matrix => 
    //   matrix.map(row => row.map(val => val.toFixed(2)).join(" ")).join("\n");


function toLatex(matrix) {
    const latex = matrix.map(row =>
        row.map(val => val.toFixed(2)).join(" & ")
    ).join(" \\\\ ");
    return `\\[\\begin{bmatrix} ${latex} \\end{bmatrix}\\]`;
}
    // Display U/L matrices
    document.getElementById("original").innerHTML = toLatex(A);
    document.getElementById("upper").innerHTML = toLatex(U);
    document.getElementById("lower").innerHTML = toLatex(L);

    // Show heading after LU decomp
    document.getElementById("originalHeading").style.display = "block";
    document.getElementById("upperHeading").style.display = "block";
    document.getElementById("lowerHeading").style.display = "block";

    // Reprocess MathJax
    if (window.MathJax) {
        MathJax.typesetPromise();
    }
}

// Make computeLU globally accessible to HTML
//window.generateMatrix = generateMatrix;
//window.clearMatrix = clearMatrix;
//window.computeLU = computeLU;