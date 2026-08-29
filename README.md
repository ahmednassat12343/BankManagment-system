# 🏦 Banking System — C++

A console-based **Banking System** built with C++ to practice and apply Object-Oriented Programming (OOP) concepts.

This project was created as a practical project after completing C++ fundamentals and OOP.

## 📌 Features

* Create a bank account
* Delete an account
* Deposit money
* Withdraw money
* Transfer money between accounts
* Find an account by account number
* Display all accounts
* Interactive console-based menu
* Input validation for deposits and withdrawals

## 🧠 OOP Concepts Practiced

This project focuses on several important C++ concepts:

* **Classes and Objects**
* **Encapsulation**
* **Constructors**
* **Constructor Initializer Lists**
* **Inheritance**
* **Polymorphism**
* **Virtual Functions**
* **Function Overriding**
* **Virtual Destructor**
* **Operator Overloading**
  * `operator==`
  * `operator+=`
  * `operator-=`
  * `operator<<`
* **Pointers**
* **Vectors**
* **Composition and class relationships**
* **Returning and checking `bool` values**

## 🏗️ Project Structure

The project contains the following main classes:

### `BankAccount`

The base class representing a basic bank account.

It handles:

* Account number
* Owner name
* Balance
* Deposit
* Withdrawal
* Account information
* Operator overloading

### `SavingsAccount`

Derived from `BankAccount`.

Additional functionality:

* Interest rate
* Interest calculation
* Customized account information display

### `CurrentAccount`

Derived from `BankAccount`.

Additional functionality:

* Overdraft limit
* Customized withdrawal behavior
* Customized account information display

### `Bank`

Responsible for managing multiple bank accounts.

It provides:

* Adding accounts
* Finding accounts
* Deleting accounts
* Depositing money
* Withdrawing money
* Transferring money
* Displaying all accounts

## 🖥️ Example Menu

```text
===== BANK SYSTEM =====

1. Add Account
2. Delete Account
3. Deposit
4. Withdraw
5. Find Account
6. Display All Accounts
7. Exit

Choose:
```

## 🛠️ Technologies

* **C++**
* Standard Template Library (STL)
* `vector`
* Console I/O

## ▶️ How to Run

### 1. Clone the repository

```bash
git clone <your-repository-url>
```

### 2. Open the project

Open the project in your preferred C++ IDE or editor, such as:

* Visual Studio
* Visual Studio Code
* Code::Blocks
* CLion

### 3. Compile the program

For example, using `g++`:

```bash
g++ main.cpp -o banking_system
```

### 4. Run

```bash
./banking_system
```

On Windows:

```bash
banking_system.exe
```

## 🎯 Learning Goal

The main goal of this project was to strengthen my understanding of **C++ Object-Oriented Programming** by building a practical application from scratch.

It also helped me practice writing classes, managing objects with vectors, using inheritance and polymorphism, working with pointers, and implementing operator overloading.

## 🚀 Future Improvements

Possible improvements for future versions:

* Store accounts in files
* Add login/authentication
* Add account types directly to the bank system
* Improve input validation
* Add transaction history
* Use smart pointers for polymorphic accounts
* Separate the project into multiple `.h` and `.cpp` files

## 👨‍💻 Author

**Ahmed Nashaat**

This project was built as part of my journey to improve my C++ programming and problem-solving skills.

