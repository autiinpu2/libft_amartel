{ pkgs ? import <nixpkgs> {} }:
(pkgs.mkShell.override { stdenv = pkgs.clangStdenv; }) {
  packages = with pkgs; [
    doxygen
    graphviz
    meson
    ninja
    python312
    python312Packages.flake8
  ]
  ++ lib.optionals stdenv.isLinux [
    valgrind
    gdb
  ];
  shellHook = ''cc --version'';
}
