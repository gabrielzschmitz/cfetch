<h1 align="center">
    <br>
    <img src="./cfetch.svg" alt="cfetch">
    <br>
    cfetch
    <br>
</h1>

<h4 align="center">A blazing fast fetch program written in <a href="https://www.open-std.org/JTC1/SC22/WG14/www/standards" target="_blank">C</a>.</h4>

<p align="center">
<a href="./LICENSE"><img src="https://img.shields.io/badge/license-GPL-3.svg" alt="License"></a>
<a href="https://www.buymeacoffee.com/gabrielzschmitz" target="_blank"><img src="https://www.buymeacoffee.com/assets/img/custom_images/orange_img.png" alt="Buy Me A Coffee" style="height: 20px !important;width: 87px;" ></a>
<a href="https://github.com/gabrielzschmitz/cfetch"><img src="https://img.shields.io/github/stars/gabrielzschmitz/cfetch?style=social" alt="Give me a Star"></a>
</p>

<p align="center">
  <a href="#💾-how-to-install">How to Install</a> •
  <a href="#🚀-how-to-use">How to Use</a> •
  <a href="#🎨-fetch-capabilities">Fetch Capabilities</a> •
  <a href="#⚓-dependencies">Dependencies</a> •
  <a href="#🙌-thanks-to">Thanks to</a> •
  <a href="#📜-license">License</a>
</p>

## 💾 How to Install
<b>Note</b>: a good practice is to clone the repo at <i>$HOME/.local/src/</i>.
```
$ git clone https://github.com/gabrielzschmitz/cfetch.git
$ cd cfetch
$ sudo make
```

## 🚀 How to Use
```
$ cfetch
```

To run it everytime you open a terminal you can call it at your shell config:
```
$ echo "cfetch" >> $HOME/.bashrc
$ echo "cfetch" >> $HOME/.zshrc
$ echo "cfetch" >> $HOME/.config/fish/config.fish
```

## 🎨 Fetch Capabilities
It can <b>fetches</b>:
<i>
 * Distribution
 * Kernel
 * Uptime
 * Window Manager 
 * Shell
 * Terminal Colors
</i>

## ⚓ Dependencies
<b>Note</b>: only compatible with [<b>linux</b>](https://www.linuxfoundation.org/).
<i>
* [gcc](https://gcc.gnu.org/)
* [xorg](https://www.x.org/wiki/)
* [xlibwrap](https://github.com/matyklug18/Flexfetch/blob/master/xlibwrap.h) (included in the repo)
* [Nerd Font](https://www.nerdfonts.com/) (for the icons)
</i>

## 🙌 Thanks to
- [<b>matyklug18</b>](https://github.com/matyklug18/Flexfetch) - By creating the base for that program

## 📜 License
This software is licensed under the [GPL-3](./LICENSE) license.

