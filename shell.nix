{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell rec {
  stdenv = pkgs.clangStdenv;

  packages = with pkgs; [
    doxygen
    graphviz
    meson
    ninja
  ]
  ++ pkgs.lib.optionals stdenv.isLinux [
    valgrind
    gdb
  ];

  shellHook = ''
    echo "direnv for lift"
    cc --version
  '';
}
