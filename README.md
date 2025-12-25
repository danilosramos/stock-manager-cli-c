# 📈 Corporate Finance Manager

> A CLI application built in **C** to manage and track corporate financial data (Balance Sheets, Stock Value, Cash Flow) using **Dynamic Linked Lists**.

![C](https://img.shields.io/badge/Language-C99-00599C?style=for-the-badge&logo=c&logoColor=white)
![Structure](https://img.shields.io/badge/Data%20Structure-Linked%20List-orange?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)

## 📖 About the Project

This project simulates a **Financial Management System** for companies. Unlike simple spreadsheet-like programs that use fixed-size arrays, this application utilizes **Singly Linked Lists** to allow for dynamic memory allocation. This means the system can store financial records for an indefinite number of years without recompilation or wasted memory.

It was designed to practice structural definitions in C (`struct`), pointer manipulation, and memory management (`malloc`/`free`) applied to a real-world business scenario.

## 🚀 Key Features

* **🔗 Dynamic Data Structure:** Uses a Linked List to store financial records year-by-year, allowing flexible insertion at the beginning or end of the history.
* **📊 Financial Metrics Tracking:** Stores complex data points for each fiscal year, including:
    * **Assets:** Stock Value, Raw Materials, Accounts Receivable (VAR).
    * **Liabilities:** Salaries Payable (SAP), Supplier Costs.
    * **Cash Flow:** Annual Inflows/Outflows and Extras.
* **📝 Detailed Reporting:** Iterates through the list to display a comprehensive log of the company's financial history.

## 🛠️ Technologies Used

* **Language:** C (Standard C99)
* **Concepts:**
    * **Structs:** To model the `dados_financeiros` data type.
    * **Pointers:** For traversing the list and manipulating nodes.
    * **Dynamic Memory:** Using `malloc` to create new records on the heap.
    * **CLI I/O:** Console-based interface for data entry.

## ⚙️ How to Run

### Prerequisites
You need a C compiler installed (like **gcc**, **clang**, or **MSVC**).

### Compilation
Open your terminal in the project folder and run:

```bash
gcc corporate-finance-manager-list.c -o finance-manager
```

Execution

On Linux/macOS:
```bash
./finance-manager
```

On Windows:
```bash
finance-manager.exe
```

## 🧩 Code Logic
The core of the system is the `dados_financeiros` node structure:
```C
typedef struct dados_financeiros
{
    int ano;
    float entrada;
    float saida;
    // ... other financial fields
    struct dados_financeiros *prox; // Pointer to the next year
} dados_financeiros;
```

The application provides a menu loop that allows the user to:

* Allocate a new node.

* Populate it with user input (Entry, Exit, Stock, etc.).

* Link it to the existing list (Head or Tail insertion).

* Traverse the list to print the report.
