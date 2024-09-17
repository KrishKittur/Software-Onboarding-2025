{ stdenv, cmake, protobuf }:

stdenv.mkDerivation rec {
    pname = "proj";
    version = "0.1.0";
    src = ./.;
    nativeBuildInputs = [ cmake ];
    buildInputs = [ protobuf ];
}