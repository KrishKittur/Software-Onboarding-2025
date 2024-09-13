{ stdenv, cmake }:

stdenv.mkDerivation rec {
    pname = "learn_nix"; 
    version = "0.1.0";
    src = ./.;
    nativeBuildInputs = [ cmake ];
}