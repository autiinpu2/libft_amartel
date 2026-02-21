import os
import re

B_YELLOW = "\033[1;33m"
RESET = "\033[0m"
RED = "\033[31m"
GREEN = "\033[32m"


class Makefile:
    def __init__(self):
        self.sources = set()
    # regex 'sources\s*\+?=\s*files\((.*?)\)' for match files
    # regex '^\s*subdir\((.*)\)' for match subdir(0)

    def _get_sources(self, path="Makefile") -> set:
        """
        Get source files from Makefile in path arg
        """
        try:
            with open(path, 'r') as f:
                content = f.read()
        except FileNotFoundError:
            raise Exception(f"{B_YELLOW}Makefile:{RESET}{RED} file '{path}' doesn't exist")

        match = re.search(r'^SOURCES\s*:?=\s*(.*?)(?:\n\n|\n[A-Z]|\Z)', content, re.MULTILINE | re.DOTALL)

        if not match:
            raise Exception(f"{B_YELLOW}Makefile:{RESET}{RED} no SOURCES variable found")

        raw = match.group(1)
        raw = raw.replace('\\', '')
        self.sources = set(raw.split())
        return (self.sources)

    def _get_disk_sources(self) -> set:
        disk_sources = set()
        for root, dirs, files in os.walk("src"):
            for file in files:
                if file.endswith(".c"):
                    disk_sources.add(os.path.join(root, file).replace("\\", "/"))
        return (disk_sources)

    def check_missing_sources(self) -> None:
        self._get_sources()
        disk_sources = self._get_disk_sources()

        missing_files = disk_sources - self.sources
        extra_files = self.sources - disk_sources

        if missing_files:
            s = 's' if len(missing_files) > 1 else ''
            files = "\n  - " + "\n  - ".join(missing_files)
            raise Exception(f"{B_YELLOW}Makefile:{RESET}{RED} Missing file{s}: {files}")
        elif extra_files:
            s = 's' if len(extra_files) > 1 else ''
            files = "\n  - " + "\n  - ".join(extra_files)
            raise Exception(f"{B_YELLOW}Makefile:{RESET}{RED} Extra file{s}: {files}")
        else:
            print(f"{GREEN}No missing source in Makefile")
