{ stdenv, cmake }:

stdenv.mkDerivation rec {
    pname = "learn_nix"; 
    verion = "0.1.0";
    src = "./.";
    nativeBuildInputs = [ cmake ];
}