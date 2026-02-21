import os


class BuildSystem:
    B_YELLOW = "\033[1;33m"
    RESET = "\033[0m"
    RED = "\033[31m"
    GREEN = "\033[32m"

    def __init__(self, name):
        self.name = name
        self.sources = set()

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
            raise Exception(f"{self.B_YELLOW}{self.name}:{self.RESET}{self.RED} Missing file{s}: {files}")
        elif extra_files:
            s = 's' if len(extra_files) > 1 else ''
            files = "\n  - " + "\n  - ".join(extra_files)
            raise Exception(f"{self.B_YELLOW}{self.name}:{self.RESET}{self.RED} Extra file{s}: {files}")
        else:
            print(f"{self.GREEN}No missing source in {self.name}{self.RESET}")
