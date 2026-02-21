import os
import re
from .BuildSystem import BuildSystem


class Meson(BuildSystem):
    def __init__(self):
        super().__init__("Meson")

    def _get_sources(self, path="meson.build") -> set:
        """
        Get source files from meson in path arg
        """
        try:
            with open(path, 'r') as f:
                content = f.read()
        except FileNotFoundError:
            raise Exception(f"{self.B_YELLOW}Meson:{self.RESET}{self.RED} file '{path}' doesn't exist")

        # regex 'sources\s*\+?=\s*files\((.*?)\)' for match files
        match = re.search(r'sources\s*\+?=\s*files\((.*?)\)', content, re.DOTALL)
        if match:
            sources = re.findall(r"'([a-zA-Z].*)'", match.group(1))
            self.sources.update(sources)

        # regex '^\s*subdir\((.*)\)' for match subdir('anything')
        subdir = re.findall(r"subdir\('(.*)'\)", content)
        if subdir:
            for directory in subdir:
                base_dir = os.path.dirname(path)
                subdir_path = os.path.join(base_dir, directory, "meson.build").replace("\\", "/")
                self._get_sources(subdir_path)
        return (self.sources)
