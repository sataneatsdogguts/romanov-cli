## Зависимости
`cmake`
`pkg-config`
`cJSON`:

* **Debian:**
  ```bash
  sudo apt install build-essential cmake pkg-config libcjson-dev
  ```

* **Arch Linux:**
  ```bash
  sudo pacman -S base-devel cmake pkgconf cjson
  ```

## Установка

Устанавливается локально в папку `~/.local` (без `sudo`):

```bash
git clone 
cd romanov
cmake -B build
cmake --build build
cmake --install build
```

> **Примечание:** Если после вызова появляется `romanov: command not found`, добавьте `~/.local/bin` в переменную `PATH`:
>
> bash
> ```bash
> echo 'export PATH="HOME/.local/bin:PATH"' >> ~/.bashrc
> source ~/.bashrc
> ```
>
> zsh
> ```bash
> echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.zshrc
> source ~/.zshrc
> ```
>
> fish
> ```bash
> fish_add_path ~/.local/bin
> ```

## Использование

```bash
romanov
```

