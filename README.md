# 🧮 Stack-Based Calculator (C)

A console-based calculator built in C that converts **Infix expressions to Postfix** and evaluates them using a **Stack data structure**.

Built as a Data Structures project to demonstrate real-world application of stacks.

---

## 📌 Features

- Converts Infix expression → Postfix expression
- Evaluates Postfix expression using a stack
- Handles operators: `+`, `-`, `*`, `/`
- Supports parentheses `(` and `)`
- Operator precedence handled correctly

---

## 🛠️ How It Works

The calculator works in 2 stages:

```
Infix Expression  →  [Conversion Module]  →  Postfix Expression
Postfix Expression  →  [Evaluation Module]  →  Result
```

**Example:**
```
Input  : 3+5*2
Postfix: 352*+
Output : 13
```

---

## 📂 Project Structure

```
stack-calculator-c/
│
├── calcu.cpp        # Main source file
└── README.md        # Project documentation
```

---

## ▶️ How to Run

**Requirements:** GCC compiler (or any C compiler)

```bash
# Compile
gcc calcu.cpp -o calculator

# Run
./calculator
```

**Sample Output:**
```
----- STACK BASED CALCULATOR -----
Enter Infix Expression: 3+5*2
Postfix Expression: 352*+
Result = 13
```

---

## 🧠 Concepts Used

| Concept | Usage |
|---|---|
| Stack (Array-based) | Core data structure |
| Infix to Postfix conversion | Shunting-yard algorithm |
| Postfix Evaluation | Stack-based evaluation |
| Operator Precedence | `*`, `/` before `+`, `-` |

---


