# Bank System

This repository contains a C++ implementation of a Bank System application. The system consists of three modules: Client, Employee, and Admin, each with specific functionalities.

**Description:**

This project implements a bank system application in C++, providing functionalities for clients to manage their accounts, employees to manage client information, and administrators to manage employees and system settings.

**Key Features:**

*   Client account management (deposit, withdrawal, transfer, balance check)
*   Employee management of client data (add, search, list, edit)
*   Admin management of employee data (add, search, list, edit)
*   Data persistence using text files
*   User-friendly menu-driven interface
*   Input validation to ensure data integrity

This project was developed as a practical exercise in object-oriented programming, data structures, and file handling in C++.  The project is implemented in three phases: Phase 1 establishes the core classes, Phase 2 implements data persistence and expands functionalities, and Phase 3 focuses on the user interface and application flow.  Technologies used: C++, file I/O.

## Project Structure

The project is structured into three phases, each with its own deadline and deliverables.  The code is organized into header (.h) and source (.cpp) files for each class.

## Phase 1  Core Classes

This phase focuses on creating the fundamental classes and their basic functionalities.

*   **Client Class:**
    *   **Attributes:** `int id`, `string name`, `string password`, `double balance`
    *   **Setters:** `setName(string name)`, `setPassword(string password)`,  (Balance is set during account creation and modified by deposit/withdraw)
        *   **Validation:** `setName`: Alphabetic characters only, 5-20 characters. `setPassword`: 8-20 characters. Initial balance must be >= 1500.
    *   **Getters:** `getId()`, `getName()`, `getPassword()`, `getBalance()`
    *   **Methods:**
        *   `deposit(double amount)`: Adds `amount` to the balance.
        *   `withdraw(double amount)`: Subtracts `amount` from the balance (check for sufficient funds).
        *   `transferTo(double amount, Client& recipient)`: Transfers `amount` to another client's account (check for sufficient funds).
        *   `checkBalance()`: Displays the current balance.
        *   `display()`: Displays client information (ID, name, balance).

*   **Employee Class:**
    *   **Attributes:** `int id`, `string name`, `string password`, `double salary`
    *   **Setters:** `setName(string name)`, `setPassword(string password)`, `setSalary(double salary)`
        *   **Validation:** `setName`: Alphabetic characters only, 5-20 characters. `setPassword`: 8-20 characters. `setSalary`: Minimum salary 5000.
    *   **Getters:** `getId()`, `getName()`, `getPassword()`, `getSalary()`
    *   **Methods:** `display()`: Displays employee information (ID, name, salary).

*   **Admin Class:** Inherits from `Employee`.
    *   **Attributes:** (Inherited)
    *   **Setters:** (Inherited)
    *   **Getters:** (Inherited)
    *   **Methods:** (Inherited)

*   **Validation Class:**
    *   **Static Methods:**
        *   `isValidName(string name)`: Validates name.
        *   `isValidPassword(string password)`: Validates password.
        *   `isValidBalance(double balance)`: Validates initial balance.
        *   `isValidSalary(double salary)`: Validates salary.

## Phase 2  Data Persistence and Functionality

This phase introduces file storage and expands the classes with data management capabilities.

*   **Data Storage:**
    *   `Clients.txt`: Stores client data (ID, name, password, balance - comma-separated).
    *   `Employees.txt`: Stores employee data (ID, name, password, salary - comma-separated).
    *   `Admins.txt`: Stores admin data (ID, name, password, salary - comma-separated).

*   **DataSourceInterface:**
    *   **Abstract Methods:** `addClient(Client)`, `addEmployee(Employee)`, `addAdmin(Admin)`, `getAllClients()`, `getAllEmployees()`, `getAllAdmins()`, `removeAllClients()`, `removeAllEmployees()`, `removeAllAdmins()`

*   **FileManager:** Implements `DataSourceInterface`.  Handles file I/O operations for all data storage files.

*   **Client Class Enhancements:** (See Phase 1)

*   **Employee Class Enhancements:**
    *   `addClient(Client& client)`: Adds a new client to the system (and `Clients.txt`).
    *   `searchClient(int id)`: Searches for a client by ID.
    *   `listClients()`: Lists all clients.
    *   `editClient(int id, string name, string password, double balance)`: Edits client information in the system and updates `Clients.txt`.

*   **Admin Class Enhancements:**
    *   (Inherits Employee functionalities)
    *   `addEmployee(Employee& employee)`: Adds a new employee to the system (and `Employees.txt`).
    *   `searchEmployee(int id)`: Searches for an employee by ID.
    *   `editEmployee(int id, string name, string password, double salary)`: Edits employee information in the system and updates `Employees.txt`.
    *   `listEmployees()`: Lists all employees.

*   **Parser Class:**
    *   **Static Methods:**
        *   `split(string line)`: Splits a line from a file into a vector of strings (using a delimiter like comma).
        *   `parseToClient(string line)`: Creates a `Client` object from a parsed line.
        *   `parseToEmployee(string line)`: Creates an `Employee` object from a parsed line.
        *   `parseToAdmin(string line)`: Creates an `Admin` object from a parsed line.

*   **FilesHelper Class:**
    *   **Static Methods:**
        *   `saveLast(string fileName, int id)`: Saves the last used ID to a file (e.g., `last_client_id.txt`).
        *   `getLast(string fileName)`: Retrieves the last used ID from a file.
        *   `saveClient(Client c)`: Saves client data to `Clients.txt`.
        *   `saveEmployee(string fileName, string lastIdFile, Employee e)`: Saves employee data to `Employees.txt`.
        *   `getClients()`: Retrieves all clients from `Clients.txt`.
        *   `getEmployees()`: Retrieves all employees from `Employees.txt`.
        *   `getAdmins()`: Retrieves all admins from `Admins.txt`.
        *   `clearFile(string fileName, string lastIdFile)`: Clears the content of a data file.

## Phase 3  User Interface and Application Flow

This phase focuses on creating the user interface and managing the overall application flow.

*   **ClientManager Class:**
    *   **Static Methods:**
        *   `printClientMenu()`: Displays the client menu options.
        *   `updatePassword(Person* person)`: Allows a user to update their password.
        *   `login(int id, string password)`: Handles client login.
        *   `clientOptions(Client* client)`: Manages client menu options.

*   **EmployeeManager Class:**
    *   **Static Methods:**
        *   `printEmployeeMenu()`: Displays the employee menu options.
        *   `newClient(Employee* employee)`: Handles creating a new client.
        *   `listAllClients(Employee* employee)`: Lists all clients.
        *   `searchForClient(Employee* employee)`: Searches for a client.
        *   `editClientInfo(Employee* employee)`: Edits client information.
        *   `login(int id, string password)`: Handles employee login.
        *   `employeeOptions(Employee* employee)`: Manages employee menu options.

*   **AdminManager Class:**
    *   **Static Methods:**
        *   `printAdminMenu()`: Displays the admin menu options.
        *   `login(int id, string password)`: Handles admin login.
        *   `adminOptions(Admin* admin)`: Manages admin menu options.

*   **Screens Class:**
    *   **Static Methods:**
        *   `bankName()`: Displays the bank name.
        *   `welcome()`: Displays the welcome message.
        *   `loginOptions()`: Displays login options (client, employee, admin).
        *   `loginAs()`: Gets user input for login role.
        *   `invalid(int c)`: Displays an invalid input message
