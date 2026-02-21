{
  description = "Flake libft";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils, ... }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs { inherit system; };
      in
      {
        devShells.default = pkgs.mkShell.override { stdenv = pkgs.clangStdenv; } {
          nativeBuildInputs = with pkgs; [
            doxygen
            graphviz
            meson
            ninja
            python3
            python3Packages.flake8
            clang-tools
          ] ++ pkgs.lib.optionals pkgs.stdenv.isLinux [
            valgrind
            gdb
          ];

          shellHook = ''
            python --version
            cc --version
          '';
        };
      }
    );
}
