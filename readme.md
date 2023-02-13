<header>
<img src="https://www.katsuki.moe/favicons/pinned.svg" alt="logo" height="100" align="left">
<h1 style="display: inline">Neko</h1>

C static socket server library made for rustlib fork

[![GitHub top language](https://img.shields.io/github/languages/top/katsuki-yuri/neko?style=flat-square&logo=github)](https://github.com/katsuki-yuri/neko)
[![Channel](https://img.shields.io/badge/Chat-grey?style=flat-square&logo=telegram)](https://t.me/yurionblog)
[![Makefile CI](https://github.com/katsuki-yuri/neko/actions/workflows/ci.yml/badge.svg)](https://github.com/katsuki-yuri/neko/actions/workflows/ci.yml)

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
./server # or ./server [port]
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.