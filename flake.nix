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

    pname = "ray-tracing";
    version = "0.1.0";

    buildInputs = with pkgs; [];
    nativeBuildInputs = with pkgs; [];
  in
  {
    devShells.default = pkgs.mkShell {
      inherit pname version buildInputs nativeBuildInputs;
    };
  });
}
