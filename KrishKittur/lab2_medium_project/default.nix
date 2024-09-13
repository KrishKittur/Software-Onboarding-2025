{ stddenv, cmake }:

stddenv.mkDerivation src {
    pname = "nixtest";
    version = "0.1.0";
    src = "./.";
    nativeBuildInputs = [ cmake ];
}