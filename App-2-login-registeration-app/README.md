# App-2 Login Registration Console Application
## Overview
This command-line tool lets a single user register and then log in using stored credentials. 
Data is kept in a CSV file. 
Passwords use a simple Caesar cipher (letters shifted by 3, digits squared) and input is validated at each step. 
On first run, it enters registration mode; on subsequent runs, it prompts for login and verifies the entered credentials.

## Application Structure
App-2/
├── CMakeLists.txt       # Build configuration
├── include/             # Public headers
│   ├── input.h          # Input handling functions
│   ├── encryption.h     # Encryption/decryption functions
│   └── fileio.h         # File I/O functions
└── src/                 # Source files
│    ├── input.cpp        # Implements input validation
│    ├── encryption.cpp   # Implements Caesar cipher logic
│    ├── fileio.cpp       # Implements file read/write
│    └── main.cpp         # Orchestrates registration and login
├── tests/             # tests
│   ├── registration.h       # All headers
│   ├── registration.cpp     # Did everything
