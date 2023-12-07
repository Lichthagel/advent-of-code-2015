{
  description = "Advent of Code 2015";

  outputs = {
    self,
    nixpkgs,
    flake-parts,
    flake-utils,
  } @ inputs:
    flake-parts.lib.mkFlake {inherit inputs;} {
      systems = flake-utils.lib.defaultSystems;

      perSystem = {
        config,
        lib,
        pkgs,
        system,
        ...
      }: {
        devShells.default = pkgs.mkShell {
          name = "aoc-2015";

          packages = with pkgs; [
            llvmPackages.clang-unwrapped
            cmake
            gcc-unwrapped
            llvmPackages.openmp
            just
          ];
        };
      };
    };

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.11";

    flake-parts.url = "github:hercules-ci/flake-parts";

    flake-utils.url = "github:numtide/flake-utils";
  };
}
