#!/usr/bin/env python3

from utils.Meson import Meson
from utils.Makefile import Makefile


def main() -> None:
    meson = Meson()
    makefile = Makefile()
    meson.check_missing_sources()
    makefile.check_missing_sources()


if __name__ == '__main__':
    main()
