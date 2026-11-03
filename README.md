# 🔐 SecureBrowse — Privacy-Focused Web Request Engine

A C++17-based web request engine designed to demonstrate secure URL validation, domain filtering, HTTPS communication, and privacy-conscious request logging.

## 🚀 Overview

SecureBrowse is a privacy-focused networking project that processes web requests while applying basic security checks before communication.

It validates URLs, checks domains against a configurable blocklist, performs HTTP/HTTPS requests using libcurl, and securely records request metadata in an SQLite database.

## ✨ Key Features

- **URL Validation:** Validates HTTP and HTTPS URLs and rejects malformed or unsupported URLs.
- **Domain Blocking:** Blocks configured domains, including their subdomains.
- **Secure HTTP Requests:** Uses libcurl with TLS certificate and hostname verification.
- **Privacy-Focused Logging:** Stores domain names, HTTP status codes, and request outcomes without recording URL paths or query parameters.
- **SQLite Integration:** Maintains persistent request logs.
- **Configurable Blocklist:** Allows users to manage blocked domains through a configuration file.
- **Automated Testing:** Uses GoogleTest to validate core components.

## 🛠️ Tech Stack

| Technology | Purpose |
|---|---|
| C++17 | Core application development |
| CMake | Build configuration |
| libcurl | HTTP/HTTPS communication |
| SQLite | Request logging and storage |
| GoogleTest | Unit testing |
| GCC / MinGW | C++ compilation |

## 🏗️ Project Architecture

```text
SecureBrowse/
│
├── config/
│   └── blocked_domains.txt
│
├── database/
│
├── docs/
│
├── include/
│   ├── url_validator.h
│   ├── http_client.h
│   ├── domain_blocker.h
│   └── request_logger.h
│
├── src/
│   ├── url_validator.cpp
│   ├── http_client.cpp
│   ├── domain_blocker.cpp
│   └── request_logger.cpp
│
├── tests/
│   ├── url_validator_test.cpp
│   ├── domain_blocker_test.cpp
│   └── request_logger_test.cpp
│
├── main.cpp
├── CMakeLists.txt
└── README.md
```

## ⚙️ Installation and Setup

### Prerequisites

- GCC C++ compiler
- CMake 3.20 or higher
- libcurl
- SQLite3
- GoogleTest

### 1. Clone the repository

```bash
git clone https://github.com/fathimaafrah1706/SecureBrowse.git
cd SecureBrowse
```

### 2. Configure the project

For Windows with MSYS2 UCRT64:

```powershell
cmake -S . -B build -G "MinGW Makefiles" -DCMAKE_CXX_COMPILER=C:/msys64/ucrt64/bin/g++.exe -DCMAKE_PREFIX_PATH=C:/msys64/ucrt64
```

### 3. Build

```powershell
cmake --build build
```

### 4. Run the application

```powershell
.\build\SecureBrowse.exe
```

Enter a URL when prompted to test the request engine.

## 🧪 Running Tests

Run the automated test suite using:

```powershell
ctest --test-dir build --output-on-failure
```

**Test results:** 16/16 tests passed.

Test coverage includes:

- URL validation
- Domain blocking
- SQLite request logging

## 🛡️ Security and Privacy

SecureBrowse demonstrates several defensive networking practices:

- TLS certificate verification.
- TLS hostname verification.
- HTTP and HTTPS protocol restrictions.
- Request timeouts.
- Response size limits.
- Disabled automatic redirects.
- Domain-based request blocking.
- Privacy-conscious request logging.

**Note:** This is an educational project and not a production-ready browser or comprehensive security gateway.

## 🔮 Future Improvements

- DNS and IP-based security checks.
- More comprehensive URL validation.
- Expanded security test coverage.
- Improved request monitoring.
- Enhanced configuration management.

## 👩‍💻 Author

**Fathima Afrah**

- GitHub: [@fathimaafrah1706](https://github.com/fathimaafrah1706)
- Project: [SecureBrowse](https://github.com/fathimaafrah1706/SecureBrowse)

---

*Built with C++17 to explore secure networking, privacy engineering, and software testing.*
