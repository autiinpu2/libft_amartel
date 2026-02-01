# libft
Extention of 42 libft

That libft can compile with `meson.build` and `Makefile`

## meson

Setup meson

```bash
meson setup builddir
meson compile -C builddir
```
The lib as been created in builddir diretory.

If you want put libft as subprojects in your project you can add `libft.wrap` or set `git submodule add https://github.com/0verLighT/libft.git subprojects/libft`

libft.wrap
```meson
[wrap-git]
url = https://github.com/0verlight/libft.git
revision = HEAD
depth = 1
```
In your meson.build you need to add these lines

```meson
deps = [
	dependency('libft')
]

executable('my_awesome_project' dependencies: deps)
```