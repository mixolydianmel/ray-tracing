{
  description = "My work through the famous \"Ray Tracing in One Weekend\" series. ";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
  flake-utils.lib.eachDefaultSystem (system:
  let
    pkgs = import nixpkgs {
      inherit system;
    };
    stdenv = pkgs.clangStdenv;

    pname = "ray-tracing";
    version = "0.1.0";
    src = ./src/.;

    buildInputs = with pkgs; [
      glibc
    ];

    nativeBuildInputs = with pkgs; [
      pkg-config
      clang-tools
      lldb
      valgrind
    ];
  in
  {
    devShells.default = pkgs.mkShell.override { stdenv = pkgs.clangStdenv; } {
      inherit pname version buildInputs nativeBuildInputs;

      # Set default cflags for shell
      NIX_CFLAGS_COMPILE = "-std=c++17 -Wall -Werror -g -fsanitize=address";
    };

    packages.default = stdenv.mkDerivation {
      inherit pname version buildInputs nativeBuildInputs src;

      buildPhase = ''
        $CC $CFLAGS $LDFLAGS $src/main.cc -o $pname
      '';

      installPhase = ''
        mkdir -p $out/bin
        mv $pname $out/bin/$pname
      '';
    };
  });
}
