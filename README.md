# AgDev Examples

This repository contains various examples for AgDev developers, showcasing different techniques and functionalities. Below is an overview of the repository and instructions to get started.

## Overview

This repository provides a collection of examples aimed at helping developers working with AgDev. The examples cover various aspects of development, including integration with assembly language and basic C programming techniques.

## Examples

### 01-helloworld

A simple "Hello, World!" example to get you started with basic syntax and structure.

### 02-callasmfromc

Demonstrates how to call assembly code from a C program, illustrating interoperability between different programming languages.

## Installation

To get started with the examples, clone the repository to your local machine:

```bash
git clone https://github.com/mikolajmikolajczyk/agdev-examples.git
```

Make sure you have [AgDev](https://github.com/pcawte/AgDev) installed.

## Usage

Navigate to the desired example directory and follow the instructions provided in the respective `README.md` or comments within the code files.

Example of running `01-helloworld`:

```bash
cd 01-helloworld
make
```

Optionally, with a bit of additional setup for hexload utility - look [here](https://mikolajczyk.org/posts/agon-hexload-wsl/) you can also execute `make send` to send example directly to Agon via serial port.

## Contributing

We welcome contributions! Please follow these steps:

1. Fork the repository
2. Create a new branch (git checkout -b feature-branch)
3. Commit your changes (git commit -m 'Add new feature')
4. Push to the branch (git push origin feature-branch)
5. Open a pull request

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.