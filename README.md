C / C++ Mini Projects Collection

This repository contains a collection of console-based C and C++ mini projects created to strengthen my understanding of core programming concepts and their practical application.

The projects progress from basic logic-building programs to slightly advanced applications involving file handling, object-oriented programming, and REST API integration.

Projects Overview

Library Management System
A console-based system to manage books and basic library operations.

What it helped me learn:

Object-Oriented Programming (classes and objects)

File handling for storing and retrieving data

Menu-driven program design

Basic data validation and control flow

Number Guessing Game
A simple interactive game where the user guesses a randomly generated number.

What it helped me learn:

Random number generation

Loops and conditional logic

User input handling

Designing simple game logic

Simple Calculator
A basic calculator supporting arithmetic operations.

What it helped me learn:

Functions and modular code

Switch-case statements

Handling user input

Clean logical separation of operations

Console-Based Supermarket Billing System
Simulates a basic supermarket billing workflow using a console interface.

What it helped me learn:

Structures / classes for real-world entities

Arrays and basic data storage

Menu-based program flow

Logical problem decomposition

User Registration and Login System
A simple authentication system using file-based storage.

What it helped me learn:

File handling (read/write operations)

String comparison and validation

Basic authentication logic

Data persistence across program runs

WeatherCLI (C++ + REST API)
A command-line weather application that fetches real-time weather data using the OpenWeatherMap API.

What it helped me learn:

How REST APIs work in real applications

Making HTTP requests in C++ using libcurl

Parsing JSON responses using nlohmann/json

Error handling for invalid inputs and API failures

Working with third-party libraries in C++

Setting up and debugging a C++ environment on Windows (MSYS2)

Technologies and Concepts Used

Languages:

C

C++

Core Concepts:

Object-Oriented Programming (OOP)

File Handling

Control Structures

Modular Programming

Libraries (WeatherCLI):

libcurl (HTTP requests)

nlohmann/json (JSON parsing)

Platform:

Windows

Toolchain:

MSYS2 (MinGW64)

Editor:

Visual Studio Code

How to Run the WeatherCLI Project (Step-by-Step)

These steps are only required for the WeatherCLI project.
Other projects can be compiled and run using standard g++ commands.

Step 1: Install MSYS2

Download and install MSYS2 from:
https://www.msys2.org

Open the MSYS2 MinGW64 terminal (important).

Step 2: Install Required Packages

In MSYS2 MinGW64, run:

pacman -Syu
pacman -S mingw-w64-x86_64-toolchain
pacman -S mingw-w64-x86_64-curl mingw-w64-x86_64-nlohmann-json

Step 3: Get an OpenWeather API Key

Create an account at https://openweathermap.org

Verify your email

Copy the default API key from https://home.openweathermap.org/api_keys

Wait 10–30 minutes for the key to become active

Step 4: Add the API Key Locally

Open WeatherCLI/weather.cpp and replace:

string apiKey = "YOUR_API_KEY_HERE";

with your own API key locally.

Note: The API key is not included in this repository for security reasons.

Step 5: Navigate to the WeatherCLI Folder

cd /d/C-Cpp-miniProjects/Cpp\ Projects/WeatherCLI

(Adjust the path if your folder structure is different.)

Step 6: Compile the Program

g++ weather.cpp -o weather.exe -lcurl

If there is no output, compilation was successful.

Step 7: Run the Program

./weather.exe

Enter a valid city name such as:
Mumbai
Delhi
London
Tokyo

Sample Output

--- Weather Report ---
City: Mumbai
Temperature: 24.99 °C
Feels Like: 25.03 °C
Humidity: 57 %
Weather: smoke

Key Learnings from This Repository

Writing clean and logical C/C++ programs

Applying OOP concepts beyond theory

Using file handling for real data storage

Understanding how APIs actually behave

Handling errors instead of assuming success

Working with third-party libraries in C++

Setting up a real development environment on Windows

Future Improvements

Add Makefile or CMake build system

Refactor projects using improved OOP design

Add more input validation and error handling

Extend WeatherCLI with forecast support

Improve documentation and code comments

Author
Rihan

Final Note

This repository is intentionally focused on learning and fundamentals, not overengineering.
Each project represents a step forward in understanding how real programs work, not just how to write syntax.
