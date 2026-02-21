import re
from .BuildSystem import BuildSystem


class Makefile(BuildSystem):
    def __init__(self):
        super().__init__("Makefile")

    def _get_sources(self, path="Makefile") -> set:
        """
        Get source files from Makefile in path arg
        """
        try:
            with open(path, 'r') as f:
                content = f.read()
        except FileNotFoundError:
            raise Exception(f"{self.B_YELLOW}{self.name}:{self.RESET}{self.RED} file '{path}' doesn't exist")

        match = re.search(r'^SOURCES\s*:?=\s*(.*?)(?:\n\n|\n[A-Z]|\Z)', content, re.MULTILINE | re.DOTALL)

        if not match:
            raise Exception(f"{self.B_YELLOW}{self.name}:{self.RESET}{self.RED} no SOURCES variable found")

        raw = match.group(1)
        raw = raw.replace('\\', '')
        self.sources = set(raw.split())
        return (self.sources)
