# App-2 Login Registration Console Application
---

## Overview
This command-line tool lets a single user register and then log in using stored credentials. 
Data is kept in a CSV file. 
Passwords use a simple Caesar cipher (letters shifted by 3, digits squared) and input is validated at each step. 
On first run, it enters registration mode; on subsequent runs, it prompts for login and verifies the entered credentials.

## 📁 App-2 Project Structure

| Path                     | Type             | Description                                 |
|--------------------------|------------------|---------------------------------------------|
| `App-2/CMakeLists.txt`   | Build Config     | Build configuration for the project         |
| `App-2/include/`         | Header Directory | Public header files                         |
| ├── `input.h`            | Header File      | Input handling functions                    |
| ├── `encryption.h`       | Header File      | Encryption/decryption functions             |
| └── `fileio.h`           | Header File      | File I/O functions                          |
| `App-2/src/`             | Source Directory | Implementation files                        |
| ├── `input.cpp`          | Source File      | Implements input validation                 |
| ├── `encryption.cpp`     | Source File      | Implements Caesar cipher logic              |
| ├── `fileio.cpp`         | Source File      | Implements file read/write                  |
| └── `main.cpp`           | Source File      | Orchestrates registration and login         |
| `App-2/tests/`           | Test Directory   | Unit and integration tests                  |
| ├── `registration.h`     | Test Header      | Test header definitions                     |
| └── `registration.cpp`   | Test Source      | Test implementation                         |
