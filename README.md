<p align="center"><img src="extra/icon.png" alt="Lua Raspi" height=150 /></p>

<h1 align="center">Lua Raspi</h1>

A Lua script embedded interpreter for the Raspberry Pi. If you are an amateur maker, with Lua Raspi you can make small proyects easier and faster on your Raspberry Pi. The system, which is based on Raspbian Lite, has been simplified and now inclides all necessary stuff to run your projects in Lua language.

<p align="center"><a href="www.lua.org"><img src="https://img.shields.io/badge/powered%20by-Lua%205.4-blue" alt="Powered by Lua" /></a> <a href="github.com/NEKERAFA/LRaspi/releases"><img src="https://img.shields.io/github/v/release/NEKERAFA/Lua-Raspi?include_prereleases" alt="Lua Raspi 2022.1" /></a> <a href="github.com/NEKERAFA/Lua-Raspi/blob/master/LICENSE"><img src="https://img.shields.io/github/license/nekerafa/lua-raspi" alt="MIT License" /></a></p>

---

## Dependencies

* [Lua 5.4](www.lua.org)
* [RayLib 3.7](www.raylib.com)

## Building

*work in progress*

## Example

```lua
while true do
    screen.clear()

    screen:print("Hello world!", 10, 10)

    screen.flip()
end
```

## Reference

All modules and functions are compiled in the [Lua Raspi Reference](https://nekerafa.github.io/LRaspi/reference/index.html) page. For language reference, you can check the [Lua 5.4 Reference](https://www.lua.org/manual/5.4/manual.html) in the official page.

The C++ module wrappes are docummented in the [Lua Raspi C Reference](https://nekerafa.github.io/LRaspi/doxygen/index.html) page.

## Downloads

You can see all releases in [GitHub Repository](https://github.com/NEKERAFA/Lua-Raspi/releases)

#### Last Release

* [2019-09-lraspi-0.0.2r.tar.xz](https://github.com/NEKERAFA/Lua-Raspi/releases/download/v0.0.2-alpha/2019-09-lraspi-0.0.2r.tar.xz)
* [2019-09-lraspi-0.0.2r.zip](https://github.com/NEKERAFA/Lua-Raspi/releases/download/v0.0.2-alpha/2019-09-lraspi-0.0.2r.zip)

---

### License

> MIT License
>
> Copyright (c) 2019 Rafael Alcalde Azpiazu
>
> Permission is hereby granted, free of charge, to any person obtaining a copy
> of this software and associated documentation files (the "Software"), to deal
> in the Software without restriction, including without limitation the rights
> to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
> copies of the Software, and to permit persons to whom the Software is
> furnished to do so, subject to the following conditions:
> 
> The above copyright notice and this permission notice shall be included in all
> copies or substantial portions of the Software.
> 
> THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
> IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
> FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
> AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
> LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
> OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
> SOFTWARE.
