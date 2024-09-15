{
    inputs = {
        nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
        hellolib.url = "github:KrishKittur/HelloWorldLib";
    };

    outputs = { self, nixpkgs, hellolib }:
        let
            helloapp_overlay = final: prev: rec {
                helloapp = final.callPackage ./default.nix { };
            };

            my_overlays = [ hellolib.overlays.default helloapp_overlay ];

            pkgs = import nixpkgs {
                system = "aarch64-darwin";
                overlays = [ self.overlays.default ];
            };
        in
            {
                packages.aarch64-darwin.default = pkgs.helloapp;
                overlays.default = nixpkgs.lib.composeManyExtensions my_overlays;
            };
}