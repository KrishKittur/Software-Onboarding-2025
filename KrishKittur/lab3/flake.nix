{
    inputs = {
        nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
    };

    outputs = { self, nixpkgs }:
        let
            system = "aarch64-darwin";

            proj_overlay = final: prev: rec {
                proj = final.callPackage ./default.nix { };
            };

            my_overlays = [ proj_overlay ];

            pkgs = import nixpkgs {
                system = "aarch64-darwin";
                overlays = [ self.overlays.default ];
            };
        in
        {
            overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
            packages.aarch64-darwin.default = pkgs.proj;
        };

}