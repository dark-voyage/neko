<header>
<img src="https://www.orzklv.uz/favicons/logo.png" alt="logo" height="100" align="left">
<h1 style="display: inline">Neko</h1>

C static socket server library made for rustlib fork

[![GitHub top language](https://img.shields.io/github/languages/top/orzklv/neko?style=flat-square&logo=github)](https://github.com/orzklv/neko)
[![Channel](https://img.shields.io/badge/Chat-grey?style=flat-square&logo=telegram)](https://t.me/orzklvb)
[![Makefile CI](https://github.com/orzklv/neko/actions/workflows/ci.yml/badge.svg)](https://github.com/orzklv/neko/actions/workflows/ci.yml)

</header>

## About

Neko is a C static socket server library made for rustlib. 
It uses the standard library only, so it's easy to compile and run. 
It's also extensible, so you can add your own functions to the server.

> I host all contents statically, so you may correct me up by sending a pull request.

## Features

- Extensible
- Standard Library only
- Essentials included out of the box
- Route based kinda MVC
- Static content hosting

## Compiling

In order to run the website, just install make, gcc or clang (whatever you want).
Then run the following commands:

```bash
make
./neko # or ./neko [port]
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.